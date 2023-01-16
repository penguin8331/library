---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: "\u6700\u8FD1\u5171\u901A\u7956\u5148 (Lowest Common Ancestor)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/AOJ/GRL_5_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"graph/lca.hpp\"\nstruct LCA {\n    vector<vector<int>>\
    \ parent;  // parent[d][v] := 2^d-th parent of v\n    vector<int> depth;\n   \
    \ LCA() {}\n    LCA(const vector<vector<int>> &G, int r = 0) { init(G, r); }\n\
    \    void init(const vector<vector<int>> &G, int r = 0) {\n        int V = (int)G.size();\n\
    \        int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h,\
    \ vector<int>(V, -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n\
    \        for (int i = 0; i + 1 < (int)parent.size(); ++i)\n            for (int\
    \ v = 0; v < V; ++v)\n                if (parent[i][v] != -1)\n              \
    \      parent[i + 1][v] = parent[i][parent[i][v]];\n    }\n    void dfs(const\
    \ vector<vector<int>> &G, int v, int p, int d) {\n        parent[0][v] = p;\n\
    \        depth[v] = d;\n        for (auto e : G[v])\n            if (e != p) dfs(G,\
    \ e, v, d + 1);\n    }\n    int get(int u, int v) {\n        if (depth[u] > depth[v])\
    \ swap(u, v);\n        for (int i = 0; i < (int)parent.size(); ++i)\n        \
    \    if ((depth[v] - depth[u]) & (1 << i))\n                v = parent[i][v];\n\
    \        if (u == v) return u;\n        for (int i = (int)parent.size() - 1; i\
    \ >= 0; --i) {\n            if (parent[i][u] != parent[i][v]) {\n            \
    \    u = parent[i][u];\n                v = parent[i][v];\n            }\n   \
    \     }\n        return parent[0][u];\n    }\n};\n#line 4 \"test/AOJ/GRL_5_C.test.cpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; j++) {\n            int a;\n            cin >> a;\n\
    \            G[i].push_back(a);\n        }\n    }\n    LCA lca(G, 0);\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << lca.get(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#include \"template/template.hpp\"\n#include \"graph/lca.hpp\"\n\nint main()\
    \ {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; j++) {\n            int a;\n            cin >> a;\n\
    \            G[i].push_back(a);\n        }\n    }\n    LCA lca(G, 0);\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << lca.get(u, v) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/lca.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2023-01-05 11:13:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_C.test.cpp
- /verify/test/AOJ/GRL_5_C.test.cpp.html
title: test/AOJ/GRL_5_C.test.cpp
---
