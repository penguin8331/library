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
  code: "#pragma once\r\n#include \"../template/template.hpp\"\r\n\r\ntemplate <typename\
    \ T>\r\nstruct Compress {\r\n    vector<T> xs;\r\n\r\n    Compress() {}\r\n\r\n\
    \    explicit Compress(const vector<T>& vs) { add(vs); }\r\n\r\n    explicit Compress(const\
    \ initializer_list<vector<T>>& vs) { add(vs); }\r\n\r\n    void add(const vector<T>&\
    \ vs) { xs.insert(xs.end(), vs.begin(), vs.end()); }\r\n\r\n    void add(const\
    \ T& x) { xs.push_back(x); }\r\n\r\n    void build() {\r\n        sort(all(xs));\r\
    \n        xs.erase(unique(all(xs)), xs.end());\r\n    }\r\n\r\n    vector<int>\
    \ get(const vector<T>& vs) const {\r\n        vector<int> ret;\r\n        transform(all(vs),\
    \ back_inserter(ret), [&](const T& x) {\r\n            return lower_bound(all(xs),\
    \ x) - xs.begin();\r\n        });\r\n        return ret;\r\n    }\r\n\r\n    int\
    \ get(const T& x) const { return lower_bound(all(xs), x) - xs.begin(); }\r\n\r\
    \n    const T& operator[](int k) const { return xs[k]; }\r\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: others/compress.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

# クエリ

- `add(vs)` : 配列 `vs` 内の座標を追加
- `add(x)` : 座標 `x` を追加
- `build()` : ビルドする
- `get(vs)` : `vs` 内の座標を座標圧縮したものを返す
- `get(x)` : 座標 `x` を座標圧縮したものを返す
- `[k]` : 座標圧縮後の `k` が示すもとの座標を返す
