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
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../data-structure/lazy-segment-tree.hpp\"\n#include\
    \ \"../template/template.hpp\"\n\nstruct Lazy_SegTree_Arthmetic {\n    struct\
    \ S {\n        ll sum;\n        int l, r;\n    };\n    struct F {\n        ll\
    \ a, b;\n        bool operator==(const F& other) {\n            if (a == other.a\
    \ && b == other.b)\n                return true;\n            else\n         \
    \       return false;\n        }\n    };\n    function<S(S, S)> fm = [](S s, S\
    \ t) -> S {\n        return {s.sum + t.sum, min(s.l, t.l), max(s.r, t.r)};\n \
    \   };\n    function<void(S&, F)> fa = [](S& s, F f) {\n        s = {s.sum + (f.a\
    \ * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l,\n             s.r};\n \
    \   };\n    function<void(F&, F)> fc = [](F& f, F g) {\n        f.a += g.a;\n\
    \        f.b += g.b;\n    };\n    int N;\n    Lazy_SegTree<S, F> seg;\n    explicit\
    \ Lazy_SegTree_Arthmetic(int n) : N(n) {\n        seg.init(N, fm, fa, fc, S({0,\
    \ inf, -inf}), F({0, 0}));\n        for (int i = 0; i < N; i++) {\n          \
    \  seg.set(i, S({0, i, i + 1}));\n        }\n        seg.build();\n    }\n   \
    \ void init(vector<int> v) {\n        for (int i = 0; i < N; i++) {\n        \
    \    seg.set(i, S({v[i], i, i + 1}));\n        }\n        seg.build();\n    }\n\
    \    void update(int l, int r, F f) {\n        seg.update(l, r, F({f.a, f.b -\
    \ f.a * seg.get(l, l + 1).l}));\n    }\n    S get(int l, int r) { return seg.get(l,\
    \ r); }\n};"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/lazy-segment-tree-arthmetic-raq.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/lazy-segment-tree-arthmetic-raq.hpp
layout: document
title: "\u7B49\u5DEE\u6570\u5217\u3092\u4F5C\u7528\u3055\u305B\u308B Lazy Segment\
  \ Tree"
---

## 概要

区間に等差数列を作用させる遅延セグメントツリー
RSQ, RAQ に対応

## 参考

[区間に等差数列を作用させる遅延セグメントツリー-null mn](https://null-mn.hatenablog.com/entry/2021/08/22/064325)
