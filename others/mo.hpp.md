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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Mo {\n    vector<int>\
    \ left, right, index;\n    vector<bool> v;\n    int window;\n    int nl, nr, ptr;\n\
    \    function<void(int)> insert, erase;\n\n    Mo(int n, const function<void(int)>\
    \ INSERT, const function<void(int)> ERASE)\n        : window((int)sqrt(n)),\n\
    \          nl(0),\n          nr(0),\n          ptr(0),\n          v(n, false),\n\
    \          insert(INSERT),\n          erase(ERASE) {}\n\n    /* push */\n    void\
    \ push(int l, int r) { left.push_back(l), right.push_back(r); }\n\n    /* sort\
    \ intervals */\n    void build() {\n        index.resize(left.size());\n     \
    \   iota(index.begin(), index.end(), 0);\n\n        sort(begin(index), end(index),\
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
  path: others/mo.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/mo.hpp
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
