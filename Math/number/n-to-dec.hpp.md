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
  bundledCode: "#line 1 \"Math/number/n-to-dec.hpp\"\nstring A = \"01\";\nlong long\
    \ DectoN(string dec) {\n    int n = A.size();\n    long long ans = 0;\n    long\
    \ long now = 1;\n    for (int i = dec.size() - 1; i >= 0; i--) {\n        ans\
    \ += (long long)distance(A.begin(), find(A.begin(), A.end(), dec[i])) * now;\n\
    \        now *= n;\n    }\n    return ans;\n}\n"
  code: "string A = \"01\";\nlong long DectoN(string dec) {\n    int n = A.size();\n\
    \    long long ans = 0;\n    long long now = 1;\n    for (int i = dec.size() -\
    \ 1; i >= 0; i--) {\n        ans += (long long)distance(A.begin(), find(A.begin(),\
    \ A.end(), dec[i])) * now;\n        now *= n;\n    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/number/n-to-dec.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/number/n-to-dec.hpp
layout: document
redirect_from:
- /library/Math/number/n-to-dec.hpp
- /library/Math/number/n-to-dec.hpp.html
title: Math/number/n-to-dec.hpp
---
