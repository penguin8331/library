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
  bundledCode: "#line 1 \"algorithm/compress.hpp\"\ntemplate <typename T>\r\nvector<T>\
    \ compress(vector<T> &X) {\r\n    // \u30BD\u30FC\u30C8\u3057\u305F\u7D50\u679C\
    \u3092 vals \u306B\r\n    vector<T> vals = X;\r\n    sort(vals.begin(), vals.end());\r\
    \n    // \u96A3\u308A\u5408\u3046\u91CD\u8907\u3092\u524A\u9664(unique), \u672B\
    \u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664(erase)\r\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\r\n    // \u5404\u8981\u7D20\u3054\u3068\u306B\u4E8C\
    \u5206\u63A2\u7D22\u3067\u4F4D\u7F6E\u3092\u6C42\u3081\u308B\r\n    for (int i\
    \ = 0; i < (int)X.size(); i++) {\r\n        X[i] = lower_bound(vals.begin(), vals.end(),\
    \ X[i]) - vals.begin();\r\n    }\r\n    return vals;\r\n}\n"
  code: "template <typename T>\r\nvector<T> compress(vector<T> &X) {\r\n    // \u30BD\
    \u30FC\u30C8\u3057\u305F\u7D50\u679C\u3092 vals \u306B\r\n    vector<T> vals =\
    \ X;\r\n    sort(vals.begin(), vals.end());\r\n    // \u96A3\u308A\u5408\u3046\
    \u91CD\u8907\u3092\u524A\u9664(unique), \u672B\u7AEF\u306E\u30B4\u30DF\u3092\u524A\
    \u9664(erase)\r\n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\r\
    \n    // \u5404\u8981\u7D20\u3054\u3068\u306B\u4E8C\u5206\u63A2\u7D22\u3067\u4F4D\
    \u7F6E\u3092\u6C42\u3081\u308B\r\n    for (int i = 0; i < (int)X.size(); i++)\
    \ {\r\n        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();\r\
    \n    }\r\n    return vals;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/compress.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:01:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---
