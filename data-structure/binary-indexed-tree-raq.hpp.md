---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
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
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
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
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/binary-indexed-tree-raq.hpp\"\
    \n\ntemplate <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel>\
    \ dat[2];\n    int N;\n\n    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity),\
    \ N(n) {\n        init(n);\n    }\n    void init(int n) {\n        for (int iter\
    \ = 0; iter < 2; ++iter)\n            dat[iter].assign(n + 1, UNITY_SUM);\n  \
    \  }\n\n    // [a, b), a and b are 0-indexed\n    inline void sub_add(int p, int\
    \ a, Abel x) {\n        for (int i = a; i < (int)dat[p].size(); i |= i + 1)\n\
    \            dat[p][i] = dat[p][i] + x;\n    }\n    inline void add(int a, int\
    \ b, Abel x) {\n        sub_add(0, a, x * (-a));\n        sub_add(1, a, x);\n\
    \        sub_add(0, b, x * b);\n        sub_add(1, b, x * (-1));\n    }\n\n  \
    \  // [a, b), a and b are 0-indexed\n    inline Abel sub_sum(int p, int a) {\n\
    \        Abel res = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i\
    \ + 1)) - 1)\n            res = res + dat[p][i];\n        return res;\n    }\n\
    \    inline Abel sum(int a, int b) {\n        return sub_sum(0, b) + sub_sum(1,\
    \ b) * b - sub_sum(0, a) - sub_sum(1, a) * a;\n    }\n    \n    friend ostream&\
    \ operator<<(ostream& os, BIT bit) {\n        os << \"[ \";\n        for (int\
    \ i = 0; i < bit.N; i++) {\n            os << bit.sum(i, i + 1) << \" \";\n  \
    \      }\n        os << ']';\n        return os;\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class Abel>\n\
    struct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat[2];\n    int N;\n\n\
    \    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), N(n) {\n  \
    \      init(n);\n    }\n    void init(int n) {\n        for (int iter = 0; iter\
    \ < 2; ++iter)\n            dat[iter].assign(n + 1, UNITY_SUM);\n    }\n\n   \
    \ // [a, b), a and b are 0-indexed\n    inline void sub_add(int p, int a, Abel\
    \ x) {\n        for (int i = a; i < (int)dat[p].size(); i |= i + 1)\n        \
    \    dat[p][i] = dat[p][i] + x;\n    }\n    inline void add(int a, int b, Abel\
    \ x) {\n        sub_add(0, a, x * (-a));\n        sub_add(1, a, x);\n        sub_add(0,\
    \ b, x * b);\n        sub_add(1, b, x * (-1));\n    }\n\n    // [a, b), a and\
    \ b are 0-indexed\n    inline Abel sub_sum(int p, int a) {\n        Abel res =\
    \ UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n   \
    \         res = res + dat[p][i];\n        return res;\n    }\n    inline Abel\
    \ sum(int a, int b) {\n        return sub_sum(0, b) + sub_sum(1, b) * b - sub_sum(0,\
    \ a) - sub_sum(1, a) * a;\n    }\n    \n    friend ostream& operator<<(ostream&\
    \ os, BIT bit) {\n        os << \"[ \";\n        for (int i = 0; i < bit.N; i++)\
    \ {\n            os << bit.sum(i, i + 1) << \" \";\n        }\n        os << ']';\n\
    \        return os;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-raq.hpp
  requiredBy: []
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_G.test.cpp
documentation_of: data-structure/binary-indexed-tree-raq.hpp
layout: document
title: "BIT (\u533A\u9593\u52A0\u7B97, \u533A\u9593\u548C\u53D6\u5F97\u306B\u4E21\u5BFE\
  \u5FDC)"
---
