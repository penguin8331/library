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
    using namespace std;\n#line 3 \"dynamic-programming/longest-increasing-subsequence-restoration.hpp\"\
    \n\ntemplate <class T>\nvector<T> LISRestoration(vector<T> a, bool is_strong =\
    \ true) {\n    int n = (int)a.size();\n    vector<T> dp;\n    vector<int> positions;\n\
    \    for (int i = 0; i < n; ++i) {\n        auto it = (is_strong ? lower_bound(dp.begin(),\
    \ dp.end(), a[i]) : upper_bound(dp.begin(), dp.end(), a[i]));\n        positions.push_back(distance(dp.begin(),\
    \ it));\n        if (it == dp.end())\n            dp.push_back(a[i]);\n      \
    \  else\n            *it = a[i];\n    }\n    vector<T> subseq(dp.size());\n  \
    \  int si = ((int)subseq.size()) - 1;\n    int pi = ((int)positions.size()) -\
    \ 1;\n    while ((0 <= si) && (0 <= pi)) {\n        if (positions[pi] == si) {\n\
    \            subseq[si] = pi;\n            --si;\n        }\n        --pi;\n \
    \   }\n    return subseq;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class T>\n\
    vector<T> LISRestoration(vector<T> a, bool is_strong = true) {\n    int n = (int)a.size();\n\
    \    vector<T> dp;\n    vector<int> positions;\n    for (int i = 0; i < n; ++i)\
    \ {\n        auto it = (is_strong ? lower_bound(dp.begin(), dp.end(), a[i]) :\
    \ upper_bound(dp.begin(), dp.end(), a[i]));\n        positions.push_back(distance(dp.begin(),\
    \ it));\n        if (it == dp.end())\n            dp.push_back(a[i]);\n      \
    \  else\n            *it = a[i];\n    }\n    vector<T> subseq(dp.size());\n  \
    \  int si = ((int)subseq.size()) - 1;\n    int pi = ((int)positions.size()) -\
    \ 1;\n    while ((0 <= si) && (0 <= pi)) {\n        if (positions[pi] == si) {\n\
    \            subseq[si] = pi;\n            --si;\n        }\n        --pi;\n \
    \   }\n    return subseq;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: dynamic-programming/longest-increasing-subsequence-restoration.hpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dynamic-programming/longest-increasing-subsequence-restoration.hpp
layout: document
title: "LIS (\u5FA9\u5143\u3042\u308A)"
---
