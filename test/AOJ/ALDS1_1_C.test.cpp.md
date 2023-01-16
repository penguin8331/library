---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number/isprime.hpp
    title: "\u7D20\u6570\u5224\u5B9A\u6CD5"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"math/number/isprime.hpp\"\nbool is_prime(long long\
    \ n) {\r\n    if (n <= 1) return false;\r\n    for (long long p = 2; p * p <=\
    \ n; ++p) {\r\n        if (n % p == 0) return false;\r\n    }\r\n    return true;\r\
    \n}\n#line 4 \"test/AOJ/ALDS1_1_C.test.cpp\"\n\r\nint main() {\r\n    int N;\r\
    \n    cin >> N;\r\n    int ans = 0;\r\n    for (int i = 0; i < N; i++) {\r\n \
    \       int a;\r\n        cin >> a;\r\n        ans += is_prime(a);\r\n    }\r\n\
    \    cout << ans << endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \r\n#include \"template/template.hpp\"\r\n#include \"math/number/isprime.hpp\"\
    \r\n\r\nint main() {\r\n    int N;\r\n    cin >> N;\r\n    int ans = 0;\r\n  \
    \  for (int i = 0; i < N; i++) {\r\n        int a;\r\n        cin >> a;\r\n  \
    \      ans += is_prime(a);\r\n    }\r\n    cout << ans << endl;\r\n}"
  dependsOn:
  - template/template.hpp
  - math/number/isprime.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:41:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_1_C.test.cpp
- /verify/test/AOJ/ALDS1_1_C.test.cpp.html
title: test/AOJ/ALDS1_1_C.test.cpp
---
