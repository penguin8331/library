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
  bundledCode: "#line 1 \"data-structure/dynamic_modular-arithmetic.hpp\"\ntemplate\
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
  code: "template <int IND = 0>\nstruct Fp {\n    long long val;\n    constexpr Fp(long\
    \ long v = 0) noexcept : val(v % MODS[IND]) {\n        if (val < 0) val += MODS[IND];\n\
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
    \ return Fp<IND>(u);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/dynamic_modular-arithmetic.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/dynamic_modular-arithmetic.hpp
layout: document
title: "\u52D5\u7684 modint"
---
