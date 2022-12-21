---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic-programming/traveling-salesman-problem.hpp
    title: dynamic-programming/traveling-salesman-problem.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"test/AOJ/DPL_2_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"dynamic-programming/traveling-salesman-problem.hpp\"\
    \n/*\n    0->1->2->3->0\u304C\u6700\u77ED\u3060\u3068\u3059\u308B\n    dp[{0,1,2,3}][0]->dp[{1,2,3}][3]\n\
    \    ->dp[{1,2}][2]->dp[{1}][1]->dp[{}][0]\n    inf\u306E\u5024\u3092\u8ABF\u6574\
    \u3057\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\
    \u306B\u3059\u308B\n    G->\u30D1\u30B9\u304C\u3042\u308C\u3070\u305D\u306E\u8DDD\
    \u96E2,\u306A\u3051\u308C\u3070INF\u3092\u3044\u308C\u308B\n*/\nint V, E;\nint\
    \ G[20][20];  // \u30B0\u30E9\u30D5\nint dp[50000][20];\n// \u30E1\u30E2\u5316\
    \u518D\u5E30\nint rec(int S, int v) {\n    if (S == 0) {\n        if (v == 0)\
    \ {\n            return 0;\n        } else {\n            return inf / 3;\n  \
    \      }\n    }\n    if ((S & (1 << v)) == 0) {  // S\u306B{v}\u304C\u542B\u307E\
    \u308C\u3066\u3044\u306A\u3044\n        return inf / 3;\n    }\n    int &ret =\
    \ dp[S][v];\n    if (ret != 0) return ret;\n    ret = inf / 3;\n    for (int u\
    \ = 0; u < V; u++) {\n        chmin(ret, rec(S ^ (1 << v), u) + G[u][v]);\n  \
    \  }\n    return ret;\n}\n#line 4 \"test/AOJ/DPL_2_A.test.cpp\"\n\nint main()\
    \ {\n    cin >> V >> E;\n    for (int i = 0; i < 20; i++) {\n        for (int\
    \ j = 0; j < 20; j++) {\n            G[i][j] = inf / 3;\n        }\n    }\n  \
    \  for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >> t\
    \ >> d;\n        G[s][t] = d;\n    }\n    int ans = rec((1 << V) - 1, 0);\n  \
    \  cout << (ans == inf / 3 ? -1 : ans) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n#include \"template/template.hpp\"\n#include \"dynamic-programming/traveling-salesman-problem.hpp\"\
    \n\nint main() {\n    cin >> V >> E;\n    for (int i = 0; i < 20; i++) {\n   \
    \     for (int j = 0; j < 20; j++) {\n            G[i][j] = inf / 3;\n       \
    \ }\n    }\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin\
    \ >> s >> t >> d;\n        G[s][t] = d;\n    }\n    int ans = rec((1 << V) - 1,\
    \ 0);\n    cout << (ans == inf / 3 ? -1 : ans) << endl;\n}"
  dependsOn:
  - template/template.hpp
  - dynamic-programming/traveling-salesman-problem.hpp
  isVerificationFile: true
  path: test/AOJ/DPL_2_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 12:35:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DPL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL_2_A.test.cpp
- /verify/test/AOJ/DPL_2_A.test.cpp.html
title: test/AOJ/DPL_2_A.test.cpp
---