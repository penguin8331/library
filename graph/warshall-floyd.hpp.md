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
redirect_from:
- /library/graph/warshall-floyd.hpp
- /library/graph/warshall-floyd.hpp.html
title: graph/warshall-floyd.hpp
---
