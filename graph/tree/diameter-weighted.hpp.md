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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstruct Edge {\n  \
    \  int to;\n    int cost;\n};\ntemplate <typename T>\npair<T, int> dfs(const vector<vector<Edge>>\
    \ &G, int u, int par) {\n    pair<T, int> ret = make_pair((T)0, u);\n    for (auto\
    \ e : G[u]) {\n        if (e.to == par) continue;\n        auto next = dfs<T>(G,\
    \ e.to, u);\n        next.first += e.cost;\n        ret = max(ret, next);\n  \
    \  }\n    return ret;\n}\ntemplate <typename T>\nT tree_diameter(const vector<vector<Edge>>\
    \ &G) {\n    pair<T, int> p = dfs<T>(G, 0, -1);\n    pair<T, int> q = dfs<T>(G,\
    \ p.second, -1);\n    return q.first;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree/diameter-weighted.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/diameter-weighted.hpp
layout: document
redirect_from:
- /library/graph/tree/diameter-weighted.hpp
- /library/graph/tree/diameter-weighted.hpp.html
title: graph/tree/diameter-weighted.hpp
---
