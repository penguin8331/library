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
  bundledCode: "#line 1 \"math/number/randInt.hpp\"\nunsigned int randInt() {\r\n\
    \    static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw =\
    \ 88675123;\r\n    unsigned int tt = (tx ^ (tx << 11));\r\n    tx = ty;\r\n  \
    \  ty = tz;\r\n    tz = tw;\r\n    return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt\
    \ >> 8)));\r\n}\n"
  code: "unsigned int randInt() {\r\n    static unsigned int tx = 123456789, ty =\
    \ 362436069, tz = 521288629, tw = 88675123;\r\n    unsigned int tt = (tx ^ (tx\
    \ << 11));\r\n    tx = ty;\r\n    ty = tz;\r\n    tz = tw;\r\n    return (tw =\
    \ (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/randInt.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/randInt.hpp
layout: document
redirect_from:
- /library/math/number/randInt.hpp
- /library/math/number/randInt.hpp.html
title: math/number/randInt.hpp
---
