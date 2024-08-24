---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/scc.hpp
    title: Strongly Connected Component
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
    path: test/yosupo/two-sat.test.cpp
    title: test/yosupo/two-sat.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"scc.hpp\"\
    \n\nstruct TwoSat {\n    int N;\n    SCC scc;\n    TwoSat(int n) : N(n), scc(2\
    \ * N) {}\n\n    void add(int i, bool f, int j, bool g) {\n        scc.addedge(i\
    \ + (f ? N : 0), j + (g ? 0 : N));\n        scc.addedge(j + (g ? N : 0), i + (f\
    \ ? 0 : N));\n    }\n    void add_eq(int i, int j) {\n        add(i, true, j,\
    \ false);\n        add(i, false, j, true);\n    }\n    void add_neq(int i, int\
    \ j) {\n        add(i, true, j, true);\n        add(i, false, j, false);\n   \
    \ }\n    void add_true(int i) {\n        scc.addedge(i + N, i);\n    }\n    void\
    \ add_false(int i) {\n        scc.addedge(i, i + N);\n    }\n    vector<bool>\
    \ solve() {\n        scc.solve();\n        vector<bool> ans(N);\n        for (int\
    \ i = 0; i < N; i++) {\n            if (scc.cmp[i] == scc.cmp[i + N]) {\n    \
    \            return vector<bool>();\n            }\n            if (scc.cmp[i]\
    \ > scc.cmp[i + N]) {\n                ans[i] = true;\n            } else {\n\
    \                ans[i] = false;\n            }\n        }\n        return ans;\n\
    \    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/scc.hpp
  isVerificationFile: false
  path: graph/two-sat.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/two-sat.test.cpp
documentation_of: graph/two-sat.hpp
layout: document
redirect_from:
- /library/graph/two-sat.hpp
- /library/graph/two-sat.hpp.html
title: graph/two-sat.hpp
---
