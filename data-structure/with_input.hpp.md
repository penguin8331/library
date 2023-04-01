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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/with_input.hpp\"\n\ntemplate <class T, class\
    \ = void>\nstruct with_input {};\n\ntemplate <class T>\nstruct with_input<T, std::enable_if_t<!std::is_class_v<T>>>\
    \ {\n   private:\n    T val;\n\n   public:\n    with_input() {\n        std::cin\
    \ >> val;\n    }\n    explicit inline with_input(const T& val)\n        : val(val)\
    \ {}\n    explicit inline with_input(T&& val)\n        : val(static_cast<T&&>(val))\
    \ {}\n    inline operator const T&() const {\n        return val;\n    }\n   \
    \ inline operator T&() {\n        return val;\n    }\n};\n\nusing inti = with_input<int>;\n\
    using lli = with_input<ll>;\nusing stri = with_input<string>;\nusing chai = with_input<char>;\n\
    using doui = with_input<double>;\nusing ldi = with_input<ld>;\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T,\
    \ class = void>\nstruct with_input {};\n\ntemplate <class T>\nstruct with_input<T,\
    \ std::enable_if_t<!std::is_class_v<T>>> {\n   private:\n    T val;\n\n   public:\n\
    \    with_input() {\n        std::cin >> val;\n    }\n    explicit inline with_input(const\
    \ T& val)\n        : val(val) {}\n    explicit inline with_input(T&& val)\n  \
    \      : val(static_cast<T&&>(val)) {}\n    inline operator const T&() const {\n\
    \        return val;\n    }\n    inline operator T&() {\n        return val;\n\
    \    }\n};\n\nusing inti = with_input<int>;\nusing lli = with_input<ll>;\nusing\
    \ stri = with_input<string>;\nusing chai = with_input<char>;\nusing doui = with_input<double>;\n\
    using ldi = with_input<ld>;"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/with_input.hpp
  requiredBy: []
  timestamp: '2023-03-22 10:09:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/with_input.hpp
layout: document
title: With-Input
---

## 概要

[もとの文](https://twitter.com/mihatsu_s/status/1636729478369120256)  

基本的には `T` 型と同様に振る舞うがデフォルトコンストラクタで標準入力から値を受け取る