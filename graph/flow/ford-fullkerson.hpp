#pragma once
#include "../../template/template.hpp"

// edge class (for network-flow)
template<class FLOWTYPE> struct FlowEdge {
    // core members
    int rev, from, to;
    FLOWTYPE cap, icap, flow;
    
    // constructor
    FlowEdge(int r, int f, int t, FLOWTYPE c)
    : rev(r), from(f), to(t), cap(c), icap(c), flow(0) {}
    void reset() { cap = icap, flow = 0; }
    
    // debug
    friend ostream& operator << (ostream& s, const FlowEdge& E) {
        return s << E.from << "->" << E.to << '(' << E.flow << '/' << E.icap << ')';
    }
};

// graph class (for network-flow)
template<class FLOWTYPE> struct FlowGraph {
    // core members
    vector<vector<FlowEdge<FLOWTYPE>>> list;
    vector<pair<int,int>> pos;  // pos[i] := {vertex, order of list[vertex]} of i-th edge
    
    // constructor
    FlowGraph(int n = 0) : list(n) { }
    void init(int n = 0) {
        list.assign(n, FlowEdge<FLOWTYPE>());
        pos.clear();
    }
    
    // getter
    vector<FlowEdge<FLOWTYPE>> &operator [] (int i) {
        return list[i];
    }
    const vector<FlowEdge<FLOWTYPE>> &operator [] (int i) const {
        return list[i];
    }
    size_t size() const {
        return list.size();
    }
    FlowEdge<FLOWTYPE> &get_rev_edge(const FlowEdge<FLOWTYPE> &e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }
    FlowEdge<FLOWTYPE> &get_edge(int i) {
        return list[pos[i].first][pos[i].second];
    }
    const FlowEdge<FLOWTYPE> &get_edge(int i) const {
        return list[pos[i].first][pos[i].second];
    }
    vector<FlowEdge<FLOWTYPE>> get_edges() const {
        vector<FlowEdge<FLOWTYPE>> edges;
        for (int i = 0; i < (int)pos.size(); ++i) {
            edges.push_back(get_edge(i));
        }
        return edges;
    }
    
    // change edges
    void reset() {
        for (int i = 0; i < (int)list.size(); ++i) {
            for (FlowEdge<FLOWTYPE> &e : list[i]) e.reset();
        }
    }
    void change_edge(FlowEdge<FLOWTYPE> &e, FLOWTYPE new_cap, FLOWTYPE new_flow) {
        FlowEdge<FLOWTYPE> &re = get_rev_edge(e);
        e.cap = new_cap - new_flow, e.icap = new_cap, e.flow = new_flow;
        re.cap = new_flow;
    }
    
    // add_edge
    void add_edge(int from, int to, FLOWTYPE cap) {
        pos.emplace_back(from, (int)list[from].size());
        list[from].push_back(FlowEdge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(FlowEdge<FLOWTYPE>((int)list[from].size() - 1, to, from, 0));
    }

    // debug
    friend ostream& operator << (ostream& s, const FlowGraph &G) {
        const auto &edges = G.get_edges();
        for (const auto &e : edges) s << e << endl;
        return s;
    }
};

// Ford-Fulkerson
template<class FLOWTYPE> FLOWTYPE FordFulkerson
 (FlowGraph<FLOWTYPE> &G, int s, int t, FLOWTYPE limit_flow)
{
    FLOWTYPE current_flow = 0;
    
    // DFS
    vector<bool> used((int)G.size(), false);
    auto dfs = [&](auto self, int v, FLOWTYPE up_flow) {
        if (v == t) return up_flow;
        FLOWTYPE res_flow = 0;
        used[v] = true;
        for (FlowEdge<FLOWTYPE> &e : G[v]) {
            if (used[e.to] || e.cap == 0) continue;
            FLOWTYPE flow = self(self, e.to, min(up_flow - res_flow, e.cap));
            FlowEdge<FLOWTYPE> &re = G.get_rev_edge(e);
            if (flow <= 0) continue;
            res_flow += flow;
            e.cap -= flow, e.flow += flow;
            re.cap += flow, re.flow -= flow;
            if (res_flow == up_flow) break;
        }
        return res_flow;
    };
    
    // flow
    while (current_flow < limit_flow) {
        used.assign((int)G.size(), false);
        FLOWTYPE flow = dfs(dfs, s, limit_flow - current_flow);
        if (!flow) break;
        current_flow += flow;
    }
    return current_flow;
};

template<class FLOWTYPE> FLOWTYPE FordFulkerson(FlowGraph<FLOWTYPE> &G, int s, int t) {
    return FordFulkerson(G, s, t, numeric_limits<FLOWTYPE>::max());
}