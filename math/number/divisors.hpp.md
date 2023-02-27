---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ITP1_3_D.test.cpp
    title: test/AOJ/ITP1_3_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/divisors.hpp\"\nvector<long long> divisors(long\
    \ long n) {\r\n    vector<long long> res;\r\n    for (long long i = 1LL; i * i\
    \ <= n; ++i) {\r\n        if (n % i == 0) {\r\n            res.push_back(i);\r\
    \n            long long j = n / i;\r\n            if (j != i) res.push_back(j);\r\
    \n        }\r\n    }\r\n    sort(res.begin(), res.end());\r\n    return res;\r\
    \n}\n"
  code: "vector<long long> divisors(long long n) {\r\n    vector<long long> res;\r\
    \n    for (long long i = 1LL; i * i <= n; ++i) {\r\n        if (n % i == 0) {\r\
    \n            res.push_back(i);\r\n            long long j = n / i;\r\n      \
    \      if (j != i) res.push_back(j);\r\n        }\r\n    }\r\n    sort(res.begin(),\
    \ res.end());\r\n    return res;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/divisors.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ITP1_3_D.test.cpp
documentation_of: math/number/divisors.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---
