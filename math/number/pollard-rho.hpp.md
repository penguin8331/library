---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/number/miller-rabin.hpp
    title: "\u78BA\u7387\u7684\u7D20\u6570\u5224\u5B9A (Miller-Rabin \u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/factorize.test.cpp
    title: test/yosupo/factorize.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/miller-rabin.hpp\"\ntemplate <class T>\nT pow_mod(T\
    \ A, T N, T M) {\n    T res = 1 % M;\n    A %= M;\n    while (N) {\n        if\
    \ (N & 1) res = (res * A) % M;\n        A = (A * A) % M;\n        N >>= 1;\n \
    \   }\n    return res;\n}\n\nbool is_prime(long long N) {\n    if (N <= 1) return\
    \ false;\n    if (N == 2 || N == 3) return true;\n    if (N % 2 == 0) return false;\n\
    \    vector<long long> A = {2, 325, 9375, 28178, 450775,\n                   \
    \        9780504, 1795265022};\n    long long s = 0, d = N - 1;\n    while (d\
    \ % 2 == 0) {\n        ++s;\n        d >>= 1;\n    }\n    for (auto a : A) {\n\
    \        if (a % N == 0) return true;\n        long long t, x = pow_mod<__int128_t>(a,\
    \ d, N);\n        if (x != 1) {\n            for (t = 0; t < s; ++t) {\n     \
    \           if (x == N - 1) break;\n                x = __int128_t(x) * x % N;\n\
    \            }\n            if (t == s) return false;\n        }\n    }\n    return\
    \ true;\n}\n#line 2 \"math/number/pollard-rho.hpp\"\n\nlong long pollard(long\
    \ long N) {\n    if (N % 2 == 0) return 2;\n    if (is_prime(N)) return N;\n\n\
    \    auto f = [&](long long x) -> long long {\n        return (__int128_t(x) *\
    \ x + 1) % N;\n    };\n    long long step = 0;\n    while (true) {\n        ++step;\n\
    \        long long x = step, y = f(x);\n        while (true) {\n            long\
    \ long p = gcd(y - x + N, N);\n            if (p == 0 || p == N) break;\n    \
    \        if (p != 1) return p;\n            x = f(x);\n            y = f(f(y));\n\
    \        }\n    }\n}\n\nvector<long long> solve_for_prime_factorize(long long\
    \ N) {\n    if (N == 1) return {};\n    long long p = pollard(N);\n    if (p ==\
    \ N) return {p};\n    vector<long long> left = solve_for_prime_factorize(p);\n\
    \    vector<long long> right = solve_for_prime_factorize(N / p);\n    left.insert(left.end(),\
    \ right.begin(), right.end());\n    sort(left.begin(), left.end());\n    return\
    \ left;\n}\n\nmap<long long, int> prime_factorize(long long N) {\n    auto res\
    \ = solve_for_prime_factorize(N);\n    map<long long, int> ret;\n    for (int\
    \ i = 0; i < res.size(); i++) {\n        ret[res[i]]++;\n    }\n    return ret;\n\
    }\n"
  code: "#include \"math/number/miller-rabin.hpp\"\n\nlong long pollard(long long\
    \ N) {\n    if (N % 2 == 0) return 2;\n    if (is_prime(N)) return N;\n\n    auto\
    \ f = [&](long long x) -> long long {\n        return (__int128_t(x) * x + 1)\
    \ % N;\n    };\n    long long step = 0;\n    while (true) {\n        ++step;\n\
    \        long long x = step, y = f(x);\n        while (true) {\n            long\
    \ long p = gcd(y - x + N, N);\n            if (p == 0 || p == N) break;\n    \
    \        if (p != 1) return p;\n            x = f(x);\n            y = f(f(y));\n\
    \        }\n    }\n}\n\nvector<long long> solve_for_prime_factorize(long long\
    \ N) {\n    if (N == 1) return {};\n    long long p = pollard(N);\n    if (p ==\
    \ N) return {p};\n    vector<long long> left = solve_for_prime_factorize(p);\n\
    \    vector<long long> right = solve_for_prime_factorize(N / p);\n    left.insert(left.end(),\
    \ right.begin(), right.end());\n    sort(left.begin(), left.end());\n    return\
    \ left;\n}\n\nmap<long long, int> prime_factorize(long long N) {\n    auto res\
    \ = solve_for_prime_factorize(N);\n    map<long long, int> ret;\n    for (int\
    \ i = 0; i < res.size(); i++) {\n        ret[res[i]]++;\n    }\n    return ret;\n\
    }"
  dependsOn:
  - math/number/miller-rabin.hpp
  isVerificationFile: false
  path: math/number/pollard-rho.hpp
  requiredBy: []
  timestamp: '2023-01-08 12:37:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/factorize.test.cpp
documentation_of: math/number/pollard-rho.hpp
layout: document
title: "\u78BA\u7387\u7684\u7D20\u56E0\u6570\u5206\u89E3 (Pollard \u306E\u30ED\u30FC\
  \u6CD5)"
---
