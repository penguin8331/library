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
  bundledCode: "#line 1 \"Math/Combinatorics/next_combination.hpp\"\nint next_combination(int\
    \ sub) {\n    int x = sub & -sub, y = sub + x;\n    return (((sub & ~y) / x) >>\
    \ 1) | y;\n}\n"
  code: "int next_combination(int sub) {\n    int x = sub & -sub, y = sub + x;\n \
    \   return (((sub & ~y) / x) >> 1) | y;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/next_combination.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:11:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combinatorics/next_combination.hpp
layout: document
redirect_from:
- /library/Math/Combinatorics/next_combination.hpp
- /library/Math/Combinatorics/next_combination.hpp.html
title: Math/Combinatorics/next_combination.hpp
---
