---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
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
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"math/combinatorics/binomial-coefficient.hpp\"\n\ntemplate <class\
    \ T>\nstruct BiCoef {\n    vector<T> fact_, inv_, finv_;\n    constexpr BiCoef()\
    \ {}\n    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n,\
    \ 1) {\n        init(n);\n    }\n    constexpr void init(int n) noexcept {\n \
    \       fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);\n        int\
    \ modular = fact_[0].getmod();\n        for (int i = 2; i < n; i++) {\n      \
    \      fact_[i] = fact_[i - 1] * i;\n            inv_[i] = -inv_[modular % i]\
    \ * (modular / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n        }\n\
    \    }\n    constexpr T com(int n, int k) const noexcept {\n        assert(n <\
    \ (int)fact_.size() && n >= k && k >= 0);\n        return fact_[n] * finv_[k]\
    \ * finv_[n - k];\n    }\n    constexpr T hom(int n, int k) const noexcept {\n\
    \        n += k - 1;\n        assert(n < (int)fact_.size() && n >= k && k >= 0);\n\
    \        return fact_[n] * finv_[k] * finv_[n - k];\n    }\n    constexpr T fact(int\
    \ n) const noexcept {\n        assert(n >= 0);\n        return fact_[n];\n   \
    \ }\n    constexpr T inv(int n) const noexcept {\n        assert(n >= 0);\n  \
    \      return inv_[n];\n    }\n    constexpr T finv(int n) const noexcept {\n\
    \        assert(n >= 0);\n        return finv_[n];\n    }\n};\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\ntemplate <class\
    \ T>\nstruct BiCoef {\n    vector<T> fact_, inv_, finv_;\n    constexpr BiCoef()\
    \ {}\n    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n,\
    \ 1) {\n        init(n);\n    }\n    constexpr void init(int n) noexcept {\n \
    \       fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);\n        int\
    \ modular = fact_[0].getmod();\n        for (int i = 2; i < n; i++) {\n      \
    \      fact_[i] = fact_[i - 1] * i;\n            inv_[i] = -inv_[modular % i]\
    \ * (modular / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n        }\n\
    \    }\n    constexpr T com(int n, int k) const noexcept {\n        assert(n <\
    \ (int)fact_.size() && n >= k && k >= 0);\n        return fact_[n] * finv_[k]\
    \ * finv_[n - k];\n    }\n    constexpr T hom(int n, int k) const noexcept {\n\
    \        n += k - 1;\n        assert(n < (int)fact_.size() && n >= k && k >= 0);\n\
    \        return fact_[n] * finv_[k] * finv_[n - k];\n    }\n    constexpr T fact(int\
    \ n) const noexcept {\n        assert(n >= 0);\n        return fact_[n];\n   \
    \ }\n    constexpr T inv(int n) const noexcept {\n        assert(n >= 0);\n  \
    \      return inv_[n];\n    }\n    constexpr T finv(int n) const noexcept {\n\
    \        assert(n >= 0);\n        return finv_[n];\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: math/combinatorics/binomial-coefficient.hpp
  requiredBy: []
  timestamp: '2023-03-14 23:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combinatorics/binomial-coefficient.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB"
---
