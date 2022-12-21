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
  bundledCode: "#line 1 \"string/rle.hpp\"\nvector<pair<char, int>> rle(string s)\
    \ {\r\n    vector<pair<char, int>> ret;\r\n    int cnt = 1;\r\n    for (int i\
    \ = 1; i < (int)s.size(); i++) {\r\n        if (s[i] != s[i - 1]) {\r\n      \
    \      ret.push_back({s[i - 1], cnt});\r\n            cnt = 0;\r\n        }\r\n\
    \        cnt++;\r\n    }\r\n    ret.push_back({s.back(), cnt});\r\n    return\
    \ ret;\r\n}\n"
  code: "vector<pair<char, int>> rle(string s) {\r\n    vector<pair<char, int>> ret;\r\
    \n    int cnt = 1;\r\n    for (int i = 1; i < (int)s.size(); i++) {\r\n      \
    \  if (s[i] != s[i - 1]) {\r\n            ret.push_back({s[i - 1], cnt});\r\n\
    \            cnt = 0;\r\n        }\r\n        cnt++;\r\n    }\r\n    ret.push_back({s.back(),\
    \ cnt});\r\n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/rle.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:03:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rle.hpp
layout: document
title: "\u9023\u9577\u5727\u7E2E"
---
