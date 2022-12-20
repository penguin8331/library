---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS1_1_C.test.cpp
    title: test/AOJ/ALDS1_1_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/eratostenes.hpp\"\nstruct Eratos {\n    vector<int>\
    \ primes;\n    vector<bool> isprime;\n    vector<int> mebius;\n    vector<int>\
    \ min_factor;\n\n    Eratos(int MAX) : primes(),\n                      isprime(MAX\
    \ + 1, true),\n                      mebius(MAX + 1, 1),\n                   \
    \   min_factor(MAX + 1, -1) {\n        isprime[0] = isprime[1] = false;\n    \
    \    min_factor[0] = 0, min_factor[1] = 1;\n        for (int i = 2; i <= MAX;\
    \ ++i) {\n            if (!isprime[i]) continue;\n            primes.push_back(i);\n\
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
    \      return res;\n    }\n};\nstruct IsPrime {\n    vector<bool> isprime;\n\n\
    \    IsPrime(int MAX) : isprime(MAX + 1, true) {\n        isprime[0] = isprime[1]\
    \ = false;\n        for (int i = 2; i <= MAX; ++i) {\n            if (!isprime[i])\
    \ continue;\n            for (int j = i * 2; j <= MAX; j += i) {\n           \
    \     isprime[j] = false;\n            }\n        }\n    }\n};\n"
  code: "struct Eratos {\n    vector<int> primes;\n    vector<bool> isprime;\n   \
    \ vector<int> mebius;\n    vector<int> min_factor;\n\n    Eratos(int MAX) : primes(),\n\
    \                      isprime(MAX + 1, true),\n                      mebius(MAX\
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
    \      return res;\n    }\n};\nstruct IsPrime {\n    vector<bool> isprime;\n\n\
    \    IsPrime(int MAX) : isprime(MAX + 1, true) {\n        isprime[0] = isprime[1]\
    \ = false;\n        for (int i = 2; i <= MAX; ++i) {\n            if (!isprime[i])\
    \ continue;\n            for (int j = i * 2; j <= MAX; j += i) {\n           \
    \     isprime[j] = false;\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/eratostenes.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS1_1_C.test.cpp
documentation_of: data-structure/eratostenes.hpp
layout: document
redirect_from:
- /library/data-structure/eratostenes.hpp
- /library/data-structure/eratostenes.hpp.html
title: data-structure/eratostenes.hpp
---
