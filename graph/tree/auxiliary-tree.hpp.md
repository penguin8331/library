---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/tree/lca.hpp
    title: Lowest Common Ancestor
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"graph/tree/lca.hpp\"\n\nstruct LCA {\n    vector<vector<int>>\
    \ parent;\n    vector<int> depth;\n    LCA() {}\n    explicit LCA(const vector<vector<int>>&\
    \ G, int r = 0) { init(G, r); }\n    void init(const vector<vector<int>>& G, int\
    \ r = 0) {\n        int V = (int)G.size();\n        int h = 1;\n        while\
    \ ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V, -1));\n       \
    \ depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for (int i = 0; i +\
    \ 1 < (int)parent.size(); ++i)\n            for (int v = 0; v < V; ++v)\n    \
    \            if (parent[i][v] != -1)\n                    parent[i + 1][v] = parent[i][parent[i][v]];\n\
    \    }\n    void dfs(const vector<vector<int>>& G, int v, int p, int d) {\n  \
    \      parent[0][v] = p;\n        depth[v] = d;\n        for (auto e : G[v])\n\
    \            if (e != p) dfs(G, e, v, d + 1);\n    }\n    int after(int u, int\
    \ k) {\n        for (int i = 0; i < (int)parent.size(); i++) {\n            if\
    \ (k & (1 << i)) {\n                u = parent[i][u];\n            }\n       \
    \ }\n        return u;\n    }\n    int get(int u, int v) {\n        if (depth[u]\
    \ > depth[v]) swap(u, v);\n        v = after(v, depth[v] - depth[u]);\n      \
    \  if (u == v) return u;\n        for (int i = (int)parent.size() - 1; i >= 0;\
    \ --i) {\n            if (parent[i][u] != parent[i][v]) {\n                u =\
    \ parent[i][u];\n                v = parent[i][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n    int dist(int u, int v) {\n        return\
    \ depth[u] + depth[v] - 2 * depth[get(u, v)];\n    }\n    bool is_on_path(int\
    \ u, int v, int a) {\n        return dist(u, a) + dist(a, v) == dist(u, v);\n\
    \    }\n};\n#line 4 \"graph/tree/auxiliary-tree.hpp\"\n\nstruct AuxiliaryTree\
    \ : LCA {\n    using super = LCA;\n\n    vector<int> idx;\n    vector<vector<int>>\
    \ T;\n    explicit AuxiliaryTree(const vector<vector<int>> &G, int r = 0)\n  \
    \      : super(G, r) {\n        build(G, r);\n    }\n\n    void dfs(const vector<vector<int>>\
    \ &G, int v, int p, int &pos) {\n        idx[v] = pos++;\n        for (int u :\
    \ G[v])\n            if (u != p) dfs(G, u, v, pos);\n    }\n\n    void build(const\
    \ vector<vector<int>> &G, int r = 0) {\n        int V = (int)G.size();\n     \
    \   idx.assign(V, 0);\n        T.assign(V, vector<int>());\n        int pos =\
    \ 0;\n        dfs(G, r, -1, pos);\n    }\n\n    void add_aux_edge(int u, int v)\
    \ {\n        T[u].emplace_back(v);\n        T[v].emplace_back(u);\n    }\n\n \
    \   using super::get, super::depth;\n    void query(vector<int> &vs) {\n     \
    \   assert(!vs.empty());\n        sort(vs.begin(), vs.end(),\n             [&](int\
    \ a, int b) { return idx[a] < idx[b]; });\n        vs.erase(unique(vs.begin(),\
    \ vs.end()), vs.end());\n\n        int k = vs.size();\n        stack<int> st;\n\
    \        st.emplace(vs[0]);\n        for (int i = 0; i + 1 < k; i++) {\n     \
    \       int w = get(vs[i], vs[i + 1]);\n            if (w != vs[i]) {\n      \
    \          int l = st.top();\n                st.pop();\n                while\
    \ (!st.empty() and depth[w] < depth[st.top()]) {\n                    add_aux_edge(st.top(),\
    \ l);\n                    l = st.top();\n                    st.pop();\n    \
    \            }\n                if (st.empty() or st.top() != w) {\n         \
    \           st.emplace(w);\n                    vs.emplace_back(w);\n        \
    \        }\n                add_aux_edge(w, l);\n            }\n            st.emplace(vs[i\
    \ + 1]);\n        }\n\n        while (st.size() > 1) {\n            int c = st.top();\n\
    \            st.pop();\n            add_aux_edge(st.top(), c);\n        }\n  \
    \  }\n\n    void clear(const vector<int> &ws) {\n        for (int w : ws) T[w].clear();\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n#include \"lca.hpp\"\
    \n\nstruct AuxiliaryTree : LCA {\n    using super = LCA;\n\n    vector<int> idx;\n\
    \    vector<vector<int>> T;\n    explicit AuxiliaryTree(const vector<vector<int>>\
    \ &G, int r = 0)\n        : super(G, r) {\n        build(G, r);\n    }\n\n   \
    \ void dfs(const vector<vector<int>> &G, int v, int p, int &pos) {\n        idx[v]\
    \ = pos++;\n        for (int u : G[v])\n            if (u != p) dfs(G, u, v, pos);\n\
    \    }\n\n    void build(const vector<vector<int>> &G, int r = 0) {\n        int\
    \ V = (int)G.size();\n        idx.assign(V, 0);\n        T.assign(V, vector<int>());\n\
    \        int pos = 0;\n        dfs(G, r, -1, pos);\n    }\n\n    void add_aux_edge(int\
    \ u, int v) {\n        T[u].emplace_back(v);\n        T[v].emplace_back(u);\n\
    \    }\n\n    using super::get, super::depth;\n    void query(vector<int> &vs)\
    \ {\n        assert(!vs.empty());\n        sort(vs.begin(), vs.end(),\n      \
    \       [&](int a, int b) { return idx[a] < idx[b]; });\n        vs.erase(unique(vs.begin(),\
    \ vs.end()), vs.end());\n\n        int k = vs.size();\n        stack<int> st;\n\
    \        st.emplace(vs[0]);\n        for (int i = 0; i + 1 < k; i++) {\n     \
    \       int w = get(vs[i], vs[i + 1]);\n            if (w != vs[i]) {\n      \
    \          int l = st.top();\n                st.pop();\n                while\
    \ (!st.empty() and depth[w] < depth[st.top()]) {\n                    add_aux_edge(st.top(),\
    \ l);\n                    l = st.top();\n                    st.pop();\n    \
    \            }\n                if (st.empty() or st.top() != w) {\n         \
    \           st.emplace(w);\n                    vs.emplace_back(w);\n        \
    \        }\n                add_aux_edge(w, l);\n            }\n            st.emplace(vs[i\
    \ + 1]);\n        }\n\n        while (st.size() > 1) {\n            int c = st.top();\n\
    \            st.pop();\n            add_aux_edge(st.top(), c);\n        }\n  \
    \  }\n\n    void clear(const vector<int> &ws) {\n        for (int w : ws) T[w].clear();\n\
    \    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/tree/lca.hpp
  isVerificationFile: false
  path: graph/tree/auxiliary-tree.hpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/auxiliary-tree.hpp
layout: document
title: Auxiliary Tree
---
