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
    path: test/yosupo/cycle-detection-undirected.test.cpp
    title: test/yosupo/cycle-detection-undirected.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nvoid cycle_detection(int\
    \ N, int M, vector<pair<int, int>> edges, vector<vector<pair<int, int>>> G, vector<int>&\
    \ V, vector<int>& E) {\n    // dfs tree\n    vector<bool> used_e(M);\n    vector<pair<int,\
    \ int>> par(N, {-1, -1});  // (vid, eid)\n    vector<int> dep(N, -1);\n    auto\
    \ dfs = [&](auto& dfs, int v, int d) -> void {\n        assert(dep[v] == -1);\n\
    \        dep[v] = d;\n        for (auto&& [eid, to] : G[v]) {\n            if\
    \ (dep[to] != -1) continue;\n            used_e[eid] = 1;\n            par[to]\
    \ = {v, eid};\n            dfs(dfs, to, d + 1);\n        }\n    };\n\n    for\
    \ (int v = 0; v < N; ++v) {\n        if (dep[v] == -1) dfs(dfs, v, 0);\n    }\n\
    \n    auto check = [&](vector<int> V, vector<int> E) -> bool {\n        int L\
    \ = V.size();\n        assert(L >= 1);\n        vector<int> used_v(N), used_e(M);\n\
    \        for (auto&& v : V) {\n            if (used_v[v]) return false;\n    \
    \        used_v[v] = 1;\n        }\n        for (auto&& e : E) {\n           \
    \ if (used_e[e]) return false;\n            used_e[e] = 1;\n        }\n      \
    \  for (int i = 0; i < L; ++i) {\n            auto [a, b] = edges[E[i]];\n   \
    \         int j = (i + 1 == L ? 0 : i + 1);\n            bool ok = 0;\n      \
    \      if (V[i] == a && V[j] == b) ok = 1;\n            if (V[i] == b && V[j]\
    \ == a) ok = 1;\n            if (!ok) return false;\n        }\n        return\
    \ true;\n    };\n\n    for (int eid = 0; eid < M; ++eid) {\n        if (used_e[eid])\
    \ continue;\n        auto [a, b] = edges[eid];\n        if (dep[a] > dep[b]) swap(a,\
    \ b);\n        assert(dep[a] <= dep[b]);\n\n        // \u5F8C\u9000\u8FBA e \u304B\
    \u3089\u3001\u30B5\u30A4\u30AF\u30EB\u304C\u51FA\u6765\u308B\n        V = {b};\n\
    \        while (V.back() != a) {\n            auto [v, e] = par[V.back()];\n \
    \           V.push_back(v);\n            E.push_back(e);\n        }\n        E.push_back(eid);\n\
    \        assert(check(V, E));\n        return;\n    }\n    return;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/cycle-detection-undirected.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/cycle-detection-undirected.test.cpp
documentation_of: graph/cycle-detection-undirected.hpp
layout: document
redirect_from:
- /library/graph/cycle-detection-undirected.hpp
- /library/graph/cycle-detection-undirected.hpp.html
title: graph/cycle-detection-undirected.hpp
---
