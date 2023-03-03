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
  _extendedRequiredBy:
  - icon: ':x:'
    path: math/number/pollard-rho.hpp
    title: "\u78BA\u7387\u7684\u7D20\u56E0\u6570\u5206\u89E3 (Pollard \u306E\u30ED\
      \u30FC\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_1_C-2.test.cpp
    title: test/AOJ/ALDS1_1_C-2.test.cpp
  - icon: ':x:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/number/miller-rabin.hpp\"\
    \n\ntemplate <class T>\nT pow_mod(T A, T N, T M) {\n    T res = 1 % M;\n    A\
    \ %= M;\n    while (N) {\n        if (N & 1) res = (res * A) % M;\n        A =\
    \ (A * A) % M;\n        N >>= 1;\n    }\n    return res;\n}\n\nbool is_prime(long\
    \ long N) {\n    if (N <= 1) return false;\n    if (N == 2 || N == 3) return true;\n\
    \    if (N % 2 == 0) return false;\n    vector<long long> A = {2, 325, 9375, 28178,\
    \ 450775,\n                           9780504, 1795265022};\n    long long s =\
    \ 0, d = N - 1;\n    while (d % 2 == 0) {\n        ++s;\n        d >>= 1;\n  \
    \  }\n    for (auto a : A) {\n        if (a % N == 0) return true;\n        long\
    \ long t, x = pow_mod<__int128_t>(a, d, N);\n        if (x != 1) {\n         \
    \   for (t = 0; t < s; ++t) {\n                if (x == N - 1) break;\n      \
    \          x = __int128_t(x) * x % N;\n            }\n            if (t == s)\
    \ return false;\n        }\n    }\n    return true;\n}\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\ntemplate <class\
    \ T>\nT pow_mod(T A, T N, T M) {\n    T res = 1 % M;\n    A %= M;\n    while (N)\
    \ {\n        if (N & 1) res = (res * A) % M;\n        A = (A * A) % M;\n     \
    \   N >>= 1;\n    }\n    return res;\n}\n\nbool is_prime(long long N) {\n    if\
    \ (N <= 1) return false;\n    if (N == 2 || N == 3) return true;\n    if (N %\
    \ 2 == 0) return false;\n    vector<long long> A = {2, 325, 9375, 28178, 450775,\n\
    \                           9780504, 1795265022};\n    long long s = 0, d = N\
    \ - 1;\n    while (d % 2 == 0) {\n        ++s;\n        d >>= 1;\n    }\n    for\
    \ (auto a : A) {\n        if (a % N == 0) return true;\n        long long t, x\
    \ = pow_mod<__int128_t>(a, d, N);\n        if (x != 1) {\n            for (t =\
    \ 0; t < s; ++t) {\n                if (x == N - 1) break;\n                x\
    \ = __int128_t(x) * x % N;\n            }\n            if (t == s) return false;\n\
    \        }\n    }\n    return true;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: math/number/miller-rabin.hpp
  requiredBy:
  - math/number/pollard-rho.hpp
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/factorize.test.cpp
  - test/AOJ/ALDS1_1_C-2.test.cpp
documentation_of: math/number/miller-rabin.hpp
layout: document
title: "\u78BA\u7387\u7684\u7D20\u6570\u5224\u5B9A (Miller-Rabin \u6CD5)"
---
