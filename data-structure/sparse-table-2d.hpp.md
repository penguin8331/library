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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T>\n\
    struct SparseTable2D {\n    vector<vector<vector<vector<T>>>> dat;\n    vector<int>\
    \ height;\n    using Func = function<T(T, T)>;\n    Func F;\n\n    SparseTable2D()\
    \ {}\n    explicit SparseTable2D(\n        const vector<vector<T>> &vec,\n   \
    \     const Func f = [](T a, T b) { return min(a, b); }) {\n        init(vec,\
    \ f);\n    }\n    void init(\n        const vector<vector<T>> &vec,\n        const\
    \ Func f = [](T a, T b) { return min(a, b); }) {\n        F = f;\n        int\
    \ n = (int)vec.size(), m = (int)vec[0].size();\n        height.assign(max(n, m)\
    \ + 1, 0);\n        for (int i = 2; i <= max(n, m); i++) {\n            height[i]\
    \ = height[i >> 1] + 1;\n        }\n        dat.assign(height[n] + 1,\n      \
    \             vector<vector<vector<T>>>(\n                       height[m] + 1,\
    \ vector<vector<T>>(n, vector<T>(m))));\n        for (int i = 0; i < n; ++i) {\n\
    \            for (int j = 0; j < m; ++j) {\n                dat[0][0][i][j] =\
    \ vec[i][j];\n            }\n        }\n        for (int k = 1; (1 << k) <= n;\
    \ ++k) {\n            for (int i = 0; i + (1 << k) <= n; ++i) {\n            \
    \    for (int j = 0; j < m; ++j) {\n                    dat[k][0][i][j] = F(dat[k\
    \ - 1][0][i][j],\n                                        dat[k - 1][0][i + (1\
    \ << (k - 1))][j]);\n                }\n            }\n        }\n        for\
    \ (int k = 0; (1 << k) <= n; ++k) {\n            for (int l = 1; (1 << l) <= m;\
    \ ++l) {\n                for (int i = 0; i + (1 << k) <= n; ++i) {\n        \
    \            for (int j = 0; j + (1 << l) <= m; ++j) {\n                     \
    \   dat[k][l][i][j] =\n                            F(dat[k][l - 1][i][j],\n  \
    \                            dat[k][l - 1][i][j + (1 << (l - 1))]);\n        \
    \            }\n                }\n            }\n        }\n    }\n    T query(int\
    \ h1, int w1, int h2, int w2) {\n        int h = height[h2 - h1], w = height[w2\
    \ - w1];\n        return F(dat[h][w][h1][w1],\n                 F(dat[h][w][h2\
    \ - (1 << h)][w1],\n                   F(dat[h][w][h1][w2 - (1 << w)],\n     \
    \                dat[h][w][h2 - (1 << h)][w2 - (1 << w)])));\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/sparse-table-2d.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/sparse-table-2d.hpp
layout: document
title: Sparse Table 2D
---

## 使い方

### 宣言

`SparseTable(vec, F)` : 二次元配列 `vec` で構築、 `F` は二項演算

### クエリ

`query(h1, w1, h2, w2)` :  区間 $[A_{h_1,w_1}, A_{h2, w2})$ の総積を取得する。
