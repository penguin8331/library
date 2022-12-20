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
  bundledCode: "#line 1 \"Algorithm/SectionSum2D.hpp\"\ntemplate <class T>\nvector<vector<T>>\
    \ pre_process(vector<vector<T>> const &a) {\n    int H = (int)a.size();\n    int\
    \ W = (int)a[0].size();\n    vector<vector<T>> res(H + 1, vector<T>(W + 1));\n\
    \    for (int h = 1; h < H + 1; h++) {\n        for (int w = 1; w < W + 1; w++)\
    \ {\n            res[h][w] = a[h - 1][w - 1] + res[h][w - 1] + res[h - 1][w] -\
    \ res[h - 1][w - 1];\n        }\n    }\n    return res;\n}\n// [h1,h2)\xD7[w1,w2)\
    \ \u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\ntemplate <class T>\nT query(int\
    \ h1, int h2, int w1, int w2, vector<vector<T>> const &S) {\n    return S[h2][w2]\
    \ - S[h1][w2] - S[h2][w1] + S[h1][w1];\n}\n"
  code: "template <class T>\nvector<vector<T>> pre_process(vector<vector<T>> const\
    \ &a) {\n    int H = (int)a.size();\n    int W = (int)a[0].size();\n    vector<vector<T>>\
    \ res(H + 1, vector<T>(W + 1));\n    for (int h = 1; h < H + 1; h++) {\n     \
    \   for (int w = 1; w < W + 1; w++) {\n            res[h][w] = a[h - 1][w - 1]\
    \ + res[h][w - 1] + res[h - 1][w] - res[h - 1][w - 1];\n        }\n    }\n   \
    \ return res;\n}\n// [h1,h2)\xD7[w1,w2) \u306E\u533A\u9593\u548C\u3092\u6C42\u3081\
    \u308B\ntemplate <class T>\nT query(int h1, int h2, int w1, int w2, vector<vector<T>>\
    \ const &S) {\n    return S[h2][w2] - S[h1][w2] - S[h2][w1] + S[h1][w1];\n}"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/SectionSum2D.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/SectionSum2D.hpp
layout: document
redirect_from:
- /library/Algorithm/SectionSum2D.hpp
- /library/Algorithm/SectionSum2D.hpp.html
title: Algorithm/SectionSum2D.hpp
---
