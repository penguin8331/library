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
    #line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"others/date.hpp\"\
    \n\r\nvector<string> S = {\"Saturday\", \"Sunday\", \"Monday\", \"Tuesday\", \"\
    Wednesday\", \"Thursday\", \"Friday\"};\r\n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\
    \u3092\u6C42\u3081\u308B\r\n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\u306B\u304A\
    \u3051\u308B\u30E6\u30EA\u30A6\u30B9\u65E5\uFF081582\u5E7410\u670815\u65E5\u3092\
    \u57FA\u6E96\u3068\u3057\u305F\u65E5\u3001\u4F46\u3057\u3001-4712\u5E741\u6708\
    1\u65E5\u304C0\u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\uFF09\r\nint GregorianDay(int\
    \ y, int m, int d) {\r\n    y += 4800;\r\n    if (m < 3) {\r\n        --y;\r\n\
    \        m += 12;\r\n    }\r\n    return 365 * y + y / 4 - y / 100 + y / 400 +\
    \ (153 * m - 457) / 5 + d - 32083;\r\n}\r\n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\
    \u306E\u4E0B\u3067\u306E\u66DC\u65E5\uFF08\u65E5:1\u3001\u6708:2\u3001\u706B:3\u3001\
    \u6C34:4\u3001\u6728:5\u3001\u91D1:6\u3001\u571F:0\uFF09\r\nint dayWeek(int y,\
    \ int m, int d) {\r\n    return (GregorianDay(y, m, d) + 5) % 7;\r\n}\n"
  code: "#pragma once\r\n#include \"../template/template.hpp\"\r\n\r\nvector<string>\
    \ S = {\"Saturday\", \"Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\"\
    , \"Friday\"};\r\n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\u3092\u6C42\u3081\u308B\
    \r\n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\u306B\u304A\u3051\u308B\u30E6\u30EA\
    \u30A6\u30B9\u65E5\uFF081582\u5E7410\u670815\u65E5\u3092\u57FA\u6E96\u3068\u3057\
    \u305F\u65E5\u3001\u4F46\u3057\u3001-4712\u5E741\u67081\u65E5\u304C0\u3068\u306A\
    \u308B\u3088\u3046\u306B\u3059\u308B\uFF09\r\nint GregorianDay(int y, int m, int\
    \ d) {\r\n    y += 4800;\r\n    if (m < 3) {\r\n        --y;\r\n        m += 12;\r\
    \n    }\r\n    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) /\
    \ 5 + d - 32083;\r\n}\r\n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\u306E\u4E0B\u3067\
    \u306E\u66DC\u65E5\uFF08\u65E5:1\u3001\u6708:2\u3001\u706B:3\u3001\u6C34:4\u3001\
    \u6728:5\u3001\u91D1:6\u3001\u571F:0\uFF09\r\nint dayWeek(int y, int m, int d)\
    \ {\r\n    return (GregorianDay(y, m, d) + 5) % 7;\r\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: others/date.hpp
  requiredBy: []
  timestamp: '2023-03-21 11:42:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/date.hpp
layout: document
title: "\u65E5\u4ED8,\u66DC\u65E5"
---
