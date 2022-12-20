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
  bundledCode: "#line 1 \"Math/number/prime-factorization.hpp\"\nvector<pair<long\
    \ long, long long> > prime_factorize(long long n) {\n    vector<pair<long long,\
    \ long long> > res;\n    for (long long p = 2; p * p <= n; ++p) {\n        if\
    \ (n % p != 0) continue;\n        int num = 0;\n        while (n % p == 0) {\n\
    \            ++num;\n            n /= p;\n        }\n        res.push_back(make_pair(p,\
    \ num));\n    }\n    if (n != 1) res.push_back(make_pair(n, 1));\n    return res;\n\
    }\n"
  code: "vector<pair<long long, long long> > prime_factorize(long long n) {\n    vector<pair<long\
    \ long, long long> > res;\n    for (long long p = 2; p * p <= n; ++p) {\n    \
    \    if (n % p != 0) continue;\n        int num = 0;\n        while (n % p ==\
    \ 0) {\n            ++num;\n            n /= p;\n        }\n        res.push_back(make_pair(p,\
    \ num));\n    }\n    if (n != 1) res.push_back(make_pair(n, 1));\n    return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/prime-factorization.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/prime-factorization.hpp
layout: document
redirect_from:
- /library/Math/number/prime-factorization.hpp
- /library/Math/number/prime-factorization.hpp.html
title: Math/number/prime-factorization.hpp
---
