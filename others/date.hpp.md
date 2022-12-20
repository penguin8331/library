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
  bundledCode: "#line 1 \"others/date.hpp\"\nvector<string> S = {\"Saturday\", \"\
    Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\", \"Friday\"};\r\
    \n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\u3092\u6C42\u3081\u308B\r\n// \u30B0\
    \u30EC\u30B4\u30EA\u30AA\u6B74\u306B\u304A\u3051\u308B\u30E6\u30EA\u30A6\u30B9\
    \u65E5\uFF081582\u5E7410\u670815\u65E5\u3092\u57FA\u6E96\u3068\u3057\u305F\u65E5\
    \u3001\u4F46\u3057\u3001-4712\u5E741\u67081\u65E5\u304C0\u3068\u306A\u308B\u3088\
    \u3046\u306B\u3059\u308B\uFF09\r\nint GregorianDay(int y, int m, int d) {\r\n\
    \    y += 4800;\r\n    if (m < 3) {\r\n        --y;\r\n        m += 12;\r\n  \
    \  }\r\n    return 365 * y + y / 4 - y / 100 + y / 400 + (153 * m - 457) / 5 +\
    \ d - 32083;\r\n}\r\n// \u30B0\u30EC\u30B4\u30EA\u30AA\u6B74\u306E\u4E0B\u3067\
    \u306E\u66DC\u65E5\uFF08\u65E5:1\u3001\u6708:2\u3001\u706B:3\u3001\u6C34:4\u3001\
    \u6728:5\u3001\u91D1:6\u3001\u571F:0\uFF09\r\nint dayWeek(int y, int m, int d)\
    \ {\r\n    return (GregorianDay(y, m, d) + 5) % 7;\r\n}\n"
  code: "vector<string> S = {\"Saturday\", \"Sunday\", \"Monday\", \"Tuesday\", \"\
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
    \ int m, int d) {\r\n    return (GregorianDay(y, m, d) + 5) % 7;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: others/date.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:04:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: others/date.hpp
layout: document
redirect_from:
- /library/others/date.hpp
- /library/others/date.hpp.html
title: others/date.hpp
---
