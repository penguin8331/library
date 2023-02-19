---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/number/pollard-rho.hpp
    title: "\u78BA\u7387\u7684\u7D20\u56E0\u6570\u5206\u89E3 (Pollard \u306E\u30ED\
      \u30FC\u6CD5)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_1_C-2.test.cpp
    title: test/AOJ/ALDS1_1_C-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/miller-rabin.hpp\"\ntemplate <class T>\nT pow_mod(T\
    \ A, T N, T M) {\n    T res = 1 % M;\n    A %= M;\n    while (N) {\n        if\
    \ (N & 1) res = (res * A) % M;\n        A = (A * A) % M;\n        N >>= 1;\n \
    \   }\n    return res;\n}\n\nbool is_prime(long long N) {\n    if (N <= 1) return\
    \ false;\n    if (N == 2 || N == 3) return true;\n    if (N % 2 == 0) return false;\n\
    \    vector<long long> A = {2, 325, 9375, 28178, 450775,\n                   \
    \        9780504, 1795265022};\n    long long s = 0, d = N - 1;\n    while (d\
    \ % 2 == 0) {\n        ++s;\n        d >>= 1;\n    }\n    for (auto a : A) {\n\
    \        if (a % N == 0) return true;\n        long long t, x = pow_mod<__int128_t>(a,\
    \ d, N);\n        if (x != 1) {\n            for (t = 0; t < s; ++t) {\n     \
    \           if (x == N - 1) break;\n                x = __int128_t(x) * x % N;\n\
    \            }\n            if (t == s) return false;\n        }\n    }\n    return\
    \ true;\n}\n"
  code: "template <class T>\nT pow_mod(T A, T N, T M) {\n    T res = 1 % M;\n    A\
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
    \ return false;\n        }\n    }\n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/miller-rabin.hpp
  requiredBy:
  - math/number/pollard-rho.hpp
  timestamp: '2023-01-08 12:37:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/factorize.test.cpp
  - test/AOJ/ALDS1_1_C-2.test.cpp
documentation_of: math/number/miller-rabin.hpp
layout: document
title: "\u78BA\u7387\u7684\u7D20\u6570\u5224\u5B9A (Miller-Rabin \u6CD5)"
---
