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
  bundledCode: "#line 1 \"math/number/pow.hpp\"\nlong long mypow(long long a, long\
    \ long n) {\r\n    long long res = 1;\r\n    while (n > 0) {\r\n        if (n\
    \ & 1) res = res * a;\r\n        a = a * a;\r\n        n >>= 1;\r\n    }\r\n \
    \   return res;\r\n}\n"
  code: "long long mypow(long long a, long long n) {\r\n    long long res = 1;\r\n\
    \    while (n > 0) {\r\n        if (n & 1) res = res * a;\r\n        a = a * a;\r\
    \n        n >>= 1;\r\n    }\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/pow.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/pow.hpp
layout: document
redirect_from:
- /library/math/number/pow.hpp
- /library/math/number/pow.hpp.html
title: math/number/pow.hpp
---
