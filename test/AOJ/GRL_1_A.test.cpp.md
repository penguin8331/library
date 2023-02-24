---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/AOJ/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing ld = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define pb push_back\n#define\
    \ mp make_pair\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) (((N) + (X)-1) / (X))\n\
    #define sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios()\
    \ {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n       \
    \ cout.tie(nullptr);\n        cout << fixed << setprecision(15);\n    };\n} fast_ios_;\n\
    template <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a = b,\
    \ true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b) { return\
    \ ((a > b) ? (a = b, true) : (false)); }\n//----------------------------------------------------------------------------\n\
    constexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[]\
    \ = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1,\
    \ -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 1\
    \ \"graph/dijkstra.hpp\"\nstruct Edge {\n    long long to;\n    long long cost;\n\
    };\nEdge make_edge(int to, int cost) {\n    Edge a;\n    a.to = to;\n    a.cost\
    \ = cost;\n    return a;\n}\nvector<long long> dijkstra(const vector<vector<Edge>>\
    \ &G, int s) {\n    int N = G.size();\n    vector<long long> dis(N, INF);\n  \
    \  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long\
    \ long, int>>> pq;  // \u300C\u4EEE\u306E\u6700\u77ED\u8DDD\u96E2, \u9802\u70B9\
    \u300D\u304C\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3076\n    dis[s] = 0;\n    pq.emplace(dis[s],\
    \ s);\n    while (!pq.empty()) {\n        pair<long long, int> p = pq.top();\n\
    \        pq.pop();\n        int v = p.second;\n        if (dis[v] < p.first) {\
    \  // \u6700\u77ED\u8DDD\u96E2\u3067\u7121\u3051\u308C\u3070\u7121\u8996\n   \
    \         continue;\n        }\n        for (auto &e : G[v]) {\n            if\
    \ (dis[e.to] > dis[v] + e.cost) {  // \u6700\u77ED\u8DDD\u96E2\u5019\u88DC\u306A\
    \u3089 priority_queue \u306B\u8FFD\u52A0\n                dis[e.to] = dis[v] +\
    \ e.cost;\n                pq.emplace(dis[e.to], e.to);\n            }\n     \
    \   }\n    }\n    return dis;\n}\n#line 4 \"test/AOJ/GRL_1_A.test.cpp\"\n\nint\
    \ main() {\n    int N, E, r;\n    cin >> N >> E >> r;\n    vector<vector<Edge>>\
    \ G(N);\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin\
    \ >> s >> t >> d;\n        G[s].push_back(make_edge(t, d));\n    }\n    auto res\
    \ = dijkstra(G, r);\n    for (int i = 0; i < N; i++) {\n        if (res[i] ==\
    \ INF) {\n            cout << \"INF\" << endl;\n        } else {\n           \
    \ cout << res[i] << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include \"template/template.hpp\"\n#include \"graph/dijkstra.hpp\"\n\nint main()\
    \ {\n    int N, E, r;\n    cin >> N >> E >> r;\n    vector<vector<Edge>> G(N);\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >>\
    \ t >> d;\n        G[s].push_back(make_edge(t, d));\n    }\n    auto res = dijkstra(G,\
    \ r);\n    for (int i = 0; i < N; i++) {\n        if (res[i] == INF) {\n     \
    \       cout << \"INF\" << endl;\n        } else {\n            cout << res[i]\
    \ << endl;\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 21:00:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_A.test.cpp
- /verify/test/AOJ/GRL_1_A.test.cpp.html
title: test/AOJ/GRL_1_A.test.cpp
---
