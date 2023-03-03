---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
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
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\nusing\
    \ pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 7 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"algorithm/compress.hpp\"\
    \n\r\ntemplate <typename T>\r\nvector<T> compress(vector<T> &X) {\r\n    // \u30BD\
    \u30FC\u30C8\u3057\u305F\u7D50\u679C\u3092 vals \u306B\r\n    vector<T> vals =\
    \ X;\r\n    sort(vals.begin(), vals.end());\r\n    // \u96A3\u308A\u5408\u3046\
    \u91CD\u8907\u3092\u524A\u9664(unique), \u672B\u7AEF\u306E\u30B4\u30DF\u3092\u524A\
    \u9664(erase)\r\n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\r\
    \n    // \u5404\u8981\u7D20\u3054\u3068\u306B\u4E8C\u5206\u63A2\u7D22\u3067\u4F4D\
    \u7F6E\u3092\u6C42\u3081\u308B\r\n    for (int i = 0; i < (int)X.size(); i++)\
    \ {\r\n        X[i] = lower_bound(vals.begin(), vals.end(), X[i]) - vals.begin();\r\
    \n    }\r\n    return vals;\r\n}\n"
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
  isVerificationFile: false
  path: algorithm/compress.hpp
  requiredBy: []
  timestamp: '2023-03-03 16:10:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---
