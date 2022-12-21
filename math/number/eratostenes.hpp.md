---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/eratostenes.hpp\"\nstruct Eratos {\n    vector<int>\
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
    \      return res;\n    }\n};\n"
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
    \      return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/number/eratostenes.hpp
  requiredBy: []
  timestamp: '2022-12-21 17:41:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/eratostenes.hpp
layout: document
redirect_from:
- /library/math/number/eratostenes.hpp
- /library/math/number/eratostenes.hpp.html
title: math/number/eratostenes.hpp
---
