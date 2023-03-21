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
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define all(x) std::begin(x),\
    \ std::end(x)\n#define rall(x) std::rbegin(x), std::rend(x)\n#define elif else\
    \ if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a +\
    \ b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
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
    \ std;\n#line 3 \"data-structure/binary-indexed-tree-2d-raq.hpp\"\n\ntemplate\
    \ <class Abel>\nstruct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel>\
    \ > dat[2][2];\n    int N, M;\n\n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\
    \ N(n), M(m) {\n        init(n, m);\n    }\n    void init(int n, int m) {\n  \
    \      for (int i = 0; i < 2; ++i)\n            for (int j = 0; j < 2; ++j)\n\
    \                dat[i][j].assign(n + 1, vector<Abel>(m + 1, UNITY_SUM));\n  \
    \  }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline void subsub_add(int\
    \ f, int s, int x, int y, Abel v) {\n        for (int i = x; i < (int)dat[f][s].size();\
    \ i |= i + 1)\n            for (int j = y; j < (int)dat[f][s][0].size(); j |=\
    \ j + 1)\n                dat[f][s][i][j] = dat[f][s][i][j] + v;\n    }\n    inline\
    \ void sub_add(int x, int y, Abel v) {\n        subsub_add(0, 0, x, y, v * x *\
    \ y);\n        subsub_add(1, 0, x, y, -v * x);\n        subsub_add(0, 1, x, y,\
    \ -v * y);\n        subsub_add(1, 1, x, y, v);\n    }\n    inline void add(int\
    \ x1, int x2, int y1, int y2, Abel v) {\n        sub_add(x1, y1, v);\n       \
    \ sub_add(x1, y2, -v);\n        sub_add(x2, y1, -v);\n        sub_add(x2, y2,\
    \ v);\n    }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline Abel\
    \ subsub_sum(int f, int s, int x, int y) {\n        Abel res = 0;\n        for\
    \ (int i = x; i > 0; i = (i & (i + 1)) - 1)\n            for (int j = y; j > 0;\
    \ j = (j & (j + 1)) - 1)\n                res = res + dat[f][s][i][j];\n     \
    \   return res;\n    }\n    inline Abel sub_sum(int x, int y) {\n        Abel\
    \ res = 0;\n        res += subsub_sum(0, 0, x, y);\n        res += subsub_sum(1,\
    \ 0, x, y) * y;\n        res += subsub_sum(0, 1, x, y) * x;\n        res += subsub_sum(1,\
    \ 1, x, y) * x * y;\n        return res;\n    }\n    inline Abel sum(int x1, int\
    \ x2, int y1, int y2) {\n        return sub_sum(x2, y2) - sub_sum(x1, y2) - sub_sum(x2,\
    \ y1) + sub_sum(x1, y1);\n    }\n\n    friend ostream& operator<<(ostream& os,\
    \ BIT2D bit) {\n        for (int i = 0; i < bit.N; i++) {\n            os << \"\
    [ \";\n            for (int j = 0; j < bit.M; j++) {\n                os << bit.sum(i,\
    \ i + 1, j, j + 1) << \" \";\n            }\n            os << ']';\n        }\n\
    \        return os;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class Abel>\n\
    struct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel> > dat[2][2];\n\
    \    int N, M;\n\n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\
    \ N(n), M(m) {\n        init(n, m);\n    }\n    void init(int n, int m) {\n  \
    \      for (int i = 0; i < 2; ++i)\n            for (int j = 0; j < 2; ++j)\n\
    \                dat[i][j].assign(n + 1, vector<Abel>(m + 1, UNITY_SUM));\n  \
    \  }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline void subsub_add(int\
    \ f, int s, int x, int y, Abel v) {\n        for (int i = x; i < (int)dat[f][s].size();\
    \ i |= i + 1)\n            for (int j = y; j < (int)dat[f][s][0].size(); j |=\
    \ j + 1)\n                dat[f][s][i][j] = dat[f][s][i][j] + v;\n    }\n    inline\
    \ void sub_add(int x, int y, Abel v) {\n        subsub_add(0, 0, x, y, v * x *\
    \ y);\n        subsub_add(1, 0, x, y, -v * x);\n        subsub_add(0, 1, x, y,\
    \ -v * y);\n        subsub_add(1, 1, x, y, v);\n    }\n    inline void add(int\
    \ x1, int x2, int y1, int y2, Abel v) {\n        sub_add(x1, y1, v);\n       \
    \ sub_add(x1, y2, -v);\n        sub_add(x2, y1, -v);\n        sub_add(x2, y2,\
    \ v);\n    }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline Abel\
    \ subsub_sum(int f, int s, int x, int y) {\n        Abel res = 0;\n        for\
    \ (int i = x; i > 0; i = (i & (i + 1)) - 1)\n            for (int j = y; j > 0;\
    \ j = (j & (j + 1)) - 1)\n                res = res + dat[f][s][i][j];\n     \
    \   return res;\n    }\n    inline Abel sub_sum(int x, int y) {\n        Abel\
    \ res = 0;\n        res += subsub_sum(0, 0, x, y);\n        res += subsub_sum(1,\
    \ 0, x, y) * y;\n        res += subsub_sum(0, 1, x, y) * x;\n        res += subsub_sum(1,\
    \ 1, x, y) * x * y;\n        return res;\n    }\n    inline Abel sum(int x1, int\
    \ x2, int y1, int y2) {\n        return sub_sum(x2, y2) - sub_sum(x1, y2) - sub_sum(x2,\
    \ y1) + sub_sum(x1, y1);\n    }\n\n    friend ostream& operator<<(ostream& os,\
    \ BIT2D bit) {\n        for (int i = 0; i < bit.N; i++) {\n            os << \"\
    [ \";\n            for (int j = 0; j < bit.M; j++) {\n                os << bit.sum(i,\
    \ i + 1, j, j + 1) << \" \";\n            }\n            os << ']';\n        }\n\
    \        return os;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-2d-raq.hpp
  requiredBy: []
  timestamp: '2023-03-21 10:37:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-indexed-tree-2d-raq.hpp
layout: document
title: "BIT-2D (\u9818\u57DF\u52A0\u7B97, \u9818\u57DF\u548C\u53D6\u5F97\u306B\u4E21\
  \u5BFE\u5FDC)"
---
