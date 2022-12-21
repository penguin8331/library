---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/warshall-floyd.hpp
    title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include \"template/template.hpp\"\n#include \"graph/warshall-floyd.hpp\"\n\n\
    int main() {\n    int V, E;\n    cin >> V >> E;\n    ll maxi = INF / 12;\n   \
    \ vector<vector<ll>> dp(V, vector<ll>(V, maxi));\n    for (int i = 0; i < V; i++)\
    \ {\n        dp[i][i] = 0;\n    }\n    for (int i = 0; i < E; i++) {\n       \
    \ int s, t, d;\n        cin >> s >> t >> d;\n        dp[s][t] = d;\n    }\n  \
    \  warshallfloyd(dp, V);\n    if (isnegative(dp, V)) {\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n    } else {\n        for (int i = 0; i < V; i++) {\n    \
    \        if (dp[i][0] > maxi / 2) {\n                cout << \"INF\";\n      \
    \      } else {\n                cout << dp[i][0];\n            }\n          \
    \  for (int j = 1; j < V; j++) {\n                if (dp[i][j] > maxi / 2) {\n\
    \                    cout << \" INF\";\n                } else {\n           \
    \         cout << \" \" << dp[i][j];\n                }\n            }\n     \
    \       cout << endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/warshall-floyd.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:31:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_C.test.cpp
- /verify/test/AOJ/GRL_1_C.test.cpp.html
title: test/AOJ/GRL_1_C.test.cpp
---
