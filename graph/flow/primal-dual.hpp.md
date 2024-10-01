---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define overload3(_1, _2, _3, name, ...) name\n\
    #define all1(v) std::begin(v), std::end(v)\n#define all2(v, a) std::begin(v),\
    \ std::begin(v) + a\n#define all3(v, a, b) std::begin(v) + a, std::begin(v) +\
    \ b\n#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)\n\
    #define rall1(v) std::rbegin(v), std::rend(v)\n#define rall2(v, a) std::rbegin(v),\
    \ std::rbegin(v) + a\n#define rall3(v, a, b) std::rbegin(v) + a, std::rbegin(v)\
    \ + b\n#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)\n\
    #define elif else if\n#define updiv(N, X) (((N) + (X) - 1) / (X))\n#define sigma(a,\
    \ b) (((a) + (b)) * ((b) - (a) + 1) / 2)\n#define INT(...)     \\\n    int __VA_ARGS__;\
    \ \\\n    scan(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define STR(...)        \\\n    string __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define CHR(...)      \\\n    char __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define DOU(...)        \\\n    double __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define LD(...)     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define pb push_back\n#define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\
    \nusing ll = long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\n\
    using pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF\
    \ = 1LL << 60;\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr\
    \ int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr\
    \ int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\ntemplate <typename T, typename U>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n\
    \    return os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <dump.hpp>\n#else\n#define\
    \ debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n\
    #line 3 \"graph/flow/primal-dual.hpp\"\n\n// edge class (for network-flow)\ntemplate<class\
    \ FLOWTYPE, class COSTTYPE> struct FlowCostEdge {\n    // core members\n    int\
    \ rev, from, to;\n    FLOWTYPE cap, icap, flow;\n    COSTTYPE cost;\n    \n  \
    \  // constructor\n    FlowCostEdge(int rev, int from, int to, FLOWTYPE cap, COSTTYPE\
    \ cost)\n    : rev(rev), from(from), to(to), cap(cap), icap(cap), flow(0), cost(cost)\
    \ {}\n    void reset() { cap = icap, flow = 0; }\n    \n    // debug\n    friend\
    \ ostream& operator << (ostream& s, const FlowCostEdge& e) {\n        return s\
    \ << e.from << \" -> \" << e.to\n        << \" (\" << e.flow << \"/\" << e.icap\
    \ << \", \" << e.cost << \")\";\n    }\n};\n\n// graph class (for network-flow)\n\
    template<class FLOWTYPE, class COSTTYPE> struct FlowCostGraph {\n    // core members\n\
    \    vector<vector<FlowCostEdge<FLOWTYPE, COSTTYPE>>> list;\n    vector<pair<int,int>>\
    \ pos;  // pos[i] := {vertex, order of list[vertex]} of i-th edge\n    \n    //\
    \ constructor\n    FlowCostGraph(int n = 0) : list(n) { }\n    void init(int n\
    \ = 0) {\n        list.assign(n, FlowCostEdge<FLOWTYPE, COSTTYPE>());\n      \
    \  pos.clear();\n    }\n    \n    // getter\n    vector<FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE>> &operator [] (int i) {\n        return list[i];\n    }\n    const\
    \ vector<FlowCostEdge<FLOWTYPE, COSTTYPE>> &operator [] (int i) const {\n    \
    \    return list[i];\n    }\n    size_t size() const {\n        return list.size();\n\
    \    }\n    FlowCostEdge<FLOWTYPE, COSTTYPE> &get_rev_edge\n    (const FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE> &e) {\n        if (e.from != e.to) return list[e.to][e.rev];\n   \
    \     else return list[e.to][e.rev + 1];\n    }\n    FlowCostEdge<FLOWTYPE, COSTTYPE>\
    \ &get_edge(int i) {\n        return list[pos[i].first][pos[i].second];\n    }\n\
    \    const FlowCostEdge<FLOWTYPE, COSTTYPE> &get_edge(int i) const {\n       \
    \ return list[pos[i].first][pos[i].second];\n    }\n    vector<FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE>> get_edges() const {\n        vector<FlowCostEdge<FLOWTYPE, COSTTYPE>>\
    \ edges;\n        for (int i = 0; i < (int)pos.size(); ++i) {\n            edges.push_back(get_edge(i));\n\
    \        }\n        return edges;\n    }\n    \n    // change edges\n    void\
    \ reset() {\n        for (int i = 0; i < (int)list.size(); ++i) {\n          \
    \  for (FlowCostEdge<FLOWTYPE, COSTTYPE> &e : list[i]) e.reset();\n        }\n\
    \    }\n    \n    // add_edge\n    void add_edge(int from, int to, FLOWTYPE cap,\
    \ COSTTYPE cost) {\n        pos.emplace_back(from, (int)list[from].size());\n\
    \        list[from].push_back(FlowCostEdge<FLOWTYPE, COSTTYPE>\n             \
    \                ((int)list[to].size(), from, to, cap, cost));\n        list[to].push_back(FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE>\n                           ((int)list[from].size() - 1, to, from,\
    \ 0, -cost));\n    }\n\n    // debug\n    friend ostream& operator << (ostream&\
    \ s, const FlowCostGraph &G) {\n        const auto &edges = G.get_edges();\n \
    \       for (const auto &e : edges) s << e << endl;\n        return s;\n    }\n\
    };\n\n// min-cost max-flow (<= limit_flow), slope ver.\ntemplate<class FLOWTYPE,\
    \ class COSTTYPE> vector<pair<FLOWTYPE, COSTTYPE>>\nMinCostFlowSlope(FlowCostGraph<FLOWTYPE,\
    \ COSTTYPE> &G, int S, int T, FLOWTYPE limit_flow)\n{\n    // result values\n\
    \    FLOWTYPE cur_flow = 0;\n    COSTTYPE cur_cost = 0, pre_cost = -1;\n    vector<pair<FLOWTYPE,\
    \ COSTTYPE>> res;\n    res.emplace_back(cur_flow, cur_cost);\n    \n    // intermediate\
    \ values\n    vector<COSTTYPE> dual((int)G.size(), 0), dist((int)G.size());\n\
    \    vector<int> prevv((int)G.size(), -1), preve((int)G.size(), -1);\n    \n \
    \   // dual\n    auto dual_step = [&]() -> bool {\n        priority_queue<pair<COSTTYPE,int>,\
    \ vector<pair<COSTTYPE,int>>, greater<pair<COSTTYPE,int>>> que;\n        que.push({0,\
    \ S});\n        dist.assign((int)G.size(), numeric_limits<COSTTYPE>::max());\n\
    \        dist[S] = 0;\n        while (!que.empty()) {\n            auto [cur_cost,\
    \ v] = que.top();\n            que.pop();\n            if (dist[v] < cur_cost)\
    \ continue;\n            for (int i = 0; i < (int)G[v].size(); ++i) {\n      \
    \          const auto &e = G[v][i];\n                COSTTYPE new_cost = e.cost\
    \ + dual[v] - dual[e.to];\n                if (e.cap > 0 && dist[e.to] > dist[v]\
    \ + new_cost) {\n                    dist[e.to] = dist[v] + new_cost;\n      \
    \              prevv[e.to] = v;\n                    preve[e.to] = i;\n      \
    \              que.push({dist[e.to], e.to});\n                }\n            }\n\
    \        }\n        if (dist[T] == numeric_limits<COSTTYPE>::max()) return false;\n\
    \        for (int v = 0; v < (int)G.size(); ++v) {\n            if (dist[T] ==\
    \ numeric_limits<COSTTYPE>::max()) continue;\n            dual[v] -= dist[T] -\
    \ dist[v];\n        }\n        return true;\n    };\n    \n    // primal\n   \
    \ auto primal_step = [&]() -> void {\n        FLOWTYPE flow = limit_flow - cur_flow;\n\
    \        COSTTYPE cost = -dual[S];\n        for (int v = T; v != S; v = prevv[v])\
    \ {\n            flow = min(flow, G[prevv[v]][preve[v]].cap);\n        }\n   \
    \     for (int v = T; v != S; v = prevv[v]) {\n            FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE> &e = G[prevv[v]][preve[v]];\n            FlowCostEdge<FLOWTYPE, COSTTYPE>\
    \ &re = G.get_rev_edge(e);\n            e.cap -= flow, e.flow += flow;\n     \
    \       re.cap += flow, re.flow -= flow;\n        }\n        cur_flow += flow;\n\
    \        cur_cost += flow * cost;\n        if (pre_cost == cost) res.pop_back();\n\
    \        res.emplace_back(cur_flow, cur_cost);\n        pre_cost = cur_cost;\n\
    \    };\n    \n    // primal-dual\n    while (cur_flow < limit_flow) {\n     \
    \   if (!dual_step()) break;\n        primal_step();\n    }\n    return res;\n\
    }\n\n// min-cost max-flow, slope ver.\ntemplate<class FLOWTYPE, class COSTTYPE>\
    \ vector<pair<FLOWTYPE, COSTTYPE>>\nMinCostFlowSlope(FlowCostGraph<FLOWTYPE, COSTTYPE>\
    \ &G, int S, int T)\n{\n    return MinCostFlowSlope(G, S, T, numeric_limits<FLOWTYPE>::max());\n\
    }\n\n// min-cost max-flow (<= limit_flow)\ntemplate<class FLOWTYPE, class COSTTYPE>\
    \ pair<FLOWTYPE, COSTTYPE>\nMinCostFlow(FlowCostGraph<FLOWTYPE, COSTTYPE> &G,\
    \ int S, int T, FLOWTYPE limit_flow)\n{\n    return MinCostFlowSlope(G, S, T,\
    \ limit_flow).back();\n}\n\n// min-cost max-flow (<= limit_flow)\ntemplate<class\
    \ FLOWTYPE, class COSTTYPE> pair<FLOWTYPE, COSTTYPE>\nMinCostFlow(FlowCostGraph<FLOWTYPE,\
    \ COSTTYPE> &G, int S, int T)\n{\n    return MinCostFlow(G, S, T, numeric_limits<FLOWTYPE>::max());\n\
    }\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\n// edge class (for\
    \ network-flow)\ntemplate<class FLOWTYPE, class COSTTYPE> struct FlowCostEdge\
    \ {\n    // core members\n    int rev, from, to;\n    FLOWTYPE cap, icap, flow;\n\
    \    COSTTYPE cost;\n    \n    // constructor\n    FlowCostEdge(int rev, int from,\
    \ int to, FLOWTYPE cap, COSTTYPE cost)\n    : rev(rev), from(from), to(to), cap(cap),\
    \ icap(cap), flow(0), cost(cost) {}\n    void reset() { cap = icap, flow = 0;\
    \ }\n    \n    // debug\n    friend ostream& operator << (ostream& s, const FlowCostEdge&\
    \ e) {\n        return s << e.from << \" -> \" << e.to\n        << \" (\" << e.flow\
    \ << \"/\" << e.icap << \", \" << e.cost << \")\";\n    }\n};\n\n// graph class\
    \ (for network-flow)\ntemplate<class FLOWTYPE, class COSTTYPE> struct FlowCostGraph\
    \ {\n    // core members\n    vector<vector<FlowCostEdge<FLOWTYPE, COSTTYPE>>>\
    \ list;\n    vector<pair<int,int>> pos;  // pos[i] := {vertex, order of list[vertex]}\
    \ of i-th edge\n    \n    // constructor\n    FlowCostGraph(int n = 0) : list(n)\
    \ { }\n    void init(int n = 0) {\n        list.assign(n, FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE>());\n        pos.clear();\n    }\n    \n    // getter\n    vector<FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE>> &operator [] (int i) {\n        return list[i];\n    }\n    const\
    \ vector<FlowCostEdge<FLOWTYPE, COSTTYPE>> &operator [] (int i) const {\n    \
    \    return list[i];\n    }\n    size_t size() const {\n        return list.size();\n\
    \    }\n    FlowCostEdge<FLOWTYPE, COSTTYPE> &get_rev_edge\n    (const FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE> &e) {\n        if (e.from != e.to) return list[e.to][e.rev];\n   \
    \     else return list[e.to][e.rev + 1];\n    }\n    FlowCostEdge<FLOWTYPE, COSTTYPE>\
    \ &get_edge(int i) {\n        return list[pos[i].first][pos[i].second];\n    }\n\
    \    const FlowCostEdge<FLOWTYPE, COSTTYPE> &get_edge(int i) const {\n       \
    \ return list[pos[i].first][pos[i].second];\n    }\n    vector<FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE>> get_edges() const {\n        vector<FlowCostEdge<FLOWTYPE, COSTTYPE>>\
    \ edges;\n        for (int i = 0; i < (int)pos.size(); ++i) {\n            edges.push_back(get_edge(i));\n\
    \        }\n        return edges;\n    }\n    \n    // change edges\n    void\
    \ reset() {\n        for (int i = 0; i < (int)list.size(); ++i) {\n          \
    \  for (FlowCostEdge<FLOWTYPE, COSTTYPE> &e : list[i]) e.reset();\n        }\n\
    \    }\n    \n    // add_edge\n    void add_edge(int from, int to, FLOWTYPE cap,\
    \ COSTTYPE cost) {\n        pos.emplace_back(from, (int)list[from].size());\n\
    \        list[from].push_back(FlowCostEdge<FLOWTYPE, COSTTYPE>\n             \
    \                ((int)list[to].size(), from, to, cap, cost));\n        list[to].push_back(FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE>\n                           ((int)list[from].size() - 1, to, from,\
    \ 0, -cost));\n    }\n\n    // debug\n    friend ostream& operator << (ostream&\
    \ s, const FlowCostGraph &G) {\n        const auto &edges = G.get_edges();\n \
    \       for (const auto &e : edges) s << e << endl;\n        return s;\n    }\n\
    };\n\n// min-cost max-flow (<= limit_flow), slope ver.\ntemplate<class FLOWTYPE,\
    \ class COSTTYPE> vector<pair<FLOWTYPE, COSTTYPE>>\nMinCostFlowSlope(FlowCostGraph<FLOWTYPE,\
    \ COSTTYPE> &G, int S, int T, FLOWTYPE limit_flow)\n{\n    // result values\n\
    \    FLOWTYPE cur_flow = 0;\n    COSTTYPE cur_cost = 0, pre_cost = -1;\n    vector<pair<FLOWTYPE,\
    \ COSTTYPE>> res;\n    res.emplace_back(cur_flow, cur_cost);\n    \n    // intermediate\
    \ values\n    vector<COSTTYPE> dual((int)G.size(), 0), dist((int)G.size());\n\
    \    vector<int> prevv((int)G.size(), -1), preve((int)G.size(), -1);\n    \n \
    \   // dual\n    auto dual_step = [&]() -> bool {\n        priority_queue<pair<COSTTYPE,int>,\
    \ vector<pair<COSTTYPE,int>>, greater<pair<COSTTYPE,int>>> que;\n        que.push({0,\
    \ S});\n        dist.assign((int)G.size(), numeric_limits<COSTTYPE>::max());\n\
    \        dist[S] = 0;\n        while (!que.empty()) {\n            auto [cur_cost,\
    \ v] = que.top();\n            que.pop();\n            if (dist[v] < cur_cost)\
    \ continue;\n            for (int i = 0; i < (int)G[v].size(); ++i) {\n      \
    \          const auto &e = G[v][i];\n                COSTTYPE new_cost = e.cost\
    \ + dual[v] - dual[e.to];\n                if (e.cap > 0 && dist[e.to] > dist[v]\
    \ + new_cost) {\n                    dist[e.to] = dist[v] + new_cost;\n      \
    \              prevv[e.to] = v;\n                    preve[e.to] = i;\n      \
    \              que.push({dist[e.to], e.to});\n                }\n            }\n\
    \        }\n        if (dist[T] == numeric_limits<COSTTYPE>::max()) return false;\n\
    \        for (int v = 0; v < (int)G.size(); ++v) {\n            if (dist[T] ==\
    \ numeric_limits<COSTTYPE>::max()) continue;\n            dual[v] -= dist[T] -\
    \ dist[v];\n        }\n        return true;\n    };\n    \n    // primal\n   \
    \ auto primal_step = [&]() -> void {\n        FLOWTYPE flow = limit_flow - cur_flow;\n\
    \        COSTTYPE cost = -dual[S];\n        for (int v = T; v != S; v = prevv[v])\
    \ {\n            flow = min(flow, G[prevv[v]][preve[v]].cap);\n        }\n   \
    \     for (int v = T; v != S; v = prevv[v]) {\n            FlowCostEdge<FLOWTYPE,\
    \ COSTTYPE> &e = G[prevv[v]][preve[v]];\n            FlowCostEdge<FLOWTYPE, COSTTYPE>\
    \ &re = G.get_rev_edge(e);\n            e.cap -= flow, e.flow += flow;\n     \
    \       re.cap += flow, re.flow -= flow;\n        }\n        cur_flow += flow;\n\
    \        cur_cost += flow * cost;\n        if (pre_cost == cost) res.pop_back();\n\
    \        res.emplace_back(cur_flow, cur_cost);\n        pre_cost = cur_cost;\n\
    \    };\n    \n    // primal-dual\n    while (cur_flow < limit_flow) {\n     \
    \   if (!dual_step()) break;\n        primal_step();\n    }\n    return res;\n\
    }\n\n// min-cost max-flow, slope ver.\ntemplate<class FLOWTYPE, class COSTTYPE>\
    \ vector<pair<FLOWTYPE, COSTTYPE>>\nMinCostFlowSlope(FlowCostGraph<FLOWTYPE, COSTTYPE>\
    \ &G, int S, int T)\n{\n    return MinCostFlowSlope(G, S, T, numeric_limits<FLOWTYPE>::max());\n\
    }\n\n// min-cost max-flow (<= limit_flow)\ntemplate<class FLOWTYPE, class COSTTYPE>\
    \ pair<FLOWTYPE, COSTTYPE>\nMinCostFlow(FlowCostGraph<FLOWTYPE, COSTTYPE> &G,\
    \ int S, int T, FLOWTYPE limit_flow)\n{\n    return MinCostFlowSlope(G, S, T,\
    \ limit_flow).back();\n}\n\n// min-cost max-flow (<= limit_flow)\ntemplate<class\
    \ FLOWTYPE, class COSTTYPE> pair<FLOWTYPE, COSTTYPE>\nMinCostFlow(FlowCostGraph<FLOWTYPE,\
    \ COSTTYPE> &G, int S, int T)\n{\n    return MinCostFlow(G, S, T, numeric_limits<FLOWTYPE>::max());\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/flow/primal-dual.hpp
  requiredBy: []
  timestamp: '2024-10-01 17:09:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/flow/primal-dual.hpp
layout: document
redirect_from:
- /library/graph/flow/primal-dual.hpp
- /library/graph/flow/primal-dual.hpp.html
title: graph/flow/primal-dual.hpp
---
