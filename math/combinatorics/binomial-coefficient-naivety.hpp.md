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
    long long nCk(int n, int k) {\r\n    assert(n >= k && k >= 0);\r\n    chmin(k,\
    \ n - k);\r\n    long long res = 1;\r\n    for (int i = 1; i <= k; i++) {\r\n\
    \        res *= (n - k + i);\r\n        res /= i;\r\n    }\r\n    return res;\r\
    \n}\n"
  code: "long long nCk(int n, int k) {\r\n    assert(n >= k && k >= 0);\r\n    chmin(k,\
    \ n - k);\r\n    long long res = 1;\r\n    for (int i = 1; i <= k; i++) {\r\n\
    \        res *= (n - k + i);\r\n        res /= i;\r\n    }\r\n    return res;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/binomial-coefficient-naivety.hpp
  requiredBy: []
  timestamp: '2023-01-14 15:50:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combinatorics/binomial-coefficient-naivety.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570 (\u611A\u76F4\u8A08\u7B97)"
---
