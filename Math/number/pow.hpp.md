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
  bundledCode: "#line 1 \"Math/number/pow.hpp\"\nlong long mypow(long long a, long\
    \ long n) {\n    long long res = 1;\n    while (n > 0) {\n        if (n & 1) res\
    \ = res * a;\n        a = a * a;\n        n >>= 1;\n    }\n    return res;\n}\n"
  code: "long long mypow(long long a, long long n) {\n    long long res = 1;\n   \
    \ while (n > 0) {\n        if (n & 1) res = res * a;\n        a = a * a;\n   \
    \     n >>= 1;\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/pow.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/pow.hpp
layout: document
redirect_from:
- /library/Math/number/pow.hpp
- /library/Math/number/pow.hpp.html
title: Math/number/pow.hpp
---
