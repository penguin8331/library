---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/prim.hpp
    title: "Prim (\u6700\u5C0F\u5168\u57DF\u6728) $O(V log E)$"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A
  bundledCode: "#line 1 \"test/AOJ/ALDS1_12_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A\"\
    \n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing ld = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define pb push_back\n#define\
    \ mp make_pair\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n\
    #define sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios()\
    \ {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n       \
    \ cout << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename\
    \ T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false));\
    \ }\ntemplate <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a\
    \ = b, true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 1 \"graph/prim.hpp\"\nstruct Edge {\n    int to;\n   \
    \ long long cost;\n};\nstruct Prim {\n    vector<vector<Edge>> G;\n    int V;\n\
    \    long long sum;\n    Prim(vector<vector<Edge>> &G_, int V_) : G(G_), V(V_)\
    \ {\n        sum = 0;\n        vector<bool> seen(V, false);\n        priority_queue<pair<ll,\
    \ int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;\n        pq.push(mp(0,\
    \ 0));\n        while (!pq.empty()) {\n            auto p = pq.top();\n      \
    \      pq.pop();\n            if (seen[p.second]) continue;\n            seen[p.second]\
    \ = true;\n            sum += p.first;\n            for (const auto &i : G[p.second])\
    \ {\n                pq.push(mp(i.cost, i.to));\n            }\n        }\n  \
    \  }\n};\n#line 4 \"test/AOJ/ALDS1_12_A.test.cpp\"\n\nint main() {\n    int N;\n\
    \    cin >> N;\n    vector<vector<Edge>> G(N, vector<Edge>(0));\n    for (int\
    \ i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++) {\n            int\
    \ a;\n            cin >> a;\n            if (a != -1) {\n                Edge\
    \ A;\n                A.to = j;\n                A.cost = a;\n               \
    \ G[i].push_back(A);\n            }\n        }\n    }\n    Prim solve(G, N);\n\
    \    cout << solve.sum << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A\"\
    \n#include \"template/template.hpp\"\n#include \"graph/prim.hpp\"\n\nint main()\
    \ {\n    int N;\n    cin >> N;\n    vector<vector<Edge>> G(N, vector<Edge>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        for (int j = 0; j < N; j++) {\n  \
    \          int a;\n            cin >> a;\n            if (a != -1) {\n       \
    \         Edge A;\n                A.to = j;\n                A.cost = a;\n  \
    \              G[i].push_back(A);\n            }\n        }\n    }\n    Prim solve(G,\
    \ N);\n    cout << solve.sum << endl;\n}"
  dependsOn:
  - template/template.hpp
  - graph/prim.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_12_A.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 22:06:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_12_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_12_A.test.cpp
- /verify/test/AOJ/ALDS1_12_A.test.cpp.html
title: test/AOJ/ALDS1_12_A.test.cpp
---
