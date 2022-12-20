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
  bundledCode: "#line 1 \"Math/NumberTheory/Dvisors.hpp\"\nvector<long long> divisors(long\
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
  path: Math/NumberTheory/Dvisors.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:11:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/Dvisors.hpp
layout: document
redirect_from:
- /library/Math/NumberTheory/Dvisors.hpp
- /library/Math/NumberTheory/Dvisors.hpp.html
title: Math/NumberTheory/Dvisors.hpp
---
