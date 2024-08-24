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
  _extendedRequiredBy:
  - icon: ':x:'
    path: data-structure/implicit-treap.hpp
    title: ImplicitTreap
  - icon: ':warning:'
    path: data-structure/pair-query-by-implicit-treap.hpp
    title: PairQuery (by Implicit Treap)
  - icon: ':warning:'
    path: data-structure/priority-sum-by-implicit-treap.hpp
    title: PrioritySum (by Implicit Treap)
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/static-rmq-3.test.cpp
    title: test/yosupo/static-rmq-3.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Rand {\n  \
    \  mt19937 mt;\n\n    using ResultType = mt19937::result_type;\n    Rand() : Rand(random_device()())\
    \ {}\n    explicit Rand(ResultType seed) : mt(seed) {}\n\n    template <typename\
    \ T = uint64_t>\n    T get(T l, T r) {\n        uniform_int_distribution<T> dist(l,\
    \ r);\n        return dist(mt);\n    }\n\n    vector<int> shuffle(int n) {\n \
    \       vector<int> res(n);\n        iota(res.begin(), res.end(), 0);\n      \
    \  for (int i = n - 1; i >= 0; i--) {\n            swap(res[i], res[get(0, i)]);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: others/rand-int.hpp
  requiredBy:
  - data-structure/pair-query-by-implicit-treap.hpp
  - data-structure/priority-sum-by-implicit-treap.hpp
  - data-structure/implicit-treap.hpp
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/static-rmq-3.test.cpp
documentation_of: others/rand-int.hpp
layout: document
title: "\u4E71\u6570\u751F\u6210"
---
