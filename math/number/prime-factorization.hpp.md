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
  bundledCode: "#line 1 \"math/number/prime-factorization.hpp\"\nvector<pair<long\
    \ long, long long> > prime_factorize(long long n) {\r\n    vector<pair<long long,\
    \ long long> > res;\r\n    for (long long p = 2; p * p <= n; ++p) {\r\n      \
    \  if (n % p != 0) continue;\r\n        int num = 0;\r\n        while (n % p ==\
    \ 0) {\r\n            ++num;\r\n            n /= p;\r\n        }\r\n        res.push_back(make_pair(p,\
    \ num));\r\n    }\r\n    if (n != 1) res.push_back(make_pair(n, 1));\r\n    return\
    \ res;\r\n}\n"
  code: "vector<pair<long long, long long> > prime_factorize(long long n) {\r\n  \
    \  vector<pair<long long, long long> > res;\r\n    for (long long p = 2; p * p\
    \ <= n; ++p) {\r\n        if (n % p != 0) continue;\r\n        int num = 0;\r\n\
    \        while (n % p == 0) {\r\n            ++num;\r\n            n /= p;\r\n\
    \        }\r\n        res.push_back(make_pair(p, num));\r\n    }\r\n    if (n\
    \ != 1) res.push_back(make_pair(n, 1));\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/prime-factorization.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/prime-factorization.hpp
layout: document
redirect_from:
- /library/math/number/prime-factorization.hpp
- /library/math/number/prime-factorization.hpp.html
title: math/number/prime-factorization.hpp
---
