---
title: 区間をsetで管理するテク
documentation_of: //others/range-set.hpp
---

## 使い方

### 宣言

```cpp
RangeSet<T> hoge;
```

### クエリ

`convered(T l, T r)` : 区間 `[l,r]` がカバーされているか
`convered_by(T l, T r)` : 区間 `[l,r]` がカバーされている場合その区間
`insert(T l, T r)` : 区間 `[l,r]` を挿入
`erase(T l, T r)` : 区間 `[l,r]` を削除
`mex(T x)` : `x` 以上ではじめにカバーされていない場所を返す

## 参考

https://mugen1337.hatenablog.com/entry/2020/10/14/134022
https://rsk0315.hatenablog.com/entry/2020/10/11/125049
