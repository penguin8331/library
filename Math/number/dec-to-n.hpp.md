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
  bundledCode: "#line 1 \"Math/number/dec-to-n.hpp\"\nstring A = \"01\";\nstring DectoN(long\
    \ long dec) {\n    int n = A.size();\n    string ans;\n    while (dec > 0) {\n\
    \        // A[0]\u304C1\u306A\u3089\u5165\u308C\u308B\n        // dec--;\n   \
    \     ans += A[(dec) % n];\n        dec = dec / n;\n    }\n    reverse(ans.begin(),\
    \ ans.end());\n    return ans;\n}\n"
  code: "string A = \"01\";\nstring DectoN(long long dec) {\n    int n = A.size();\n\
    \    string ans;\n    while (dec > 0) {\n        // A[0]\u304C1\u306A\u3089\u5165\
    \u308C\u308B\n        // dec--;\n        ans += A[(dec) % n];\n        dec = dec\
    \ / n;\n    }\n    reverse(ans.begin(), ans.end());\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/dec-to-n.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/dec-to-n.hpp
layout: document
redirect_from:
- /library/Math/number/dec-to-n.hpp
- /library/Math/number/dec-to-n.hpp.html
title: Math/number/dec-to-n.hpp
---
