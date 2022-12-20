---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/YukiCoder/1800.test.cpp
    title: test/YukiCoder/1800.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructure/Static_ModularArithmetic.hpp\"\ntemplate <int\
    \ MOD>\nstruct Fp {\n    long long val;\n    constexpr Fp(long long v = 0) noexcept\
    \ : val(v % MOD) {\n        if (val < 0) val += MOD;\n    }\n    constexpr int\
    \ getmod() const { return MOD; }\n    constexpr Fp operator-() const noexcept\
    \ {\n        return val ? MOD - val : 0;\n    }\n    constexpr Fp operator+(const\
    \ Fp& r) const noexcept { return Fp(*this) += r; }\n    constexpr Fp operator-(const\
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
    \      }\n        return Fp<MOD>(u);\n    }\n};\n"
  code: "template <int MOD>\nstruct Fp {\n    long long val;\n    constexpr Fp(long\
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
    \ Fp<MOD>(u);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/Static_ModularArithmetic.hpp
  requiredBy: []
  timestamp: '2022-12-20 12:47:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/YukiCoder/1800.test.cpp
documentation_of: DataStructure/Static_ModularArithmetic.hpp
layout: document
redirect_from:
- /library/DataStructure/Static_ModularArithmetic.hpp
- /library/DataStructure/Static_ModularArithmetic.hpp.html
title: DataStructure/Static_ModularArithmetic.hpp
---
