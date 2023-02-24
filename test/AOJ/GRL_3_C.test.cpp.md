---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/scc.hpp
    title: Strongly Connected Component
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 18: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include \"template/template.hpp\"\n#include \"graph/scc.hpp\"\n\nint main()\
    \ {\n    int V, E;\n    cin >> V >> E;\n    SCC scc(V);\n    for (int i = 0; i\
    \ < E; i++) {\n        int a, b;\n        cin >> a >> b;\n        scc.addedge(a,\
    \ b);\n    }\n    scc.solve();\n    int Q;\n    cin >> Q;\n    for (int i = 0;\
    \ i < Q; i++) {\n        int u, v;\n        cin >> u >> v;\n        cout << (scc.cmp[u]\
    \ == scc.cmp[v] ? 1 : 0) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 16:23:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_3_C.test.cpp
- /verify/test/AOJ/GRL_3_C.test.cpp.html
title: test/AOJ/GRL_3_C.test.cpp
---
