---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
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
    \ long long;\nusing ld = long double;\nusing pii = pair<int, int>;\nusing pll\
    \ = pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1,\
    \ 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9\
    \ + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T&\
    \ a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename\
    \ T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false));\
    \ }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n    \
    \    std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n     \
    \   std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/static-modular-arithmetic.hpp\"\
    \n\ntemplate <int MOD>\nstruct Fp {\n    long long val;\n    constexpr Fp(long\
    \ long v = 0) noexcept : val(v % MOD) {\n        if (val < 0) val += MOD;\n  \
    \  }\n    constexpr int getmod() const { return MOD; }\n    constexpr Fp operator-()\
    \ const noexcept {\n        return val ? MOD - val : 0;\n    }\n    constexpr\
    \ Fp operator+(const Fp& r) const noexcept { return Fp(*this) += r; }\n    constexpr\
    \ Fp operator-(const Fp& r) const noexcept { return Fp(*this) -= r; }\n    constexpr\
    \ Fp operator*(const Fp& r) const noexcept { return Fp(*this) *= r; }\n    constexpr\
    \ Fp operator/(const Fp& r) const noexcept { return Fp(*this) /= r; }\n    constexpr\
    \ Fp& operator+=(const Fp& r) noexcept {\n        val += r.val;\n        if (val\
    \ >= MOD) val -= MOD;\n        return *this;\n    }\n    constexpr Fp& operator-=(const\
    \ Fp& r) noexcept {\n        val -= r.val;\n        if (val < 0) val += MOD;\n\
    \        return *this;\n    }\n    constexpr Fp& operator*=(const Fp& r) noexcept\
    \ {\n        val = val * r.val % MOD;\n        return *this;\n    }\n    constexpr\
    \ Fp& operator/=(const Fp& r) noexcept {\n        long long a = r.val, b = MOD,\
    \ u = 1, v = 0;\n        while (b) {\n            long long t = a / b;\n     \
    \       a -= t * b, swap(a, b);\n            u -= t * v, swap(u, v);\n       \
    \ }\n        val = val * u % MOD;\n        if (val < 0) val += MOD;\n        return\
    \ *this;\n    }\n    constexpr bool operator==(const Fp& r) const noexcept {\n\
    \        return this->val == r.val;\n    }\n    constexpr bool operator!=(const\
    \ Fp& r) const noexcept {\n        return this->val != r.val;\n    }\n    friend\
    \ constexpr istream& operator>>(istream& is, Fp<MOD>& x) noexcept {\n        is\
    \ >> x.val;\n        x.val %= MOD;\n        if (x.val < 0) x.val += MOD;\n   \
    \     return is;\n    }\n    friend constexpr ostream& operator<<(ostream& os,\
    \ const Fp<MOD>& x) noexcept {\n        return os << x.val;\n    }\n    friend\
    \ constexpr Fp<MOD> modpow(const Fp<MOD>& r, long long n) noexcept {\n       \
    \ if (n == 0) return 1;\n        if (n < 0) return modpow(modinv(r), -n);\n  \
    \      auto t = modpow(r, n / 2);\n        t = t * t;\n        if (n & 1) t =\
    \ t * r;\n        return t;\n    }\n    friend constexpr Fp<MOD> modinv(const\
    \ Fp<MOD>& r) noexcept {\n        long long a = r.val, b = MOD, u = 1, v = 0;\n\
    \        while (b) {\n            long long t = a / b;\n            a -= t * b,\
    \ swap(a, b);\n            u -= t * v, swap(u, v);\n        }\n        return\
    \ Fp<MOD>(u);\n    }\n};\n"
  code: "#pragma once\n#include \"template/template.hpp\"\n\ntemplate <int MOD>\n\
    struct Fp {\n    long long val;\n    constexpr Fp(long long v = 0) noexcept :\
    \ val(v % MOD) {\n        if (val < 0) val += MOD;\n    }\n    constexpr int getmod()\
    \ const { return MOD; }\n    constexpr Fp operator-() const noexcept {\n     \
    \   return val ? MOD - val : 0;\n    }\n    constexpr Fp operator+(const Fp& r)\
    \ const noexcept { return Fp(*this) += r; }\n    constexpr Fp operator-(const\
    \ Fp& r) const noexcept { return Fp(*this) -= r; }\n    constexpr Fp operator*(const\
    \ Fp& r) const noexcept { return Fp(*this) *= r; }\n    constexpr Fp operator/(const\
    \ Fp& r) const noexcept { return Fp(*this) /= r; }\n    constexpr Fp& operator+=(const\
    \ Fp& r) noexcept {\n        val += r.val;\n        if (val >= MOD) val -= MOD;\n\
    \        return *this;\n    }\n    constexpr Fp& operator-=(const Fp& r) noexcept\
    \ {\n        val -= r.val;\n        if (val < 0) val += MOD;\n        return *this;\n\
    \    }\n    constexpr Fp& operator*=(const Fp& r) noexcept {\n        val = val\
    \ * r.val % MOD;\n        return *this;\n    }\n    constexpr Fp& operator/=(const\
    \ Fp& r) noexcept {\n        long long a = r.val, b = MOD, u = 1, v = 0;\n   \
    \     while (b) {\n            long long t = a / b;\n            a -= t * b, swap(a,\
    \ b);\n            u -= t * v, swap(u, v);\n        }\n        val = val * u %\
    \ MOD;\n        if (val < 0) val += MOD;\n        return *this;\n    }\n    constexpr\
    \ bool operator==(const Fp& r) const noexcept {\n        return this->val == r.val;\n\
    \    }\n    constexpr bool operator!=(const Fp& r) const noexcept {\n        return\
    \ this->val != r.val;\n    }\n    friend constexpr istream& operator>>(istream&\
    \ is, Fp<MOD>& x) noexcept {\n        is >> x.val;\n        x.val %= MOD;\n  \
    \      if (x.val < 0) x.val += MOD;\n        return is;\n    }\n    friend constexpr\
    \ ostream& operator<<(ostream& os, const Fp<MOD>& x) noexcept {\n        return\
    \ os << x.val;\n    }\n    friend constexpr Fp<MOD> modpow(const Fp<MOD>& r, long\
    \ long n) noexcept {\n        if (n == 0) return 1;\n        if (n < 0) return\
    \ modpow(modinv(r), -n);\n        auto t = modpow(r, n / 2);\n        t = t *\
    \ t;\n        if (n & 1) t = t * r;\n        return t;\n    }\n    friend constexpr\
    \ Fp<MOD> modinv(const Fp<MOD>& r) noexcept {\n        long long a = r.val, b\
    \ = MOD, u = 1, v = 0;\n        while (b) {\n            long long t = a / b;\n\
    \            a -= t * b, swap(a, b);\n            u -= t * v, swap(u, v);\n  \
    \      }\n        return Fp<MOD>(u);\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: data-structure/static-modular-arithmetic.hpp
  requiredBy: []
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/static-modular-arithmetic.hpp
layout: document
title: "\u9759\u7684 modint"
---
