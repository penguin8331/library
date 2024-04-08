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
    \ std;\n#line 3 \"data-structure/sparse-table-2d.hpp\"\n\ntemplate <class T>\n\
    struct SparseTable2D {\n    vector<vector<vector<vector<T>>>> dat;\n    vector<int>\
    \ height;\n    using Func = function<T(T, T)>;\n    Func F;\n\n    SparseTable2D()\
    \ {}\n    explicit SparseTable2D(\n        const vector<vector<T>> &vec,\n   \
    \     const Func f = [](T a, T b) { return min(a, b); }) {\n        init(vec,\
    \ f);\n    }\n    void init(\n        const vector<vector<T>> &vec,\n        const\
    \ Func f = [](T a, T b) { return min(a, b); }) {\n        F = f;\n        int\
    \ n = (int)vec.size(), m = (int)vec[0].size();\n        height.assign(max(n, m)\
    \ + 1, 0);\n        for (int i = 2; i <= max(n, m); i++) {\n            height[i]\
    \ = height[i >> 1] + 1;\n        }\n        dat.assign(height[n] + 1,\n      \
    \             vector<vector<vector<T>>>(\n                       height[m] + 1,\
    \ vector<vector<T>>(n, vector<T>(m))));\n        for (int i = 0; i < n; ++i) {\n\
    \            for (int j = 0; j < m; ++j) {\n                dat[0][0][i][j] =\
    \ vec[i][j];\n            }\n        }\n        for (int k = 1; (1 << k) <= n;\
    \ ++k) {\n            for (int i = 0; i + (1 << k) <= n; ++i) {\n            \
    \    for (int j = 0; j < m; ++j) {\n                    dat[k][0][i][j] = F(dat[k\
    \ - 1][0][i][j],\n                                        dat[k - 1][0][i + (1\
    \ << (k - 1))][j]);\n                }\n            }\n        }\n        for\
    \ (int k = 0; (1 << k) <= n; ++k) {\n            for (int l = 1; (1 << l) <= m;\
    \ ++l) {\n                for (int i = 0; i + (1 << k) <= n; ++i) {\n        \
    \            for (int j = 0; j + (1 << l) <= m; ++j) {\n                     \
    \   dat[k][l][i][j] =\n                            F(dat[k][l - 1][i][j],\n  \
    \                            dat[k][l - 1][i][j + (1 << (l - 1))]);\n        \
    \            }\n                }\n            }\n        }\n    }\n    T query(int\
    \ h1, int w1, int h2, int w2) {\n        int h = height[h2 - h1], w = height[w2\
    \ - w1];\n        return F(dat[h][w][h1][w1],\n                 F(dat[h][w][h2\
    \ - (1 << h)][w1],\n                   F(dat[h][w][h1][w2 - (1 << w)],\n     \
    \                dat[h][w][h2 - (1 << h)][w2 - (1 << w)])));\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T>\n\
    struct SparseTable2D {\n    vector<vector<vector<vector<T>>>> dat;\n    vector<int>\
    \ height;\n    using Func = function<T(T, T)>;\n    Func F;\n\n    SparseTable2D()\
    \ {}\n    explicit SparseTable2D(\n        const vector<vector<T>> &vec,\n   \
    \     const Func f = [](T a, T b) { return min(a, b); }) {\n        init(vec,\
    \ f);\n    }\n    void init(\n        const vector<vector<T>> &vec,\n        const\
    \ Func f = [](T a, T b) { return min(a, b); }) {\n        F = f;\n        int\
    \ n = (int)vec.size(), m = (int)vec[0].size();\n        height.assign(max(n, m)\
    \ + 1, 0);\n        for (int i = 2; i <= max(n, m); i++) {\n            height[i]\
    \ = height[i >> 1] + 1;\n        }\n        dat.assign(height[n] + 1,\n      \
    \             vector<vector<vector<T>>>(\n                       height[m] + 1,\
    \ vector<vector<T>>(n, vector<T>(m))));\n        for (int i = 0; i < n; ++i) {\n\
    \            for (int j = 0; j < m; ++j) {\n                dat[0][0][i][j] =\
    \ vec[i][j];\n            }\n        }\n        for (int k = 1; (1 << k) <= n;\
    \ ++k) {\n            for (int i = 0; i + (1 << k) <= n; ++i) {\n            \
    \    for (int j = 0; j < m; ++j) {\n                    dat[k][0][i][j] = F(dat[k\
    \ - 1][0][i][j],\n                                        dat[k - 1][0][i + (1\
    \ << (k - 1))][j]);\n                }\n            }\n        }\n        for\
    \ (int k = 0; (1 << k) <= n; ++k) {\n            for (int l = 1; (1 << l) <= m;\
    \ ++l) {\n                for (int i = 0; i + (1 << k) <= n; ++i) {\n        \
    \            for (int j = 0; j + (1 << l) <= m; ++j) {\n                     \
    \   dat[k][l][i][j] =\n                            F(dat[k][l - 1][i][j],\n  \
    \                            dat[k][l - 1][i][j + (1 << (l - 1))]);\n        \
    \            }\n                }\n            }\n        }\n    }\n    T query(int\
    \ h1, int w1, int h2, int w2) {\n        int h = height[h2 - h1], w = height[w2\
    \ - w1];\n        return F(dat[h][w][h1][w1],\n                 F(dat[h][w][h2\
    \ - (1 << h)][w1],\n                   F(dat[h][w][h1][w2 - (1 << w)],\n     \
    \                dat[h][w][h2 - (1 << h)][w2 - (1 << w)])));\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/sparse-table-2d.hpp
  requiredBy: []
  timestamp: '2024-04-01 16:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/sparse-table-2d.hpp
layout: document
title: Sparse Table 2D
---

## 使い方

### 宣言

`SparseTable(vec, F)` : 二次元配列 `vec` で構築、 `F` は二項演算

### クエリ

`query(h1, w1, h2, w2)` :  区間 $[A_{h_1,w_1}, A_{h2, w2})$ の総積を取得する。
