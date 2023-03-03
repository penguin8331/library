---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/number/prime-factorization.hpp
    title: "\u7D20\u56E0\u6570\u5206\u89E3"
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/AOJ/NTL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define pb push_back\n#define mp make_pair\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ld = long double;\n\
    using pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int\
    \ inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1,\
    \ 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr\
    \ int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\
    \n\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a\
    \ = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b)\
    \ { return ((a > b) ? (a = b, true) : (false)); }\n#line 3 \"template/util.hpp\"\
    \n\nstruct IOSetup {\n    IOSetup() {\n        std::cin.tie(nullptr);\n      \
    \  std::ios::sync_with_stdio(false);\n        std::cout.tie(0);\n        std::cout\
    \ << std::fixed << std::setprecision(12);\n        std::cerr << std::fixed <<\
    \ std::setprecision(12);\n    }\n};\n#line 7 \"template/template.hpp\"\nusing\
    \ namespace std;\n#line 3 \"math/number/prime-factorization.hpp\"\n\r\nmap<long\
    \ long, int> prime_factorize(long long n) {\r\n    map<long long, int> res;\r\n\
    \    for (long long p = 2; p * p <= n; ++p) {\r\n        if (n % p != 0) continue;\r\
    \n        int num = 0;\r\n        while (n % p == 0) {\r\n            ++num;\r\
    \n            n /= p;\r\n        }\r\n        res[p] = num;\r\n    }\r\n    if\
    \ (n != 1) res[n] = 1;\r\n    return res;\r\n}\n#line 4 \"test/AOJ/NTL_1_A.test.cpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    auto res = prime_factorize(N);\n\
    \    cout << N << \":\";\n    for (const auto &i : res) {\n        for (int j\
    \ = 0; j < i.second; j++) {\n            cout << \" \" << i.first;\n        }\n\
    \    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../math/number/prime-factorization.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    auto res = prime_factorize(N);\n\
    \    cout << N << \":\";\n    for (const auto &i : res) {\n        for (int j\
    \ = 0; j < i.second; j++) {\n            cout << \" \" << i.first;\n        }\n\
    \    }\n    cout << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - math/number/prime-factorization.hpp
  isVerificationFile: true
  path: test/AOJ/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/NTL_1_A.test.cpp
- /verify/test/AOJ/NTL_1_A.test.cpp.html
title: test/AOJ/NTL_1_A.test.cpp
---
