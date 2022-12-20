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
  bundledCode: "#line 1 \"Math/NumberTheory/Primenumber Enumeration.hpp\"\nvector<int>\
    \ Era(int n) {\n    vector<bool> isprime(n, true);\n    vector<int> res;\n   \
    \ isprime[0] = false;\n    isprime[1] = false;\n    for (int i = 2; i < n; ++i)\
    \ isprime[i] = true;\n    for (int i = 2; i < n; ++i) {\n        if (isprime[i])\
    \ {\n            res.push_back(i);\n            for (int j = i * 2; j < n; j +=\
    \ i) isprime[j] = false;\n        }\n    }\n    return res;\n}\n"
  code: "vector<int> Era(int n) {\n    vector<bool> isprime(n, true);\n    vector<int>\
    \ res;\n    isprime[0] = false;\n    isprime[1] = false;\n    for (int i = 2;\
    \ i < n; ++i) isprime[i] = true;\n    for (int i = 2; i < n; ++i) {\n        if\
    \ (isprime[i]) {\n            res.push_back(i);\n            for (int j = i *\
    \ 2; j < n; j += i) isprime[j] = false;\n        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/NumberTheory/Primenumber Enumeration.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:11:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/NumberTheory/Primenumber Enumeration.hpp
layout: document
redirect_from:
- /library/Math/NumberTheory/Primenumber Enumeration.hpp
- /library/Math/NumberTheory/Primenumber Enumeration.hpp.html
title: Math/NumberTheory/Primenumber Enumeration.hpp
---
