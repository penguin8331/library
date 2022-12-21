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
  bundledCode: "#line 1 \"graph/dijkstra-route.hpp\"\nstruct Edge {\n    long long\
    \ to;\n    long long cost;\n};\nvoid dijkstra(const vector<vector<Edge>> &G, int\
    \ s, vector<long long> &dis, vector<int> &prev) {\n    int N = G.size();\n   \
    \ dis.resize(N, INF);\n    prev.resize(N, -1);  // \u521D\u671F\u5316\n    priority_queue<pair<long\
    \ long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;\n\
    \    dis[s] = 0;\n    pq.emplace(dis[s], s);\n    while (!pq.empty()) {\n    \
    \    pair<long long, int> p = pq.top();\n        pq.pop();\n        int v = p.second;\n\
    \        if (dis[v] < p.first) {\n            continue;\n        }\n        for\
    \ (auto &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost) {\n       \
    \         dis[e.to] = dis[v] + e.cost;\n                prev[e.to] = v;  // \u9802\
    \u70B9 v \u3092\u901A\u3063\u3066 e.to \u306B\u305F\u3069\u308A\u7740\u3044\u305F\
    \n                pq.emplace(dis[e.to], e.to);\n            }\n        }\n   \
    \ }\n}\nvector<int> get_path(const vector<int> &prev, int t) {\n    vector<int>\
    \ path;\n    for (int cur = t; cur != -1; cur = prev[cur]) {\n        path.push_back(cur);\n\
    \    }\n    reverse(path.begin(), path.end());  // \u9006\u9806\u306A\u306E\u3067\
    \u3072\u3063\u304F\u308A\u8FD4\u3059\n    return path;\n}\n"
  code: "struct Edge {\n    long long to;\n    long long cost;\n};\nvoid dijkstra(const\
    \ vector<vector<Edge>> &G, int s, vector<long long> &dis, vector<int> &prev) {\n\
    \    int N = G.size();\n    dis.resize(N, INF);\n    prev.resize(N, -1);  // \u521D\
    \u671F\u5316\n    priority_queue<pair<long long, int>, vector<pair<long long,\
    \ int>>, greater<pair<long long, int>>> pq;\n    dis[s] = 0;\n    pq.emplace(dis[s],\
    \ s);\n    while (!pq.empty()) {\n        pair<long long, int> p = pq.top();\n\
    \        pq.pop();\n        int v = p.second;\n        if (dis[v] < p.first) {\n\
    \            continue;\n        }\n        for (auto &e : G[v]) {\n          \
    \  if (dis[e.to] > dis[v] + e.cost) {\n                dis[e.to] = dis[v] + e.cost;\n\
    \                prev[e.to] = v;  // \u9802\u70B9 v \u3092\u901A\u3063\u3066 e.to\
    \ \u306B\u305F\u3069\u308A\u7740\u3044\u305F\n                pq.emplace(dis[e.to],\
    \ e.to);\n            }\n        }\n    }\n}\nvector<int> get_path(const vector<int>\
    \ &prev, int t) {\n    vector<int> path;\n    for (int cur = t; cur != -1; cur\
    \ = prev[cur]) {\n        path.push_back(cur);\n    }\n    reverse(path.begin(),\
    \ path.end());  // \u9006\u9806\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\
    \u3059\n    return path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/dijkstra-route.hpp
  requiredBy: []
  timestamp: '2022-12-21 16:26:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dijkstra-route.hpp
layout: document
title: "\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5(\u7D4C\u8DEF\u5FA9\u5143\u3042\u308A\
  )"
---

## 概要

$dijkstra(G,s,dis,prev)$<br>
入力：グラフ $G$, 開始点 $s$, 距離を格納する $dis$, 最短経路の前の点を記録する $prev$<br>
計算量：$O(|E|log|V|)$<br>
副作用：$dis$, $prev$が書き換えられる

$getpath(prev, t)$<br>
入力：$dijkstra$ で得た $prev$, ゴール $t$<br>
出力： $s$から$t$への最短路のパス
