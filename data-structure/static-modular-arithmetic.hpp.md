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
  bundledCode: "#line 1 \"data-structure/static-modular-arithmetic.hpp\"\ntemplate\
    \ <int MOD>\nstruct Fp {\n    long long val;\n    constexpr Fp(long long v = 0)\
    \ noexcept : val(v % MOD) {\n        if (val < 0) val += MOD;\n    }\n    constexpr\
    \ int getmod() const { return MOD; }\n    constexpr Fp operator-() const noexcept\
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
  path: data-structure/static-modular-arithmetic.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/static-modular-arithmetic.hpp
layout: document
title: "\u9759\u7684modint"
---
