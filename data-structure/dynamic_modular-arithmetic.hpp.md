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
    \ std;\n#line 3 \"data-structure/dynamic_modular-arithmetic.hpp\"\n\ntemplate\
    \ <int IND = 0>\nstruct Fp {\n    long long val;\n    constexpr Fp(long long v\
    \ = 0) noexcept : val(v % MODS[IND]) {\n        if (val < 0) val += MODS[IND];\n\
    \    }\n    constexpr int getmod() const { return MODS[IND]; }\n    constexpr\
    \ Fp operator-() const noexcept {\n        return val ? MODS[IND] - val : 0;\n\
    \    }\n    constexpr Fp operator+(const Fp& r) const noexcept { return Fp(*this)\
    \ += r; }\n    constexpr Fp operator-(const Fp& r) const noexcept { return Fp(*this)\
    \ -= r; }\n    constexpr Fp operator*(const Fp& r) const noexcept { return Fp(*this)\
    \ *= r; }\n    constexpr Fp operator/(const Fp& r) const noexcept { return Fp(*this)\
    \ /= r; }\n    constexpr Fp& operator+=(const Fp& r) noexcept {\n        val +=\
    \ r.val;\n        if (val >= MODS[IND]) val -= MODS[IND];\n        return *this;\n\
    \    }\n    constexpr Fp& operator-=(const Fp& r) noexcept {\n        val -= r.val;\n\
    \        if (val < 0) val += MODS[IND];\n        return *this;\n    }\n    constexpr\
    \ Fp& operator*=(const Fp& r) noexcept {\n        val = val * r.val % MODS[IND];\n\
    \        return *this;\n    }\n    constexpr Fp& operator/=(const Fp& r) noexcept\
    \ {\n        long long a = r.val, b = MODS[IND], u = 1, v = 0;\n        while\
    \ (b) {\n            long long t = a / b;\n            a -= t * b;\n         \
    \   swap(a, b);\n            u -= t * v;\n            swap(u, v);\n        }\n\
    \        val = val * u % MODS[IND];\n        if (val < 0) val += MODS[IND];\n\
    \        return *this;\n    }\n    constexpr bool operator==(const Fp& r) const\
    \ noexcept {\n        return this->val == r.val;\n    }\n    constexpr bool operator!=(const\
    \ Fp& r) const noexcept {\n        return this->val != r.val;\n    }\n    friend\
    \ constexpr istream& operator>>(istream& is, Fp<IND>& x) noexcept {\n        is\
    \ >> x.val;\n        x.val %= MODS[IND];\n        if (x.val < 0) x.val += MODS[IND];\n\
    \        return is;\n    }\n    friend constexpr ostream& operator<<(ostream&\
    \ os, const Fp<IND>& x) noexcept {\n        return os << x.val;\n    }\n    friend\
    \ constexpr Fp<IND> modpow(const Fp<IND>& r, long long n) noexcept {\n       \
    \ if (n == 0) return 1;\n        if (n < 0) return modpow(modinv(r), -n);\n  \
    \      auto t = modpow(r, n / 2);\n        t = t * t;\n        if (n & 1) t =\
    \ t * r;\n        return t;\n    }\n    friend constexpr Fp<IND> modinv(const\
    \ Fp<IND>& r) noexcept {\n        long long a = r.val, b = MODS[IND], u = 1, v\
    \ = 0;\n        while (b) {\n            long long t = a / b;\n            a -=\
    \ t * b, swap(a, b);\n            u -= t * v, swap(u, v);\n        }\n       \
    \ return Fp<IND>(u);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <int IND\
    \ = 0>\nstruct Fp {\n    long long val;\n    constexpr Fp(long long v = 0) noexcept\
    \ : val(v % MODS[IND]) {\n        if (val < 0) val += MODS[IND];\n    }\n    constexpr\
    \ int getmod() const { return MODS[IND]; }\n    constexpr Fp operator-() const\
    \ noexcept {\n        return val ? MODS[IND] - val : 0;\n    }\n    constexpr\
    \ Fp operator+(const Fp& r) const noexcept { return Fp(*this) += r; }\n    constexpr\
    \ Fp operator-(const Fp& r) const noexcept { return Fp(*this) -= r; }\n    constexpr\
    \ Fp operator*(const Fp& r) const noexcept { return Fp(*this) *= r; }\n    constexpr\
    \ Fp operator/(const Fp& r) const noexcept { return Fp(*this) /= r; }\n    constexpr\
    \ Fp& operator+=(const Fp& r) noexcept {\n        val += r.val;\n        if (val\
    \ >= MODS[IND]) val -= MODS[IND];\n        return *this;\n    }\n    constexpr\
    \ Fp& operator-=(const Fp& r) noexcept {\n        val -= r.val;\n        if (val\
    \ < 0) val += MODS[IND];\n        return *this;\n    }\n    constexpr Fp& operator*=(const\
    \ Fp& r) noexcept {\n        val = val * r.val % MODS[IND];\n        return *this;\n\
    \    }\n    constexpr Fp& operator/=(const Fp& r) noexcept {\n        long long\
    \ a = r.val, b = MODS[IND], u = 1, v = 0;\n        while (b) {\n            long\
    \ long t = a / b;\n            a -= t * b;\n            swap(a, b);\n        \
    \    u -= t * v;\n            swap(u, v);\n        }\n        val = val * u %\
    \ MODS[IND];\n        if (val < 0) val += MODS[IND];\n        return *this;\n\
    \    }\n    constexpr bool operator==(const Fp& r) const noexcept {\n        return\
    \ this->val == r.val;\n    }\n    constexpr bool operator!=(const Fp& r) const\
    \ noexcept {\n        return this->val != r.val;\n    }\n    friend constexpr\
    \ istream& operator>>(istream& is, Fp<IND>& x) noexcept {\n        is >> x.val;\n\
    \        x.val %= MODS[IND];\n        if (x.val < 0) x.val += MODS[IND];\n   \
    \     return is;\n    }\n    friend constexpr ostream& operator<<(ostream& os,\
    \ const Fp<IND>& x) noexcept {\n        return os << x.val;\n    }\n    friend\
    \ constexpr Fp<IND> modpow(const Fp<IND>& r, long long n) noexcept {\n       \
    \ if (n == 0) return 1;\n        if (n < 0) return modpow(modinv(r), -n);\n  \
    \      auto t = modpow(r, n / 2);\n        t = t * t;\n        if (n & 1) t =\
    \ t * r;\n        return t;\n    }\n    friend constexpr Fp<IND> modinv(const\
    \ Fp<IND>& r) noexcept {\n        long long a = r.val, b = MODS[IND], u = 1, v\
    \ = 0;\n        while (b) {\n            long long t = a / b;\n            a -=\
    \ t * b, swap(a, b);\n            u -= t * v, swap(u, v);\n        }\n       \
    \ return Fp<IND>(u);\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/dynamic_modular-arithmetic.hpp
  requiredBy: []
  timestamp: '2023-03-14 23:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic_modular-arithmetic.hpp
layout: document
title: "\u52D5\u7684 modint"
---
