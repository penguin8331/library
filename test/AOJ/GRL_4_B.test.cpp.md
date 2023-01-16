---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/topological-sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"test/AOJ/GRL_4_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"graph/topological-sort.hpp\"\nvoid dfs(const vector<vector<int>>\
    \ &G, int v, vector<bool> &used, vector<int> &ans) {\n    used[v] = true;\n  \
    \  for (auto e : G[v]) {\n        if (!used[e]) {\n            dfs(G, e, used,\
    \ ans);\n        }\n    }\n    ans.push_back(v);  // \u5E30\u308A\u304C\u3051\u306B\
    push_back\n}\nvector<int> topo_sort(const vector<vector<int>> &G) {  // bfs\n\
    \    vector<int> ans;\n    int n = (int)G.size();\n    vector<bool> used(n, false);\n\
    \    for (int v = 0; v < n; v++) {  // \u672A\u63A2\u7D22\u306E\u9802\u70B9\u3054\
    \u3068\u306BDFS\n        if (!used[v]) dfs(G, v, used, ans);\n    }\n    reverse(ans.begin(),\
    \ ans.end());  // \u9006\u5411\u304D\u306A\u306E\u3067\u3072\u3063\u304F\u308A\
    \u8FD4\u3059\n    return ans;\n}\n#line 4 \"test/AOJ/GRL_4_B.test.cpp\"\n\nint\
    \ main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V, vector<int>(0));\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n\
    \        G[s].push_back(t);\n    }\n    auto ans = topo_sort(G);\n    for (int\
    \ i = 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n#include \"template/template.hpp\"\n#include \"graph/topological-sort.hpp\"\n\
    \nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V,\
    \ vector<int>(0));\n    for (int i = 0; i < E; i++) {\n        int s, t;\n   \
    \     cin >> s >> t;\n        G[s].push_back(t);\n    }\n    auto ans = topo_sort(G);\n\
    \    for (int i = 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/topological-sort.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2023-01-04 13:25:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_4_B.test.cpp
- /verify/test/AOJ/GRL_4_B.test.cpp.html
title: test/AOJ/GRL_4_B.test.cpp
---
