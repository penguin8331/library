---
data:
  _extendedDependsOn:
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
    \ std;\n#line 3 \"data-structure/weighted-union-find.hpp\"\n\ntemplate <class\
    \ T>\nstruct WeightedUnionFind {\n    // core member\n    vector<int> par;\n \
    \   vector<T> weight;\n\n    // constructor\n    WeightedUnionFind() {}\n    WeightedUnionFind(int\
    \ N, T zero = 0) : par(N, -1), weight(N, zero) {}\n    void init(int N, T zero\
    \ = 0) {\n        par.assign(N, -1);\n        weight.assign(N, zero);\n    }\n\
    \n    // core methods\n    int root(int x) {\n        if (par[x] < 0)\n      \
    \      return x;\n        else {\n            int r = root(par[x]);\n        \
    \    weight[x] += weight[par[x]];\n            return par[x] = r;\n        }\n\
    \    }\n    bool same(int x, int y) { return root(x) == root(y); }\n    int size(int\
    \ x) { return -par[root(x)]; }\n\n    // v[y] - v[x] = w\n    bool merge(int x,\
    \ int y, T w) {\n        w += get_weight(x), w -= get_weight(y);\n        x =\
    \ root(x), y = root(y);\n        if (x == y) return false;\n        if (par[x]\
    \ > par[y]) swap(x, y), w = -w;  // merge technique\n        par[x] += par[y];\n\
    \        par[y] = x;\n        weight[y] = w;\n        return true;\n    }\n\n\
    \    // get v[x]\n    T get_weight(int x) {\n        root(x);\n        return\
    \ weight[x];\n    }\n\n    // get v[y] - v[x]\n    T get_diff(int x, int y) {\
    \ return get_weight(y) - get_weight(x); }\n\n    // get groups\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> member(par.size());\n        for (int\
    \ v = 0; v < (int)par.size(); ++v) {\n            member[root(v)].push_back(v);\n\
    \        }\n        vector<vector<int>> res;\n        for (int v = 0; v < (int)par.size();\
    \ ++v) {\n            if (!member[v].empty()) res.push_back(member[v]);\n    \
    \    }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T>\n\
    struct WeightedUnionFind {\n    // core member\n    vector<int> par;\n    vector<T>\
    \ weight;\n\n    // constructor\n    WeightedUnionFind() {}\n    WeightedUnionFind(int\
    \ N, T zero = 0) : par(N, -1), weight(N, zero) {}\n    void init(int N, T zero\
    \ = 0) {\n        par.assign(N, -1);\n        weight.assign(N, zero);\n    }\n\
    \n    // core methods\n    int root(int x) {\n        if (par[x] < 0)\n      \
    \      return x;\n        else {\n            int r = root(par[x]);\n        \
    \    weight[x] += weight[par[x]];\n            return par[x] = r;\n        }\n\
    \    }\n    bool same(int x, int y) { return root(x) == root(y); }\n    int size(int\
    \ x) { return -par[root(x)]; }\n\n    // v[y] - v[x] = w\n    bool merge(int x,\
    \ int y, T w) {\n        w += get_weight(x), w -= get_weight(y);\n        x =\
    \ root(x), y = root(y);\n        if (x == y) return false;\n        if (par[x]\
    \ > par[y]) swap(x, y), w = -w;  // merge technique\n        par[x] += par[y];\n\
    \        par[y] = x;\n        weight[y] = w;\n        return true;\n    }\n\n\
    \    // get v[x]\n    T get_weight(int x) {\n        root(x);\n        return\
    \ weight[x];\n    }\n\n    // get v[y] - v[x]\n    T get_diff(int x, int y) {\
    \ return get_weight(y) - get_weight(x); }\n\n    // get groups\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> member(par.size());\n        for (int\
    \ v = 0; v < (int)par.size(); ++v) {\n            member[root(v)].push_back(v);\n\
    \        }\n        vector<vector<int>> res;\n        for (int v = 0; v < (int)par.size();\
    \ ++v) {\n            if (!member[v].empty()) res.push_back(member[v]);\n    \
    \    }\n        return res;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/weighted-union-find.hpp
  requiredBy: []
  timestamp: '2024-04-29 11:07:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/weighted-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/weighted-union-find.hpp
- /library/data-structure/weighted-union-find.hpp.html
title: data-structure/weighted-union-find.hpp
---
