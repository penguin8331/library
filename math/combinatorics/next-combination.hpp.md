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
  bundledCode: "#line 1 \"math/combinatorics/next-combination.hpp\"\nint next_combination(int\
    \ sub) {\r\n    int x = sub & -sub, y = sub + x;\r\n    return (((sub & ~y) /\
    \ x) >> 1) | y;\r\n}\n"
  code: "int next_combination(int sub) {\r\n    int x = sub & -sub, y = sub + x;\r\
    \n    return (((sub & ~y) / x) >> 1) | y;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/next-combination.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combinatorics/next-combination.hpp
layout: document
title: next_combination
---
