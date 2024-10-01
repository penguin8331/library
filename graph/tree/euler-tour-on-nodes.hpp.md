---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
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
    path: test/AOJ/2667.test.cpp
    title: test/AOJ/2667.test.cpp
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <dump.hpp>\n#else\n#define\
    \ debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n\
    #line 3 \"data-structure/lazy-segment-tree.hpp\"\n\ntemplate <class Monoid, class\
    \ Action>\nstruct Lazy_SegTree {\n    using FuncMonoid = function<Monoid(Monoid,\
    \ Monoid)>;\n    using FuncAction = function<void(Monoid&, Action)>;\n    using\
    \ FuncComposition = function<void(Action&, Action)>;\n    FuncMonoid FM;\n   \
    \ FuncAction FA;\n    FuncComposition FC;\n    Monoid IDENTITY_MONOID;\n    Action\
    \ IDENTITY_LAZY;\n    int N, SIZE, HEIGHT;\n    vector<Monoid> dat;\n    vector<Action>\
    \ lazy;\n\n    Lazy_SegTree() {}\n    Lazy_SegTree(int n, const FuncMonoid fm,\
    \ const FuncAction fa,\n                 const FuncComposition fc,\n         \
    \        const Monoid& identity_monoid, const Action& identity_lazy)\n       \
    \ : FM(fm), FA(fa), FC(fc), IDENTITY_MONOID(identity_monoid), IDENTITY_LAZY(identity_lazy),\
    \ N(n) {\n        SIZE = 1, HEIGHT = 0;\n        while (SIZE < n) SIZE <<= 1,\
    \ ++HEIGHT;\n        dat.assign(SIZE * 2, IDENTITY_MONOID);\n        lazy.assign(SIZE\
    \ * 2, IDENTITY_LAZY);\n    }\n    void init(int n, const FuncMonoid fm, const\
    \ FuncAction fa,\n              const FuncComposition fc,\n              const\
    \ Monoid& identity_monoid, const Action& identity_lazy) {\n        FM = fm, FA\
    \ = fa, FC = fc;\n        IDENTITY_MONOID = identity_monoid, IDENTITY_LAZY = identity_lazy;\n\
    \        SIZE = 1, HEIGHT = 0;\n        while (SIZE < n) SIZE <<= 1, ++HEIGHT;\n\
    \        dat.assign(SIZE * 2, IDENTITY_MONOID);\n        lazy.assign(SIZE * 2,\
    \ IDENTITY_LAZY);\n    }\n\n    void set(int a, const Monoid& v) { dat[a + SIZE]\
    \ = v; }\n    void build() {\n        for (int k = SIZE - 1; k > 0; --k)\n   \
    \         dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);\n    }\n\n    inline void evaluate(int\
    \ k) {\n        if (lazy[k] == IDENTITY_LAZY) return;\n        if (k < SIZE) FC(lazy[k\
    \ * 2], lazy[k]), FC(lazy[k * 2 + 1], lazy[k]);\n        FA(dat[k], lazy[k]);\n\
    \        lazy[k] = IDENTITY_LAZY;\n    }\n    inline void update(int a, int b,\
    \ const Action& v, int k, int l, int r) {\n        evaluate(k);\n        if (a\
    \ <= l && r <= b)\n            FC(lazy[k], v), evaluate(k);\n        else if (a\
    \ < r && l < b) {\n            update(a, b, v, k * 2, l, (l + r) >> 1);\n    \
    \        update(a, b, v, k * 2 + 1, (l + r) >> 1, r);\n            dat[k] = FM(dat[k\
    \ * 2], dat[k * 2 + 1]);\n        }\n    }\n    inline void update(int a, int\
    \ b, const Action& v) {\n        update(a, b, v, 1, 0, SIZE);\n    }\n\n    inline\
    \ Monoid get(int a, int b, int k, int l, int r) {\n        evaluate(k);\n    \
    \    if (a <= l && r <= b)\n            return dat[k];\n        else if (a < r\
    \ && l < b)\n            return FM(get(a, b, k * 2, l, (l + r) >> 1),\n      \
    \                get(a, b, k * 2 + 1, (l + r) >> 1, r));\n        else\n     \
    \       return IDENTITY_MONOID;\n    }\n    inline Monoid get(int a, int b) {\n\
    \        return get(a, b, 1, 0, SIZE);\n    }\n    inline Monoid operator[](int\
    \ a) {\n        return get(a, a + 1);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, Lazy_SegTree seg) {\n        os << \"[ \";\n        for (int i = 0; i <\
    \ seg.N; i++) {\n            os << seg.get(i, i + 1) << \" \";\n        }\n  \
    \      os << ']';\n        return os;\n    }\n};\n#line 3 \"data-structure/sparse-table.hpp\"\
    \n\ntemplate <class T>\nstruct SparseTable {\n    vector<vector<T>> dat;\n   \
    \ vector<int> height;\n    using Func = function<T(T, T)>;\n    Func F;\n\n  \
    \  SparseTable() {}\n    explicit SparseTable(\n        const vector<T> &vec,\n\
    \        const Func f = [](T a, T b) { return min(a, b); }) {\n        init(vec,\
    \ f);\n    }\n    void init(\n        const vector<T> &vec,\n        const Func\
    \ f = [](T a, T b) { return min(a, b); }) {\n        F = f;\n        int n = (int)vec.size(),\
    \ h = 32 - __builtin_clz(n);\n        dat.assign(h, vector<T>(1 << h));\n    \
    \    height.assign(n + 1, 0);\n        for (int i = 2; i <= n; i++) height[i]\
    \ = height[i >> 1] + 1;\n        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];\n\
    \        for (int i = 1; i < h; ++i)\n            for (int j = 0; j < n; ++j)\n\
    \                dat[i][j] = F(dat[i - 1][j],\n                              dat[i\
    \ - 1][min(j + (1 << (i - 1)), n - 1)]);\n    }\n\n    T get(int a, int b) {\n\
    \        return F(dat[height[b - a]][a],\n                 dat[height[b - a]][b\
    \ - (1 << height[b - a])]);\n    }\n};\n#line 5 \"graph/tree/euler-tour-on-nodes.hpp\"\
    \n\nstruct EulerTour {\n    using Graph = vector<vector<int>>;\n    using Node\
    \ = pair<long long, int>;\n    const function<Node(Node, Node)> fm = [](Node a,\
    \ Node b) { return Node(a.first + b.first, a.second + b.second); };\n    const\
    \ function<void(Node &, long long)> fa = [](Node &a, long long d) { a.first +=\
    \ d * a.second; };\n    const function<void(long long &, long long)> fl = [](long\
    \ long &d, long long e) { d += e; };\n\n    // main results\n    Graph tree;\n\
    \    vector<int> depth;\n    vector<int> node;    // the node-number of i-th element\
    \ of Euler-tour\n    vector<int> vf, ve;  // the index of Euler-tour of node v\n\
    \    vector<int> eid;     // the index of edge e (i*2 + (0: dir to leaf, 1: dir\
    \ to root))\n\n    // sub results\n    SparseTable<pair<int, int>> st;  // depth\
    \ (to find LCA)\n\n    // segtree\n    Lazy_SegTree<Node, long long> seg;\n\n\
    \    // initialization\n    EulerTour(const Graph &tree_) { init(tree_); }\n \
    \   void init(const Graph &tree_) {\n        tree = tree_;\n        int V = (int)tree.size();\n\
    \        depth.resize(V * 2 - 1);\n        node.resize(V * 2 - 1);\n        vf.resize(V);\n\
    \        ve.resize(V);\n        eid.resize((V - 1) * 2);\n        seg.init((V\
    \ - 1) * 2, fm, fa, fl, Node(0, 0), 0);\n        int k = 0;\n        dfs(0, -1,\
    \ 0, k);\n        vector<pair<int, int>> tmp(int(depth.size()));\n        for\
    \ (int i = 0; i < int(depth.size()); i++) {\n            tmp[i] = {depth[i], i};\n\
    \        }\n        st.init(tmp);\n        seg.build();\n    }\n\n    void dfs(int\
    \ v, int par, int dep, int &ord) {\n        node[ord] = v;\n        depth[ord]\
    \ = dep;\n        vf[v] = ve[v] = ord;\n        ++ord;\n        for (auto e :\
    \ tree[v]) {\n            if (e == par) continue;\n            seg.set(ord - 1,\
    \ Node(0, 1));\n            dfs(e, v, dep + 1, ord);\n            node[ord] =\
    \ v;\n            depth[ord] = dep;\n            ve[v] = ord;\n            seg.set(ord\
    \ - 1, Node(0, -1));\n            ++ord;\n        }\n    }\n\n    inline int LCA(int\
    \ u, int v) {\n        int a = vf[u], b = vf[v];\n        if (a > b) swap(a, b);\n\
    \        return node[st.get(a, b + 1).second];\n    }\n\n    inline void update(int\
    \ v, long long x) {\n        seg.update(vf[v], ve[v], x);\n    }\n\n    inline\
    \ long long get(int v) {\n        return seg.get(0, vf[v]).first;\n    }\n\n \
    \   inline long long get(int u, int v) {\n        int lca = LCA(u, v);\n     \
    \   return get(u) + get(v) - get(lca) * 2;\n    }\n};\n"
  code: "#pragma once\n#include \"../../data-structure/lazy-segment-tree.hpp\"\n#include\
    \ \"../../data-structure/sparse-table.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nstruct EulerTour {\n    using Graph = vector<vector<int>>;\n    using Node\
    \ = pair<long long, int>;\n    const function<Node(Node, Node)> fm = [](Node a,\
    \ Node b) { return Node(a.first + b.first, a.second + b.second); };\n    const\
    \ function<void(Node &, long long)> fa = [](Node &a, long long d) { a.first +=\
    \ d * a.second; };\n    const function<void(long long &, long long)> fl = [](long\
    \ long &d, long long e) { d += e; };\n\n    // main results\n    Graph tree;\n\
    \    vector<int> depth;\n    vector<int> node;    // the node-number of i-th element\
    \ of Euler-tour\n    vector<int> vf, ve;  // the index of Euler-tour of node v\n\
    \    vector<int> eid;     // the index of edge e (i*2 + (0: dir to leaf, 1: dir\
    \ to root))\n\n    // sub results\n    SparseTable<pair<int, int>> st;  // depth\
    \ (to find LCA)\n\n    // segtree\n    Lazy_SegTree<Node, long long> seg;\n\n\
    \    // initialization\n    EulerTour(const Graph &tree_) { init(tree_); }\n \
    \   void init(const Graph &tree_) {\n        tree = tree_;\n        int V = (int)tree.size();\n\
    \        depth.resize(V * 2 - 1);\n        node.resize(V * 2 - 1);\n        vf.resize(V);\n\
    \        ve.resize(V);\n        eid.resize((V - 1) * 2);\n        seg.init((V\
    \ - 1) * 2, fm, fa, fl, Node(0, 0), 0);\n        int k = 0;\n        dfs(0, -1,\
    \ 0, k);\n        vector<pair<int, int>> tmp(int(depth.size()));\n        for\
    \ (int i = 0; i < int(depth.size()); i++) {\n            tmp[i] = {depth[i], i};\n\
    \        }\n        st.init(tmp);\n        seg.build();\n    }\n\n    void dfs(int\
    \ v, int par, int dep, int &ord) {\n        node[ord] = v;\n        depth[ord]\
    \ = dep;\n        vf[v] = ve[v] = ord;\n        ++ord;\n        for (auto e :\
    \ tree[v]) {\n            if (e == par) continue;\n            seg.set(ord - 1,\
    \ Node(0, 1));\n            dfs(e, v, dep + 1, ord);\n            node[ord] =\
    \ v;\n            depth[ord] = dep;\n            ve[v] = ord;\n            seg.set(ord\
    \ - 1, Node(0, -1));\n            ++ord;\n        }\n    }\n\n    inline int LCA(int\
    \ u, int v) {\n        int a = vf[u], b = vf[v];\n        if (a > b) swap(a, b);\n\
    \        return node[st.get(a, b + 1).second];\n    }\n\n    inline void update(int\
    \ v, long long x) {\n        seg.update(vf[v], ve[v], x);\n    }\n\n    inline\
    \ long long get(int v) {\n        return seg.get(0, vf[v]).first;\n    }\n\n \
    \   inline long long get(int u, int v) {\n        int lca = LCA(u, v);\n     \
    \   return get(u) + get(v) - get(lca) * 2;\n    }\n};"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: graph/tree/euler-tour-on-nodes.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:50:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2667.test.cpp
documentation_of: graph/tree/euler-tour-on-nodes.hpp
layout: document
redirect_from:
- /library/graph/tree/euler-tour-on-nodes.hpp
- /library/graph/tree/euler-tour-on-nodes.hpp.html
title: graph/tree/euler-tour-on-nodes.hpp
---
