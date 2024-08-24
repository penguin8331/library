---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/implicit-treap.hpp
    title: ImplicitTreap
  - icon: ':x:'
    path: others/rand-int.hpp
    title: "\u4E71\u6570\u751F\u6210"
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../data-structure/implicit-treap.hpp\"\
    \n\ntemplate <typename T, bool ascending = true>\nstruct PrioritySum {\n    SumUpdateQuery<T,\
    \ T> tr;\n    MinUpdateQuery<T, T> tr2;\n    int cnt = 0;\n\n    void add(T a)\
    \ {\n        int p = tr2.binary_search(0, tr2.size(), a, !ascending);\n      \
    \  if (ascending) {\n            tr.insert(p + 1, a);\n            tr2.insert(p\
    \ + 1, a);\n        } else {\n            if (p == -1) {\n                tr.insert(tr.size(),\
    \ a);\n                tr2.insert(tr2.size(), a);\n            } else {\n    \
    \            tr.insert(p, a);\n                tr2.insert(p, a);\n           \
    \ }\n        }\n        cnt++;\n    }\n\n    void erase_at(int k) {\n        assert(0\
    \ <= k && k < cnt);\n        tr.erase(k);\n        tr2.erase(k);\n        cnt--;\n\
    \    }\n\n    void erase_value(T a) {\n        int p = tr2.binary_search(0, tr2.size(),\
    \ a, !ascending);\n        if (ascending) {\n            if (p == cnt) p = 0;\n\
    \            p++;\n        } else {\n            if (p == -1) p = cnt;\n     \
    \       p--;\n        }\n        assert(0 <= p && p < tr.size() && tr[p] == a);\n\
    \        erase_at(p);\n    }\n\n    int size() const { return cnt; }\n\n    T\
    \ sum(int k) { return tr.query(0, k); }\n\n    T operator[](int k) { return tr[k];\
    \ }\n\n    void dump() { tr.dump(); }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/implicit-treap.hpp
  - others/rand-int.hpp
  isVerificationFile: false
  path: data-structure/priority-sum-by-implicit-treap.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/priority-sum-by-implicit-treap.hpp
layout: document
title: PrioritySum (by Implicit Treap)
---

## 概要

集合を sort したときの上位 k 個の累積が求められる

## 宣言

```cpp
PrioritySum<T, bool ascending = true> hoge;
```

`T` 集合の要素の型、 `accending` は要素を昇順にするかどうか

## クエリ

`void add(T a)` : 集合に `a` を追加 $O(log n)$

`void erase_at(int k)` : 位置を指定して要素を削除。先頭の削除なら `k = 0` を指定。 $O(log n)$

`void erase_value(T a)` : 要素を指定して削除。 `a` がすでに `add` されていることが仮定されている。 $O(log n)$

`int size()` : 現時点でのサイズを返す $O(1)$

`T query(int k)` : 上位 k 個の累積

`T operator[](int k)` : インデックスアクセスができます。 $O(log n)$

`void dump()` : デバッグ用です。配列の中身をprintします。
