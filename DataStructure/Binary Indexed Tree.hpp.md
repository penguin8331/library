---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Inversion Number.hpp
    title: DataStructure/Inversion Number.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_5_D.test.cpp
    title: test/AOJ/ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/Binary Indexed Tree.hpp\"\ntemplate <class\
    \ Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat;\n\n    //\
    \ [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) {}\n\
    \    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\n    // a\
    \ is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int i = a;\
    \ i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n    }\n\n\
    \    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n        Abel res\
    \ = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n \
    \           res = res + dat[i];\n        return res;\n    }\n\n    // [a, b),\
    \ a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n        return sum(b)\
    \ - sum(a);\n    }\n\n    // debug\n    void print() {\n#ifdef LOCAL\n       \
    \ for (int i = 0; i < (int)dat.size(); ++i)\n            cout << sum(i, i + 1)\
    \ << \",\";\n        cout << endl;\n#endif\n    }\n};\n"
  code: "template <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel>\
    \ dat;\n\n    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n,\
    \ unity) {}\n    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\
    \n    // a is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int\
    \ i = a; i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n\
    \    }\n\n    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n      \
    \  Abel res = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1))\
    \ - 1)\n            res = res + dat[i];\n        return res;\n    }\n\n    //\
    \ [a, b), a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n       \
    \ return sum(b) - sum(a);\n    }\n\n    // debug\n    void print() {\n#ifdef LOCAL\n\
    \        for (int i = 0; i < (int)dat.size(); ++i)\n            cout << sum(i,\
    \ i + 1) << \",\";\n        cout << endl;\n#endif\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Binary Indexed Tree.hpp
  requiredBy:
  - DataStructure/Inversion Number.hpp
  timestamp: '2022-12-20 15:08:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_5_D.test.cpp
documentation_of: DataStructure/Binary Indexed Tree.hpp
layout: document
redirect_from:
- /library/DataStructure/Binary Indexed Tree.hpp
- /library/DataStructure/Binary Indexed Tree.hpp.html
title: DataStructure/Binary Indexed Tree.hpp
---
