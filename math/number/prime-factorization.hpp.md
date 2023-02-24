---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/NTL_1_A.test.cpp
    title: test/AOJ/NTL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/prime-factorization.hpp\"\nmap<long long, int>\
    \ prime_factorize(long long n) {\r\n    map<long long, int> res;\r\n    for (long\
    \ long p = 2; p * p <= n; ++p) {\r\n        if (n % p != 0) continue;\r\n    \
    \    int num = 0;\r\n        while (n % p == 0) {\r\n            ++num;\r\n  \
    \          n /= p;\r\n        }\r\n        res[p] = num;\r\n    }\r\n    if (n\
    \ != 1) res[n] = 1;\r\n    return res;\r\n}\n"
  code: "map<long long, int> prime_factorize(long long n) {\r\n    map<long long,\
    \ int> res;\r\n    for (long long p = 2; p * p <= n; ++p) {\r\n        if (n %\
    \ p != 0) continue;\r\n        int num = 0;\r\n        while (n % p == 0) {\r\n\
    \            ++num;\r\n            n /= p;\r\n        }\r\n        res[p] = num;\r\
    \n    }\r\n    if (n != 1) res[n] = 1;\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/prime-factorization.hpp
  requiredBy: []
  timestamp: '2022-12-21 11:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/NTL_1_A.test.cpp
documentation_of: math/number/prime-factorization.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---
