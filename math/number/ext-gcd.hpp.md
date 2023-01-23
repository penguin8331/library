---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/number/chinese-remainder-theorem.hpp
    title: math/number/chinese-remainder-theorem.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/ext-gcd.hpp\"\nlong long extGcd(long long a,\
    \ long long b, long long &p, long long &q) {\n    if (b == 0) { \n        p =\
    \ 1, q = 0; \n        return a; \n    }\n    long long d = extGcd(b, a % b, q,\
    \ p);\n    q -= a / b * p;\n    return d;\n}\n"
  code: "long long extGcd(long long a, long long b, long long &p, long long &q) {\n\
    \    if (b == 0) { \n        p = 1, q = 0; \n        return a; \n    }\n    long\
    \ long d = extGcd(b, a % b, q, p);\n    q -= a / b * p;\n    return d;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/ext-gcd.hpp
  requiredBy:
  - math/number/chinese-remainder-theorem.hpp
  timestamp: '2023-01-23 15:58:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/ext-gcd.hpp
layout: document
redirect_from:
- /library/math/number/ext-gcd.hpp
- /library/math/number/ext-gcd.hpp.html
title: math/number/ext-gcd.hpp
---
