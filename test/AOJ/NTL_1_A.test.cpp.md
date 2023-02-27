---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number/prime-factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/AOJ/NTL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"math/number/prime-factorization.hpp\"\nmap<long long,\
    \ int> prime_factorize(long long n) {\r\n    map<long long, int> res;\r\n    for\
    \ (long long p = 2; p * p <= n; ++p) {\r\n        if (n % p != 0) continue;\r\n\
    \        int num = 0;\r\n        while (n % p == 0) {\r\n            ++num;\r\n\
    \            n /= p;\r\n        }\r\n        res[p] = num;\r\n    }\r\n    if\
    \ (n != 1) res[n] = 1;\r\n    return res;\r\n}\n#line 4 \"test/AOJ/NTL_1_A.test.cpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    auto res = prime_factorize(N);\n\
    \    cout << N << \":\";\n    for (const auto &i : res) {\n        for (int j\
    \ = 0; j < i.second; j++) {\n            cout << \" \" << i.first;\n        }\n\
    \    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#include \"template/template.hpp\"\n#include \"math/number/prime-factorization.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    auto res = prime_factorize(N);\n\
    \    cout << N << \":\";\n    for (const auto &i : res) {\n        for (int j\
    \ = 0; j < i.second; j++) {\n            cout << \" \" << i.first;\n        }\n\
    \    }\n    cout << endl;\n}"
  dependsOn:
  - template/template.hpp
  - math/number/prime-factorization.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 22:06:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_A.test.cpp
- /verify/test/AOJ/NTL_1_A.test.cpp.html
title: test/AOJ/NTL_1_A.test.cpp
---
