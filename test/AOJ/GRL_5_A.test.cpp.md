---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../graph/diameter-weighted.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include \"../../graph/diameter-weighted.hpp\"\n#include \"../../template/template.hpp\"\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<vector<Edge>> G(N, vector<Edge>(0));\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        Edge a, b;\n        a.to = t;\n        b.to = s;\n     \
    \   a.cost = w;\n        b.cost = w;\n        G[s].push_back(a);\n        G[t].push_back(b);\n\
    \    }\n    cout << tree_diameter<ll>(G) << endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_A.test.cpp
- /verify/test/AOJ/GRL_5_A.test.cpp.html
title: test/AOJ/GRL_5_A.test.cpp
---
