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
  bundledCode: "#line 1 \"Algorithm/section-sum.hpp\"\ntemplate <class T>\nstruct\
    \ sectionsum {\n    vector<T> data;\n\n    sectionsum(int n) : data(n + 1, 0)\
    \ {}\n\n    void update(int k, const T& x) {\n        data[k + 1] = x;\n    }\n\
    \n    void build() {\n        for (int i = 1; i < (int)data.size(); i++) {\n \
    \           data[i] += data[i - 1];\n        }\n    }\n\n    T get(int r) const\
    \ {\n        if (r < 0) return 0;\n        return data[min(r, (int)data.size()\
    \ - 1)];\n    }\n    T get(int l, int r) const {\n        return get(r) - get(l);\n\
    \    }\n};\n"
  code: "template <class T>\nstruct sectionsum {\n    vector<T> data;\n\n    sectionsum(int\
    \ n) : data(n + 1, 0) {}\n\n    void update(int k, const T& x) {\n        data[k\
    \ + 1] = x;\n    }\n\n    void build() {\n        for (int i = 1; i < (int)data.size();\
    \ i++) {\n            data[i] += data[i - 1];\n        }\n    }\n\n    T get(int\
    \ r) const {\n        if (r < 0) return 0;\n        return data[min(r, (int)data.size()\
    \ - 1)];\n    }\n    T get(int l, int r) const {\n        return get(r) - get(l);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: Algorithm/section-sum.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithm/section-sum.hpp
layout: document
redirect_from:
- /library/Algorithm/section-sum.hpp
- /library/Algorithm/section-sum.hpp.html
title: Algorithm/section-sum.hpp
---
