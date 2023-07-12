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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/binomial-cofficient-prime-mod.test.cpp
    title: test/yosupo/binomial-cofficient-prime-mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)\
    \        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...) \
    \       \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
    \     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
    #define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug_print.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/dynamic_modular-arithmetic.hpp\"\n\nvector<int>\
    \ MODS;\ntemplate <int IND = 0>\nstruct Fp {\n    long long val;\n    constexpr\
    \ Fp(long long v = 0) noexcept : val(v % MODS[IND]) {\n        if (val < 0) val\
    \ += MODS[IND];\n    }\n    constexpr int getmod() const { return MODS[IND]; }\n\
    \    constexpr Fp operator-() const noexcept {\n        return val ? MODS[IND]\
    \ - val : 0;\n    }\n    constexpr Fp operator+(const Fp& r) const noexcept {\
    \ return Fp(*this) += r; }\n    constexpr Fp operator-(const Fp& r) const noexcept\
    \ { return Fp(*this) -= r; }\n    constexpr Fp operator*(const Fp& r) const noexcept\
    \ { return Fp(*this) *= r; }\n    constexpr Fp operator/(const Fp& r) const noexcept\
    \ { return Fp(*this) /= r; }\n    constexpr Fp& operator+=(const Fp& r) noexcept\
    \ {\n        val += r.val;\n        if (val >= MODS[IND]) val -= MODS[IND];\n\
    \        return *this;\n    }\n    constexpr Fp& operator-=(const Fp& r) noexcept\
    \ {\n        val -= r.val;\n        if (val < 0) val += MODS[IND];\n        return\
    \ *this;\n    }\n    constexpr Fp& operator*=(const Fp& r) noexcept {\n      \
    \  val = val * r.val % MODS[IND];\n        return *this;\n    }\n    constexpr\
    \ Fp& operator/=(const Fp& r) noexcept {\n        long long a = r.val, b = MODS[IND],\
    \ u = 1, v = 0;\n        while (b) {\n            long long t = a / b;\n     \
    \       a -= t * b;\n            swap(a, b);\n            u -= t * v;\n      \
    \      swap(u, v);\n        }\n        val = val * u % MODS[IND];\n        if\
    \ (val < 0) val += MODS[IND];\n        return *this;\n    }\n    constexpr bool\
    \ operator==(const Fp& r) const noexcept {\n        return this->val == r.val;\n\
    \    }\n    constexpr bool operator!=(const Fp& r) const noexcept {\n        return\
    \ this->val != r.val;\n    }\n    friend constexpr istream& operator>>(istream&\
    \ is, Fp<IND>& x) noexcept {\n        is >> x.val;\n        x.val %= MODS[IND];\n\
    \        if (x.val < 0) x.val += MODS[IND];\n        return is;\n    }\n    friend\
    \ constexpr ostream& operator<<(ostream& os, const Fp<IND>& x) noexcept {\n  \
    \      return os << x.val;\n    }\n    friend constexpr Fp<IND> modpow(const Fp<IND>&\
    \ r, long long n) noexcept {\n        if (n == 0) return 1;\n        if (n < 0)\
    \ return modpow(modinv(r), -n);\n        auto t = modpow(r, n / 2);\n        t\
    \ = t * t;\n        if (n & 1) t = t * r;\n        return t;\n    }\n    friend\
    \ constexpr Fp<IND> modinv(const Fp<IND>& r) noexcept {\n        long long a =\
    \ r.val, b = MODS[IND], u = 1, v = 0;\n        while (b) {\n            long long\
    \ t = a / b;\n            a -= t * b, swap(a, b);\n            u -= t * v, swap(u,\
    \ v);\n        }\n        return Fp<IND>(u);\n    }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nvector<int> MODS;\n\
    template <int IND = 0>\nstruct Fp {\n    long long val;\n    constexpr Fp(long\
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
  timestamp: '2023-04-21 23:32:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/binomial-cofficient-prime-mod.test.cpp
documentation_of: data-structure/dynamic_modular-arithmetic.hpp
layout: document
title: Dynamic-ModInt
---
