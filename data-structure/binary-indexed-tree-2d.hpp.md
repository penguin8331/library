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
    path: test/AOJ/2842.test.cpp
    title: test/AOJ/2842.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\nusing\
    \ pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/binary-indexed-tree-2d.hpp\"\n\ntemplate <class\
    \ Abel>\nstruct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel>>\
    \ dat;\n\n    // [0, n) x [0, m)\n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\n\
    \                                          dat(n, vector<Abel>(m, UNITY_SUM))\
    \ {}\n    void init(int n, int m) {\n        dat.assign(n, vector<Abel>(m, UNITY_SUM));\n\
    \    }\n\n    // add x on the point (a, b)\n    inline void add(int a, int b,\
    \ Abel x) {\n        for (int i = a; i < (int)dat.size(); i |= i + 1)\n      \
    \      for (int j = b; j < (int)dat[0].size(); j |= j + 1)\n                dat[i][j]\
    \ = dat[i][j] + x;\n    }\n\n    // [0, p) x [0, q), 0-indexed\n    inline Abel\
    \ sum(int p, int q) {\n        Abel res = UNITY_SUM;\n        for (int i = p -\
    \ 1; i >= 0; i = (i & (i + 1)) - 1)\n            for (int j = q - 1; j >= 0; j\
    \ = (j & (j + 1)) - 1)\n                res = res + dat[i][j];\n        return\
    \ res;\n    }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline Abel\
    \ sum(int x1, int x2, int y1, int y2) {\n        return sum(x2, y2) - sum(x1,\
    \ y2) - sum(x2, y1) + sum(x1, y1);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, BIT2D bit) {\n        for (int i = 0; i < (int)bit.dat.size(); i++) {\n\
    \            os << \"[ \";\n            for (int j = 0; j < (int)bit.dat[0].size();\
    \ j++) {\n                os << bit.sum(i, i + 1, j, j + 1) << \" \";\n      \
    \      }\n            os << ']';\n        }\n        return os;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class Abel>\n\
    struct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel>> dat;\n\
    \n    // [0, n) x [0, m)\n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\n\
    \                                          dat(n, vector<Abel>(m, UNITY_SUM))\
    \ {}\n    void init(int n, int m) {\n        dat.assign(n, vector<Abel>(m, UNITY_SUM));\n\
    \    }\n\n    // add x on the point (a, b)\n    inline void add(int a, int b,\
    \ Abel x) {\n        for (int i = a; i < (int)dat.size(); i |= i + 1)\n      \
    \      for (int j = b; j < (int)dat[0].size(); j |= j + 1)\n                dat[i][j]\
    \ = dat[i][j] + x;\n    }\n\n    // [0, p) x [0, q), 0-indexed\n    inline Abel\
    \ sum(int p, int q) {\n        Abel res = UNITY_SUM;\n        for (int i = p -\
    \ 1; i >= 0; i = (i & (i + 1)) - 1)\n            for (int j = q - 1; j >= 0; j\
    \ = (j & (j + 1)) - 1)\n                res = res + dat[i][j];\n        return\
    \ res;\n    }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline Abel\
    \ sum(int x1, int x2, int y1, int y2) {\n        return sum(x2, y2) - sum(x1,\
    \ y2) - sum(x2, y1) + sum(x1, y1);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, BIT2D bit) {\n        for (int i = 0; i < (int)bit.dat.size(); i++) {\n\
    \            os << \"[ \";\n            for (int j = 0; j < (int)bit.dat[0].size();\
    \ j++) {\n                os << bit.sum(i, i + 1, j, j + 1) << \" \";\n      \
    \      }\n            os << ']';\n        }\n        return os;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-2d.hpp
  requiredBy: []
  timestamp: '2023-03-14 23:16:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2842.test.cpp
documentation_of: data-structure/binary-indexed-tree-2d.hpp
layout: document
title: "\u4E8C\u6B21\u5143 BIT"
---
