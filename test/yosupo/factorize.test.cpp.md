---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/number/miller-rabin.hpp
    title: "\u78BA\u7387\u7684\u7D20\u6570\u5224\u5B9A (Miller-Rabin \u6CD5)"
  - icon: ':x:'
    path: math/number/pollard-rho.hpp
    title: "\u78BA\u7387\u7684\u7D20\u56E0\u6570\u5206\u89E3 (Pollard \u306E\u30ED\
      \u30FC\u6CD5)"
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
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
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
    \ std::setprecision(12);\n    }\n} IOSetup;\n#line 1 \"template/debug.hpp\"\n\
    #ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n#define debug(...)\n#define line\n\
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/number/miller-rabin.hpp\"\
    \n\ntemplate <class T>\nT pow_mod(T A, T N, T M) {\n    T res = 1 % M;\n    A\
    \ %= M;\n    while (N) {\n        if (N & 1) res = (res * A) % M;\n        A =\
    \ (A * A) % M;\n        N >>= 1;\n    }\n    return res;\n}\n\nbool is_prime(long\
    \ long N) {\n    if (N <= 1) return false;\n    if (N == 2 || N == 3) return true;\n\
    \    if (N % 2 == 0) return false;\n    vector<long long> A = {2, 325, 9375, 28178,\
    \ 450775,\n                           9780504, 1795265022};\n    long long s =\
    \ 0, d = N - 1;\n    while (d % 2 == 0) {\n        ++s;\n        d >>= 1;\n  \
    \  }\n    for (auto a : A) {\n        if (a % N == 0) return true;\n        long\
    \ long t, x = pow_mod<__int128_t>(a, d, N);\n        if (x != 1) {\n         \
    \   for (t = 0; t < s; ++t) {\n                if (x == N - 1) break;\n      \
    \          x = __int128_t(x) * x % N;\n            }\n            if (t == s)\
    \ return false;\n        }\n    }\n    return true;\n}\n#line 4 \"math/number/pollard-rho.hpp\"\
    \n\nlong long pollard(long long N) {\n    if (N % 2 == 0) return 2;\n    if (is_prime(N))\
    \ return N;\n\n    auto f = [&](long long x) -> long long {\n        return (__int128_t(x)\
    \ * x + 1) % N;\n    };\n    long long step = 0;\n    while (true) {\n       \
    \ ++step;\n        long long x = step, y = f(x);\n        while (true) {\n   \
    \         long long p = gcd(y - x + N, N);\n            if (p == 0 || p == N)\
    \ break;\n            if (p != 1) return p;\n            x = f(x);\n         \
    \   y = f(f(y));\n        }\n    }\n}\n\nvector<long long> solve_for_prime_factorize(long\
    \ long N) {\n    if (N == 1) return {};\n    long long p = pollard(N);\n    if\
    \ (p == N) return {p};\n    vector<long long> left = solve_for_prime_factorize(p);\n\
    \    vector<long long> right = solve_for_prime_factorize(N / p);\n    left.insert(left.end(),\
    \ right.begin(), right.end());\n    sort(left.begin(), left.end());\n    return\
    \ left;\n}\n\nmap<long long, int> prime_factorize(long long N) {\n    auto res\
    \ = solve_for_prime_factorize(N);\n    map<long long, int> ret;\n    for (int\
    \ i = 0; i < res.size(); i++) {\n        ret[res[i]]++;\n    }\n    return ret;\n\
    }\n#line 4 \"test/yosupo/factorize.test.cpp\"\n\nint main() {\n    int Q;\n  \
    \  cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        ll N;\n        cin >>\
    \ N;\n        if (N == 1) {\n            cout << 0 << endl;\n            continue;\n\
    \        }\n        auto res = solve_for_prime_factorize(N);\n        cout <<\
    \ res.size();\n        for (int j = 0; j < res.size(); j++) {\n            cout\
    \ << \" \" << res[j];\n        }\n        cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n#include \"\
    ../../template/template.hpp\"\n#include \"../../math/number/pollard-rho.hpp\"\n\
    \nint main() {\n    int Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n\
    \        ll N;\n        cin >> N;\n        if (N == 1) {\n            cout <<\
    \ 0 << endl;\n            continue;\n        }\n        auto res = solve_for_prime_factorize(N);\n\
    \        cout << res.size();\n        for (int j = 0; j < res.size(); j++) {\n\
    \            cout << \" \" << res[j];\n        }\n        cout << endl;\n    }\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - math/number/pollard-rho.hpp
  - math/number/miller-rabin.hpp
  isVerificationFile: true
  path: test/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2023-03-10 14:30:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/factorize.test.cpp
- /verify/test/yosupo/factorize.test.cpp.html
title: test/yosupo/factorize.test.cpp
---
