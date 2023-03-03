---
data:
  _extendedDependsOn:
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/number/eratostenes.hpp\"\
    \n\nstruct Eratos {\n    vector<int> primes;\n    vector<bool> isprime;\n    vector<int>\
    \ mebius;\n    vector<int> min_factor;\n\n    Eratos(int MAX) : primes(),\n  \
    \                    isprime(MAX + 1, true),\n                      mebius(MAX\
    \ + 1, 1),\n                      min_factor(MAX + 1, -1) {\n        isprime[0]\
    \ = isprime[1] = false;\n        min_factor[0] = 0, min_factor[1] = 1;\n     \
    \   for (int i = 2; i <= MAX; ++i) {\n            if (!isprime[i]) continue;\n\
    \            primes.push_back(i);\n            mebius[i] = -1;\n            min_factor[i]\
    \ = i;\n            for (int j = i * 2; j <= MAX; j += i) {\n                isprime[j]\
    \ = false;\n                if ((j / i) % i == 0)\n                    mebius[j]\
    \ = 0;\n                else\n                    mebius[j] = -mebius[j];\n  \
    \              if (min_factor[j] == -1) min_factor[j] = i;\n            }\n  \
    \      }\n    }\n\n    // \u7D20\u56E0\u6570\u5206\u89E3\n    vector<pair<int,\
    \ int>> prime_factors(int n) {\n        vector<pair<int, int>> res;\n        while\
    \ (n != 1) {\n            int prime = min_factor[n];\n            int exp = 0;\n\
    \            while (min_factor[n] == prime) {\n                ++exp;\n      \
    \          n /= prime;\n            }\n            res.push_back(make_pair(prime,\
    \ exp));\n        }\n        return res;\n    }\n\n    // \u7D04\u6570\u5217\u6319\
    \n    vector<int> divisors(int n) {\n        vector<int> res({1});\n        auto\
    \ pf = prime_factors(n);\n        for (auto p : pf) {\n            int siz = (int)res.size();\n\
    \            for (int i = 0; i < siz; ++i) {\n                int v = 1;\n   \
    \             for (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n\n    // \u7D04\u6570\u500B\u6570\
    \n    int divisors_num(int n) {\n        int res = 1;\n        auto pf = prime_factors(n);\n\
    \        for (auto p : pf) {\n            res *= p.second + 1;\n        }\n  \
    \      return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\nstruct Eratos {\n\
    \    vector<int> primes;\n    vector<bool> isprime;\n    vector<int> mebius;\n\
    \    vector<int> min_factor;\n\n    Eratos(int MAX) : primes(),\n            \
    \          isprime(MAX + 1, true),\n                      mebius(MAX + 1, 1),\n\
    \                      min_factor(MAX + 1, -1) {\n        isprime[0] = isprime[1]\
    \ = false;\n        min_factor[0] = 0, min_factor[1] = 1;\n        for (int i\
    \ = 2; i <= MAX; ++i) {\n            if (!isprime[i]) continue;\n            primes.push_back(i);\n\
    \            mebius[i] = -1;\n            min_factor[i] = i;\n            for\
    \ (int j = i * 2; j <= MAX; j += i) {\n                isprime[j] = false;\n \
    \               if ((j / i) % i == 0)\n                    mebius[j] = 0;\n  \
    \              else\n                    mebius[j] = -mebius[j];\n           \
    \     if (min_factor[j] == -1) min_factor[j] = i;\n            }\n        }\n\
    \    }\n\n    // \u7D20\u56E0\u6570\u5206\u89E3\n    vector<pair<int, int>> prime_factors(int\
    \ n) {\n        vector<pair<int, int>> res;\n        while (n != 1) {\n      \
    \      int prime = min_factor[n];\n            int exp = 0;\n            while\
    \ (min_factor[n] == prime) {\n                ++exp;\n                n /= prime;\n\
    \            }\n            res.push_back(make_pair(prime, exp));\n        }\n\
    \        return res;\n    }\n\n    // \u7D04\u6570\u5217\u6319\n    vector<int>\
    \ divisors(int n) {\n        vector<int> res({1});\n        auto pf = prime_factors(n);\n\
    \        for (auto p : pf) {\n            int siz = (int)res.size();\n       \
    \     for (int i = 0; i < siz; ++i) {\n                int v = 1;\n          \
    \      for (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n\n    // \u7D04\u6570\u500B\u6570\
    \n    int divisors_num(int n) {\n        int res = 1;\n        auto pf = prime_factors(n);\n\
    \        for (auto p : pf) {\n            res *= p.second + 1;\n        }\n  \
    \      return res;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: math/number/eratostenes.hpp
  requiredBy: []
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/eratostenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
