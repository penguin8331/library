---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
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
    path: test/atcoder/abc177_f.test.cpp
    title: test/atcoder/abc177_f.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../data-structure/lazy-segment-tree.hpp\"\
    \n\nstruct Lazy_SegTree_Arthmetic {\n    struct S {\n        ll min, max, sum;\n\
    \        int l, r;\n    };\n    struct F {\n        ll a, b;\n        bool operator==(const\
    \ F& other) {\n            if (a == other.a && b == other.b)\n               \
    \ return true;\n            else\n                return false;\n        }\n \
    \   };\n    function<S(S, S)> fm = [](S s, S t) -> S { return {min(s.min, t.min),\
    \ max(s.max, t.max), s.sum + t.sum, min(s.l, t.l), max(s.r, t.r)}; };\n    function<void(S&,\
    \ F)> fa = [](S& s, F f) {\n        if (f.a == INF) {\n            return;\n \
    \       }\n        if (f.a >= 0) {\n            s = {f.a * s.l + f.b, f.a * (s.r\
    \ - 1) + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};\n\
    \            return;\n        } else {\n            s = {f.a * (s.r - 1) + f.b,\
    \ f.a * s.l + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};\n\
    \            return;\n        }\n    };\n    function<void(F&, F)> fc = [](F&\
    \ f, F g) {\n        if (g.a != INF) {\n            f = g;\n        }\n    };\n\
    \    int N;\n    Lazy_SegTree<S, F> seg;\n    explicit Lazy_SegTree_Arthmetic(int\
    \ n) : N(n) {\n        seg.init(N, fm, fa, fc, S({INF, -INF, 0, inf, -inf}), F({INF,\
    \ INF}));\n        for (int i = 0; i < N; i++) {\n            seg.set(i, S({0,\
    \ 0, 0, i, i + 1}));\n        }\n        seg.build();\n    }\n    void init(vector<int>\
    \ v) {\n        for (int i = 0; i < N; i++) {\n            seg.set(i, S({v[i],\
    \ v[i], v[i], i, i + 1}));\n        }\n        seg.build();\n    }\n    void update(int\
    \ l, int r, F f) {\n        seg.update(l, r, F({f.a, f.b - f.a * seg.get(l, l\
    \ + 1).l}));\n    }\n    S get(int l, int r) {\n        return seg.get(l, r);\n\
    \    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: false
  path: data-structure/lazy-segment-tree-arthmetic-ruq.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc177_f.test.cpp
documentation_of: data-structure/lazy-segment-tree-arthmetic-ruq.hpp
layout: document
title: "\u7B49\u5DEE\u6570\u5217\u3092\u4F5C\u7528\u3055\u305B\u308B Lazy Segment\
  \ Tree"
---

## 概要

区間に等差数列を作用させる遅延セグメントツリー
RMQ, RSQ, RUQ に対応

## 参考

[区間に等差数列を作用させる遅延セグメントツリー-null mn](https://null-mn.hatenablog.com/entry/2021/08/22/064325)
