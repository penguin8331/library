#pragma once
#include "../../template/template.hpp"

// edge class (for network-flow)
template<class FLOWTYPE, class COSTTYPE> struct FlowCostEdge {
    // core members
    int rev, from, to;
    FLOWTYPE cap, icap, flow;
    COSTTYPE cost;
    
    // constructor
    FlowCostEdge(int rev, int from, int to, FLOWTYPE cap, COSTTYPE cost)
    : rev(rev), from(from), to(to), cap(cap), icap(cap), flow(0), cost(cost) {}
    void reset() { cap = icap, flow = 0; }
    
    // debug
    friend ostream& operator << (ostream& s, const FlowCostEdge& e) {
        return s << e.from << " -> " << e.to
        << " (" << e.flow << "/" << e.icap << ", " << e.cost << ")";
    }
};

// graph class (for network-flow)
template<class FLOWTYPE, class COSTTYPE> struct FlowCostGraph {
    // core members
    vector<vector<FlowCostEdge<FLOWTYPE, COSTTYPE>>> list;
    vector<pair<int,int>> pos;  // pos[i] := {vertex, order of list[vertex]} of i-th edge
    
    // constructor
    FlowCostGraph(int n = 0) : list(n) { }
    void init(int n = 0) {
        list.assign(n, FlowCostEdge<FLOWTYPE, COSTTYPE>());
        pos.clear();
    }
    
    // getter
    vector<FlowCostEdge<FLOWTYPE, COSTTYPE>> &operator [] (int i) {
        return list[i];
    }
    const vector<FlowCostEdge<FLOWTYPE, COSTTYPE>> &operator [] (int i) const {
        return list[i];
    }
    size_t size() const {
        return list.size();
    }
    FlowCostEdge<FLOWTYPE, COSTTYPE> &get_rev_edge
    (const FlowCostEdge<FLOWTYPE, COSTTYPE> &e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }
    FlowCostEdge<FLOWTYPE, COSTTYPE> &get_edge(int i) {
        return list[pos[i].first][pos[i].second];
    }
    const FlowCostEdge<FLOWTYPE, COSTTYPE> &get_edge(int i) const {
        return list[pos[i].first][pos[i].second];
    }
    vector<FlowCostEdge<FLOWTYPE, COSTTYPE>> get_edges() const {
        vector<FlowCostEdge<FLOWTYPE, COSTTYPE>> edges;
        for (int i = 0; i < (int)pos.size(); ++i) {
            edges.push_back(get_edge(i));
        }
        return edges;
    }
    
    // change edges
    void reset() {
        for (int i = 0; i < (int)list.size(); ++i) {
            for (FlowCostEdge<FLOWTYPE, COSTTYPE> &e : list[i]) e.reset();
        }
    }
    
    // add_edge
    void add_edge(int from, int to, FLOWTYPE cap, COSTTYPE cost) {
        pos.emplace_back(from, (int)list[from].size());
        list[from].push_back(FlowCostEdge<FLOWTYPE, COSTTYPE>
                             ((int)list[to].size(), from, to, cap, cost));
        list[to].push_back(FlowCostEdge<FLOWTYPE, COSTTYPE>
                           ((int)list[from].size() - 1, to, from, 0, -cost));
    }

    // debug
    friend ostream& operator << (ostream& s, const FlowCostGraph &G) {
        const auto &edges = G.get_edges();
        for (const auto &e : edges) s << e << endl;
        return s;
    }
};

// min-cost max-flow (<= limit_flow), slope ver.
template<class FLOWTYPE, class COSTTYPE> vector<pair<FLOWTYPE, COSTTYPE>>
MinCostFlowSlope(FlowCostGraph<FLOWTYPE, COSTTYPE> &G, int S, int T, FLOWTYPE limit_flow)
{
    // result values
    FLOWTYPE cur_flow = 0;
    COSTTYPE cur_cost = 0, pre_cost = -1;
    vector<pair<FLOWTYPE, COSTTYPE>> res;
    res.emplace_back(cur_flow, cur_cost);
    
    // intermediate values
    vector<COSTTYPE> dual((int)G.size(), 0), dist((int)G.size());
    vector<int> prevv((int)G.size(), -1), preve((int)G.size(), -1);
    
    // dual
    auto dual_step = [&]() -> bool {
        priority_queue<pair<COSTTYPE,int>, vector<pair<COSTTYPE,int>>, greater<pair<COSTTYPE,int>>> que;
        que.push({0, S});
        dist.assign((int)G.size(), numeric_limits<COSTTYPE>::max());
        dist[S] = 0;
        while (!que.empty()) {
            auto [cur_cost, v] = que.top();
            que.pop();
            if (dist[v] < cur_cost) continue;
            for (int i = 0; i < (int)G[v].size(); ++i) {
                const auto &e = G[v][i];
                COSTTYPE new_cost = e.cost + dual[v] - dual[e.to];
                if (e.cap > 0 && dist[e.to] > dist[v] + new_cost) {
                    dist[e.to] = dist[v] + new_cost;
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push({dist[e.to], e.to});
                }
            }
        }
        if (dist[T] == numeric_limits<COSTTYPE>::max()) return false;
        for (int v = 0; v < (int)G.size(); ++v) {
            if (dist[T] == numeric_limits<COSTTYPE>::max()) continue;
            dual[v] -= dist[T] - dist[v];
        }
        return true;
    };
    
    // primal
    auto primal_step = [&]() -> void {
        FLOWTYPE flow = limit_flow - cur_flow;
        COSTTYPE cost = -dual[S];
        for (int v = T; v != S; v = prevv[v]) {
            flow = min(flow, G[prevv[v]][preve[v]].cap);
        }
        for (int v = T; v != S; v = prevv[v]) {
            FlowCostEdge<FLOWTYPE, COSTTYPE> &e = G[prevv[v]][preve[v]];
            FlowCostEdge<FLOWTYPE, COSTTYPE> &re = G.get_rev_edge(e);
            e.cap -= flow, e.flow += flow;
            re.cap += flow, re.flow -= flow;
        }
        cur_flow += flow;
        cur_cost += flow * cost;
        if (pre_cost == cost) res.pop_back();
        res.emplace_back(cur_flow, cur_cost);
        pre_cost = cur_cost;
    };
    
    // primal-dual
    while (cur_flow < limit_flow) {
        if (!dual_step()) break;
        primal_step();
    }
    return res;
}

// min-cost max-flow, slope ver.
template<class FLOWTYPE, class COSTTYPE> vector<pair<FLOWTYPE, COSTTYPE>>
MinCostFlowSlope(FlowCostGraph<FLOWTYPE, COSTTYPE> &G, int S, int T)
{
    return MinCostFlowSlope(G, S, T, numeric_limits<FLOWTYPE>::max());
}

// min-cost max-flow (<= limit_flow)
template<class FLOWTYPE, class COSTTYPE> pair<FLOWTYPE, COSTTYPE>
MinCostFlow(FlowCostGraph<FLOWTYPE, COSTTYPE> &G, int S, int T, FLOWTYPE limit_flow)
{
    return MinCostFlowSlope(G, S, T, limit_flow).back();
}

// min-cost max-flow (<= limit_flow)
template<class FLOWTYPE, class COSTTYPE> pair<FLOWTYPE, COSTTYPE>
MinCostFlow(FlowCostGraph<FLOWTYPE, COSTTYPE> &G, int S, int T)
{
    return MinCostFlow(G, S, T, numeric_limits<FLOWTYPE>::max());
}