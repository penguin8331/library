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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc214_e.test.cpp
    title: test/atcoder/abc214_e.test.cpp
  - icon: ':x:'
    path: test/yukicoder/674.test.cpp
    title: test/yukicoder/674.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <typename\
    \ T>\nstruct RangeSet {\n    set<pair<T, T>> st;\n    T TINF;\n\n    RangeSet()\
    \ : TINF(numeric_limits<T>::max() / 2) {\n        st.emplace(TINF, TINF);\n  \
    \      st.emplace(-TINF, -TINF);\n    }\n    // [l,r] covered?\n    bool covered(T\
    \ l, T r) {\n        assert(l <= r);\n        auto ite = prev(st.lower_bound({l\
    \ + 1, l + 1}));\n        return ite->first <= l and r <= ite->second;\n    }\n\
    \    bool covered(T x) { return covered(x, x); }\n    // [l, r]\u304C\u30AB\u30D0\
    \u30FC\u3055\u308C\u3066\u3044\u308B\u306A\u3089\uFF0C\u305D\u306E\u533A\u9593\
    \u3092\u8FD4\u3059.\n    // \u3055\u308C\u3066\u3044\u306A\u3044\u306A\u3089[-TINF,-TINF]\u3092\
    \u8FD4\u3059\n    pair<T, T> covered_by(T l, T r) {\n        assert(l <= r);\n\
    \        auto ite = prev(st.lower_bound({l + 1, l + 1}));\n        if (ite->first\
    \ <= l and r <= ite->second) return *ite;\n        return make_pair(-TINF, -TINF);\n\
    \    }\n    pair<T, T> covered_by(T x) { return covered_by(x, x); }\n    // insert[l,r],\
    \ \u5897\u52A0\u91CF\u3092\u8FD4\u3059\n    T insert(T l, T r) {\n        assert(l\
    \ <= r);\n        auto ite = prev(st.lower_bound({l + 1, l + 1}));\n        if\
    \ (ite->first <= l and r <= ite->second) return T(0);\n        T sum_erased =\
    \ T(0);\n        if (ite->first <= l and l <= ite->second + 1) {\n           \
    \ l = ite->first;\n            sum_erased += ite->second - ite->first + 1;\n \
    \           ite = st.erase(ite);\n        } else\n            ite = next(ite);\n\
    \        while (r > ite->second) {\n            sum_erased += ite->second - ite->first\
    \ + 1;\n            ite = st.erase(ite);\n        }\n        if (ite->first -\
    \ 1 <= r) {\n            sum_erased += ite->second - ite->first + 1;\n       \
    \     r = ite->second;\n            st.erase(ite);\n        }\n        st.emplace(l,\
    \ r);\n        return r - l + 1 - sum_erased;\n    }\n    T insert(T x) { return\
    \ insert(x, x); }\n    // erase [l,r], \u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n\
    \    T erase(T l, T r) {\n        assert(l <= r);\n        auto ite = prev(st.lower_bound({l\
    \ + 1, l + 1}));\n        if (ite->first <= l and r <= ite->second) {\n      \
    \      // \u5B8C\u5168\u306B1\u3064\u306E\u533A\u9593\u306B\u5305\u542B\u3055\u308C\
    \u3066\u3044\u308B\n            if (ite->first < l) st.emplace(ite->first, l -\
    \ 1);\n            if (r < ite->second) st.emplace(r + 1, ite->second);\n    \
    \        st.erase(ite);\n            return r - l + 1;\n        }\n\n        T\
    \ ret = T(0);\n        if (ite->first <= l and l <= ite->second) {\n         \
    \   ret += ite->second - l + 1;  // \u6D88\u3048\u305F\n            if (ite->first\
    \ < l) st.emplace(ite->first, l - 1);\n            ite = st.erase(ite);  // \u6B21\
    \u3078\n        } else\n            ite = next(ite);\n        while (ite->second\
    \ <= r) {\n            ret += ite->second - ite->first + 1;\n            ite =\
    \ st.erase(ite);\n        }\n        // \u53F3\u7AEF\u304C\u533A\u9593\u306E\u9593\
    \u306B\u3042\u308B\u304B\n        if (ite->first <= r) {\n            ret += r\
    \ - ite->first + 1;\n            st.emplace(r + 1, ite->second);\n           \
    \ st.erase(ite);\n        }\n        return ret;\n    }\n    T erase(T x) { return\
    \ erase(x, x); }\n    // number of range\n    int size() { return (int)st.size()\
    \ - 2; }\n    // mex [x,~)\n    T mex(T x = 0) {\n        auto ite = prev(st.lower_bound({x\
    \ + 1, x + 1}));\n        if (ite->first <= x and x <= ite->second)\n        \
    \    return ite->second + 1;\n        else\n            return x;\n    }\n   \
    \ void output() {\n        cout << \"RangeSet : \";\n        for (auto &p : st)\
    \ {\n            if (p.first == -TINF or p.second == TINF) continue;\n       \
    \     cout << \"[\" << p.first << \", \" << p.second << \"] \";\n        }\n \
    \       cout << \"\\n\";\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: others/range-set.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc214_e.test.cpp
  - test/yukicoder/674.test.cpp
documentation_of: others/range-set.hpp
layout: document
title: "\u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u30C6\u30AF"
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
