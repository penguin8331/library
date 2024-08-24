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
    path: test/atcoder/abc280_f.test.cpp
    title: test/atcoder/abc280_f.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T>\n\
    struct WeightedUnionFind {\n    // core member\n    vector<int> par;\n    vector<T>\
    \ weight;\n\n    // constructor\n    WeightedUnionFind() {}\n    WeightedUnionFind(int\
    \ N, T zero = 0) : par(N, -1), weight(N, zero) {}\n    void init(int N, T zero\
    \ = 0) {\n        par.assign(N, -1);\n        weight.assign(N, zero);\n    }\n\
    \n    // core methods\n    int root(int x) {\n        if (par[x] < 0)\n      \
    \      return x;\n        else {\n            int r = root(par[x]);\n        \
    \    weight[x] += weight[par[x]];\n            return par[x] = r;\n        }\n\
    \    }\n    bool issame(int x, int y) { return root(x) == root(y); }\n\n    //\
    \ v[y] - v[x] = w\n    bool unite(int x, int y, T w) {\n        w += get_weight(x),\
    \ w -= get_weight(y);\n        x = root(x), y = root(y);\n        if (x == y)\
    \ return false;\n        if (par[x] > par[y]) swap(x, y), w = -w;  // merge technique\n\
    \        par[x] += par[y];\n        par[y] = x;\n        weight[y] = w;\n    \
    \    return true;\n    }\n\n    int size(int x) { return -par[root(x)]; }\n\n\
    \    // get v[x]\n    T get_weight(int x) {\n        root(x);\n        return\
    \ weight[x];\n    }\n\n    // get v[y] - v[x]\n    T get_diff(int x, int y) {\
    \ return get_weight(y) - get_weight(x); }\n\n    // get groups\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> member(par.size());\n        for (int\
    \ v = 0; v < (int)par.size(); ++v) {\n            member[root(v)].push_back(v);\n\
    \        }\n        vector<vector<int>> res;\n        for (int v = 0; v < (int)par.size();\
    \ ++v) {\n            if (!member[v].empty()) res.push_back(member[v]);\n    \
    \    }\n        return res;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/weighted-union-find.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc280_f.test.cpp
documentation_of: data-structure/weighted-union-find.hpp
layout: document
title: WeightedUnionFind
---

## 注意

`diff(x, y)` を投げるとき、先に同じ連結成分に属しているかどうか確認する
