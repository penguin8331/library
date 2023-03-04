---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\nusing\
    \ pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 7 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/binary-search-on-bit.hpp\"\
    \n\ntemplate <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel>\
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
    \ res + i;\n            }\n        }\n        return res;\n    }\n\n    friend\
    \ ostream& operator<<(ostream& os, BIT bit) {\n        os << \"[ \";\n       \
    \ for (int i = 0; i < (int)bit.dat.size(); i++) {\n            os << bit.sum(i,\
    \ i + 1) << \" \";\n        }\n        os << ']';\n        return os;\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class Abel>\n\
    struct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat;\n\n    // [0, n)\n\
    \    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) {}\n    void\
    \ init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\n    // a is 0-indexed\n\
    \    inline void add(int a, Abel x) {\n        for (int i = a; i < (int)dat.size();\
    \ i |= i + 1)\n            dat[i] = dat[i] + x;\n    }\n\n    // [0, a), a is\
    \ 0-indexed\n    inline Abel sum(int a) {\n        Abel res = UNITY_SUM;\n   \
    \     for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n            res = res\
    \ + dat[i];\n        return res;\n    }\n\n    // [a, b), a and b are 0-indexed\n\
    \    inline Abel sum(int a, int b) {\n        return sum(b) - sum(a);\n    }\n\
    \n    // k-th number (k is 0-indexed)\n    int get(long long k) {\n        ++k;\n\
    \        int res = 0;\n        int N = 1;\n        while (N < (int)dat.size())\
    \ N *= 2;\n        for (int i = N / 2; i > 0; i /= 2) {\n            if (res +\
    \ i - 1 < (int)dat.size() && dat[res + i - 1] < k) {\n                k = k -\
    \ dat[res + i - 1];\n                res = res + i;\n            }\n        }\n\
    \        return res;\n    }\n\n    friend ostream& operator<<(ostream& os, BIT\
    \ bit) {\n        os << \"[ \";\n        for (int i = 0; i < (int)bit.dat.size();\
    \ i++) {\n            os << bit.sum(i, i + 1) << \" \";\n        }\n        os\
    \ << ']';\n        return os;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: data-structure/binary-search-on-bit.hpp
  requiredBy: []
  timestamp: '2023-03-03 16:10:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-search-on-bit.hpp
layout: document
title: "BIT \u4E0A\u4E8C\u5206\u63A2\u7D22 (k \u756A\u76EE\u306E\u8981\u7D20\u3092\
  \u6C42\u3081\u308B)"
---

## 概要

BIT 上二分探索 (以下のクエリに答えられる、ただし `v` <= `N` として$O(N)$のメモリが必要、時間計算量は $O(log N)$)

## 使い方

- `add(int v,1)`  集合 `S` に要素 `v` を追加する
- `add(int v,-1)` 集合 `S` から要素 `v` を除く
- `get(int k)`    集合 `S` の `k` 番目に大きい要素を答える