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
    path: test/yosupo/shortes-path.test.cpp
    title: test/yosupo/shortes-path.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Edge {\n  \
    \  long long to;\n    long long cost;\n};\nvector<long long> dijkstra(const vector<vector<Edge>>\
    \ &G, int s, vector<int> &prev) {\n    int N = G.size();\n    vector<long long>\
    \ dis(N, INF);\n    prev.assign(N, -1);\n    priority_queue<pair<long long, int>,\
    \ vector<pair<long long, int>>, greater<pair<long long, int>>> pq;\n    dis[s]\
    \ = 0;\n    pq.emplace(dis[s], s);\n    while (!pq.empty()) {\n        pair<long\
    \ long, int> p = pq.top();\n        pq.pop();\n        int v = p.second;\n   \
    \     if (dis[v] < p.first) {\n            continue;\n        }\n        for (auto\
    \ &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost) {\n             \
    \   dis[e.to] = dis[v] + e.cost;\n                prev[e.to] = v;\n          \
    \      pq.emplace(dis[e.to], e.to);\n            }\n        }\n    }\n    return\
    \ dis;\n}\nvector<int> get_path(const vector<int> &prev, int t) {\n    vector<int>\
    \ path;\n    for (int cur = t; cur != -1; cur = prev[cur]) {\n        path.push_back(cur);\n\
    \    }\n    reverse(path.begin(), path.end());\n    return path;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/dijkstra-route.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/shortes-path.test.cpp
documentation_of: graph/dijkstra-route.hpp
layout: document
title: "Dijkstra (\u7D4C\u8DEF\u5FA9\u5143\u3042\u308A)"
---

## 使い方

- `dijkstra(vector<vector<Edge>> G,int s,vector<int> prev)`

    入力：グラフ `G`, 開始点 `s`, 最短経路の前の点を記録する `prev`

    出力: 開始点 `s` から各頂点への最短距離

    計算量：$O(E log V)$

    副作用：`prev` が書き換えられる

- `getpath(prev, t)`

    入力：`dijkstra` で得た `prev`, ゴール `t`

    出力: `s` から `t` への最短路のパス
