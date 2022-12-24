---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree-raq.hpp\"\ntemplate <class\
    \ Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat[2];\n\n \
    \   // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity) {\n        init(n);\n\
    \    }\n    void init(int n) {\n        for (int iter = 0; iter < 2; ++iter)\n\
    \            dat[iter].assign(n + 1, UNITY_SUM);\n    }\n\n    // [a, b), a and\
    \ b are 0-indexed\n    inline void sub_add(int p, int a, Abel x) {\n        for\
    \ (int i = a; i < (int)dat[p].size(); i |= i + 1)\n            dat[p][i] = dat[p][i]\
    \ + x;\n    }\n    inline void add(int a, int b, Abel x) {\n        sub_add(0,\
    \ a, x * (-a));\n        sub_add(1, a, x);\n        sub_add(0, b, x * b);\n  \
    \      sub_add(1, b, x * (-1));\n    }\n\n    // [a, b), a and b are 0-indexed\n\
    \    inline Abel sub_sum(int p, int a) {\n        Abel res = UNITY_SUM;\n    \
    \    for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n            res = res\
    \ + dat[p][i];\n        return res;\n    }\n    inline Abel sum(int a, int b)\
    \ {\n        return sub_sum(0, b) + sub_sum(1, b) * b - sub_sum(0, a) - sub_sum(1,\
    \ a) * a;\n    }\n\n    // debug\n    void print() {\n        for (int i = 0;\
    \ i < (int)dat[0].size(); ++i)\n            cout << sum(i, i + 1) << \",\";\n\
    \        cout << endl;\n    }\n};\n"
  code: "template <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel>\
    \ dat[2];\n\n    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity)\
    \ {\n        init(n);\n    }\n    void init(int n) {\n        for (int iter =\
    \ 0; iter < 2; ++iter)\n            dat[iter].assign(n + 1, UNITY_SUM);\n    }\n\
    \n    // [a, b), a and b are 0-indexed\n    inline void sub_add(int p, int a,\
    \ Abel x) {\n        for (int i = a; i < (int)dat[p].size(); i |= i + 1)\n   \
    \         dat[p][i] = dat[p][i] + x;\n    }\n    inline void add(int a, int b,\
    \ Abel x) {\n        sub_add(0, a, x * (-a));\n        sub_add(1, a, x);\n   \
    \     sub_add(0, b, x * b);\n        sub_add(1, b, x * (-1));\n    }\n\n    //\
    \ [a, b), a and b are 0-indexed\n    inline Abel sub_sum(int p, int a) {\n   \
    \     Abel res = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i +\
    \ 1)) - 1)\n            res = res + dat[p][i];\n        return res;\n    }\n \
    \   inline Abel sum(int a, int b) {\n        return sub_sum(0, b) + sub_sum(1,\
    \ b) * b - sub_sum(0, a) - sub_sum(1, a) * a;\n    }\n\n    // debug\n    void\
    \ print() {\n        for (int i = 0; i < (int)dat[0].size(); ++i)\n          \
    \  cout << sum(i, i + 1) << \",\";\n        cout << endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-raq.hpp
  requiredBy: []
  timestamp: '2022-12-24 11:15:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_G.test.cpp
documentation_of: data-structure/binary-indexed-tree-raq.hpp
layout: document
title: "Binary Indexed Tree (\u533A\u9593\u52A0\u7B97 \u533A\u9593\u548C\u53D6\u5F97\
  \u306B\u5BFE\u5FDC)"
---
