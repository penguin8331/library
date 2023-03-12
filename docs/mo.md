---
title: Mo's algorithm
documentation_of: //data-structure/mo.hpp
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
