---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
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
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define all(x) std::begin(x),\
    \ std::end(x)\n#define rall(x) std::rbegin(x), std::rend(x)\n#define elif else\
    \ if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a +\
    \ b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/mo.hpp\"\n\nstruct Mo {\n    vector<int> left,\
    \ right, index;  // the interval's left, right, index\n    vector<bool> v;\n \
    \   int window;\n    int nl, nr, ptr;\n    function<void(int)> insert, erase;\n\
    \n    Mo(int n, const function<void(int)> INSERT, const function<void(int)> ERASE)\n\
    \        : window((int)sqrt(n)),\n          nl(0),\n          nr(0),\n       \
    \   ptr(0),\n          v(n, false),\n          insert(INSERT),\n          erase(ERASE)\
    \ {}\n\n    /* push */\n    void push(int l, int r) { left.push_back(l), right.push_back(r);\
    \ }\n\n    /* sort intervals */\n    void build() {\n        index.resize(left.size());\n\
    \        iota(index.begin(), index.end(), 0);\n\n        sort(begin(index), end(index),\
    \ [&](int a, int b) {\n            if (left[a] / window != left[b] / window) return\
    \ left[a] < left[b];\n            return right[a] < right[b];\n        });\n \
    \   }\n\n    /* extend-shorten */\n    void extend_shorten(int id) {\n       \
    \ v[id].flip();\n        if (v[id])\n            insert(id);\n        else\n \
    \           erase(id);\n    }\n\n    /* next id of interval */\n    int next()\
    \ {\n        if (ptr == index.size()) return -1;\n        int id = index[ptr];\n\
    \        while (nl > left[id]) extend_shorten(--nl);\n        while (nr < right[id])\
    \ extend_shorten(nr++);\n        while (nl < left[id]) extend_shorten(nl++);\n\
    \        while (nr > right[id]) extend_shorten(--nr);\n        return index[ptr++];\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Mo {\n    vector<int>\
    \ left, right, index;  // the interval's left, right, index\n    vector<bool>\
    \ v;\n    int window;\n    int nl, nr, ptr;\n    function<void(int)> insert, erase;\n\
    \n    Mo(int n, const function<void(int)> INSERT, const function<void(int)> ERASE)\n\
    \        : window((int)sqrt(n)),\n          nl(0),\n          nr(0),\n       \
    \   ptr(0),\n          v(n, false),\n          insert(INSERT),\n          erase(ERASE)\
    \ {}\n\n    /* push */\n    void push(int l, int r) { left.push_back(l), right.push_back(r);\
    \ }\n\n    /* sort intervals */\n    void build() {\n        index.resize(left.size());\n\
    \        iota(index.begin(), index.end(), 0);\n\n        sort(begin(index), end(index),\
    \ [&](int a, int b) {\n            if (left[a] / window != left[b] / window) return\
    \ left[a] < left[b];\n            return right[a] < right[b];\n        });\n \
    \   }\n\n    /* extend-shorten */\n    void extend_shorten(int id) {\n       \
    \ v[id].flip();\n        if (v[id])\n            insert(id);\n        else\n \
    \           erase(id);\n    }\n\n    /* next id of interval */\n    int next()\
    \ {\n        if (ptr == index.size()) return -1;\n        int id = index[ptr];\n\
    \        while (nl > left[id]) extend_shorten(--nl);\n        while (nr < right[id])\
    \ extend_shorten(nr++);\n        while (nl < left[id]) extend_shorten(nl++);\n\
    \        while (nr > right[id]) extend_shorten(--nr);\n        return index[ptr++];\n\
    \    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/mo.hpp
  requiredBy: []
  timestamp: '2023-03-21 10:37:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/mo.hpp
layout: document
title: Mo's algorithm
---

## 概要

以下の条件を満たしていれば使える可能性がある
- 配列の要素が不変
- クエリを先読みできる
- 区間 $[l,r)$ の結果から区間 $[l+1,r),[l-1,r),[l,r+1),[l,r-1)$ の結果が簡単に出せる

## 使い方

### 宣言

`Mo hoge(N)` : 配列の要素数を N として Mo を宣言

### ex

```cpp
int N;
vector<int> A(N);
vector<ll> cnt(300000);
ll res = 0;
auto insert = [&](int id) {
    int var = A[id];
    res += cnt[var] * (cnt[var] - 1) / 2;
    cnt[var]++;
};
auto erase = [&](int id) {
    int var = A[id];
    cnt[var]--;
    res -= cnt[var] * (cnt[var] - 1) / 2;
};
Mo mo(N, insert, erase);
```

### 関数

`void push(l, r)` : `i` 番目の区間クエリを $[l, r)$ として push

`void build()` : build

`int next()` : 返り値を `i` とすると `i` 番目のクエリに対する答えとなる状態に
insert 内で定義された変数がなる。
