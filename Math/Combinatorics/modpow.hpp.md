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
  bundledCode: "#line 1 \"Math/Combinatorics/modpow.hpp\"\nlong long modpow(long long\
    \ a, long long n, long long mod) {\n    long long res = 1;\n    while (n > 0)\
    \ {\n        if (n & 1) res = res * a % mod;\n        a = a * a % mod;\n     \
    \   n >>= 1;\n    }\n    return res;\n}\n"
  code: "long long modpow(long long a, long long n, long long mod) {\n    long long\
    \ res = 1;\n    while (n > 0) {\n        if (n & 1) res = res * a % mod;\n   \
    \     a = a * a % mod;\n        n >>= 1;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/modpow.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:11:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combinatorics/modpow.hpp
layout: document
redirect_from:
- /library/Math/Combinatorics/modpow.hpp
- /library/Math/Combinatorics/modpow.hpp.html
title: Math/Combinatorics/modpow.hpp
---
