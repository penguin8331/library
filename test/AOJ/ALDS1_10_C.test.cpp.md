---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic-programming/longest-common-subsequence.hpp
    title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\u5217"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_10_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"dynamic-programming/longest-common-subsequence.hpp\"\
    \nint LCS(const string& a, const string& b) {\n    const int n = a.size(), m =\
    \ b.size();\n    vector<vector<int> > X(n + 1, vector<int>(m + 1));\n    for (int\
    \ i = 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n            if\
    \ (a[i] == b[j]) {\n                X[i + 1][j + 1] = X[i][j] + 1;\n         \
    \   } else if (X[i + 1][j] < X[i][j + 1]) {\n                X[i + 1][j + 1] =\
    \ X[i][j + 1];\n            } else {\n                X[i + 1][j + 1] = X[i +\
    \ 1][j];\n            }\n        }\n    }\n    return X[n][m];\n}\n#line 4 \"\
    test/AOJ/ALDS1_10_C.test.cpp\"\n\nint main() {\n    int N;\n    cin >> N;\n  \
    \  for (int i = 0; i < N; i++) {\n        string s, t;\n        cin >> s >> t;\n\
    \        cout << LCS(s, t) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n#include \"template/template.hpp\"\n#include \"dynamic-programming/longest-common-subsequence.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    for (int i = 0; i < N; i++) {\n\
    \        string s, t;\n        cin >> s >> t;\n        cout << LCS(s, t) << endl;\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - dynamic-programming/longest-common-subsequence.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_10_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 12:35:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_10_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_10_C.test.cpp
- /verify/test/AOJ/ALDS1_10_C.test.cpp.html
title: test/AOJ/ALDS1_10_C.test.cpp
---
