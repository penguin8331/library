---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/NTL_1_A.test.cpp
    title: test/AOJ/NTL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/NTL_1_A.test.cpp
documentation_of: math/number/prime-factorization.hpp
layout: document
redirect_from:
- /library/math/number/prime-factorization.hpp
- /library/math/number/prime-factorization.hpp.html
title: math/number/prime-factorization.hpp
---
