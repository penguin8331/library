---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman-ford.hpp
    title: "Bellman\u2013Ford"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
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
    \ template/template.hpp: line 19: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include \"template/template.hpp\"\n#include \"graph/bellman-ford.hpp\"\n\n\
    int main() {\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<Edge> es(E);\n\
    \    for (int i = 0; i < E; i++) {\n        Edge a;\n        cin >> a.from >>\
    \ a.to >> a.cost;\n        es[i] = a;\n    }\n    vector<ll> dis(V);\n    if (bellman_ford(es,\
    \ V, r, dis)) {\n        cout << \"NEGATIVE CYCLE\" << endl;\n    } else {\n \
    \       for (int i = 0; i < V; i++) {\n            if (dis[i] == INF) {\n    \
    \            cout << \"INF\" << endl;\n            } else {\n                cout\
    \ << dis[i] << endl;\n            }\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/bellman-ford.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 16:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_B.test.cpp
- /verify/test/AOJ/GRL_1_B.test.cpp.html
title: test/AOJ/GRL_1_B.test.cpp
---
