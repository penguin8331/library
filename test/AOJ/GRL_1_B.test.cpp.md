---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bellman-ford.hpp
    title: "\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
  bundledCode: "#line 1 \"test/AOJ/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing ld = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define pb push_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) ((N + X - 1) / X)\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct\
    \ fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename\
    \ T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false));\
    \ }\ntemplate <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a\
    \ = b, true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 1 \"graph/bellman-ford.hpp\"\nstruct Edge {\n    long\
    \ long from;\n    long long to;\n    long long cost;\n};\nbool bellman_ford(const\
    \ vector<Edge> &Es, int V, int s, vector<long long> &dis) {\n    dis.assign(V,\
    \ INF);\n    dis[s] = 0;\n    int cnt = 0;\n    while (cnt < V) {\n        bool\
    \ end = true;\n        for (auto e : Es) {\n            if (dis[e.from] != INF\
    \ && dis[e.from] + e.cost < dis[e.to]) {\n                dis[e.to] = dis[e.from]\
    \ + e.cost;\n                end = false;\n            }\n        }\n        if\
    \ (end) break;\n        cnt++;\n    }\n    return (cnt == V);\n}\n#line 4 \"test/AOJ/GRL_1_B.test.cpp\"\
    \n\nint main() {\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<Edge>\
    \ es(E);\n    for (int i = 0; i < E; i++) {\n        Edge a;\n        cin >> a.from\
    \ >> a.to >> a.cost;\n        es[i] = a;\n    }\n    vector<ll> dis(V);\n    if\
    \ (bellman_ford(es, V, r, dis)) {\n        cout << \"NEGATIVE CYCLE\" << endl;\n\
    \    } else {\n        for (int i = 0; i < V; i++) {\n            if (dis[i] ==\
    \ INF) {\n                cout << \"INF\" << endl;\n            } else {\n   \
    \             cout << dis[i] << endl;\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B\"\
    \n#include \"template/template.hpp\"\n#include \"graph/bellman-ford.hpp\"\n\n\
    int main() {\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<Edge> es(E);\n\
    \    for (int i = 0; i < E; i++) {\n        Edge a;\n        cin >> a.from >>\
    \ a.to >> a.cost;\n        es[i] = a;\n    }\n    vector<ll> dis(V);\n    if (bellman_ford(es,\
    \ V, r, dis)) {\n        cout << \"NEGATIVE CYCLE\" << endl;\n    } else {\n \
    \       for (int i = 0; i < V; i++) {\n            if (dis[i] == INF) {\n    \
    \            cout << \"INF\" << endl;\n            } else {\n                cout\
    \ << dis[i] << endl;\n            }\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/bellman-ford.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 22:45:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_B.test.cpp
- /verify/test/AOJ/GRL_1_B.test.cpp.html
title: test/AOJ/GRL_1_B.test.cpp
---
