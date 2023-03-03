---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
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
    \ long long;\nusing ld = long double;\nusing pii = pair<int, int>;\nusing pll\
    \ = pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\n\
    constexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1,\
    \ 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9\
    \ + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T&\
    \ a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename\
    \ T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false));\
    \ }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n    \
    \    std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n     \
    \   std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"others/date.hpp\"\
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
  code: "#pragma once\r\n#include \"template/template.hpp\"\r\n\r\nvector<string>\
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
  isVerificationFile: false
  path: others/date.hpp
  requiredBy: []
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/date.hpp
layout: document
title: "\u65E5\u4ED8"
---
