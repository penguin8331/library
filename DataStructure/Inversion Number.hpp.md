---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructure/Binary Indexed Tree.hpp
    title: DataStructure/Binary Indexed Tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS1_5_D.test.cpp
    title: test/AOJ/ALDS1_5_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ << \",\";\n        cout << endl;\n#endif\n    }\n};\n#line 2 \"DataStructure/Inversion\
    \ Number.hpp\"\ntemplate <class T>\nlong long inversion_number(const vector<T>\
    \ &a) {\n    int n = (int)a.size();\n    vector<T> b = a;\n    sort(b.begin(),\
    \ b.end());\n    b.erase(unique(b.begin(), b.end()), b.end());\n\n    long long\
    \ res = 0;\n    BIT<int> bit(n);\n    for (int i = 0; i < n; ++i) {\n        int\
    \ order = lower_bound(b.begin(), b.end(), a[i]) - b.begin();\n        ++order;\n\
    \        res += bit.sum(order + 1, n + 1);\n        bit.add(order, 1);\n    }\n\
    \    return res;\n}\n"
  code: "#include \"DataStructure/Binary Indexed Tree.hpp\"\ntemplate <class T>\n\
    long long inversion_number(const vector<T> &a) {\n    int n = (int)a.size();\n\
    \    vector<T> b = a;\n    sort(b.begin(), b.end());\n    b.erase(unique(b.begin(),\
    \ b.end()), b.end());\n\n    long long res = 0;\n    BIT<int> bit(n);\n    for\
    \ (int i = 0; i < n; ++i) {\n        int order = lower_bound(b.begin(), b.end(),\
    \ a[i]) - b.begin();\n        ++order;\n        res += bit.sum(order + 1, n +\
    \ 1);\n        bit.add(order, 1);\n    }\n    return res;\n}"
  dependsOn:
  - DataStructure/Binary Indexed Tree.hpp
  isVerificationFile: false
  path: DataStructure/Inversion Number.hpp
  requiredBy: []
  timestamp: '2022-12-20 15:08:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS1_5_D.test.cpp
documentation_of: DataStructure/Inversion Number.hpp
layout: document
redirect_from:
- /library/DataStructure/Inversion Number.hpp
- /library/DataStructure/Inversion Number.hpp.html
title: DataStructure/Inversion Number.hpp
---
