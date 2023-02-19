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
  bundledCode: "#line 1 \"graph/is_biparite.hpp\"\nbool isbipartite(const vector<vector<int>>&\
    \ G) {\n    int N = (int)G.size();\n    vector<int> color(N, -1);\n\n    for (int\
    \ v = 0; v < N; ++v) {\n        if (color[v] != -1) {\n            continue;\n\
    \        }\n        queue<int> que;\n        color[v] = 0;\n        que.push(v);\n\
    \        while (!que.empty()) {\n            int qv = que.front();\n         \
    \   que.pop();\n            for (auto nv : G[qv]) {\n                if (color[nv]\
    \ != -1) {\n                    if (color[nv] == color[qv]) {\n              \
    \          return false;\n                    }\n                    continue;\n\
    \                }\n                color[nv] = 1 - color[qv];\n             \
    \   que.push(nv);\n            }\n        }\n    }\n    return true;\n}\n"
  code: "bool isbipartite(const vector<vector<int>>& G) {\n    int N = (int)G.size();\n\
    \    vector<int> color(N, -1);\n\n    for (int v = 0; v < N; ++v) {\n        if\
    \ (color[v] != -1) {\n            continue;\n        }\n        queue<int> que;\n\
    \        color[v] = 0;\n        que.push(v);\n        while (!que.empty()) {\n\
    \            int qv = que.front();\n            que.pop();\n            for (auto\
    \ nv : G[qv]) {\n                if (color[nv] != -1) {\n                    if\
    \ (color[nv] == color[qv]) {\n                        return false;\n        \
    \            }\n                    continue;\n                }\n           \
    \     color[nv] = 1 - color[qv];\n                que.push(nv);\n            }\n\
    \        }\n    }\n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/is_biparite.hpp
  requiredBy: []
  timestamp: '2023-02-19 15:34:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/is_biparite.hpp
layout: document
redirect_from:
- /library/graph/is_biparite.hpp
- /library/graph/is_biparite.hpp.html
title: graph/is_biparite.hpp
---
