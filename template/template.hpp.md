---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0560.test.cpp
    title: test/AOJ/0560.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1160.test.cpp
    title: test/AOJ/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_10_C.test.cpp
    title: test/AOJ/ALDS1_10_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_11_C.test.cpp
    title: test/AOJ/ALDS1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_1_C.test.cpp
    title: test/AOJ/ALDS1_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_5_D.test.cpp
    title: test/AOJ/ALDS1_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_1_d.test.cpp
    title: test/AOJ/DPL_1_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_2_A.test.cpp
    title: test/AOJ/DPL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_A.test.cpp
    title: test/AOJ/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_4_A.test.cpp
    title: test/AOJ/DSL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_A.test.cpp
    title: test/AOJ/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_B.test.cpp
    title: test/AOJ/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_1_C.test.cpp
    title: test/AOJ/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_3_A.test.cpp
    title: test/AOJ/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_3_B.test.cpp
    title: test/AOJ/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ITP1_3_D.test.cpp
    title: test/AOJ/ITP1_3_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_A.test.cpp
    title: test/AOJ/NTL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_B.test.cpp
    title: test/AOJ/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortes-path.test.cpp
    title: test/yosupo/shortes-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static-range-sum.test.cpp
    title: test/yosupo/static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\"\
    )\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing ld\
    \ = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define\
    \ pb push_back\n#define mp make_pair\n#define mt make_tuple\n#define all(x) (x).begin(),\
    \ (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n\
    #define updiv(N, X) ((N + X - 1) / X)\n#define sigma(a, b) ((a + b) * (b - a +\
    \ 1) / 2)\nstruct fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n  \
    \      ios::sync_with_stdio(false);\n        cout << fixed << setprecision(15);\n\
    \    };\n} fast_ios_;\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return\
    \ ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T&\
    \ a, T b) { return ((a > b) ? (a = b, true) : (false)); }\nconstexpr int inf =\
    \ 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1, 0,\
    \ 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr\
    \ int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n"
  code: "// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n#define pb push_back\n#define mp make_pair\n#define\
    \ mt make_tuple\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) ((N + X - 1) / X)\n#define\
    \ sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios() {\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL <<\
    \ 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] =\
    \ {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2022-12-21 18:41:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/1160.test.cpp
  - test/AOJ/ALDS1_11_C.test.cpp
  - test/AOJ/GRL_2_A.test.cpp
  - test/AOJ/DSL_4_A.test.cpp
  - test/AOJ/GRL_3_B.test.cpp
  - test/AOJ/DSL_1_A.test.cpp
  - test/AOJ/ALDS1_1_C.test.cpp
  - test/AOJ/NTL_1_A.test.cpp
  - test/AOJ/GRL_1_B.test.cpp
  - test/AOJ/GRL_3_A.test.cpp
  - test/AOJ/DPL_2_A.test.cpp
  - test/AOJ/0560.test.cpp
  - test/AOJ/GRL_1_C.test.cpp
  - test/AOJ/GRL_1_A.test.cpp
  - test/AOJ/ITP1_3_D.test.cpp
  - test/AOJ/ALDS1_10_C.test.cpp
  - test/AOJ/ALDS1_5_D.test.cpp
  - test/AOJ/DPL_1_d.test.cpp
  - test/AOJ/NTL_1_B.test.cpp
  - test/yosupo/static-range-sum.test.cpp
  - test/yosupo/shortes-path.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
