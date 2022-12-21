---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: Binary Indexed Tree
  _extendedRequiredBy: []
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
    \ - sum(a);\n    }\n\n    // debug\n    void print() {\n#ifdef LOCAL\n       \
    \ for (int i = 0; i < (int)dat.size(); ++i)\n            cout << sum(i, i + 1)\
    \ << \",\";\n        cout << endl;\n#endif\n    }\n};\n#line 2 \"math/combinatorics/inversion-number.hpp\"\
    \n\r\ntemplate <class T>\r\nlong long inversion_number(const vector<T> &a) {\r\
    \n    int n = (int)a.size();\r\n    vector<T> b = a;\r\n    sort(b.begin(), b.end());\r\
    \n    b.erase(unique(b.begin(), b.end()), b.end());\r\n\r\n    long long res =\
    \ 0;\r\n    BIT<int> bit(n + 1);\r\n    for (int i = 0; i < n; ++i) {\r\n    \
    \    int order = lower_bound(b.begin(), b.end(), a[i]) - b.begin();\r\n      \
    \  ++order;\r\n        res += bit.sum(order + 1, n + 1);\r\n        bit.add(order,\
    \ 1);\r\n    }\r\n    return res;\r\n}\r\n"
  code: "#include \"data-structure/binary-indexed-tree.hpp\"\r\n\r\ntemplate <class\
    \ T>\r\nlong long inversion_number(const vector<T> &a) {\r\n    int n = (int)a.size();\r\
    \n    vector<T> b = a;\r\n    sort(b.begin(), b.end());\r\n    b.erase(unique(b.begin(),\
    \ b.end()), b.end());\r\n\r\n    long long res = 0;\r\n    BIT<int> bit(n + 1);\r\
    \n    for (int i = 0; i < n; ++i) {\r\n        int order = lower_bound(b.begin(),\
    \ b.end(), a[i]) - b.begin();\r\n        ++order;\r\n        res += bit.sum(order\
    \ + 1, n + 1);\r\n        bit.add(order, 1);\r\n    }\r\n    return res;\r\n}\r\
    \n"
  dependsOn:
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: false
  path: math/combinatorics/inversion-number.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:08:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_5_D.test.cpp
documentation_of: math/combinatorics/inversion-number.hpp
layout: document
title: "\u8EE2\u5012\u6570"
---
