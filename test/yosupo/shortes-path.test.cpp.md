---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dijkstra-route.hpp
    title: "Dijkstra (\u7D4C\u8DEF\u5FA9\u5143)"
  - icon: ':x:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/util.hpp
    title: template/util.hpp
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
  bundledCode: "#line 1 \"test/yosupo/shortes-path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\n\n#define pb push_back\n\
    #define mp make_pair\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n\
    #define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\
    \n\nusing ll = long long;\nusing ld = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/dijkstra-route.hpp\"\
    \n\nstruct Edge {\n    long long to;\n    long long cost;\n};\nvector<long long>\
    \ dijkstra(const vector<vector<Edge>> &G, int s, vector<int> &prev) {\n    int\
    \ N = G.size();\n    vector<long long> dis(N, INF);\n    prev.assign(N, -1); \
    \ // \u521D\u671F\u5316\n    priority_queue<pair<long long, int>, vector<pair<long\
    \ long, int>>, greater<pair<long long, int>>> pq;\n    dis[s] = 0;\n    pq.emplace(dis[s],\
    \ s);\n    while (!pq.empty()) {\n        pair<long long, int> p = pq.top();\n\
    \        pq.pop();\n        int v = p.second;\n        if (dis[v] < p.first) {\n\
    \            continue;\n        }\n        for (auto &e : G[v]) {\n          \
    \  if (dis[e.to] > dis[v] + e.cost) {\n                dis[e.to] = dis[v] + e.cost;\n\
    \                prev[e.to] = v;  // \u9802\u70B9 v \u3092\u901A\u3063\u3066 e.to\
    \ \u306B\u305F\u3069\u308A\u7740\u3044\u305F\n                pq.emplace(dis[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return dis;\n}\nvector<int> get_path(const\
    \ vector<int> &prev, int t) {\n    vector<int> path;\n    for (int cur = t; cur\
    \ != -1; cur = prev[cur]) {\n        path.push_back(cur);\n    }\n    reverse(path.begin(),\
    \ path.end());  // \u9006\u9806\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\
    \u3059\n    return path;\n}\n#line 4 \"test/yosupo/shortes-path.test.cpp\"\n\n\
    int main() {\n    int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    vector<vector<Edge>>\
    \ G(N, vector<Edge>(0));\n    for (int i = 0; i < M; i++) {\n        int a, b,\
    \ c;\n        cin >> a >> b >> c;\n        G[a].push_back(make_edge(b, c));\n\
    \    }\n    vector<int> prev;\n    auto res = dijkstra(G, s, prev);\n    auto\
    \ ans = get_path(prev, t);\n    if (res[t] == INF) {\n        cout << -1 << endl;\n\
    \        return 0;\n    }\n    cout << res[t] << \" \" << ans.size() - 1 << endl;\n\
    \    for (int i = 0; i < ans.size() - 1; i++) {\n        cout << ans[i] << \"\
    \ \" << ans[i + 1] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n#include\
    \ \"template/template.hpp\"\n#include \"graph/dijkstra-route.hpp\"\n\nint main()\
    \ {\n    int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    vector<vector<Edge>>\
    \ G(N, vector<Edge>(0));\n    for (int i = 0; i < M; i++) {\n        int a, b,\
    \ c;\n        cin >> a >> b >> c;\n        G[a].push_back(make_edge(b, c));\n\
    \    }\n    vector<int> prev;\n    auto res = dijkstra(G, s, prev);\n    auto\
    \ ans = get_path(prev, t);\n    if (res[t] == INF) {\n        cout << -1 << endl;\n\
    \        return 0;\n    }\n    cout << res[t] << \" \" << ans.size() - 1 << endl;\n\
    \    for (int i = 0; i < ans.size() - 1; i++) {\n        cout << ans[i] << \"\
    \ \" << ans[i + 1] << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - graph/dijkstra-route.hpp
  isVerificationFile: true
  path: test/yosupo/shortes-path.test.cpp
  requiredBy: []
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/shortes-path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortes-path.test.cpp
- /verify/test/yosupo/shortes-path.test.cpp.html
title: test/yosupo/shortes-path.test.cpp
---
