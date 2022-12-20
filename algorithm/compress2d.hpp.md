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
  bundledCode: "#line 1 \"algorithm/compress2d.hpp\"\ntemplate <typename T>\r\nvector<T>\
    \ compress(vector<T> &C1, vector<T> &C2) {\r\n    vector<T> vals;\r\n    int N\
    \ = (int)C1.size();\r\n    for (int i = 0; i < N; i++) {\r\n        for (T d =\
    \ 0; d < 1; d++) {  // \u305D\u306E\u4F4D\u7F6E\u3068\u3001\u4E00\u3064\u96A3\u3092\
    \u78BA\u4FDD(\u96A3\u3092\u78BA\u4FDD\u3057\u306A\u3044\u3068\u7A7A\u767D\u304C\
    \u57CB\u307E\u3063\u3066\u3057\u307E\u3046\u3053\u3068\u304C\u3042\u308B)\r\n\
    \            T tc1 = C1[i] + d;\r\n            T tc2 = C2[i] + d;\r\n        \
    \    vals.push_back(tc1);\r\n            vals.push_back(tc2);\r\n        }\r\n\
    \    }\r\n    // \u30BD\u30FC\u30C8\r\n    sort(vals.begin(), vals.end());\r\n\
    \    // \u96A3\u308A\u5408\u3046\u91CD\u8907\u3092\u524A\u9664(unique), \u672B\
    \u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664(erase)\r\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\r\n    for (int i = 0; i < N; i++) {\r\n        C1[i]\
    \ = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();\r\n        C2[i]\
    \ = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();\r\n    }\r\n\
    \    return vals;\r\n}\n"
  code: "template <typename T>\r\nvector<T> compress(vector<T> &C1, vector<T> &C2)\
    \ {\r\n    vector<T> vals;\r\n    int N = (int)C1.size();\r\n    for (int i =\
    \ 0; i < N; i++) {\r\n        for (T d = 0; d < 1; d++) {  // \u305D\u306E\u4F4D\
    \u7F6E\u3068\u3001\u4E00\u3064\u96A3\u3092\u78BA\u4FDD(\u96A3\u3092\u78BA\u4FDD\
    \u3057\u306A\u3044\u3068\u7A7A\u767D\u304C\u57CB\u307E\u3063\u3066\u3057\u307E\
    \u3046\u3053\u3068\u304C\u3042\u308B)\r\n            T tc1 = C1[i] + d;\r\n  \
    \          T tc2 = C2[i] + d;\r\n            vals.push_back(tc1);\r\n        \
    \    vals.push_back(tc2);\r\n        }\r\n    }\r\n    // \u30BD\u30FC\u30C8\r\
    \n    sort(vals.begin(), vals.end());\r\n    // \u96A3\u308A\u5408\u3046\u91CD\
    \u8907\u3092\u524A\u9664(unique), \u672B\u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664\
    (erase)\r\n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\r\n \
    \   for (int i = 0; i < N; i++) {\r\n        C1[i] = lower_bound(vals.begin(),\
    \ vals.end(), C1[i]) - vals.begin();\r\n        C2[i] = lower_bound(vals.begin(),\
    \ vals.end(), C2[i]) - vals.begin();\r\n    }\r\n    return vals;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/compress2d.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:01:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress2d.hpp
layout: document
redirect_from:
- /library/algorithm/compress2d.hpp
- /library/algorithm/compress2d.hpp.html
title: algorithm/compress2d.hpp
---
