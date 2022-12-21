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
  bundledCode: "#line 1 \"math/number/n-to-dec.hpp\"\nstring A = \"01\";\r\nlong long\
    \ DectoN(string dec) {\r\n    int n = A.size();\r\n    long long ans = 0;\r\n\
    \    long long now = 1;\r\n    for (int i = dec.size() - 1; i >= 0; i--) {\r\n\
    \        ans += (long long)distance(A.begin(), find(A.begin(), A.end(), dec[i]))\
    \ * now;\r\n        now *= n;\r\n    }\r\n    return ans;\r\n}\n"
  code: "string A = \"01\";\r\nlong long DectoN(string dec) {\r\n    int n = A.size();\r\
    \n    long long ans = 0;\r\n    long long now = 1;\r\n    for (int i = dec.size()\
    \ - 1; i >= 0; i--) {\r\n        ans += (long long)distance(A.begin(), find(A.begin(),\
    \ A.end(), dec[i])) * now;\r\n        now *= n;\r\n    }\r\n    return ans;\r\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/number/n-to-dec.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/n-to-dec.hpp
layout: document
title: "N\u9032\u6CD5\u306E\u3082\u306E\u309210\u9032\u6CD5\u306B\u5909\u63DB"
---
