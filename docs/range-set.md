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
`convered_by(T l, T r)` : 区間 `[l,r]` が**完全に**カバーされている区間が存在する場合その区間を返す  
`insert(T l, T r)` : 区間 `[l,r]` を挿入  
`erase(T l, T r)` : 区間 `[l,r]` を削除  
`mex(T x)` : `x` 以上ではじめにカバーされていない場所を返す

## 参考

[区間をsetで管理するやつでもうバグらせたくない-むげんのぶろぐ](https://mugen1337.hatenablog.com/entry/2020/10/14/134022)  
[要素の追加・削除と mex を対数時間で処理するよ-えびちゃんの日記](https://rsk0315.hatenablog.com/entry/2020/10/11/125049)
