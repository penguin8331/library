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
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree-2d-raq.hpp\"\ntemplate\
    \ <class Abel>\nstruct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel>\
    \ > dat[2][2];\n    int N, M;\n\n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\
    \ N(n), M(m) {\n        init(n, m);\n    }\n    void init(int n, int m) {\n  \
    \      for (int i = 0; i < 2; ++i)\n            for (int j = 0; j < 2; ++j)\n\
    \                dat[i][j].assign(n + 1, vector<Abel>(m + 1, UNITY_SUM));\n  \
    \  }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline void subsub_add(int\
    \ f, int s, int x, int y, Abel v) {\n        for (int i = x; i < (int)dat[f][s].size();\
    \ i |= i + 1)\n            for (int j = y; j < (int)dat[f][s][0].size(); j |=\
    \ j + 1)\n                dat[f][s][i][j] = dat[f][s][i][j] + v;\n    }\n    inline\
    \ void sub_add(int x, int y, Abel v) {\n        subsub_add(0, 0, x, y, v * x *\
    \ y);\n        subsub_add(1, 0, x, y, -v * x);\n        subsub_add(0, 1, x, y,\
    \ -v * y);\n        subsub_add(1, 1, x, y, v);\n    }\n    inline void add(int\
    \ x1, int x2, int y1, int y2, Abel v) {\n        sub_add(x1, y1, v);\n       \
    \ sub_add(x1, y2, -v);\n        sub_add(x2, y1, -v);\n        sub_add(x2, y2,\
    \ v);\n    }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n    inline Abel\
    \ subsub_sum(int f, int s, int x, int y) {\n        Abel res = 0;\n        for\
    \ (int i = x; i > 0; i = (i & (i + 1)) - 1)\n            for (int j = y; j > 0;\
    \ j = (j & (j + 1)) - 1)\n                res = res + dat[f][s][i][j];\n     \
    \   return res;\n    }\n    inline Abel sub_sum(int x, int y) {\n        Abel\
    \ res = 0;\n        res += subsub_sum(0, 0, x, y);\n        res += subsub_sum(1,\
    \ 0, x, y) * y;\n        res += subsub_sum(0, 1, x, y) * x;\n        res += subsub_sum(1,\
    \ 1, x, y) * x * y;\n        return res;\n    }\n    inline Abel sum(int x1, int\
    \ x2, int y1, int y2) {\n        return sub_sum(x2, y2) - sub_sum(x1, y2) - sub_sum(x2,\
    \ y1) + sub_sum(x1, y1);\n    }\n\n    friend ostream& operator<<(ostream& os,\
    \ BIT2D bit) {\n        for (int i = 0; i < bit.N; i++) {\n            os << \"\
    [ \";\n            for (int j = 0; j < bit.M; j++) {\n                os << bit.sum(i,\
    \ i + 1, j, j + 1) << \" \";\n            }\n            os << ']';\n        }\n\
    \        return os;\n    }\n};\n"
  code: "template <class Abel>\nstruct BIT2D {\n    const Abel UNITY_SUM = 0;\n  \
    \  vector<vector<Abel> > dat[2][2];\n    int N, M;\n\n    BIT2D(int n, int m,\
    \ Abel unity = 0) : UNITY_SUM(unity), N(n), M(m) {\n        init(n, m);\n    }\n\
    \    void init(int n, int m) {\n        for (int i = 0; i < 2; ++i)\n        \
    \    for (int j = 0; j < 2; ++j)\n                dat[i][j].assign(n + 1, vector<Abel>(m\
    \ + 1, UNITY_SUM));\n    }\n\n    // x1 <= x < x2, y1 <= y < y2, 0-indexed\n \
    \   inline void subsub_add(int f, int s, int x, int y, Abel v) {\n        for\
    \ (int i = x; i < (int)dat[f][s].size(); i |= i + 1)\n            for (int j =\
    \ y; j < (int)dat[f][s][0].size(); j |= j + 1)\n                dat[f][s][i][j]\
    \ = dat[f][s][i][j] + v;\n    }\n    inline void sub_add(int x, int y, Abel v)\
    \ {\n        subsub_add(0, 0, x, y, v * x * y);\n        subsub_add(1, 0, x, y,\
    \ -v * x);\n        subsub_add(0, 1, x, y, -v * y);\n        subsub_add(1, 1,\
    \ x, y, v);\n    }\n    inline void add(int x1, int x2, int y1, int y2, Abel v)\
    \ {\n        sub_add(x1, y1, v);\n        sub_add(x1, y2, -v);\n        sub_add(x2,\
    \ y1, -v);\n        sub_add(x2, y2, v);\n    }\n\n    // x1 <= x < x2, y1 <= y\
    \ < y2, 0-indexed\n    inline Abel subsub_sum(int f, int s, int x, int y) {\n\
    \        Abel res = 0;\n        for (int i = x; i > 0; i = (i & (i + 1)) - 1)\n\
    \            for (int j = y; j > 0; j = (j & (j + 1)) - 1)\n                res\
    \ = res + dat[f][s][i][j];\n        return res;\n    }\n    inline Abel sub_sum(int\
    \ x, int y) {\n        Abel res = 0;\n        res += subsub_sum(0, 0, x, y);\n\
    \        res += subsub_sum(1, 0, x, y) * y;\n        res += subsub_sum(0, 1, x,\
    \ y) * x;\n        res += subsub_sum(1, 1, x, y) * x * y;\n        return res;\n\
    \    }\n    inline Abel sum(int x1, int x2, int y1, int y2) {\n        return\
    \ sub_sum(x2, y2) - sub_sum(x1, y2) - sub_sum(x2, y1) + sub_sum(x1, y1);\n   \
    \ }\n\n    friend ostream& operator<<(ostream& os, BIT2D bit) {\n        for (int\
    \ i = 0; i < bit.N; i++) {\n            os << \"[ \";\n            for (int j\
    \ = 0; j < bit.M; j++) {\n                os << bit.sum(i, i + 1, j, j + 1) <<\
    \ \" \";\n            }\n            os << ']';\n        }\n        return os;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-2d-raq.hpp
  requiredBy: []
  timestamp: '2023-01-16 22:52:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-indexed-tree-2d-raq.hpp
layout: document
title: "\u4E8C\u6B21\u5143 BIT (\u9818\u57DF\u52A0\u7B97, \u9818\u57DF\u548C\u53D6\
  \u5F97\u306B\u4E21\u5BFE\u5FDC)"
---
