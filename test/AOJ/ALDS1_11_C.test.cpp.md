---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bfs.hpp
    title: "\u5E45\u512A\u5148\u5EA6\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_11_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"graph/bfs.hpp\"\nvector<int> BFS(const vector<vector<int>>\
    \ &G, int s) {\n    int N = (int)G.size();    // \u9802\u70B9\u6570\n    vector<int>\
    \ dist(N, -1);  // \u3059\u3079\u3066\u306E\u9802\u70B9\u3092\u672A\u8A2A\u554F\
    \u306B\u521D\u671F\u5316\n    queue<int> que;\n\n    // \u521D\u671F\u6761\u4EF6\
    \ (\u9802\u70B9s\u3092\u521D\u671F\u9802\u70B9\u3068\u3059\u308B)\n    dist[s]\
    \ = 0;\n    que.push(s);  // s\u3092\u63A2\u7D22\u6E08\u307F\u9802\u70B9\u306B\
    \n\n    // BFS\u958B\u59CB\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n\n        // \u9802\u70B9v\u304B\u3089\u305F\u3069\u308C\u308B\
    \u9802\u70B9\u3092\u5168\u3066\u8ABF\u3079\u308B\n        for (int x : G[v]) {\n\
    \            // \u3059\u3067\u306B\u767A\u898B\u6E08\u307F\u306E\u9802\u70B9\u306F\
    \u63A2\u7D22\u3057\u306A\u3044\n            if (dist[x] != -1) continue;\n\n \
    \           // \u65B0\u305F\u306A\u672A\u63A2\u7D22\u9802\u70B9x\u306B\u3064\u3044\
    \u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\u65B0\u3057\u3066\u30AD\u30E5\u30FC\
    \u306B\u633F\u5165\n            dist[x] = dist[v] + 1;\n            que.push(x);\n\
    \        }\n    }\n    return dist;\n}\n#line 4 \"test/AOJ/ALDS1_11_C.test.cpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int u, k;\n        cin >> u >> k;\n\
    \        u--;\n        for (int j = 0; j < k; j++) {\n            int v;\n   \
    \         cin >> v;\n            v--;\n            G[u].push_back(v);\n      \
    \  }\n    }\n    auto res = BFS(G, 0);\n    for (int i = 0; i < N; i++) {\n  \
    \      cout << i + 1 << \" \" << res[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#include \"template/template.hpp\"\n#include \"graph/bfs.hpp\"\n\nint main()\
    \ {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int u, k;\n        cin >> u >> k;\n\
    \        u--;\n        for (int j = 0; j < k; j++) {\n            int v;\n   \
    \         cin >> v;\n            v--;\n            G[u].push_back(v);\n      \
    \  }\n    }\n    auto res = BFS(G, 0);\n    for (int i = 0; i < N; i++) {\n  \
    \      cout << i + 1 << \" \" << res[i] << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/bfs.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_11_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:41:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_11_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_11_C.test.cpp
- /verify/test/AOJ/ALDS1_11_C.test.cpp.html
title: test/AOJ/ALDS1_11_C.test.cpp
---
