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
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_4_A.test.cpp
    title: test/AOJ/DSL_4_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"algorithm/compress2d.hpp\"\
    \n\r\ntemplate <typename T>\r\nvector<T> compress(vector<T> &C1, vector<T> &C2)\
    \ {\r\n    vector<T> vals;\r\n    int N = (int)C1.size();\r\n    for (int i =\
    \ 0; i < N; i++) {\r\n        for (T d = 0; d < 1; d++) {  // \u305D\u306E\u4F4D\
    \u7F6E\u3068\u3001\u4E00\u3064\u96A3\u3092\u78BA\u4FDD(\u96A3\u3092\u78BA\u4FDD\
    \u3057\u306A\u3044\u3068\u7A7A\u767D\u304C\u57CB\u307E\u3063\u3066\u3057\u307E\
    \u3046\u3053\u3068\u304C\u3042\u308B)\r\n            T tc1 = C1[i] + d;\r\n  \
    \          T tc2 = C2[i] + d;\r\n            vals.push_back(tc1);\r\n        \
    \    vals.push_back(tc2);\r\n        }\r\n    }\r\n    // \u30BD\u30FC\u30C8\r\
    \n    sort(vals.begin(), vals.end());\r\n    // \u96A3\u308A\u5408\u3046\u91CD\
    \u8907\u3092\u524A\u9664(unique), \u672B\u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664\
    (erase)\r\n    vals.erase(unique(vals.begin(), vals.end()), vals.end());\r\n \
    \   for (int i = 0; i < N; i++) {\r\n        C1[i] = lower_bound(vals.begin(),\
    \ vals.end(), C1[i]) - vals.begin();\r\n        C2[i] = lower_bound(vals.begin(),\
    \ vals.end(), C2[i]) - vals.begin();\r\n    }\r\n    return vals;\r\n}\n"
  code: "#pragma once\r\n#include \"template/template.hpp\"\r\n\r\ntemplate <typename\
    \ T>\r\nvector<T> compress(vector<T> &C1, vector<T> &C2) {\r\n    vector<T> vals;\r\
    \n    int N = (int)C1.size();\r\n    for (int i = 0; i < N; i++) {\r\n       \
    \ for (T d = 0; d < 1; d++) {  // \u305D\u306E\u4F4D\u7F6E\u3068\u3001\u4E00\u3064\
    \u96A3\u3092\u78BA\u4FDD(\u96A3\u3092\u78BA\u4FDD\u3057\u306A\u3044\u3068\u7A7A\
    \u767D\u304C\u57CB\u307E\u3063\u3066\u3057\u307E\u3046\u3053\u3068\u304C\u3042\
    \u308B)\r\n            T tc1 = C1[i] + d;\r\n            T tc2 = C2[i] + d;\r\n\
    \            vals.push_back(tc1);\r\n            vals.push_back(tc2);\r\n    \
    \    }\r\n    }\r\n    // \u30BD\u30FC\u30C8\r\n    sort(vals.begin(), vals.end());\r\
    \n    // \u96A3\u308A\u5408\u3046\u91CD\u8907\u3092\u524A\u9664(unique), \u672B\
    \u7AEF\u306E\u30B4\u30DF\u3092\u524A\u9664(erase)\r\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\r\n    for (int i = 0; i < N; i++) {\r\n        C1[i]\
    \ = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();\r\n        C2[i]\
    \ = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();\r\n    }\r\n\
    \    return vals;\r\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  isVerificationFile: false
  path: algorithm/compress2d.hpp
  requiredBy: []
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DSL_4_A.test.cpp
documentation_of: algorithm/compress2d.hpp
layout: document
title: "\u4E8C\u6B21\u5143\u5EA7\u6A19\u5727\u7E2E"
---
