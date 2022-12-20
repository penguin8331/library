---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/isprime.hpp
layout: document
redirect_from:
- /library/math/number/isprime.hpp
- /library/math/number/isprime.hpp.html
title: math/number/isprime.hpp
---
