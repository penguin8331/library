---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/low-link.hpp
    title: "Low-Link(\u6A4B,\u95A2\u7BC0\u70B9\u5217\u6319)"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 19: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n#include \"template/template.hpp\"\n#include \"graph/low-link.hpp\"\n\nint main()\
    \ {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V, vector<int>(0));\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n\
    \        G[s].push_back(t);\n        G[t].push_back(s);\n    }\n    LowLink A;\n\
    \    A.solve(G);\n    auto ans = A.aps;\n    sort(all(ans));\n    for (int i =\
    \ 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/low-link.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:31:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_3_A.test.cpp
- /verify/test/AOJ/GRL_3_A.test.cpp.html
title: test/AOJ/GRL_3_A.test.cpp
---
