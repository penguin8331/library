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
  bundledCode: "#line 1 \"algorithm/section-sum2d.hpp\"\ntemplate <class T>\r\nvector<vector<T>>\
    \ pre_process(vector<vector<T>> const &a) {\r\n    int H = (int)a.size();\r\n\
    \    int W = (int)a[0].size();\r\n    vector<vector<T>> res(H + 1, vector<T>(W\
    \ + 1));\r\n    for (int h = 1; h < H + 1; h++) {\r\n        for (int w = 1; w\
    \ < W + 1; w++) {\r\n            res[h][w] = a[h - 1][w - 1] + res[h][w - 1] +\
    \ res[h - 1][w] - res[h - 1][w - 1];\r\n        }\r\n    }\r\n    return res;\r\
    \n}\r\n// [h1,h2)\xD7[w1,w2) \u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\r\
    \ntemplate <class T>\r\nT query(int h1, int h2, int w1, int w2, vector<vector<T>>\
    \ const &S) {\r\n    return S[h2][w2] - S[h1][w2] - S[h2][w1] + S[h1][w1];\r\n\
    }\n"
  code: "template <class T>\r\nvector<vector<T>> pre_process(vector<vector<T>> const\
    \ &a) {\r\n    int H = (int)a.size();\r\n    int W = (int)a[0].size();\r\n   \
    \ vector<vector<T>> res(H + 1, vector<T>(W + 1));\r\n    for (int h = 1; h < H\
    \ + 1; h++) {\r\n        for (int w = 1; w < W + 1; w++) {\r\n            res[h][w]\
    \ = a[h - 1][w - 1] + res[h][w - 1] + res[h - 1][w] - res[h - 1][w - 1];\r\n \
    \       }\r\n    }\r\n    return res;\r\n}\r\n// [h1,h2)\xD7[w1,w2) \u306E\u533A\
    \u9593\u548C\u3092\u6C42\u3081\u308B\r\ntemplate <class T>\r\nT query(int h1,\
    \ int h2, int w1, int w2, vector<vector<T>> const &S) {\r\n    return S[h2][w2]\
    \ - S[h1][w2] - S[h2][w1] + S[h1][w1];\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/section-sum2d.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:01:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/section-sum2d.hpp
layout: document
redirect_from:
- /library/algorithm/section-sum2d.hpp
- /library/algorithm/section-sum2d.hpp.html
title: algorithm/section-sum2d.hpp
---
