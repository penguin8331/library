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
  bundledCode: "#line 1 \"data-structure/binary-search-on-bit.hpp\"\ntemplate <class\
    \ Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat;\n\n    //\
    \ [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) {}\n\
    \    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\n    // a\
    \ is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int i = a;\
    \ i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n    }\n\n\
    \    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n        Abel res\
    \ = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n \
    \           res = res + dat[i];\n        return res;\n    }\n\n    // [a, b),\
    \ a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n        return sum(b)\
    \ - sum(a);\n    }\n\n    // k-th number (k is 0-indexed)\n    int get(long long\
    \ k) {\n        ++k;\n        int res = 0;\n        int N = 1;\n        while\
    \ (N < (int)dat.size()) N *= 2;\n        for (int i = N / 2; i > 0; i /= 2) {\n\
    \            if (res + i - 1 < (int)dat.size() && dat[res + i - 1] < k) {\n  \
    \              k = k - dat[res + i - 1];\n                res = res + i;\n   \
    \         }\n        }\n        return res;\n    }\n\n    // debug\n    void print()\
    \ {\n        for (int i = 0; i < (int)dat.size(); ++i)\n            cout << sum(i,\
    \ i + 1) << \",\";\n        cout << endl;\n    }\n};\n"
  code: "template <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel>\
    \ dat;\n\n    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n,\
    \ unity) {}\n    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\
    \n    // a is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int\
    \ i = a; i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n\
    \    }\n\n    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n      \
    \  Abel res = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1))\
    \ - 1)\n            res = res + dat[i];\n        return res;\n    }\n\n    //\
    \ [a, b), a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n       \
    \ return sum(b) - sum(a);\n    }\n\n    // k-th number (k is 0-indexed)\n    int\
    \ get(long long k) {\n        ++k;\n        int res = 0;\n        int N = 1;\n\
    \        while (N < (int)dat.size()) N *= 2;\n        for (int i = N / 2; i >\
    \ 0; i /= 2) {\n            if (res + i - 1 < (int)dat.size() && dat[res + i -\
    \ 1] < k) {\n                k = k - dat[res + i - 1];\n                res =\
    \ res + i;\n            }\n        }\n        return res;\n    }\n\n    // debug\n\
    \    void print() {\n        for (int i = 0; i < (int)dat.size(); ++i)\n     \
    \       cout << sum(i, i + 1) << \",\";\n        cout << endl;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/binary-search-on-bit.hpp
  requiredBy: []
  timestamp: '2023-01-02 09:22:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-search-on-bit.hpp
layout: document
title: "BIT\u4E0A\u306E\u4E8C\u5206\u63A2\u7D22(k\u756A\u76EE\u306E\u8981\u7D20\u3092\
  \u6C42\u3081\u308B)"
---

## 概要

BIT 上二分探索 (以下のクエリに答えられる、ただし $v$<=$N$ として$O(N)$のメモリが必要、時間計算量は $O(log N)$)

- 集合 $S$ に要素 $v$ を追加する ($add(v,1)$)
- 集合 $S$ から要素 $v$ を除く ($add(v,-1)$)
- 集合 $S$ の $k$ 番目に大きい要素を答える ($get(k)$)
