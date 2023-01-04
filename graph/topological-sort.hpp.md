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
  bundledCode: "#line 1 \"graph/topological-sort.hpp\"\nvoid dfs(const vector<vector<int>>\
    \ &G, int v, vector<bool> &used, vector<int> &ans) {\n    used[v] = true;\n  \
    \  for (auto e : G[v]) {\n        if (!used[e]) {\n            dfs(G, e, used,\
    \ ans);\n        }\n    }\n    ans.push_back(v);  // \u5E30\u308A\u304C\u3051\u306B\
    push_back\n}\nvector<int> topo_sort(const vector<vector<int>> &G) {  // bfs\n\
    \    vector<int> ans;\n    int n = (int)G.size();\n    vector<bool> used(n, false);\n\
    \    for (int v = 0; v < n; v++) {  // \u672A\u63A2\u7D22\u306E\u9802\u70B9\u3054\
    \u3068\u306BDFS\n        if (!used[v]) dfs(G, v, used, ans);\n    }\n    reverse(ans.begin(),\
    \ ans.end());  // \u9006\u5411\u304D\u306A\u306E\u3067\u3072\u3063\u304F\u308A\
    \u8FD4\u3059\n    return ans;\n}\n"
  code: "void dfs(const vector<vector<int>> &G, int v, vector<bool> &used, vector<int>\
    \ &ans) {\n    used[v] = true;\n    for (auto e : G[v]) {\n        if (!used[e])\
    \ {\n            dfs(G, e, used, ans);\n        }\n    }\n    ans.push_back(v);\
    \  // \u5E30\u308A\u304C\u3051\u306Bpush_back\n}\nvector<int> topo_sort(const\
    \ vector<vector<int>> &G) {  // bfs\n    vector<int> ans;\n    int n = (int)G.size();\n\
    \    vector<bool> used(n, false);\n    for (int v = 0; v < n; v++) {  // \u672A\
    \u63A2\u7D22\u306E\u9802\u70B9\u3054\u3068\u306BDFS\n        if (!used[v]) dfs(G,\
    \ v, used, ans);\n    }\n    reverse(ans.begin(), ans.end());  // \u9006\u5411\
    \u304D\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\u3059\n    return ans;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological-sort.hpp
  requiredBy: []
  timestamp: '2023-01-04 13:19:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/topological-sort.hpp
layout: document
title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
---
