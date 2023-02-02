---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/combinatorics/inversion-number.hpp
    title: "\u8EE2\u5012\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_5_D.test.cpp
    title: test/AOJ/ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/binary-indexed-tree.hpp\"\ntemplate <class\
    \ Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat;\n\n    //\
    \ [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) {}\n\
    \    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\n    // a\
    \ is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int i = a;\
    \ i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n    }\n\n\
    \    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n        Abel res\
    \ = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n \
    \           res = res + dat[i];\n        return res;\n    }\n\n    // [a, b),\
    \ a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n        return sum(b)\
    \ - sum(a);\n    }\n\n    friend ostream& operator<<(ostream& os, BIT bit) {\n\
    \        os << \"[ \";\n        for (int i = 0; i < (int)bit.dat.size(); i++)\
    \ {\n            os << bit.sum(i, i + 1) << \" \";\n        }\n        os << ']';\n\
    \        return os;\n    }\n};\n"
  code: "template <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel>\
    \ dat;\n\n    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n,\
    \ unity) {}\n    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\
    \n    // a is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int\
    \ i = a; i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n\
    \    }\n\n    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n      \
    \  Abel res = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1))\
    \ - 1)\n            res = res + dat[i];\n        return res;\n    }\n\n    //\
    \ [a, b), a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n       \
    \ return sum(b) - sum(a);\n    }\n\n    friend ostream& operator<<(ostream& os,\
    \ BIT bit) {\n        os << \"[ \";\n        for (int i = 0; i < (int)bit.dat.size();\
    \ i++) {\n            os << bit.sum(i, i + 1) << \" \";\n        }\n        os\
    \ << ']';\n        return os;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-indexed-tree.hpp
  requiredBy:
  - math/combinatorics/inversion-number.hpp
  timestamp: '2023-01-16 22:52:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_5_D.test.cpp
documentation_of: data-structure/binary-indexed-tree.hpp
layout: document
title: BIT
---
