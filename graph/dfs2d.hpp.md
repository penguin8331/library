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
  bundledCode: "#line 1 \"graph/dfs2d.hpp\"\nvector<vector<bool>> seen;  //\u8A2A\u554F\
    \u6E08\u307F\u304B\u3069\u3046\u304B v->\u59CB\u70B9\nvoid dfs(int H, int W, const\
    \ vector<string> &G, pair<int, int> v) {\n    seen[v.first][v.second] = true;\n\
    \n    for (int i = 0; i < 4; i++) {\n        int X = dx[i] + v.first;\n      \
    \  int Y = dy[i] + v.second;\n        if (X < 0 || X >= H || Y < 0 || Y >= W)\
    \ continue;\n        if (seen[X][Y] || G[X][Y] == '#') continue;  //\u63A2\u7D22\
    \u6E08\u307F\u306A\u3089\u635C\u7D22\u3057\u306A\u3044\n        dfs(H, W, G, make_pair(X,\
    \ Y));\n    }\n}\n"
  code: "vector<vector<bool>> seen;  //\u8A2A\u554F\u6E08\u307F\u304B\u3069\u3046\u304B\
    \ v->\u59CB\u70B9\nvoid dfs(int H, int W, const vector<string> &G, pair<int, int>\
    \ v) {\n    seen[v.first][v.second] = true;\n\n    for (int i = 0; i < 4; i++)\
    \ {\n        int X = dx[i] + v.first;\n        int Y = dy[i] + v.second;\n   \
    \     if (X < 0 || X >= H || Y < 0 || Y >= W) continue;\n        if (seen[X][Y]\
    \ || G[X][Y] == '#') continue;  //\u63A2\u7D22\u6E08\u307F\u306A\u3089\u635C\u7D22\
    \u3057\u306A\u3044\n        dfs(H, W, G, make_pair(X, Y));\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dfs2d.hpp
  requiredBy: []
  timestamp: '2022-12-22 14:57:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dfs2d.hpp
layout: document
title: DFS-2D
---
