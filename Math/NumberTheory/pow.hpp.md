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
  bundledCode: "#line 1 \"Math/NumberTheory/pow.hpp\"\nlong long mypow(long long a,\
    \ long long n) {\n    long long res = 1;\n    while (n > 0) {\n        if (n &\
    \ 1) res = res * a;\n        a = a * a;\n        n >>= 1;\n    }\n    return res;\n\
    }\n"
  code: "long long mypow(long long a, long long n) {\n    long long res = 1;\n   \
    \ while (n > 0) {\n        if (n & 1) res = res * a;\n        a = a * a;\n   \
    \     n >>= 1;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/pow.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:11:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/pow.hpp
layout: document
redirect_from:
- /library/Math/NumberTheory/pow.hpp
- /library/Math/NumberTheory/pow.hpp.html
title: Math/NumberTheory/pow.hpp
---
