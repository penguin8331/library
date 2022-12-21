---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_1_C.test.cpp
    title: test/AOJ/ALDS1_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/isprime.hpp\"\nbool is_prime(long long n) {\r\
    \n    if (n <= 1) return false;\r\n    for (long long p = 2; p * p <= n; ++p)\
    \ {\r\n        if (n % p == 0) return false;\r\n    }\r\n    return true;\r\n\
    }\n"
  code: "bool is_prime(long long n) {\r\n    if (n <= 1) return false;\r\n    for\
    \ (long long p = 2; p * p <= n; ++p) {\r\n        if (n % p == 0) return false;\r\
    \n    }\r\n    return true;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/isprime.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_1_C.test.cpp
documentation_of: math/number/isprime.hpp
layout: document
title: "\u7D20\u6570\u5224\u5B9A\u6CD5"
---
