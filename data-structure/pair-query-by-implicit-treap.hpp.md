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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../data-structure/implicit-treap.hpp\"\n#include\
    \ \"../template/template.hpp\"\n\nnamespace std {\ntemplate <typename T0, typename\
    \ T1>\nclass numeric_limits<pair<T0, T1>> {\n   public:\n    static constexpr\
    \ pair<T0, T1> min() {\n        return {numeric_limits<T0>::min(), numeric_limits<T1>::min()};\n\
    \    }\n    static constexpr pair<T0, T1> max() {\n        return {numeric_limits<T0>::max(),\
    \ numeric_limits<T1>::max()};\n    }\n};\n}  // namespace std\n\n// \u30DA\u30A2\
    \u306E\u7B2C\u4E00\u8981\u7D20\u3067\u30BD\u30FC\u30C8\u3057\u3001\u7B2C\u4E00\
    \u8981\u7D20\u304Cx\u306E\u3082\u306E\u3068x\u3088\u308A\u5DE6\u5074\u306E\u3082\
    \u306E\u306B\u5BFE\u3057\u7B2C\u4E8C\u8981\u7D20\u306E\u7D2F\u7A4D\u3092\u8FD4\
    \u3059\ntemplate <typename T0, typename T1, bool ascending = true>\nstruct PairQuery\
    \ {\n    // \u7D2F\u7A4D\u7528\u3002\u7B2C\u4E8C\u8981\u7D20\u3092\u7BA1\u7406\
    \n    SumUpdateQuery<T1, T1> tr;\n    // \u9806\u5E8F\u7BA1\u7406\u7528\n    MinUpdateQuery<pair<T0,\
    \ T1>, pair<T0, T1>> tr2;\n    int cnt = 0;\n\n    void add(const pair<T0, T1>\
    \ &a) {\n        int p = tr2.binary_search(0, tr2.size(), a, !ascending);\n  \
    \      if (ascending) {\n            tr.insert(p + 1, a.second);\n           \
    \ tr2.insert(p + 1, a);\n        } else {\n            if (p == -1) {\n      \
    \          tr.insert(tr.size(), a.second);\n                tr2.insert(tr2.size(),\
    \ a);\n            } else {\n                tr.insert(p, a.second);\n       \
    \         tr2.insert(p, a);\n            }\n        }\n        cnt++;\n    }\n\
    \n    // \u7B2C\u4E00\u8981\u7D20\u304Cx\u306E\u3082\u306E\u3068x\u3088\u308A\u5DE6\
    \u5074\u306E\u3082\u306E\u306B\u5BFE\u3057\u7B2C\u4E8C\u8981\u7D20\u306E\u7D2F\
    \u7A4D\u3092\u8FD4\u3059\n    T1 query(T0 x) {\n        if (ascending) {\n   \
    \         int p = tr2.binary_search(0, tr2.size(), {x, numeric_limits<T1>::max()},\
    \ false);\n            p++;\n            return tr.query(0, p);\n        } else\
    \ {\n            int p = tr2.binary_search(0, tr2.size(), {x, numeric_limits<T1>::min()});\n\
    \            if (p == -1) p = cnt;\n            return tr.query(0, p);\n     \
    \   }\n    }\n\n    void erase_at(int k) {\n        assert(0 <= k && k < cnt);\n\
    \        tr.erase(k);\n        tr2.erase(k);\n        cnt--;\n    }\n\n    void\
    \ erase_value(const pair<T0, T1> &a) {\n        int p = tr2.binary_search(0, tr2.size(),\
    \ a, !ascending);\n        if (ascending) {\n            p++;\n        } else\
    \ {\n            if (p == -1) p = cnt;\n            p--;\n        }\n        assert(0\
    \ <= p && p < cnt && tr2[p] == a);\n        erase_at(p);\n    }\n\n    int size()\
    \ const { return cnt; }\n\n    T1 sum(int k) { return tr.query(0, k); }\n\n  \
    \  pair<T0, T1> operator[](int k) { return tr2[k]; }\n\n    void dump() { tr2.dump();\
    \ }\n};"
  dependsOn:
  - data-structure/implicit-treap.hpp
  - others/rand-int.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/pair-query-by-implicit-treap.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/pair-query-by-implicit-treap.hpp
layout: document
title: PairQuery (by Implicit Treap)
---

## 概要

pair 型の要素を第一要素の要素で sort したときの第二要素の累積を求める

## 宣言

```cpp
PairQuery<T0, T1, bool ascending = true> hoge;
```

`pair<T0,T1>` 集合が要素の型となる、 `accending` は要素を昇順にするかどうか

## クエリ

`void add(pair<T0, T1> a)` : 集合に `a` を追加 $O(log n)$

`void erase_at(int k)` : 位置を指定して要素を削除。先頭の削除なら `k = 0` を指定。 $O(log n)$

`void erase_value(pair<T0, T1> a)` : 要素を指定して削除。 `a` がすでに `add` されていることが仮定されている。 $O(log n)$

`int size()` : 現時点でのサイズを返す $O(1)$

`T1 query(T0 x)` : 第一要素が `x` の要素と `x` より左側にある要素に対し第二要素の累積を返します。 $O(log n)$

`pair<T0, T1> operator[](int k)` : インデックスアクセスができます。 $O(log n)$

`void dump()` : デバッグ用です。配列の中身をprintします。
