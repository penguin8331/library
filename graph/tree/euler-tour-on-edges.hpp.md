---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
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
    \ 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)\
    \        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...) \
    \       \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/segment-tree.hpp\"\n\ntemplate <class Monoid>\n\
    struct SegTree {\n    using Func = function<Monoid(Monoid, Monoid)>;\n    int\
    \ N;\n    Func F;\n    Monoid IDENTITY;\n    int SIZE_R;\n    vector<Monoid> dat;\n\
    \n    /* initialization */\n    SegTree() {}\n    SegTree(int n, const Func f,\
    \ const Monoid& identity)\n        : N(n), F(f), IDENTITY(identity) {\n      \
    \  SIZE_R = 1;\n        while (SIZE_R < n) SIZE_R *= 2;\n        dat.assign(SIZE_R\
    \ * 2, IDENTITY);\n    }\n    void init(int n, const Func f, const Monoid& identity)\
    \ {\n        N = n;\n        F = f;\n        IDENTITY = identity;\n        SIZE_R\
    \ = 1;\n        while (SIZE_R < n) SIZE_R *= 2;\n        dat.assign(SIZE_R * 2,\
    \ IDENTITY);\n    }\n\n    /* set, a is 0-indexed */\n    /* build(): O(N) */\n\
    \    void set(int a, const Monoid& v) { dat[a + SIZE_R] = v; }\n    void build()\
    \ {\n        for (int k = SIZE_R - 1; k > 0; --k)\n            dat[k] = F(dat[k\
    \ * 2], dat[k * 2 + 1]);\n    }\n\n    /* update a, a is 0-indexed, O(log N) */\n\
    \    void update(int a, const Monoid& v) {\n        int k = a + SIZE_R;\n    \
    \    dat[k] = v;\n        while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);\n\
    \    }\n\n    /* get [a, b), a and b are 0-indexed, O(log N) */\n    Monoid get(int\
    \ a, int b) {\n        Monoid vleft = IDENTITY, vright = IDENTITY;\n        for\
    \ (int left = a + SIZE_R, right = b + SIZE_R; left < right;\n             left\
    \ >>= 1, right >>= 1) {\n            if (left & 1) vleft = F(vleft, dat[left++]);\n\
    \            if (right & 1) vright = F(dat[--right], vright);\n        }\n   \
    \     return F(vleft, vright);\n    }\n    Monoid all_get() { return dat[1]; }\n\
    \    Monoid operator[](int a) { return dat[a + SIZE_R]; }\n\n    /* get max r\
    \ that f(get(l, r)) = True (0-indexed), O(log N) */\n    /* f(IDENTITY) need to\
    \ be True */\n    int max_right(const function<bool(Monoid)> f, int l = 0) {\n\
    \        if (l == N) return N;\n        l += SIZE_R;\n        Monoid sum = IDENTITY;\n\
    \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(F(sum,\
    \ dat[l]))) {\n                while (l < SIZE_R) {\n                    l = l\
    \ * 2;\n                    if (f(F(sum, dat[l]))) {\n                       \
    \ sum = F(sum, dat[l]);\n                        ++l;\n                    }\n\
    \                }\n                return l - SIZE_R;\n            }\n      \
    \      sum = F(sum, dat[l]);\n            ++l;\n        } while ((l & -l) != l);\n\
    \        return N;\n    }\n\n    /* get min l that f(get(l, r)) = True (0-indexed),\
    \ O(log N) */\n    /* f(IDENTITY) need to be True */\n    int min_left(const function<bool(Monoid)>\
    \ f, int r = -1) {\n        if (r == 0) return 0;\n        if (r == -1) r = N;\n\
    \        r += SIZE_R;\n        Monoid sum = IDENTITY;\n        do {\n        \
    \    --r;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(F(dat[r],\
    \ sum))) {\n                while (r < SIZE_R) {\n                    r = r *\
    \ 2 + 1;\n                    if (f(F(dat[r], sum))) {\n                     \
    \   sum = F(dat[r], sum);\n                        --r;\n                    }\n\
    \                }\n                return r + 1 - SIZE_R;\n            }\n  \
    \          sum = F(dat[r], sum);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n\n    friend ostream& operator<<(ostream& os, SegTree seg) {\n  \
    \      os << \"[ \";\n        for (int i = 0; i < seg.N; i++) {\n            os\
    \ << seg.get(i, i + 1) << \" \";\n        }\n        os << ']';\n        return\
    \ os;\n    }\n};\n#line 3 \"data-structure/sparse-table.hpp\"\n\ntemplate <class\
    \ T>\nstruct SparseTable {\n    vector<vector<T>> dat;\n    vector<int> height;\n\
    \    using Func = function<T(T, T)>;\n    Func F;\n\n    SparseTable() {}\n  \
    \  explicit SparseTable(\n        const vector<T> &vec,\n        const Func f\
    \ = [](T a, T b) { return min(a, b); }) {\n        init(vec, f);\n    }\n    void\
    \ init(\n        const vector<T> &vec,\n        const Func f = [](T a, T b) {\
    \ return min(a, b); }) {\n        F = f;\n        int n = (int)vec.size(), h =\
    \ 0;\n        while ((1 << h) < n) ++h;\n        dat.assign(h, vector<T>(1 <<\
    \ h));\n        height.assign(n + 1, 0);\n        for (int i = 2; i <= n; i++)\
    \ height[i] = height[i >> 1] + 1;\n        for (int i = 0; i < n; ++i) dat[0][i]\
    \ = vec[i];\n        for (int i = 1; i < h; ++i)\n            for (int j = 0;\
    \ j < n; ++j)\n                dat[i][j] = F(dat[i - 1][j],\n                \
    \              dat[i - 1][min(j + (1 << (i - 1)), n - 1)]);\n    }\n\n    T get(int\
    \ a, int b) {\n        return F(dat[height[b - a]][a],\n                 dat[height[b\
    \ - a]][b - (1 << height[b - a])]);\n    }\n};\n#line 5 \"graph/tree/euler-tour-on-edges.hpp\"\
    \n\nstruct Edge {\n    int next;\n    long long cost;\n    int idx;\n};\nstruct\
    \ EulerTour {\n    using pli = pair<long long, int>;\n    vector<int> edge;\n\
    \    vector<int> node;\n    vector<int> vf, ve;\n    vector<int> ef, ee;\n   \
    \ vector<int> depth;\n    vector<vector<Edge>> tree;\n    SparseTable<pair<int,\
    \ int>> st;\n    SegTree<pli> seg;\n    const function<pli(pli, pli)> fm = [](pli\
    \ a, pli b) { return pli{a.first * a.second + b.first * b.second, 1}; };\n   \
    \ EulerTour(const vector<vector<Edge>>& tree_) {\n        init(tree_);\n    }\n\
    \    void init(const vector<vector<Edge>>& tree_) {\n        tree = tree_;\n \
    \       int V = (int)tree.size();\n        depth.resize(V * 2 - 1);\n        edge.resize(V\
    \ * 2 - 2);\n        node.resize(V * 2 - 1);\n        vf.resize(V);\n        ve.resize(V);\n\
    \        ef.resize(V - 1);\n        ee.resize(V - 1);\n        seg.init((V - 1)\
    \ * 2, fm, pli({0, 0}));\n        int k = 0;\n        dfs(0, -1, 0, k);\n    \
    \    vector<pair<int, int>> tmp((int)depth.size());\n        for (int i = 0; i\
    \ < (int)depth.size(); i++) {\n            tmp[i] = {depth[i], i};\n        }\n\
    \        st.init(tmp);\n        seg.build();\n    }\n    void dfs(int now, int\
    \ prev, int dep, int& ord) {\n        node[ord] = now;\n        depth[ord] = dep;\n\
    \        vf[now] = ve[now] = ord;\n        ord++;\n        for (const auto& [next,\
    \ cost, idx] : tree[now]) {\n            if (next != prev) {\n               \
    \ seg.set(ord - 1, {cost, 1});\n                edge[ord - 1] = idx;\n       \
    \         ef[idx] = ord - 1;\n                dfs(next, now, dep + 1, ord);\n\
    \                node[ord] = now;\n                depth[ord] = dep;\n       \
    \         ve[next] = ord;\n                ee[idx] = ord - 1;\n              \
    \  seg.set(ord - 1, {cost, -1});\n                edge[ord - 1] = idx;\n     \
    \           ord++;\n            }\n        }\n    }\n    inline int LCA(int u,\
    \ int v) {\n        int a = vf[u], b = vf[v];\n        if (a > b) swap(a, b);\n\
    \        return node[st.get(a, b + 1).second];\n    }\n    inline void update(int\
    \ idx, int x) {\n        seg.update(ef[idx], {x, 1});\n        seg.update(ee[idx],\
    \ {x, -1});\n    }\n    inline long long get(int v) {\n        return seg.get(0,\
    \ vf[v]).first;\n    }\n    inline long long get(int u, int v) {\n        int\
    \ lca = LCA(u, v);\n        return get(u) + get(v) - get(lca) * 2;\n    }\n};\n"
  code: "#pragma once\n#include \"../../data-structure/segment-tree.hpp\"\n#include\
    \ \"../../data-structure/sparse-table.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nstruct Edge {\n    int next;\n    long long cost;\n    int idx;\n};\nstruct\
    \ EulerTour {\n    using pli = pair<long long, int>;\n    vector<int> edge;\n\
    \    vector<int> node;\n    vector<int> vf, ve;\n    vector<int> ef, ee;\n   \
    \ vector<int> depth;\n    vector<vector<Edge>> tree;\n    SparseTable<pair<int,\
    \ int>> st;\n    SegTree<pli> seg;\n    const function<pli(pli, pli)> fm = [](pli\
    \ a, pli b) { return pli{a.first * a.second + b.first * b.second, 1}; };\n   \
    \ EulerTour(const vector<vector<Edge>>& tree_) {\n        init(tree_);\n    }\n\
    \    void init(const vector<vector<Edge>>& tree_) {\n        tree = tree_;\n \
    \       int V = (int)tree.size();\n        depth.resize(V * 2 - 1);\n        edge.resize(V\
    \ * 2 - 2);\n        node.resize(V * 2 - 1);\n        vf.resize(V);\n        ve.resize(V);\n\
    \        ef.resize(V - 1);\n        ee.resize(V - 1);\n        seg.init((V - 1)\
    \ * 2, fm, pli({0, 0}));\n        int k = 0;\n        dfs(0, -1, 0, k);\n    \
    \    vector<pair<int, int>> tmp((int)depth.size());\n        for (int i = 0; i\
    \ < (int)depth.size(); i++) {\n            tmp[i] = {depth[i], i};\n        }\n\
    \        st.init(tmp);\n        seg.build();\n    }\n    void dfs(int now, int\
    \ prev, int dep, int& ord) {\n        node[ord] = now;\n        depth[ord] = dep;\n\
    \        vf[now] = ve[now] = ord;\n        ord++;\n        for (const auto& [next,\
    \ cost, idx] : tree[now]) {\n            if (next != prev) {\n               \
    \ seg.set(ord - 1, {cost, 1});\n                edge[ord - 1] = idx;\n       \
    \         ef[idx] = ord - 1;\n                dfs(next, now, dep + 1, ord);\n\
    \                node[ord] = now;\n                depth[ord] = dep;\n       \
    \         ve[next] = ord;\n                ee[idx] = ord - 1;\n              \
    \  seg.set(ord - 1, {cost, -1});\n                edge[ord - 1] = idx;\n     \
    \           ord++;\n            }\n        }\n    }\n    inline int LCA(int u,\
    \ int v) {\n        int a = vf[u], b = vf[v];\n        if (a > b) swap(a, b);\n\
    \        return node[st.get(a, b + 1).second];\n    }\n    inline void update(int\
    \ idx, int x) {\n        seg.update(ef[idx], {x, 1});\n        seg.update(ee[idx],\
    \ {x, -1});\n    }\n    inline long long get(int v) {\n        return seg.get(0,\
    \ vf[v]).first;\n    }\n    inline long long get(int u, int v) {\n        int\
    \ lca = LCA(u, v);\n        return get(u) + get(v) - get(lca) * 2;\n    }\n};"
  dependsOn:
  - data-structure/segment-tree.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: graph/tree/euler-tour-on-edges.hpp
  requiredBy: []
  timestamp: '2024-02-25 20:07:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/euler-tour-on-edges.hpp
layout: document
redirect_from:
- /library/graph/tree/euler-tour-on-edges.hpp
- /library/graph/tree/euler-tour-on-edges.hpp.html
title: graph/tree/euler-tour-on-edges.hpp
---
