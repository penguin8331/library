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
  bundledCode: "#line 1 \"math/combinatorics/modpow.hpp\"\nlong long modpow(long long\
    \ a, long long n, long long mod) {\r\n    long long res = 1;\r\n    while (n >\
    \ 0) {\r\n        if (n & 1) res = res * a % mod;\r\n        a = a * a % mod;\r\
    \n        n >>= 1;\r\n    }\r\n    return res;\r\n}\n"
  code: "long long modpow(long long a, long long n, long long mod) {\r\n    long long\
    \ res = 1;\r\n    while (n > 0) {\r\n        if (n & 1) res = res * a % mod;\r\
    \n        a = a * a % mod;\r\n        n >>= 1;\r\n    }\r\n    return res;\r\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/modpow.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combinatorics/modpow.hpp
layout: document
redirect_from:
- /library/math/combinatorics/modpow.hpp
- /library/math/combinatorics/modpow.hpp.html
title: math/combinatorics/modpow.hpp
---
