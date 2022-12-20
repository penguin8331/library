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
  bundledCode: "#line 1 \"Algorithm/SectionSum.hpp\"\ntemplate <class T>\nvector<T>\
    \ pre_process(vector<T> const &a) {\n    int n = (int)a.size();\n    vector<T>\
    \ res(n + 1);\n    for (int i = 0; i < n; i++) {\n        res[i + 1] = res[i]\
    \ + a[i];\n    }\n    return res;\n}\n\n// [i,j) \u306E\u533A\u9593\u548C\u3092\
    \u6C42\u3081\u308B\ntemplate <class T>\nT query(int i, int j, vector<T> const\
    \ &S) {\n    return S[j] - S[i];\n}\n"
  code: "template <class T>\nvector<T> pre_process(vector<T> const &a) {\n    int\
    \ n = (int)a.size();\n    vector<T> res(n + 1);\n    for (int i = 0; i < n; i++)\
    \ {\n        res[i + 1] = res[i] + a[i];\n    }\n    return res;\n}\n\n// [i,j)\
    \ \u306E\u533A\u9593\u548C\u3092\u6C42\u3081\u308B\ntemplate <class T>\nT query(int\
    \ i, int j, vector<T> const &S) {\n    return S[j] - S[i];\n}"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/SectionSum.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/SectionSum.hpp
layout: document
redirect_from:
- /library/Algorithm/SectionSum.hpp
- /library/Algorithm/SectionSum.hpp.html
title: Algorithm/SectionSum.hpp
---
