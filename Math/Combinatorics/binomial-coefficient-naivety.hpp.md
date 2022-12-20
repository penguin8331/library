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
  bundledCode: "#line 1 \"Math/Combinatorics/binomial-coefficient-naivety.hpp\"\n\
    long long nCk(int n, int k) {\n    long long res = 1;\n    for (int i = 1; i <=\
    \ k; i++) {\n        res *= (n - k + i) / i;\n    }\n    return res;\n}\n"
  code: "long long nCk(int n, int k) {\n    long long res = 1;\n    for (int i = 1;\
    \ i <= k; i++) {\n        res *= (n - k + i) / i;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/binomial-coefficient-naivety.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combinatorics/binomial-coefficient-naivety.hpp
layout: document
redirect_from:
- /library/Math/Combinatorics/binomial-coefficient-naivety.hpp
- /library/Math/Combinatorics/binomial-coefficient-naivety.hpp.html
title: Math/Combinatorics/binomial-coefficient-naivety.hpp
---
