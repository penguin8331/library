---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0560.test.cpp
    title: test/AOJ/0560.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/section-sum2d.hpp\"\ntemplate <class T>\r\nstruct\
    \ sectionsum2d {\r\n    vector<vector<T>> data;\r\n\r\n    sectionsum2d(int H,\
    \ int W) : data(H + 1, vector<T>(W + 1, 0)) {}\r\n\r\n    void update(int x, int\
    \ y, const T& z) {\r\n        x++;\r\n        y++;\r\n        data[x][y] = z;\r\
    \n    }\r\n\r\n    void build() {\r\n        for (int i = 1; i < data.size();\
    \ i++) {\r\n            for (int j = 1; j < data[i].size(); j++) {\r\n       \
    \         data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];\r\
    \n            }\r\n        }\r\n    }\r\n\r\n    T get(int sx, int sy, int gx,\
    \ int gy) const {\r\n        return (data[gx][gy] - data[sx][gy] - data[gx][sy]\
    \ + data[sx][sy]);\r\n    }\r\n};\n"
  code: "template <class T>\r\nstruct sectionsum2d {\r\n    vector<vector<T>> data;\r\
    \n\r\n    sectionsum2d(int H, int W) : data(H + 1, vector<T>(W + 1, 0)) {}\r\n\
    \r\n    void update(int x, int y, const T& z) {\r\n        x++;\r\n        y++;\r\
    \n        data[x][y] = z;\r\n    }\r\n\r\n    void build() {\r\n        for (int\
    \ i = 1; i < data.size(); i++) {\r\n            for (int j = 1; j < data[i].size();\
    \ j++) {\r\n                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i\
    \ - 1][j - 1];\r\n            }\r\n        }\r\n    }\r\n\r\n    T get(int sx,\
    \ int sy, int gx, int gy) const {\r\n        return (data[gx][gy] - data[sx][gy]\
    \ - data[gx][sy] + data[sx][sy]);\r\n    }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/section-sum2d.hpp
  requiredBy: []
  timestamp: '2022-12-21 11:16:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/0560.test.cpp
documentation_of: algorithm/section-sum2d.hpp
layout: document
title: "\u4E8C\u6B21\u5143\u7D2F\u7A4D\u548C"
---
