---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct LCA {\n   \
    \ vector<vector<int>> parent;\n    vector<int> depth;\n    LCA() {}\n    explicit\
    \ LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }\n    void init(const\
    \ vector<vector<int>>& G, int r = 0) {\n        int V = (int)G.size();\n     \
    \   int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V,\
    \ -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for\
    \ (int i = 0; i + 1 < (int)parent.size(); ++i)\n            for (int v = 0; v\
    \ < V; ++v)\n                if (parent[i][v] != -1)\n                    parent[i\
    \ + 1][v] = parent[i][parent[i][v]];\n    }\n    void dfs(const vector<vector<int>>&\
    \ G, int v, int p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n\
    \        for (auto e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n \
    \   }\n    int after(int u, int k) {\n        for (int i = 0; i < (int)parent.size();\
    \ i++) {\n            if (k & (1 << i)) {\n                u = parent[i][u];\n\
    \            }\n        }\n        return u;\n    }\n    int get(int u, int v)\
    \ {\n        if (depth[u] > depth[v]) swap(u, v);\n        v = after(v, depth[v]\
    \ - depth[u]);\n        if (u == v) return u;\n        for (int i = (int)parent.size()\
    \ - 1; i >= 0; --i) {\n            if (parent[i][u] != parent[i][v]) {\n     \
    \           u = parent[i][u];\n                v = parent[i][v];\n           \
    \ }\n        }\n        return parent[0][u];\n    }\n    int dist(int u, int v)\
    \ {\n        return depth[u] + depth[v] - 2 * depth[get(u, v)];\n    }\n    bool\
    \ is_on_path(int u, int v, int a) {\n        return dist(u, a) + dist(a, v) ==\
    \ dist(u, v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/lca.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/lca.hpp
layout: document
redirect_from:
- /library/graph/tree/lca.hpp
- /library/graph/tree/lca.hpp.html
title: graph/tree/lca.hpp
---
