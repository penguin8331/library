---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/number/chinese-remainder-theorem.hpp
    title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/2659.test.cpp
    title: test/AOJ/2659.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = pair<int, int>;\nusing pll\
    \ = pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1,\
    \ 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9\
    \ + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T&\
    \ a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename\
    \ T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false));\
    \ }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n    \
    \    std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n     \
    \   std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/number/ext-gcd.hpp\"\
    \n\nlong long extGcd(long long a, long long b, long long &p, long long &q) {\n\
    \    if (b == 0) { \n        p = 1, q = 0; \n        return a; \n    }\n    long\
    \ long d = extGcd(b, a % b, q, p);\n    q -= a / b * p;\n    return d;\n}\n"
  code: "#pragma once\n#include \"template/template.hpp\"\n\nlong long extGcd(long\
    \ long a, long long b, long long &p, long long &q) {\n    if (b == 0) { \n   \
    \     p = 1, q = 0; \n        return a; \n    }\n    long long d = extGcd(b, a\
    \ % b, q, p);\n    q -= a / b * p;\n    return d;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: math/number/ext-gcd.hpp
  requiredBy:
  - math/number/chinese-remainder-theorem.hpp
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/2659.test.cpp
documentation_of: math/number/ext-gcd.hpp
layout: document
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---
