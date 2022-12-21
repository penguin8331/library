---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/low-link.hpp
    title: "Low-Link(\u6A4B,\u95A2\u7BC0\u70B9\u5217\u6319)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/AOJ/GRL_3_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"graph/low-link.hpp\"\nstruct LowLink {\n    // main\
    \ results\n    vector<int> aps;             // articulation points\n    vector<pair<int,\
    \ int>> brs;  // brideges\n\n    // intermediate results\n    vector<int> seen,\
    \ ord, low;\n    void dfs_lowlink(const vector<vector<int>> &G, int v, int p =\
    \ -1) {\n        static int time = 0;\n        seen[v] = true;\n        ord[v]\
    \ = low[v] = time++;\n        int num_of_child = 0;\n        bool exist = false;\
    \  // for articulation point\n        for (auto ch : G[v]) {\n            if (seen[ch])\
    \ {\n                if (ch != p) low[v] = min(low[v], ord[ch]);  // back edge\n\
    \                continue;\n            }\n            dfs_lowlink(G, ch, v);\n\
    \            low[v] = min(low[v], low[ch]);  // forward edge of DFS-tree\n   \
    \         if (ord[v] < low[ch]) brs.emplace_back(v, ch);\n            if (ord[v]\
    \ <= low[ch]) exist = true;\n            ++num_of_child;\n        }\n        if\
    \ ((p == -1 && num_of_child > 1) || (p != -1 && exist)) aps.emplace_back(v);\n\
    \    }\n    void solve(const vector<vector<int>> &G) {\n        int N = (int)G.size();\n\
    \        seen.assign(N, 0);\n        ord.resize(N);\n        low.resize(N);\n\
    \        aps.clear();\n        brs.clear();\n        for (int v = 0; v < N; ++v)\n\
    \            if (!seen[v]) dfs_lowlink(G, v);\n    }\n};\n#line 4 \"test/AOJ/GRL_3_A.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V,\
    \ vector<int>(0));\n    for (int i = 0; i < E; i++) {\n        int s, t;\n   \
    \     cin >> s >> t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    LowLink A;\n    A.solve(G);\n    auto ans = A.aps;\n    sort(all(ans));\n\
    \    for (int i = 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n#include \"template/template.hpp\"\n#include \"graph/low-link.hpp\"\n\nint main()\
    \ {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V, vector<int>(0));\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n\
    \        G[s].push_back(t);\n        G[t].push_back(s);\n    }\n    LowLink A;\n\
    \    A.solve(G);\n    auto ans = A.aps;\n    sort(all(ans));\n    for (int i =\
    \ 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/low-link.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:41:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_3_A.test.cpp
- /verify/test/AOJ/GRL_3_A.test.cpp.html
title: test/AOJ/GRL_3_A.test.cpp
---
