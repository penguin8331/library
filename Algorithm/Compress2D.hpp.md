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
  bundledCode: "#line 1 \"Algorithm/Compress2D.hpp\"\ntemplate <typename T>\nvector<T>\
    \ compress(vector<T> &C1, vector<T> &C2) {\n    vector<T> vals;\n    int N = (int)C1.size();\n\
    \    for (int i = 0; i < N; i++) {\n        for (T d = 0; d < 1; d++) {  // \u305D\
    \u306E\u4F4D\u7F6E\u3068\u3001\u4E00\u3064\u96A3\u3092\u78BA\u4FDD(\u96A3\u3092\
    \u78BA\u4FDD\u3057\u306A\u3044\u3068\u7A7A\u767D\u304C\u57CB\u307E\u3063\u3066\
    \u3057\u307E\u3046\u3053\u3068\u304C\u3042\u308B)\n            T tc1 = C1[i] +\
    \ d;\n            T tc2 = C2[i] + d;\n            vals.push_back(tc1);\n     \
    \       vals.push_back(tc2);\n        }\n    }\n    // \u30BD\u30FC\u30C8\n  \
    \  sort(vals.begin(), vals.end());\n    // \u96A3\u308A\u5408\u3046\u91CD\u8907\
    \u3092\u524A\u9664(unique), \u672B\u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664(erase)\n\
    \    vals.erase(unique(vals.begin(), vals.end()), vals.end());\n    for (int i\
    \ = 0; i < N; i++) {\n        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i])\
    \ - vals.begin();\n        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i])\
    \ - vals.begin();\n    }\n    return vals;\n}\n"
  code: "template <typename T>\nvector<T> compress(vector<T> &C1, vector<T> &C2) {\n\
    \    vector<T> vals;\n    int N = (int)C1.size();\n    for (int i = 0; i < N;\
    \ i++) {\n        for (T d = 0; d < 1; d++) {  // \u305D\u306E\u4F4D\u7F6E\u3068\
    \u3001\u4E00\u3064\u96A3\u3092\u78BA\u4FDD(\u96A3\u3092\u78BA\u4FDD\u3057\u306A\
    \u3044\u3068\u7A7A\u767D\u304C\u57CB\u307E\u3063\u3066\u3057\u307E\u3046\u3053\
    \u3068\u304C\u3042\u308B)\n            T tc1 = C1[i] + d;\n            T tc2 =\
    \ C2[i] + d;\n            vals.push_back(tc1);\n            vals.push_back(tc2);\n\
    \        }\n    }\n    // \u30BD\u30FC\u30C8\n    sort(vals.begin(), vals.end());\n\
    \    // \u96A3\u308A\u5408\u3046\u91CD\u8907\u3092\u524A\u9664(unique), \u672B\
    \u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664(erase)\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\n    for (int i = 0; i < N; i++) {\n        C1[i]\
    \ = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();\n        C2[i]\
    \ = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();\n    }\n    return\
    \ vals;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/Compress2D.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/Compress2D.hpp
layout: document
redirect_from:
- /library/Algorithm/Compress2D.hpp
- /library/Algorithm/Compress2D.hpp.html
title: Algorithm/Compress2D.hpp
---
