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
  bundledCode: "#line 1 \"Math/number/randInt.hpp\"\nunsigned int randInt() {\n  \
    \  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;\n\
    \    unsigned int tt = (tx ^ (tx << 11));\n    tx = ty;\n    ty = tz;\n    tz\
    \ = tw;\n    return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));\n}\n"
  code: "unsigned int randInt() {\n    static unsigned int tx = 123456789, ty = 362436069,\
    \ tz = 521288629, tw = 88675123;\n    unsigned int tt = (tx ^ (tx << 11));\n \
    \   tx = ty;\n    ty = tz;\n    tz = tw;\n    return (tw = (tw ^ (tw >> 19)) ^\
    \ (tt ^ (tt >> 8)));\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/randInt.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/randInt.hpp
layout: document
redirect_from:
- /library/Math/number/randInt.hpp
- /library/Math/number/randInt.hpp.html
title: Math/number/randInt.hpp
---
