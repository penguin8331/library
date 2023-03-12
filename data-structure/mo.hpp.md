---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
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
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#define line\n#endif\n#line 8 \"template/template.hpp\"\n\
    using namespace std;\n#line 3 \"data-structure/mo.hpp\"\n\nstruct Mo {\n    vector<int>\
    \ left, right, index;  // the interval's left, right, index\n    vector<bool>\
    \ v;\n    int window;\n    int nl, nr, ptr;\n\n    Mo(int n) : window((int)sqrt(n)),\
    \ nl(0), nr(0), ptr(0), v(n, false) {}\n\n    /* push */\n    void push(int l,\
    \ int r) { left.push_back(l), right.push_back(r); }\n\n    /* sort intervals */\n\
    \    void build() {\n        index.resize(left.size());\n        iota(index.begin(),\
    \ index.end(), 0);\n\n        sort(begin(index), end(index), [&](int a, int b)\
    \ {\n            if (left[a] / window != left[b] / window) return left[a] < left[b];\n\
    \            return right[a] < right[b];\n        });\n    }\n\n    /* extend-shorten\
    \ */\n    void extend_shorten(int id) {\n        v[id].flip();\n        if (v[id])\n\
    \            insert(id);\n        else\n            erase(id);\n    }\n\n    /*\
    \ next id of interval */\n    int next() {\n        if (ptr == index.size()) return\
    \ -1;\n        int id = index[ptr];\n        while (nl > left[id]) extend_shorten(--nl);\n\
    \        while (nr < right[id]) extend_shorten(nr++);\n        while (nl < left[id])\
    \ extend_shorten(nl++);\n        while (nr > right[id]) extend_shorten(--nr);\n\
    \        return index[ptr++];\n    }\n\n    /* insert, erase (to be set appropriately)\
    \ */\n    void insert(int id);\n    void erase(int id);\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Mo {\n    vector<int>\
    \ left, right, index;  // the interval's left, right, index\n    vector<bool>\
    \ v;\n    int window;\n    int nl, nr, ptr;\n\n    Mo(int n) : window((int)sqrt(n)),\
    \ nl(0), nr(0), ptr(0), v(n, false) {}\n\n    /* push */\n    void push(int l,\
    \ int r) { left.push_back(l), right.push_back(r); }\n\n    /* sort intervals */\n\
    \    void build() {\n        index.resize(left.size());\n        iota(index.begin(),\
    \ index.end(), 0);\n\n        sort(begin(index), end(index), [&](int a, int b)\
    \ {\n            if (left[a] / window != left[b] / window) return left[a] < left[b];\n\
    \            return right[a] < right[b];\n        });\n    }\n\n    /* extend-shorten\
    \ */\n    void extend_shorten(int id) {\n        v[id].flip();\n        if (v[id])\n\
    \            insert(id);\n        else\n            erase(id);\n    }\n\n    /*\
    \ next id of interval */\n    int next() {\n        if (ptr == index.size()) return\
    \ -1;\n        int id = index[ptr];\n        while (nl > left[id]) extend_shorten(--nl);\n\
    \        while (nr < right[id]) extend_shorten(nr++);\n        while (nl < left[id])\
    \ extend_shorten(nl++);\n        while (nr > right[id]) extend_shorten(--nr);\n\
    \        return index[ptr++];\n    }\n\n    /* insert, erase (to be set appropriately)\
    \ */\n    void insert(int id);\n    void erase(int id);\n};\n"
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
  timestamp: '2023-03-12 14:09:29+09:00'
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

## 宣言

`Mo hoge(N)` : 配列の要素数を N として Mo を宣言

## 使い方

注意点: 区間に $A_i$を含める, 消す場合どのように更新するかを定義する `insert`, `erase` 関数を定義する

例:
- mode := 最頻値の出現回数 (求めたいもの)
    - `cnt[i]` := `i` が何個あるか
    - `hist[c]` := 区間内に `c` 個ある値が何種類あるか
    - `num_kind := 区間内に何種類の数があるか`

```cpp
int A[100100];
int cnt[200100], hist[100100];
int num_kind = 0, mode = 0;

void Mo::insert(int id) {
    int val = A[id];
    if (cnt[val] == 0) ++num_kind;
    --hist[cnt[val]];
    ++cnt[val];
    ++hist[cnt[val]];
    mode = max(mode, cnt[val]);
}

void Mo::erase(int id) {
    int val = A[id];
    --hist[cnt[val]];
    if (cnt[val] == mode && hist[cnt[val]] == 0) --mode;
    --cnt[val];
    ++hist[cnt[val]];
    if (cnt[val] == 0) --num_kind;
}
```


`void push(l, r)` : `i` 番目の区間クエリを $[l, r)$ として push

`void build()` : build

`int next()` : 返り値を `i` とすると `i` 番目のクエリに対する答えとなる状態に insert 内で定義された変数がなる。
