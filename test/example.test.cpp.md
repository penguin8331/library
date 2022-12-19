---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"test/example.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
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
    \ = b, true) : (false)); }\n#line 3 \"test/example.test.cpp\"\n\nint main() {\n\
    \    int N;\n    cin >> N;\n    vector<int> S(N);\n    for (int i = 0; i < N;\
    \ i++) {\n        cin >> S[i];\n    }\n    int Q;\n    cin >> Q;\n    int cnt\
    \ = 0;\n    while (Q--) {\n        int t_i;\n        cin >> t_i;\n        cnt\
    \ += binary_search(all(S), t_i);\n    }\n    cout << cnt << endl;\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include \"template/template.hpp\"\n\nint main() {\n    int N;\n    cin >> N;\n\
    \    vector<int> S(N);\n    for (int i = 0; i < N; i++) {\n        cin >> S[i];\n\
    \    }\n    int Q;\n    cin >> Q;\n    int cnt = 0;\n    while (Q--) {\n     \
    \   int t_i;\n        cin >> t_i;\n        cnt += binary_search(all(S), t_i);\n\
    \    }\n    cout << cnt << endl;\n    return 0;\n}"
  dependsOn:
  - template/template.hpp
  isVerificationFile: true
  path: test/example.test.cpp
  requiredBy: []
  timestamp: '2022-12-19 21:41:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/example.test.cpp
layout: document
redirect_from:
- /verify/test/example.test.cpp
- /verify/test/example.test.cpp.html
title: test/example.test.cpp
---
