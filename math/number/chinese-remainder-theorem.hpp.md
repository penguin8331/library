---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number/ext-gcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2659.test.cpp
    title: test/AOJ/2659.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"math/number/ext-gcd.hpp\"\
    \n\nlong long extGcd(long long a, long long b, long long &p, long long &q) {\n\
    \    if (b == 0) { \n        p = 1, q = 0; \n        return a; \n    }\n    long\
    \ long d = extGcd(b, a % b, q, p);\n    q -= a / b * p;\n    return d;\n}\n#line\
    \ 4 \"math/number/chinese-remainder-theorem.hpp\"\n\npair<long long, long long>\
    \ crt(const vector<long long>& vr, const vector<long long>& vm) {\n    if (vr.empty()\
    \ || vm.empty()) return make_pair(0, 1);\n    long long R = vr[0], M = vm[0];\n\
    \    for (int i = 1; i < (int)vr.size(); ++i) {\n        long long p, q, r = vr[i],\
    \ m = vm[i];\n        if (M < m) swap(M, m), swap(R, r);  // prevent overflow\n\
    \        long long d = extGcd(M, m, p, q);   // p is inv of M/d (mod. m/d)\n \
    \       if ((r - R) % d != 0) return make_pair(0, -1);\n        long long md =\
    \ m / d;\n        long long tmp = (r - R) / d % md * p % md;\n        R += M *\
    \ tmp, M *= md;\n    }\n    R %= M;\n    if (R < 0) R += M;\n    return make_pair(R,\
    \ M);\n}\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n#include \"../../math/number/ext-gcd.hpp\"\
    \n\npair<long long, long long> crt(const vector<long long>& vr, const vector<long\
    \ long>& vm) {\n    if (vr.empty() || vm.empty()) return make_pair(0, 1);\n  \
    \  long long R = vr[0], M = vm[0];\n    for (int i = 1; i < (int)vr.size(); ++i)\
    \ {\n        long long p, q, r = vr[i], m = vm[i];\n        if (M < m) swap(M,\
    \ m), swap(R, r);  // prevent overflow\n        long long d = extGcd(M, m, p,\
    \ q);   // p is inv of M/d (mod. m/d)\n        if ((r - R) % d != 0) return make_pair(0,\
    \ -1);\n        long long md = m / d;\n        long long tmp = (r - R) / d % md\
    \ * p % md;\n        R += M * tmp, M *= md;\n    }\n    R %= M;\n    if (R < 0)\
    \ R += M;\n    return make_pair(R, M);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - math/number/ext-gcd.hpp
  isVerificationFile: false
  path: math/number/chinese-remainder-theorem.hpp
  requiredBy: []
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2659.test.cpp
documentation_of: math/number/chinese-remainder-theorem.hpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---
