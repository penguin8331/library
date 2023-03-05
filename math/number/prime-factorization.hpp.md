---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/NTL_1_A.test.cpp
    title: test/AOJ/NTL_1_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\nusing\
    \ pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#define line\n#endif\n#line 8 \"template/template.hpp\"\n\
    using namespace std;\n#line 3 \"math/number/prime-factorization.hpp\"\n\r\nmap<long\
    \ long, int> prime_factorize(long long n) {\r\n    map<long long, int> res;\r\n\
    \    for (long long p = 2; p * p <= n; ++p) {\r\n        if (n % p != 0) continue;\r\
    \n        int num = 0;\r\n        while (n % p == 0) {\r\n            ++num;\r\
    \n            n /= p;\r\n        }\r\n        res[p] = num;\r\n    }\r\n    if\
    \ (n != 1) res[n] = 1;\r\n    return res;\r\n}\n"
  code: "#pragma once\r\n#include \"../../template/template.hpp\"\r\n\r\nmap<long\
    \ long, int> prime_factorize(long long n) {\r\n    map<long long, int> res;\r\n\
    \    for (long long p = 2; p * p <= n; ++p) {\r\n        if (n % p != 0) continue;\r\
    \n        int num = 0;\r\n        while (n % p == 0) {\r\n            ++num;\r\
    \n            n /= p;\r\n        }\r\n        res[p] = num;\r\n    }\r\n    if\
    \ (n != 1) res[n] = 1;\r\n    return res;\r\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: math/number/prime-factorization.hpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/NTL_1_A.test.cpp
documentation_of: math/number/prime-factorization.hpp
layout: document
title: "\u7D20\u56E0\u6570\u5206\u89E3"
---
