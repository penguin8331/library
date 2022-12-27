---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/diameter-weighted.hpp
    title: "\u6728\u306E\u76F4\u5F84"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A
  bundledCode: "#line 1 \"test/AOJ/GRL_5_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"graph/diameter-weighted.hpp\"\nstruct Edge {\n   \
    \ int to;\n    int cost;\n};\ntemplate <typename T>\npair<T, int> dfs(const vector<vector<Edge>>\
    \ &G, int u, int par) {  // \u6700\u9060\u70B9\u9593\u8DDD\u96E2\u3068\u6700\u9060\
    \u70B9\u3092\u6C42\u3081\u308B\n    pair<T, int> ret = make_pair((T)0, u);\n \
    \   for (auto e : G[u]) {\n        if (e.to == par) continue;\n        auto next\
    \ = dfs<T>(G, e.to, u);\n        next.first += e.cost;\n        ret = max(ret,\
    \ next);\n    }\n    return ret;\n}\ntemplate <typename T>\nT tree_diameter(const\
    \ vector<vector<Edge>> &G) {\n    pair<T, int> p = dfs<T>(G, 0, -1);\n    pair<T,\
    \ int> q = dfs<T>(G, p.second, -1);\n    return q.first;\n}\n#line 4 \"test/AOJ/GRL_5_A.test.cpp\"\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<vector<Edge>> G(N, vector<Edge>(0));\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        Edge a, b;\n        a.to = t;\n        b.to = s;\n     \
    \   a.cost = w;\n        b.cost = w;\n        G[s].push_back(a);\n        G[t].push_back(b);\n\
    \    }\n    cout << tree_diameter<ll>(G) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include \"template/template.hpp\"\n#include \"graph/diameter-weighted.hpp\"\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<vector<Edge>> G(N, vector<Edge>(0));\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        Edge a, b;\n        a.to = t;\n        b.to = s;\n     \
    \   a.cost = w;\n        b.cost = w;\n        G[s].push_back(a);\n        G[t].push_back(b);\n\
    \    }\n    cout << tree_diameter<ll>(G) << endl;\n}"
  dependsOn:
  - template/template.hpp
  - graph/diameter-weighted.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-24 12:34:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_A.test.cpp
- /verify/test/AOJ/GRL_5_A.test.cpp.html
title: test/AOJ/GRL_5_A.test.cpp
---
