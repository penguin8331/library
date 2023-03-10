---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low-link.hpp
    title: "Low-Link (\u6A4B, \u95A2\u7BC0\u70B9\u5217\u6319)"
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"test/AOJ/GRL_3_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define pb push_back\n#define mp make_pair\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ld = long double;\n\
    using pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int\
    \ inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1,\
    \ 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr\
    \ int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\
    \n\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a\
    \ = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b)\
    \ { return ((a > b) ? (a = b, true) : (false)); }\n#line 3 \"template/util.hpp\"\
    \n\nstruct IOSetup {\n    IOSetup() {\n        std::cin.tie(nullptr);\n      \
    \  std::ios::sync_with_stdio(false);\n        std::cout.tie(0);\n        std::cout\
    \ << std::fixed << std::setprecision(12);\n        std::cerr << std::fixed <<\
    \ std::setprecision(12);\n    }\n} IOSetup;\n#line 1 \"template/debug.hpp\"\n\
    #ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n#define debug(...)\n#define line\n\
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/low-link.hpp\"\
    \n\nstruct LowLink {\n    vector<int> aps;             // \u95A2\u7BC0\u70B9\n\
    \    vector<pair<int, int>> brs;  // \u6A4B\n\n    vector<int> seen, ord, low;\n\
    \    void dfs_lowlink(const vector<vector<int>> &G, int v, int p = -1) {\n   \
    \     static int time = 0;\n        seen[v] = true;\n        ord[v] = low[v] =\
    \ time++;\n        int num_of_child = 0;\n        bool exist = false;  // for\
    \ articulation point\n        for (auto ch : G[v]) {\n            if (seen[ch])\
    \ {\n                if (ch != p) low[v] = min(low[v], ord[ch]);  // back edge\n\
    \                continue;\n            }\n            dfs_lowlink(G, ch, v);\n\
    \            low[v] = min(low[v], low[ch]);  // forward edge of DFS-tree\n   \
    \         if (ord[v] < low[ch]) brs.emplace_back(v, ch);\n            if (ord[v]\
    \ <= low[ch]) exist = true;\n            ++num_of_child;\n        }\n        if\
    \ ((p == -1 && num_of_child > 1) || (p != -1 && exist)) aps.emplace_back(v);\n\
    \    }\n    void solve(const vector<vector<int>> &G) {\n        int N = (int)G.size();\n\
    \        seen.assign(N, 0);\n        ord.resize(N);\n        low.resize(N);\n\
    \        aps.clear();\n        brs.clear();\n        for (int v = 0; v < N; ++v)\n\
    \            if (!seen[v]) dfs_lowlink(G, v);\n    }\n};\n#line 4 \"test/AOJ/GRL_3_B.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V,\
    \ vector<int>(0));\n    for (int i = 0; i < E; i++) {\n        int s, t;\n   \
    \     cin >> s >> t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    LowLink A;\n    A.solve(G);\n    auto ans = A.brs;\n    for (int i\
    \ = 0; i < ans.size(); i++) {\n        if (ans[i].first > ans[i].second) {\n \
    \           swap(ans[i].first, ans[i].second);\n        }\n    }\n    sort(all(ans));\n\
    \    for (int i = 0; i < ans.size(); i++) {\n        cout << ans[i].first << \"\
    \ \" << ans[i].second << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/low-link.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V,\
    \ vector<int>(0));\n    for (int i = 0; i < E; i++) {\n        int s, t;\n   \
    \     cin >> s >> t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    LowLink A;\n    A.solve(G);\n    auto ans = A.brs;\n    for (int i\
    \ = 0; i < ans.size(); i++) {\n        if (ans[i].first > ans[i].second) {\n \
    \           swap(ans[i].first, ans[i].second);\n        }\n    }\n    sort(all(ans));\n\
    \    for (int i = 0; i < ans.size(); i++) {\n        cout << ans[i].first << \"\
    \ \" << ans[i].second << endl;\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/low-link.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_3_B.test.cpp
- /verify/test/AOJ/GRL_3_B.test.cpp.html
title: test/AOJ/GRL_3_B.test.cpp
---
