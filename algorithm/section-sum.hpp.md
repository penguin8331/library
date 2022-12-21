---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static-range-sum.test.cpp
    title: test/yosupo/static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/section-sum.hpp\"\ntemplate <class T>\r\nstruct\
    \ sectionsum {\r\n    vector<T> data;\r\n\r\n    sectionsum(int n) : data(n +\
    \ 1, 0) {}\r\n\r\n    void update(int k, const T& x) {\r\n        data[k + 1]\
    \ = x;\r\n    }\r\n\r\n    void build() {\r\n        for (int i = 1; i < (int)data.size();\
    \ i++) {\r\n            data[i] += data[i - 1];\r\n        }\r\n    }\r\n\r\n\
    \    T get(int r) const {\r\n        if (r < 0) return 0;\r\n        return data[min(r,\
    \ (int)data.size() - 1)];\r\n    }\r\n    T get(int l, int r) const {\r\n    \
    \    return get(r) - get(l);\r\n    }\r\n};\n"
  code: "template <class T>\r\nstruct sectionsum {\r\n    vector<T> data;\r\n\r\n\
    \    sectionsum(int n) : data(n + 1, 0) {}\r\n\r\n    void update(int k, const\
    \ T& x) {\r\n        data[k + 1] = x;\r\n    }\r\n\r\n    void build() {\r\n \
    \       for (int i = 1; i < (int)data.size(); i++) {\r\n            data[i] +=\
    \ data[i - 1];\r\n        }\r\n    }\r\n\r\n    T get(int r) const {\r\n     \
    \   if (r < 0) return 0;\r\n        return data[min(r, (int)data.size() - 1)];\r\
    \n    }\r\n    T get(int l, int r) const {\r\n        return get(r) - get(l);\r\
    \n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/section-sum.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:01:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static-range-sum.test.cpp
documentation_of: algorithm/section-sum.hpp
layout: document
title: "\u7D2F\u7A4D\u548C"
---
