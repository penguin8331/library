---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/UnionFind_Checker.test.cpp
    title: test/AOJ/UnionFind_Checker.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/example.test.cpp
    title: test/example.test.cpp
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
    \ MOD = 1e9 + 7;"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2022-12-20 12:47:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/example.test.cpp
  - test/AOJ/UnionFind_Checker.test.cpp
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
