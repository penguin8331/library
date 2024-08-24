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
  - icon: ':warning:'
    path: graph/tree/euler-tour-on-edges.hpp
    title: graph/tree/euler-tour-on-edges.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree/euler-tour-on-nodes.hpp
    title: graph/tree/euler-tour-on-nodes.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2667.test.cpp
    title: test/AOJ/2667.test.cpp
  - icon: ':x:'
    path: test/yosupo/static-rmq-4.test.cpp
    title: test/yosupo/static-rmq-4.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T>\n\
    struct SparseTable {\n    vector<vector<T>> dat;\n    vector<int> height;\n  \
    \  using Func = function<T(T, T)>;\n    Func F;\n\n    SparseTable() {}\n    explicit\
    \ SparseTable(\n        const vector<T> &vec,\n        const Func f = [](T a,\
    \ T b) { return min(a, b); }) {\n        init(vec, f);\n    }\n    void init(\n\
    \        const vector<T> &vec,\n        const Func f = [](T a, T b) { return min(a,\
    \ b); }) {\n        F = f;\n        int n = (int)vec.size(), h = 32 - __builtin_clz(n);\n\
    \        dat.assign(h, vector<T>(1 << h));\n        height.assign(n + 1, 0);\n\
    \        for (int i = 2; i <= n; i++) height[i] = height[i >> 1] + 1;\n      \
    \  for (int i = 0; i < n; ++i) dat[0][i] = vec[i];\n        for (int i = 1; i\
    \ < h; ++i)\n            for (int j = 0; j < n; ++j)\n                dat[i][j]\
    \ = F(dat[i - 1][j],\n                              dat[i - 1][min(j + (1 << (i\
    \ - 1)), n - 1)]);\n    }\n\n    T get(int a, int b) {\n        return F(dat[height[b\
    \ - a]][a],\n                 dat[height[b - a]][b - (1 << height[b - a])]);\n\
    \    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/sparse-table.hpp
  requiredBy:
  - graph/tree/euler-tour-on-nodes.hpp
  - graph/tree/euler-tour-on-edges.hpp
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/2667.test.cpp
  - test/yosupo/static-rmq-4.test.cpp
documentation_of: data-structure/sparse-table.hpp
layout: document
redirect_from:
- /library/data-structure/sparse-table.hpp
- /library/data-structure/sparse-table.hpp.html
title: data-structure/sparse-table.hpp
---
