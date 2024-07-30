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
    \ 3 \"template/macro.hpp\"\n\n#define overload3(_1, _2, _3, name, ...) name\n\
    #define all1(v) std::begin(v), std::end(v)\n#define all2(v, a) std::begin(v),\
    \ std::begin(v) + a\n#define all3(v, a, b) std::begin(v) + a, std::begin(v) +\
    \ b\n#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)\n\
    #define rall1(v) std::rbegin(v), std::rend(v)\n#define rall2(v, a) std::rbegin(v),\
    \ std::rbegin(v) + a\n#define rall3(v, a, b) std::rbegin(v) + a, std::rbegin(v)\
    \ + b\n#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)\n\
    #define elif else if\n#define updiv(N, X) (((N) + (X) - 1) / (X))\n#define sigma(a,\
    \ b) (((a) + (b)) * ((b) - (a) + 1) / 2)\n#define INT(...)     \\\n    int __VA_ARGS__;\
    \ \\\n    scan(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define STR(...)        \\\n    string __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define CHR(...)      \\\n    char __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define DOU(...)        \\\n    double __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define LD(...)     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define pb push_back\n#define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\
    \nusing ll = long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\n\
    using pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF\
    \ = 1LL << 60;\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr\
    \ int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr\
    \ int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\ntemplate <typename T, typename U>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n\
    \    return os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"math/combinatorics/binomial-coefficient.hpp\"\n\ntemplate <class\
    \ T>\nstruct BiCoef {\n    vector<T> fact_, inv_, finv_;\n    constexpr BiCoef()\
    \ {}\n    explicit constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1),\
    \ finv_(n, 1) {\n        init(n);\n    }\n    constexpr void init(int n) noexcept\
    \ {\n        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);\n    \
    \    int modular = fact_[0].getmod();\n        for (int i = 2; i < n; i++) {\n\
    \            fact_[i] = fact_[i - 1] * i;\n            inv_[i] = -inv_[modular\
    \ % i] * (modular / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n    \
    \    }\n    }\n    constexpr T com(int n, int k) const noexcept {\n        assert(n\
    \ < (int)fact_.size() && n >= k && k >= 0);\n        return fact_[n] * finv_[k]\
    \ * finv_[n - k];\n    }\n    constexpr T hom(int n, int k) const noexcept {\n\
    \        n += k - 1;\n        assert(n < (int)fact_.size() && n >= k && k >= 0);\n\
    \        return fact_[n] * finv_[k] * finv_[n - k];\n    }\n    constexpr T fact(int\
    \ n) const noexcept {\n        assert(n >= 0);\n        return fact_[n];\n   \
    \ }\n    constexpr T inv(int n) const noexcept {\n        assert(n >= 0);\n  \
    \      return inv_[n];\n    }\n    constexpr T finv(int n) const noexcept {\n\
    \        assert(n >= 0);\n        return finv_[n];\n    }\n};\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\ntemplate <class\
    \ T>\nstruct BiCoef {\n    vector<T> fact_, inv_, finv_;\n    constexpr BiCoef()\
    \ {}\n    explicit constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1),\
    \ finv_(n, 1) {\n        init(n);\n    }\n    constexpr void init(int n) noexcept\
    \ {\n        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);\n    \
    \    int modular = fact_[0].getmod();\n        for (int i = 2; i < n; i++) {\n\
    \            fact_[i] = fact_[i - 1] * i;\n            inv_[i] = -inv_[modular\
    \ % i] * (modular / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n    \
    \    }\n    }\n    constexpr T com(int n, int k) const noexcept {\n        assert(n\
    \ < (int)fact_.size() && n >= k && k >= 0);\n        return fact_[n] * finv_[k]\
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
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/binomial-cofficient-prime-mod.test.cpp
documentation_of: math/combinatorics/binomial-coefficient.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB"
---
