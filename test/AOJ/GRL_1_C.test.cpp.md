---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/warshall-floyd.hpp
    title: Warshall Floyd
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/AOJ/GRL_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing ld = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define pb push_back\n#define\
    \ mp make_pair\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) (((N) + (X)-1) / (X))\n\
    #define sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios()\
    \ {\n        ios::sync_with_stdio(false);\n        cin.tie(nullptr);\n       \
    \ cout.tie(nullptr);\n        cout << fixed << setprecision(15);\n    };\n} fast_ios_;\n\
    template <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a = b,\
    \ true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b) { return\
    \ ((a > b) ? (a = b, true) : (false)); }\n//----------------------------------------------------------------------------\n\
    constexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[]\
    \ = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1,\
    \ -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 1\
    \ \"graph/warshall-floyd.hpp\"\nvoid warshallfloyd(vector<vector<long long>> &dp,\
    \ int V) {\n    // i->j\u306E\u7D4C\u8DEF\u306B\u3064\u3044\u3066i->k->j\u3092\
    \u691C\u8A0E\u3059\u308B\n    for (int k = 0; k < V; ++k) {\n        for (int\
    \ i = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n          \
    \      dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);\n            }\n       \
    \ }\n    }\n}\nbool isnegative(vector<vector<long long>> dp, int V) {\n    bool\
    \ isnegative = false;\n    for (int v = 0; v < V; ++v) {\n        if (dp[v][v]\
    \ < 0) isnegative = true;\n    }\n    return isnegative;\n}\n#line 4 \"test/AOJ/GRL_1_C.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    ll maxi = INF / 12;\n\
    \    vector<vector<ll>> dp(V, vector<ll>(V, maxi));\n    for (int i = 0; i < V;\
    \ i++) {\n        dp[i][i] = 0;\n    }\n    for (int i = 0; i < E; i++) {\n  \
    \      int s, t, d;\n        cin >> s >> t >> d;\n        dp[s][t] = d;\n    }\n\
    \    warshallfloyd(dp, V);\n    if (isnegative(dp, V)) {\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n    } else {\n        for (int i = 0; i < V; i++) {\n    \
    \        if (dp[i][0] > maxi / 2) {\n                cout << \"INF\";\n      \
    \      } else {\n                cout << dp[i][0];\n            }\n          \
    \  for (int j = 1; j < V; j++) {\n                if (dp[i][j] > maxi / 2) {\n\
    \                    cout << \" INF\";\n                } else {\n           \
    \         cout << \" \" << dp[i][j];\n                }\n            }\n     \
    \       cout << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n#include \"template/template.hpp\"\n#include \"graph/warshall-floyd.hpp\"\n\n\
    int main() {\n    int V, E;\n    cin >> V >> E;\n    ll maxi = INF / 12;\n   \
    \ vector<vector<ll>> dp(V, vector<ll>(V, maxi));\n    for (int i = 0; i < V; i++)\
    \ {\n        dp[i][i] = 0;\n    }\n    for (int i = 0; i < E; i++) {\n       \
    \ int s, t, d;\n        cin >> s >> t >> d;\n        dp[s][t] = d;\n    }\n  \
    \  warshallfloyd(dp, V);\n    if (isnegative(dp, V)) {\n        cout << \"NEGATIVE\
    \ CYCLE\" << endl;\n    } else {\n        for (int i = 0; i < V; i++) {\n    \
    \        if (dp[i][0] > maxi / 2) {\n                cout << \"INF\";\n      \
    \      } else {\n                cout << dp[i][0];\n            }\n          \
    \  for (int j = 1; j < V; j++) {\n                if (dp[i][j] > maxi / 2) {\n\
    \                    cout << \" INF\";\n                } else {\n           \
    \         cout << \" \" << dp[i][j];\n                }\n            }\n     \
    \       cout << endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - graph/warshall-floyd.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 21:00:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_C.test.cpp
- /verify/test/AOJ/GRL_1_C.test.cpp.html
title: test/AOJ/GRL_1_C.test.cpp
---
