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
  bundledCode: "#line 1 \"test/yosupo/shortes-path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n#line 1 \"template/template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n#define pb push_back\n#define mp make_pair\n#define\
    \ mt make_tuple\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) ((N + X - 1) / X)\n#define\
    \ sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios() {\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL <<\
    \ 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] =\
    \ {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 1 \"graph/dijkstra-route.hpp\"\nstruct Edge {\n    long\
    \ long to;\n    long long cost;\n};\nEdge make_edge(int to, int cost) {\n    Edge\
    \ a;\n    a.to = to;\n    a.cost = cost;\n    return a;\n}\nvector<long long>\
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
    \ ans = get_path(prev, t);\n    cout << res[t] << \" \" << ans.size() - 1 << endl;\n\
    \    for (int i = 0; i < ans.size() - 1; i++) {\n        cout << ans[i] << \"\
    \ \" << ans[i + 1] << endl;\n    }\n}\n"
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
  timestamp: '2022-12-21 18:41:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/shortes-path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortes-path.test.cpp
- /verify/test/yosupo/shortes-path.test.cpp.html
title: test/yosupo/shortes-path.test.cpp
---
