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
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/tree/euler-tour-on-edges.hpp
    title: graph/tree/euler-tour-on-edges.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/euler-tour-on-nodes.hpp
    title: graph/tree/euler-tour-on-nodes.hpp
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/sparse-table.hpp\"\n\ntemplate <class T>\nstruct\
    \ SparseTable {\n    vector<vector<T>> dat;\n    vector<int> height;\n    using\
    \ Func = function<T(T, T)>;\n    Func F;\n\n    SparseTable() {}\n    SparseTable(\n\
    \        const vector<T> &vec, const Func f = [](T a, T b) { return min(a, b);\
    \ }) {\n        init(vec, f);\n    }\n    void init(\n        const vector<T>\
    \ &vec, const Func f = [](T a, T b) { return min(a, b); }) {\n        F = f;\n\
    \        int n = (int)vec.size(), h = 0;\n        while ((1 << h) < n) ++h;\n\
    \        dat.assign(h, vector<T>(1 << h));\n        height.assign(n + 1, 0);\n\
    \        for (int i = 2; i <= n; i++) height[i] = height[i >> 1] + 1;\n      \
    \  for (int i = 0; i < n; ++i) dat[0][i] = vec[i];\n        for (int i = 1; i\
    \ < h; ++i)\n            for (int j = 0; j < n; ++j)\n                dat[i][j]\
    \ = F(dat[i - 1][j], dat[i - 1][min(j + (1 << (i - 1)), n - 1)]);\n    }\n\n \
    \   T get(int a, int b) {\n        return F(dat[height[b - a]][a], dat[height[b\
    \ - a]][b - (1 << height[b - a])]);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T>\n\
    struct SparseTable {\n    vector<vector<T>> dat;\n    vector<int> height;\n  \
    \  using Func = function<T(T, T)>;\n    Func F;\n\n    SparseTable() {}\n    SparseTable(\n\
    \        const vector<T> &vec, const Func f = [](T a, T b) { return min(a, b);\
    \ }) {\n        init(vec, f);\n    }\n    void init(\n        const vector<T>\
    \ &vec, const Func f = [](T a, T b) { return min(a, b); }) {\n        F = f;\n\
    \        int n = (int)vec.size(), h = 0;\n        while ((1 << h) < n) ++h;\n\
    \        dat.assign(h, vector<T>(1 << h));\n        height.assign(n + 1, 0);\n\
    \        for (int i = 2; i <= n; i++) height[i] = height[i >> 1] + 1;\n      \
    \  for (int i = 0; i < n; ++i) dat[0][i] = vec[i];\n        for (int i = 1; i\
    \ < h; ++i)\n            for (int j = 0; j < n; ++j)\n                dat[i][j]\
    \ = F(dat[i - 1][j], dat[i - 1][min(j + (1 << (i - 1)), n - 1)]);\n    }\n\n \
    \   T get(int a, int b) {\n        return F(dat[height[b - a]][a], dat[height[b\
    \ - a]][b - (1 << height[b - a])]);\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - graph/tree/euler-tour-on-nodes.hpp
  - graph/tree/euler-tour-on-edges.hpp
  timestamp: '2023-04-09 14:01:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2667.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-table.hpp
- /library/data-structure/sparse-table.hpp.html
title: data-structure/sparse-table.hpp
---
