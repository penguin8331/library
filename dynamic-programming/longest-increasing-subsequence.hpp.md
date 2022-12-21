---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DPL_1_d.test.cpp
    title: test/AOJ/DPL_1_d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dynamic-programming/longest-increasing-subsequence.hpp\"\
    \ntemplate <class T>\nint LIS(vector<T> a, bool is_strong = true) {\n    int n\
    \ = (int)a.size();\n    vector<T> dp;\n    for (int i = 0; i < n; ++i) {\n   \
    \     auto it = (is_strong ? lower_bound(dp.begin(), dp.end(), a[i]) : upper_bound(dp.begin(),\
    \ dp.end(), a[i]));\n        if (it == dp.end())\n            dp.push_back(a[i]);\n\
    \        else\n            *it = a[i];\n    }\n    return dp.size();\n}\n"
  code: "template <class T>\nint LIS(vector<T> a, bool is_strong = true) {\n    int\
    \ n = (int)a.size();\n    vector<T> dp;\n    for (int i = 0; i < n; ++i) {\n \
    \       auto it = (is_strong ? lower_bound(dp.begin(), dp.end(), a[i]) : upper_bound(dp.begin(),\
    \ dp.end(), a[i]));\n        if (it == dp.end())\n            dp.push_back(a[i]);\n\
    \        else\n            *it = a[i];\n    }\n    return dp.size();\n}"
  dependsOn: []
  isVerificationFile: false
  path: dynamic-programming/longest-increasing-subsequence.hpp
  requiredBy: []
  timestamp: '2022-12-21 12:17:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DPL_1_d.test.cpp
documentation_of: dynamic-programming/longest-increasing-subsequence.hpp
layout: document
redirect_from:
- /library/dynamic-programming/longest-increasing-subsequence.hpp
- /library/dynamic-programming/longest-increasing-subsequence.hpp.html
title: dynamic-programming/longest-increasing-subsequence.hpp
---
