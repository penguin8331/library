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
  bundledCode: "#line 1 \"Math/Combinatorics/next-combination.hpp\"\nint next_combination(int\
    \ sub) {\n    int x = sub & -sub, y = sub + x;\n    return (((sub & ~y) / x) >>\
    \ 1) | y;\n}\n"
  code: "int next_combination(int sub) {\n    int x = sub & -sub, y = sub + x;\n \
    \   return (((sub & ~y) / x) >> 1) | y;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/next-combination.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combinatorics/next-combination.hpp
layout: document
redirect_from:
- /library/Math/Combinatorics/next-combination.hpp
- /library/Math/Combinatorics/next-combination.hpp.html
title: Math/Combinatorics/next-combination.hpp
---
