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
    \ std;\n#line 3 \"algorithm/compress.hpp\"\n\r\ntemplate <typename T>\r\nvector<T>\
    \ compress(vector<T> &X) {\r\n    // \u30BD\u30FC\u30C8\u3057\u305F\u7D50\u679C\
    \u3092 vals \u306B\r\n    vector<T> vals = X;\r\n    sort(vals.begin(), vals.end());\r\
    \n    // \u96A3\u308A\u5408\u3046\u91CD\u8907\u3092\u524A\u9664(unique), \u672B\
    \u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664(erase)\r\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\r\n    // \u5404\u8981\u7D20\u3054\u3068\u306B\u4E8C\
    \u5206\u63A2\u7D22\u3067\u4F4D\u7F6E\u3092\u6C42\u3081\u308B\r\n    for (int i\
    \ = 0; i < (int)X.size(); i++) {\r\n        X[i] = lower_bound(vals.begin(), vals.end(),\
    \ X[i]) - vals.begin();\r\n    }\r\n    return vals;\r\n}\n"
  code: "#pragma once\r\n#include \"../template/template.hpp\"\r\n\r\ntemplate <typename\
    \ T>\r\nvector<T> compress(vector<T> &X) {\r\n    // \u30BD\u30FC\u30C8\u3057\u305F\
    \u7D50\u679C\u3092 vals \u306B\r\n    vector<T> vals = X;\r\n    sort(vals.begin(),\
    \ vals.end());\r\n    // \u96A3\u308A\u5408\u3046\u91CD\u8907\u3092\u524A\u9664\
    (unique), \u672B\u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664(erase)\r\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\r\n    // \u5404\u8981\u7D20\u3054\u3068\u306B\u4E8C\
    \u5206\u63A2\u7D22\u3067\u4F4D\u7F6E\u3092\u6C42\u3081\u308B\r\n    for (int i\
    \ = 0; i < (int)X.size(); i++) {\r\n        X[i] = lower_bound(vals.begin(), vals.end(),\
    \ X[i]) - vals.begin();\r\n    }\r\n    return vals;\r\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: algorithm/compress.hpp
  requiredBy: []
  timestamp: '2023-03-21 18:23:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---
