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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_6_A.test.cpp
    title: test/AOJ/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_7_A.test.cpp
    title: test/AOJ/GRL_7_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"graph/flow/ford-fullkerson.hpp\"\n\ntemplate <class FLOWTYPE>\n\
    struct Edge {\n    int rev, from, to;\n    FLOWTYPE cap, icap;\n    Edge(int r,\
    \ int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c) {}\n   \
    \ friend ostream& operator<<(ostream& s, Edge E) {\n        if (E.cap > 0)\n \
    \           return s << E.from << \"->\" << E.to << '(' << E.cap << ')' << \"\
    \ \";\n        else\n            return s;\n    }\n};\n\ntemplate <class FLOWTYPE>\n\
    struct Graph {\n    vector<vector<Edge<FLOWTYPE> > > list;\n\n    Graph(int n\
    \ = 0) : list(n) {}\n    void init(int n = 0) {\n        list.clear();\n     \
    \   list.resize(n);\n    }\n    void reset() {\n        for (int i = 0; i < (int)list.size();\
    \ ++i)\n            for (int j = 0; j < list[i].size(); ++j) list[i][j].cap =\
    \ list[i][j].icap;\n    }\n    inline vector<Edge<FLOWTYPE> >& operator[](int\
    \ i) { return list[i]; }\n    inline const size_t size() const { return list.size();\
    \ }\n\n    inline Edge<FLOWTYPE>& redge(Edge<FLOWTYPE> e) {\n        if (e.from\
    \ != e.to)\n            return list[e.to][e.rev];\n        else\n            return\
    \ list[e.to][e.rev + 1];\n    }\n\n    void addedge(int from, int to, FLOWTYPE\
    \ cap) {\n        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from,\
    \ to, cap));\n        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size()\
    \ - 1, to, from, 0));\n    }\n\n    void add_undirected_edge(int from, int to,\
    \ FLOWTYPE cap) {\n        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(),\
    \ from, to, cap));\n        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size()\
    \ - 1, to, from, cap));\n    }\n\n    friend ostream& operator<<(ostream& s, Graph\
    \ G) {\n        s << endl;\n        for (int i = 0; i < G.size(); i++) {\n   \
    \         s << i << \": \";\n            for (Edge<FLOWTYPE> j : G.list[i]) {\n\
    \                s << j;\n            }\n            s << endl;\n        }\n \
    \       return s;\n    }\n};\n\ntemplate <class FLOWTYPE>\nstruct FordFulkerson\
    \ {\n    const FLOWTYPE INF = 1 << 30;\n    vector<int> used;\n\n    FordFulkerson()\
    \ {}\n    FLOWTYPE fodfs(Graph<FLOWTYPE>& G, int v, int t, FLOWTYPE f) {\n   \
    \     if (v == t) return f;\n        used[v] = true;\n        for (auto& e : G[v])\
    \ {\n            if (!used[e.to] && e.cap > 0) {\n                int d = fodfs(G,\
    \ e.to, t, min(f, e.cap));\n                if (d > 0) {\n                   \
    \ e.cap -= d;\n                    G.redge(e).cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    \    FLOWTYPE solve(Graph<FLOWTYPE>& G, int s, int t) {\n        FLOWTYPE res\
    \ = 0;\n        while (true) {\n            used.assign((int)G.size(), 0);\n \
    \           int flow = fodfs(G, s, t, INF);\n            if (flow == 0)\n    \
    \            return res;\n            else\n                res += flow;\n   \
    \     }\n        return 0;\n    }\n};\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\ntemplate <class\
    \ FLOWTYPE>\nstruct Edge {\n    int rev, from, to;\n    FLOWTYPE cap, icap;\n\
    \    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c)\
    \ {}\n    friend ostream& operator<<(ostream& s, Edge E) {\n        if (E.cap\
    \ > 0)\n            return s << E.from << \"->\" << E.to << '(' << E.cap << ')'\
    \ << \" \";\n        else\n            return s;\n    }\n};\n\ntemplate <class\
    \ FLOWTYPE>\nstruct Graph {\n    vector<vector<Edge<FLOWTYPE> > > list;\n\n  \
    \  Graph(int n = 0) : list(n) {}\n    void init(int n = 0) {\n        list.clear();\n\
    \        list.resize(n);\n    }\n    void reset() {\n        for (int i = 0; i\
    \ < (int)list.size(); ++i)\n            for (int j = 0; j < list[i].size(); ++j)\
    \ list[i][j].cap = list[i][j].icap;\n    }\n    inline vector<Edge<FLOWTYPE> >&\
    \ operator[](int i) { return list[i]; }\n    inline const size_t size() const\
    \ { return list.size(); }\n\n    inline Edge<FLOWTYPE>& redge(Edge<FLOWTYPE> e)\
    \ {\n        if (e.from != e.to)\n            return list[e.to][e.rev];\n    \
    \    else\n            return list[e.to][e.rev + 1];\n    }\n\n    void addedge(int\
    \ from, int to, FLOWTYPE cap) {\n        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(),\
    \ from, to, cap));\n        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size()\
    \ - 1, to, from, 0));\n    }\n\n    void add_undirected_edge(int from, int to,\
    \ FLOWTYPE cap) {\n        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(),\
    \ from, to, cap));\n        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size()\
    \ - 1, to, from, cap));\n    }\n\n    friend ostream& operator<<(ostream& s, Graph\
    \ G) {\n        s << endl;\n        for (int i = 0; i < G.size(); i++) {\n   \
    \         s << i << \": \";\n            for (Edge<FLOWTYPE> j : G.list[i]) {\n\
    \                s << j;\n            }\n            s << endl;\n        }\n \
    \       return s;\n    }\n};\n\ntemplate <class FLOWTYPE>\nstruct FordFulkerson\
    \ {\n    const FLOWTYPE INF = 1 << 30;\n    vector<int> used;\n\n    FordFulkerson()\
    \ {}\n    FLOWTYPE fodfs(Graph<FLOWTYPE>& G, int v, int t, FLOWTYPE f) {\n   \
    \     if (v == t) return f;\n        used[v] = true;\n        for (auto& e : G[v])\
    \ {\n            if (!used[e.to] && e.cap > 0) {\n                int d = fodfs(G,\
    \ e.to, t, min(f, e.cap));\n                if (d > 0) {\n                   \
    \ e.cap -= d;\n                    G.redge(e).cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    \    FLOWTYPE solve(Graph<FLOWTYPE>& G, int s, int t) {\n        FLOWTYPE res\
    \ = 0;\n        while (true) {\n            used.assign((int)G.size(), 0);\n \
    \           int flow = fodfs(G, s, t, INF);\n            if (flow == 0)\n    \
    \            return res;\n            else\n                res += flow;\n   \
    \     }\n        return 0;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/flow/ford-fullkerson.hpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_6_A.test.cpp
  - test/AOJ/GRL_7_A.test.cpp
documentation_of: graph/flow/ford-fullkerson.hpp
layout: document
title: "Ford Fullkerson (\u6700\u5927\u6D41)"
---
