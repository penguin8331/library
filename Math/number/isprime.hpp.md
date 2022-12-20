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
  bundledCode: "#line 1 \"Math/number/isprime.hpp\"\nbool is_prime(long long n) {\n\
    \    if (n <= 1) return false;\n    for (long long p = 2; p * p <= n; ++p) {\n\
    \        if (n % p == 0) return false;\n    }\n    return true;\n}\n"
  code: "bool is_prime(long long n) {\n    if (n <= 1) return false;\n    for (long\
    \ long p = 2; p * p <= n; ++p) {\n        if (n % p == 0) return false;\n    }\n\
    \    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/isprime.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/isprime.hpp
layout: document
redirect_from:
- /library/Math/number/isprime.hpp
- /library/Math/number/isprime.hpp.html
title: Math/number/isprime.hpp
---
