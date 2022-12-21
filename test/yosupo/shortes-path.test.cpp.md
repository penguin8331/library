---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra-route.hpp
    title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u7D4C\u8DEF\u5FA9\u5143\u3042\
      \u308A)"
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"template/template.hpp\"\n#include \"graph/dijkstra-route.hpp\"\n\nint main()\
    \ {\n    int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    vector<vector<Edge>>\
    \ G(N, vector<Edge>(0));\n    for (int i = 0; i < M; i++) {\n        int a, b,\
    \ c;\n        cin >> a >> b >> c;\n        G[a].push_back(make_edge(b, c));\n\
    \    }\n    vector<int> prev;\n    auto res = dijkstra(G, s, prev);\n    auto\
    \ ans = get_path(prev, t);\n    cout << res[t] << \" \" << ans.size() - 1 << endl;\n\
    \    for (int i = 0; i < ans.size() - 1; i++) {\n        cout << ans[i] << \"\
    \ \" << ans[i + 1] << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/dijkstra-route.hpp
  isVerificationFile: true
  path: test/yosupo/shortes-path.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:31:06+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/shortes-path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortes-path.test.cpp
- /verify/test/yosupo/shortes-path.test.cpp.html
title: test/yosupo/shortes-path.test.cpp
---
