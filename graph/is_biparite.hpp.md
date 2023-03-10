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
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#define line\n#endif\n#line 8 \"template/template.hpp\"\n\
    using namespace std;\n#line 3 \"graph/is_biparite.hpp\"\n\nbool isbipartite(const\
    \ vector<vector<int>>& G) {\n    int N = (int)G.size();\n    vector<int> color(N,\
    \ -1);\n\n    for (int v = 0; v < N; ++v) {\n        if (color[v] != -1) {\n \
    \           continue;\n        }\n        queue<int> que;\n        color[v] =\
    \ 0;\n        que.push(v);\n        while (!que.empty()) {\n            int qv\
    \ = que.front();\n            que.pop();\n            for (auto nv : G[qv]) {\n\
    \                if (color[nv] != -1) {\n                    if (color[nv] ==\
    \ color[qv]) {\n                        return false;\n                    }\n\
    \                    continue;\n                }\n                color[nv] =\
    \ 1 - color[qv];\n                que.push(nv);\n            }\n        }\n  \
    \  }\n    return true;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nbool isbipartite(const\
    \ vector<vector<int>>& G) {\n    int N = (int)G.size();\n    vector<int> color(N,\
    \ -1);\n\n    for (int v = 0; v < N; ++v) {\n        if (color[v] != -1) {\n \
    \           continue;\n        }\n        queue<int> que;\n        color[v] =\
    \ 0;\n        que.push(v);\n        while (!que.empty()) {\n            int qv\
    \ = que.front();\n            que.pop();\n            for (auto nv : G[qv]) {\n\
    \                if (color[nv] != -1) {\n                    if (color[nv] ==\
    \ color[qv]) {\n                        return false;\n                    }\n\
    \                    continue;\n                }\n                color[nv] =\
    \ 1 - color[qv];\n                que.push(nv);\n            }\n        }\n  \
    \  }\n    return true;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/is_biparite.hpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/is_biparite.hpp
layout: document
title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
