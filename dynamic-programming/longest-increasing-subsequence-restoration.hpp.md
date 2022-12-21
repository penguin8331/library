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
  bundledCode: "#line 1 \"dynamic-programming/longest-increasing-subsequence-restoration.hpp\"\
    \ntemplate <class T>\nvector<T> LISRestoration(vector<T> a, bool is_strong = true)\
    \ {\n    int n = (int)a.size();\n    vector<T> dp;\n    vector<int> positions;\n\
    \    for (int i = 0; i < n; ++i) {\n        auto it = (is_strong ? lower_bound(dp.begin(),\
    \ dp.end(), a[i]) : upper_bound(dp.begin(), dp.end(), a[i]));\n        positions.push_back(distance(dp.begin(),\
    \ it));\n        if (it == dp.end())\n            dp.push_back(a[i]);\n      \
    \  else\n            *it = a[i];\n    }\n    vector<T> subseq(dp.size());\n  \
    \  int si = ((int)subseq.size()) - 1;\n    int pi = ((int)positions.size()) -\
    \ 1;\n    while ((0 <= si) && (0 <= pi)) {\n        if (positions[pi] == si) {\n\
    \            subseq[si] = pi;\n            --si;\n        }\n        --pi;\n \
    \   }\n    return subseq;\n}\n"
  code: "template <class T>\nvector<T> LISRestoration(vector<T> a, bool is_strong\
    \ = true) {\n    int n = (int)a.size();\n    vector<T> dp;\n    vector<int> positions;\n\
    \    for (int i = 0; i < n; ++i) {\n        auto it = (is_strong ? lower_bound(dp.begin(),\
    \ dp.end(), a[i]) : upper_bound(dp.begin(), dp.end(), a[i]));\n        positions.push_back(distance(dp.begin(),\
    \ it));\n        if (it == dp.end())\n            dp.push_back(a[i]);\n      \
    \  else\n            *it = a[i];\n    }\n    vector<T> subseq(dp.size());\n  \
    \  int si = ((int)subseq.size()) - 1;\n    int pi = ((int)positions.size()) -\
    \ 1;\n    while ((0 <= si) && (0 <= pi)) {\n        if (positions[pi] == si) {\n\
    \            subseq[si] = pi;\n            --si;\n        }\n        --pi;\n \
    \   }\n    return subseq;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dynamic-programming/longest-increasing-subsequence-restoration.hpp
  requiredBy: []
  timestamp: '2022-12-21 12:17:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dynamic-programming/longest-increasing-subsequence-restoration.hpp
layout: document
redirect_from:
- /library/dynamic-programming/longest-increasing-subsequence-restoration.hpp
- /library/dynamic-programming/longest-increasing-subsequence-restoration.hpp.html
title: dynamic-programming/longest-increasing-subsequence-restoration.hpp
---
