---
title: Mo's algorithm
documentation_of: //others/mo.hpp
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
