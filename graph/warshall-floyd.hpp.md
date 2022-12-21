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
  bundledCode: "#line 1 \"graph/warshall-floyd.hpp\"\nvoid warshallfloyd(vector<vector<long\
    \ long>> dp, int V) {\n    // i->j\u306E\u7D4C\u8DEF\u306B\u3064\u3044\u3066i->k->j\u3092\
    \u691C\u8A0E\u3059\u308B\n    for (int k = 0; k < V; ++k) {\n        for (int\
    \ i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n          \
    \      dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);\n            }\n       \
    \ }\n    }\n}\nbool isnegative(vector<vector<long long>> dp, int V) {\n    bool\
    \ isnegative = false;\n    for (int v = 0; v < V; ++v) {\n        if (dp[v][v]\
    \ < 0) isnegative = true;\n    }\n    return isnegative;\n}\n"
  code: "void warshallfloyd(vector<vector<long long>> dp, int V) {\n    // i->j\u306E\
    \u7D4C\u8DEF\u306B\u3064\u3044\u3066i->k->j\u3092\u691C\u8A0E\u3059\u308B\n  \
    \  for (int k = 0; k < V; ++k) {\n        for (int i = 0; i < V; ++i) {\n    \
    \        for (int j = 0; j < V; ++j) {\n                dp[i][j] = min(dp[i][j],\
    \ dp[i][k] + dp[k][j]);\n            }\n        }\n    }\n}\nbool isnegative(vector<vector<long\
    \ long>> dp, int V) {\n    bool isnegative = false;\n    for (int v = 0; v < V;\
    \ ++v) {\n        if (dp[v][v] < 0) isnegative = true;\n    }\n    return isnegative;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/warshall-floyd.hpp
  requiredBy: []
  timestamp: '2022-12-21 16:26:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/warshall-floyd.hpp
layout: document
title: "\u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5"
---

## 概要

$dp[a][b]$ := $a$ から $b$ への距離として初期化しておいて、アルゴリズム終了後には<br>
$dp[a][b]$ := $a$ から $b$ への最短距離が格納される。注意点として、初期化時に $dp[a][a]$ = 0 となるようにする必要がある。なお負閉路判定に用いることもできて、
* 負閉路がなければ、任意の頂点 $a$ に対して $dp[a][a]$ = 0<br>
* 負閉路があったら、ある頂点 $a$ に対して $dp[a][a]$ < 0<br>
  
辺の追加クエリについては$a$,$b$間に辺が追加されたとき、すべての$i$->$j$について$i$->$a$->$b$->$j$を検討するだけで良いためO(V^2)
*/