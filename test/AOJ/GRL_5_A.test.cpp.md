---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/diameter-weighted.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
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
    \ std::setprecision(12);\n    }\n};\n#line 7 \"template/template.hpp\"\nusing\
    \ namespace std;\n#line 3 \"graph/diameter-weighted.hpp\"\n\nstruct Edge {\n \
    \   int to;\n    int cost;\n};\ntemplate <typename T>\npair<T, int> dfs(const\
    \ vector<vector<Edge>> &G, int u, int par) {  // \u6700\u9060\u70B9\u9593\u8DDD\
    \u96E2\u3068\u6700\u9060\u70B9\u3092\u6C42\u3081\u308B\n    pair<T, int> ret =\
    \ make_pair((T)0, u);\n    for (auto e : G[u]) {\n        if (e.to == par) continue;\n\
    \        auto next = dfs<T>(G, e.to, u);\n        next.first += e.cost;\n    \
    \    ret = max(ret, next);\n    }\n    return ret;\n}\ntemplate <typename T>\n\
    T tree_diameter(const vector<vector<Edge>> &G) {\n    pair<T, int> p = dfs<T>(G,\
    \ 0, -1);\n    pair<T, int> q = dfs<T>(G, p.second, -1);\n    return q.first;\n\
    }\n#line 4 \"test/AOJ/GRL_5_A.test.cpp\"\nint main() {\n    int N;\n    cin >>\
    \ N;\n    vector<vector<Edge>> G(N, vector<Edge>(0));\n    for (int i = 0; i <\
    \ N - 1; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        Edge\
    \ a, b;\n        a.to = t;\n        b.to = s;\n        a.cost = w;\n        b.cost\
    \ = w;\n        G[s].push_back(a);\n        G[t].push_back(b);\n    }\n    cout\
    \ << tree_diameter<ll>(G) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/diameter-weighted.hpp\"\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<vector<Edge>> G(N, vector<Edge>(0));\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int s, t, w;\n        cin >> s\
    \ >> t >> w;\n        Edge a, b;\n        a.to = t;\n        b.to = s;\n     \
    \   a.cost = w;\n        b.cost = w;\n        G[s].push_back(a);\n        G[t].push_back(b);\n\
    \    }\n    cout << tree_diameter<ll>(G) << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - graph/diameter-weighted.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_A.test.cpp
- /verify/test/AOJ/GRL_5_A.test.cpp.html
title: test/AOJ/GRL_5_A.test.cpp
---
