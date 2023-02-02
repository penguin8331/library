---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2842.test.cpp
    title: test/AOJ/2842.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree-2d.hpp\"\ntemplate <class\
    \ Abel>\nstruct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel>>\
    \ dat;\n\n    // [0, n) x [0, m)\n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\n\
    \                                          dat(n, vector<Abel>(m, UNITY_SUM))\
    \ {}\n    void init(int n, int m) {\n        dat.assign(n, vector<Abel>(m, UNITY_SUM));\n\
    \    }\n\n    // add x on the point (a, b)\n    inline void add(int a, int b,\
    \ Abel x) {\n        for (int i = a; i < (int)dat.size(); i |= i + 1)\n      \
    \      for (int j = b; j < (int)dat[0].size(); j |= j + 1)\n                dat[i][j]\
    \ = dat[i][j] + x;\n    }\n\n    // [0, p) x [0, q), 0-indexed\n    inline Abel\
    \ sum(int p, int q) {\n        Abel res = UNITY_SUM;\n        for (int i = p -\
    \ 1; i >= 0; i = (i & (i + 1)) - 1)\n            for (int j = q - 1; j >= 0; j\
    \ = (j & (j + 1)) - 1)\n                res = res + dat[i][j];\n        return\
    \ res;\n    }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline Abel\
    \ sum(int x1, int x2, int y1, int y2) {\n        return sum(x2, y2) - sum(x1,\
    \ y2) - sum(x2, y1) + sum(x1, y1);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, BIT2D bit) {\n        for (int i = 0; i < (int)bit.dat.size(); i++) {\n\
    \            os << \"[ \";\n            for (int j = 0; j < (int)bit.dat[0].size();\
    \ j++) {\n                os << bit.sum(i, i + 1, j, j + 1) << \" \";\n      \
    \      }\n            os << ']';\n        }\n        return os;\n    }\n};\n"
  code: "template <class Abel>\nstruct BIT2D {\n    const Abel UNITY_SUM = 0;\n  \
    \  vector<vector<Abel>> dat;\n\n    // [0, n) x [0, m)\n    BIT2D(int n, int m,\
    \ Abel unity = 0) : UNITY_SUM(unity),\n                                      \
    \    dat(n, vector<Abel>(m, UNITY_SUM)) {}\n    void init(int n, int m) {\n  \
    \      dat.assign(n, vector<Abel>(m, UNITY_SUM));\n    }\n\n    // add x on the\
    \ point (a, b)\n    inline void add(int a, int b, Abel x) {\n        for (int\
    \ i = a; i < (int)dat.size(); i |= i + 1)\n            for (int j = b; j < (int)dat[0].size();\
    \ j |= j + 1)\n                dat[i][j] = dat[i][j] + x;\n    }\n\n    // [0,\
    \ p) x [0, q), 0-indexed\n    inline Abel sum(int p, int q) {\n        Abel res\
    \ = UNITY_SUM;\n        for (int i = p - 1; i >= 0; i = (i & (i + 1)) - 1)\n \
    \           for (int j = q - 1; j >= 0; j = (j & (j + 1)) - 1)\n             \
    \   res = res + dat[i][j];\n        return res;\n    }\n\n    // x1 <= x < x2,\
    \ y1 <= y < y2, 0-indexed\n    inline Abel sum(int x1, int x2, int y1, int y2)\
    \ {\n        return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);\n \
    \   }\n\n    friend ostream& operator<<(ostream& os, BIT2D bit) {\n        for\
    \ (int i = 0; i < (int)bit.dat.size(); i++) {\n            os << \"[ \";\n   \
    \         for (int j = 0; j < (int)bit.dat[0].size(); j++) {\n               \
    \ os << bit.sum(i, i + 1, j, j + 1) << \" \";\n            }\n            os <<\
    \ ']';\n        }\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-2d.hpp
  requiredBy: []
  timestamp: '2023-01-16 22:52:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2842.test.cpp
documentation_of: data-structure/binary-indexed-tree-2d.hpp
layout: document
title: "\u4E8C\u6B21\u5143 BIT"
---
