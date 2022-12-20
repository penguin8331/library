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
  bundledCode: "#line 1 \"math/combinatorics/binomial-coefficient-naivety.hpp\"\n\
    long long nCk(int n, int k) {\r\n    long long res = 1;\r\n    for (int i = 1;\
    \ i <= k; i++) {\r\n        res *= (n - k + i) / i;\r\n    }\r\n    return res;\r\
    \n}\n"
  code: "long long nCk(int n, int k) {\r\n    long long res = 1;\r\n    for (int i\
    \ = 1; i <= k; i++) {\r\n        res *= (n - k + i) / i;\r\n    }\r\n    return\
    \ res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/binomial-coefficient-naivety.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combinatorics/binomial-coefficient-naivety.hpp
layout: document
redirect_from:
- /library/math/combinatorics/binomial-coefficient-naivety.hpp
- /library/math/combinatorics/binomial-coefficient-naivety.hpp.html
title: math/combinatorics/binomial-coefficient-naivety.hpp
---