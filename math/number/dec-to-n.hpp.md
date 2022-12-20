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
  bundledCode: "#line 1 \"math/number/dec-to-n.hpp\"\nstring A = \"01\";\r\nstring\
    \ DectoN(long long dec) {\r\n    int n = A.size();\r\n    string ans;\r\n    while\
    \ (dec > 0) {\r\n        // A[0]\u304C1\u306A\u3089\u5165\u308C\u308B\r\n    \
    \    // dec--;\r\n        ans += A[(dec) % n];\r\n        dec = dec / n;\r\n \
    \   }\r\n    reverse(ans.begin(), ans.end());\r\n    return ans;\r\n}\n"
  code: "string A = \"01\";\r\nstring DectoN(long long dec) {\r\n    int n = A.size();\r\
    \n    string ans;\r\n    while (dec > 0) {\r\n        // A[0]\u304C1\u306A\u3089\
    \u5165\u308C\u308B\r\n        // dec--;\r\n        ans += A[(dec) % n];\r\n  \
    \      dec = dec / n;\r\n    }\r\n    reverse(ans.begin(), ans.end());\r\n   \
    \ return ans;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/dec-to-n.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/dec-to-n.hpp
layout: document
redirect_from:
- /library/math/number/dec-to-n.hpp
- /library/math/number/dec-to-n.hpp.html
title: math/number/dec-to-n.hpp
---
