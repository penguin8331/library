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
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define eb emplace_back\n\
    #define all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x), std::rend(x)\n\
    #define elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#define INT(...)     \\\n    int __VA_ARGS__;\
    \ \\\n    scan(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define STR(...)        \\\n    string __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define CHR(...)      \\\n    char __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define DOU(...)        \\\n    double __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define LD(...)     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ld = long double;\n\
    using pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int\
    \ inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[8] = {1, 0,\
    \ -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n\
    constexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\
    \n\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a\
    \ = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b)\
    \ { return ((a > b) ? (a = b, true) : (false)); }\ntemplate <typename T, typename\
    \ U>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {\n\
    \    os << p.first << \" \" << p.second;\n    return os;\n}\ntemplate <typename\
    \ T, typename U>\nstd::istream &operator>>(std::istream &is, std::pair<T, U> &p)\
    \ {\n    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename T>\n\
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {\n    for\
    \ (auto it = std::begin(v); it != std::end(v);) {\n        os << *it << ((++it)\
    \ != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v) {\n    for\
    \ (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline void scan()\
    \ {}\ntemplate <class Head, class... Tail>\ninline void scan(Head &head, Tail\
    \ &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate <class T>\n\
    inline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate <class Head,\
    \ class... Tail>\ninline void print(const Head &head, const Tail &...tail) {\n\
    \    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate <class... T>\n\
    inline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n}\n#line 3 \"\
    template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n        std::cout.tie(0);\n      \
    \  std::cout << std::fixed << std::setprecision(12);\n        std::cerr << std::fixed\
    \ << std::setprecision(12);\n    }\n} IOSetup;\n#line 3 \"template/debug.hpp\"\
    \n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n#define debug(...)\n#endif\n\
    #line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/boost-multiprecision.hpp\"\
    \n\n#include <boost/multiprecision/cpp_dec_float.hpp>\n#include <boost/multiprecision/cpp_int.hpp>\n\
    using Bint = boost::multiprecision::cpp_int;\nusing Real = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;\n"
  code: '#pragma once

    #include "../template/template.hpp"


    #include <boost/multiprecision/cpp_dec_float.hpp>

    #include <boost/multiprecision/cpp_int.hpp>

    using Bint = boost::multiprecision::cpp_int;

    using Real = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>;'
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/boost-multiprecision.hpp
  requiredBy: []
  timestamp: '2023-03-21 11:42:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/boost-multiprecision.hpp
layout: document
title: boost/multiprecision
---

## 概要

`Bint` (`<boost/multiprecision/cpp_int.hpp>` `boost::multiprecision::cpp_int`)  
任意長整数型

`Real` (`<boost/multiprecision/cpp_dec_float.hpp>` `boost::multiprecision::number<boost::multiprecision::cpp_dec_float<1024>>`)  
仮数部が10進数で1024桁の浮動小数点数型

## 使い方

`x.str()` := `Bint` もしくは `Real` 型の変数 `x` を `string` 型に変換する  

`x.assign(string str) := `str` から `Bint` もしくは `Real` 型へと変換する

