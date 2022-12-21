---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bfs.hpp
    title: "\u5E45\u512A\u5148\u5EA6\u63A2\u7D22"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#include \"template/template.hpp\"\n#include \"graph/bfs.hpp\"\n\nint main()\
    \ {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int u, k;\n        cin >> u >> k;\n\
    \        u--;\n        for (int j = 0; j < k; j++) {\n            int v;\n   \
    \         cin >> v;\n            v--;\n            G[u].push_back(v);\n      \
    \  }\n    }\n    auto res = BFS(G, 0);\n    for (int i = 0; i < N; i++) {\n  \
    \      cout << i + 1 << \" \" << res[i] << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/bfs.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_11_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:31:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_11_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_11_C.test.cpp
- /verify/test/AOJ/ALDS1_11_C.test.cpp.html
title: test/AOJ/ALDS1_11_C.test.cpp
---
