---
title: ローリングハッシュ
documentation_of: //string/rolling-hash.hpp
---

## 使い方

- `build(S)` : 文字列Sのハッシュを返す
- `query(hash,l,r)` : hashを用いて[l,r)のハッシュ値を求める
- `combine(h1,h2,h2len)` : ハッシュ値h1とハッシュ値h2のものを連結する
- `lcp(hash1,l,r,hash2,l,r)` : hash1の[l,r)とhash2の[l,r)の最長共通接頭辞の長さを返す (二分探索を用いる)
