---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/combinatorics/modpow.hpp
    title: modpow
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/AOJ/NTL_1_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
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
    \ \"math/combinatorics/modpow.hpp\"\nlong long modpow(long long a, long long n,\
    \ long long mod) {\r\n    long long res = 1;\r\n    while (n > 0) {\r\n      \
    \  if (n & 1) res = res * a % mod;\r\n        a = a * a % mod;\r\n        n >>=\
    \ 1;\r\n    }\r\n    return res;\r\n}\n#line 4 \"test/AOJ/NTL_1_B.test.cpp\"\n\
    \r\nint main() {\r\n    int m, n;\r\n    cin >> m >> n;\r\n    cout << modpow(m,\
    \ n, MOD)<<endl;\r\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \r\n#include \"template/template.hpp\"\r\n#include \"math/combinatorics/modpow.hpp\"\
    \r\n\r\nint main() {\r\n    int m, n;\r\n    cin >> m >> n;\r\n    cout << modpow(m,\
    \ n, MOD)<<endl;\r\n}"
  dependsOn:
  - template/template.hpp
  - math/combinatorics/modpow.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 21:00:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_B.test.cpp
- /verify/test/AOJ/NTL_1_B.test.cpp.html
title: test/AOJ/NTL_1_B.test.cpp
---
