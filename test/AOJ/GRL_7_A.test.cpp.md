---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/flow/ford-fullkerson.hpp
    title: "Ford Fullkerson (\u6700\u5927\u6D41)"
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/AOJ/GRL_7_A.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\n#line 2 \"\
    template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define overload3(_1, _2, _3, name, ...) name\n#define all1(v) std::begin(v),\
    \ std::end(v)\n#define all2(v, a) std::begin(v), std::begin(v) + a\n#define all3(v,\
    \ a, b) std::begin(v) + a, std::begin(v) + b\n#define all(...) overload3(__VA_ARGS__,\
    \ all3, all2, all1)(__VA_ARGS__)\n#define rall1(v) std::rbegin(v), std::rend(v)\n\
    #define rall2(v, a) std::rbegin(v), std::rbegin(v) + a\n#define rall3(v, a, b)\
    \ std::rbegin(v) + a, std::rbegin(v) + b\n#define rall(...) overload3(__VA_ARGS__,\
    \ rall3, rall2, rall1)(__VA_ARGS__)\n#define elif else if\n#define updiv(N, X)\
    \ (((N) + (X) - 1) / (X))\n#define sigma(a, b) (((a) + (b)) * ((b) - (a) + 1)\
    \ / 2)\n#define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ STR(...)        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ CHR(...)      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...)\
    \        \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
    \     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
    #define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
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
    #line 3 \"graph/flow/ford-fullkerson.hpp\"\n\n// edge class (for network-flow)\n\
    template<class FLOWTYPE> struct FlowEdge {\n    // core members\n    int rev,\
    \ from, to;\n    FLOWTYPE cap, icap, flow;\n    \n    // constructor\n    FlowEdge(int\
    \ r, int f, int t, FLOWTYPE c)\n    : rev(r), from(f), to(t), cap(c), icap(c),\
    \ flow(0) {}\n    void reset() { cap = icap, flow = 0; }\n    \n    // debug\n\
    \    friend ostream& operator << (ostream& s, const FlowEdge& E) {\n        return\
    \ s << E.from << \"->\" << E.to << '(' << E.flow << '/' << E.icap << ')';\n  \
    \  }\n};\n\n// graph class (for network-flow)\ntemplate<class FLOWTYPE> struct\
    \ FlowGraph {\n    // core members\n    vector<vector<FlowEdge<FLOWTYPE>>> list;\n\
    \    vector<pair<int,int>> pos;  // pos[i] := {vertex, order of list[vertex]}\
    \ of i-th edge\n    \n    // constructor\n    FlowGraph(int n = 0) : list(n) {\
    \ }\n    void init(int n = 0) {\n        list.assign(n, FlowEdge<FLOWTYPE>());\n\
    \        pos.clear();\n    }\n    \n    // getter\n    vector<FlowEdge<FLOWTYPE>>\
    \ &operator [] (int i) {\n        return list[i];\n    }\n    const vector<FlowEdge<FLOWTYPE>>\
    \ &operator [] (int i) const {\n        return list[i];\n    }\n    size_t size()\
    \ const {\n        return list.size();\n    }\n    FlowEdge<FLOWTYPE> &get_rev_edge(const\
    \ FlowEdge<FLOWTYPE> &e) {\n        if (e.from != e.to) return list[e.to][e.rev];\n\
    \        else return list[e.to][e.rev + 1];\n    }\n    FlowEdge<FLOWTYPE> &get_edge(int\
    \ i) {\n        return list[pos[i].first][pos[i].second];\n    }\n    const FlowEdge<FLOWTYPE>\
    \ &get_edge(int i) const {\n        return list[pos[i].first][pos[i].second];\n\
    \    }\n    vector<FlowEdge<FLOWTYPE>> get_edges() const {\n        vector<FlowEdge<FLOWTYPE>>\
    \ edges;\n        for (int i = 0; i < (int)pos.size(); ++i) {\n            edges.push_back(get_edge(i));\n\
    \        }\n        return edges;\n    }\n    \n    // change edges\n    void\
    \ reset() {\n        for (int i = 0; i < (int)list.size(); ++i) {\n          \
    \  for (FlowEdge<FLOWTYPE> &e : list[i]) e.reset();\n        }\n    }\n    void\
    \ change_edge(FlowEdge<FLOWTYPE> &e, FLOWTYPE new_cap, FLOWTYPE new_flow) {\n\
    \        FlowEdge<FLOWTYPE> &re = get_rev_edge(e);\n        e.cap = new_cap -\
    \ new_flow, e.icap = new_cap, e.flow = new_flow;\n        re.cap = new_flow;\n\
    \    }\n    \n    // add_edge\n    void add_edge(int from, int to, FLOWTYPE cap)\
    \ {\n        pos.emplace_back(from, (int)list[from].size());\n        list[from].push_back(FlowEdge<FLOWTYPE>((int)list[to].size(),\
    \ from, to, cap));\n        list[to].push_back(FlowEdge<FLOWTYPE>((int)list[from].size()\
    \ - 1, to, from, 0));\n    }\n\n    // debug\n    friend ostream& operator <<\
    \ (ostream& s, const FlowGraph &G) {\n        const auto &edges = G.get_edges();\n\
    \        for (const auto &e : edges) s << e << endl;\n        return s;\n    }\n\
    };\n\n// Ford-Fulkerson\ntemplate<class FLOWTYPE> FLOWTYPE FordFulkerson\n (FlowGraph<FLOWTYPE>\
    \ &G, int s, int t, FLOWTYPE limit_flow)\n{\n    FLOWTYPE current_flow = 0;\n\
    \    \n    // DFS\n    vector<bool> used((int)G.size(), false);\n    auto dfs\
    \ = [&](auto self, int v, FLOWTYPE up_flow) {\n        if (v == t) return up_flow;\n\
    \        FLOWTYPE res_flow = 0;\n        used[v] = true;\n        for (FlowEdge<FLOWTYPE>\
    \ &e : G[v]) {\n            if (used[e.to] || e.cap == 0) continue;\n        \
    \    FLOWTYPE flow = self(self, e.to, min(up_flow - res_flow, e.cap));\n     \
    \       FlowEdge<FLOWTYPE> &re = G.get_rev_edge(e);\n            if (flow <= 0)\
    \ continue;\n            res_flow += flow;\n            e.cap -= flow, e.flow\
    \ += flow;\n            re.cap += flow, re.flow -= flow;\n            if (res_flow\
    \ == up_flow) break;\n        }\n        return res_flow;\n    };\n    \n    //\
    \ flow\n    while (current_flow < limit_flow) {\n        used.assign((int)G.size(),\
    \ false);\n        FLOWTYPE flow = dfs(dfs, s, limit_flow - current_flow);\n \
    \       if (!flow) break;\n        current_flow += flow;\n    }\n    return current_flow;\n\
    };\n\ntemplate<class FLOWTYPE> FLOWTYPE FordFulkerson(FlowGraph<FLOWTYPE> &G,\
    \ int s, int t) {\n    return FordFulkerson(G, s, t, numeric_limits<FLOWTYPE>::max());\n\
    }\n#line 5 \"test/AOJ/GRL_7_A.test.cpp\"\n\nint main() {\n    INT(X, Y, E);\n\
    \    Graph<int> G(X + Y + 2);\n    for (int i = 0; i < X; i++) {\n        G.addedge(0,\
    \ i + 1, 1);\n    }\n    for (int i = 0; i < E; i++) {\n        INT(x, y);\n \
    \       x++;\n        y += X + 1;\n        G.addedge(x, y, 1);\n    }\n    for\
    \ (int i = 0; i < Y; i++) {\n        G.add_undirected_edge(i + X + 1, X + Y +\
    \ 1, 1);\n    }\n    FordFulkerson<int> ff;\n    cout << ff.solve(G, 0, X + Y\
    \ + 1) << endl;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n#include \"graph/flow/ford-fullkerson.hpp\"\n#include \"template/template.hpp\"\
    \n\nint main() {\n    INT(X, Y, E);\n    Graph<int> G(X + Y + 2);\n    for (int\
    \ i = 0; i < X; i++) {\n        G.addedge(0, i + 1, 1);\n    }\n    for (int i\
    \ = 0; i < E; i++) {\n        INT(x, y);\n        x++;\n        y += X + 1;\n\
    \        G.addedge(x, y, 1);\n    }\n    for (int i = 0; i < Y; i++) {\n     \
    \   G.add_undirected_edge(i + X + 1, X + Y + 1, 1);\n    }\n    FordFulkerson<int>\
    \ ff;\n    cout << ff.solve(G, 0, X + Y + 1) << endl;\n}"
  dependsOn:
  - graph/flow/ford-fullkerson.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_7_A.test.cpp
  requiredBy: []
  timestamp: '2024-10-01 17:09:04+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_7_A.test.cpp
- /verify/test/AOJ/GRL_7_A.test.cpp.html
title: test/AOJ/GRL_7_A.test.cpp
---
