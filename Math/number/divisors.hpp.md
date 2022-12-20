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
  bundledCode: "#line 1 \"Math/number/divisors.hpp\"\nvector<long long> divisors(long\
    \ long n) {\n    vector<long long> res;\n    for (long long i = 1LL; i * i <=\
    \ n; ++i) {\n        if (n % i == 0) {\n            res.push_back(i);\n      \
    \      long long j = n / i;\n            if (j != i) res.push_back(j);\n     \
    \   }\n    }\n    sort(res.begin(), res.end());\n    return res;\n}\n"
  code: "vector<long long> divisors(long long n) {\n    vector<long long> res;\n \
    \   for (long long i = 1LL; i * i <= n; ++i) {\n        if (n % i == 0) {\n  \
    \          res.push_back(i);\n            long long j = n / i;\n            if\
    \ (j != i) res.push_back(j);\n        }\n    }\n    sort(res.begin(), res.end());\n\
    \    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/divisors.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/divisors.hpp
layout: document
redirect_from:
- /library/Math/number/divisors.hpp
- /library/Math/number/divisors.hpp.html
title: Math/number/divisors.hpp
---
