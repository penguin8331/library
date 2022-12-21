---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number/divisors.hpp
    title: "\u7D04\u6570\u5217\u6319"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
  bundledCode: "#line 1 \"test/AOJ/ITP1_3_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \r\n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
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
    \ MOD = 1e9 + 7;\n#line 1 \"math/number/divisors.hpp\"\nvector<long long> divisors(long\
    \ long n) {\r\n    vector<long long> res;\r\n    for (long long i = 1LL; i * i\
    \ <= n; ++i) {\r\n        if (n % i == 0) {\r\n            res.push_back(i);\r\
    \n            long long j = n / i;\r\n            if (j != i) res.push_back(j);\r\
    \n        }\r\n    }\r\n    sort(res.begin(), res.end());\r\n    return res;\r\
    \n}\n#line 4 \"test/AOJ/ITP1_3_D.test.cpp\"\n\r\nint main() {\r\n    int a, b,\
    \ c;\r\n    cin >> a >> b >> c;\r\n    auto res = divisors(c);\r\n    int ans\
    \ = 0;\r\n    for (int i = 0; i < res.size(); i++) {\r\n        if (res[i] >=\
    \ a && res[i] <= b) {\r\n            ans++;\r\n        }\r\n    }\r\n    cout\
    \ << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \r\n#include \"template/template.hpp\"\r\n#include \"math/number/divisors.hpp\"\
    \r\n\r\nint main() {\r\n    int a, b, c;\r\n    cin >> a >> b >> c;\r\n    auto\
    \ res = divisors(c);\r\n    int ans = 0;\r\n    for (int i = 0; i < res.size();\
    \ i++) {\r\n        if (res[i] >= a && res[i] <= b) {\r\n            ans++;\r\n\
    \        }\r\n    }\r\n    cout << ans << endl;\r\n}"
  dependsOn:
  - template/template.hpp
  - math/number/divisors.hpp
  isVerificationFile: true
  path: test/AOJ/ITP1_3_D.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:41:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ITP1_3_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ITP1_3_D.test.cpp
- /verify/test/AOJ/ITP1_3_D.test.cpp.html
title: test/AOJ/ITP1_3_D.test.cpp
---
