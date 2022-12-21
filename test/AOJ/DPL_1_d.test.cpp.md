---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic-programming/longest-increasing-subsequence.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D
  bundledCode: "#line 1 \"test/AOJ/DPL_1_d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"dynamic-programming/longest-increasing-subsequence.hpp\"\
    \ntemplate <class T>\nint LIS(vector<T> a, bool is_strong = true) {\n    int n\
    \ = (int)a.size();\n    vector<T> dp;\n    for (int i = 0; i < n; ++i) {\n   \
    \     auto it = (is_strong ? lower_bound(dp.begin(), dp.end(), a[i]) : upper_bound(dp.begin(),\
    \ dp.end(), a[i]));\n        if (it == dp.end())\n            dp.push_back(a[i]);\n\
    \        else\n            *it = a[i];\n    }\n    return dp.size();\n}\n#line\
    \ 4 \"test/AOJ/DPL_1_d.test.cpp\"\n\nint main() {\n    int N;\n    cin >> N;\n\
    \    vector<int> A(N);\n    for (int i = 0; i < N; i++) {\n        cin >> A[i];\n\
    \    }\n    cout << LIS(A) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D\"\
    \n#include \"template/template.hpp\"\n#include \"dynamic-programming/longest-increasing-subsequence.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    cout << LIS(A) << endl;\n\
    }"
  dependsOn:
  - template/template.hpp
  - dynamic-programming/longest-increasing-subsequence.hpp
  isVerificationFile: true
  path: test/AOJ/DPL_1_d.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 12:35:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DPL_1_d.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL_1_d.test.cpp
- /verify/test/AOJ/DPL_1_d.test.cpp.html
title: test/AOJ/DPL_1_d.test.cpp
---
