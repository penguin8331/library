---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number/ext-gcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
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
  bundledCode: "#line 1 \"math/number/ext-gcd.hpp\"\nlong long extGcd(long long a,\
    \ long long b, long long &p, long long &q) {\n    if (b == 0) { \n        p =\
    \ 1, q = 0; \n        return a; \n    }\n    long long d = extGcd(b, a % b, q,\
    \ p);\n    q -= a / b * p;\n    return d;\n}\n#line 2 \"math/number/chinese-remainder-theorem.hpp\"\
    \n\npair<long long, long long> crt(const vector<long long>& vr, const vector<long\
    \ long>& vm) {\n    if (vr.empty() || vm.empty()) return make_pair(0, 1);\n  \
    \  long long R = vr[0], M = vm[0];\n    for (int i = 1; i < (int)vr.size(); ++i)\
    \ {\n        long long p, q, r = vr[i], m = vm[i];\n        if (M < m) swap(M,\
    \ m), swap(R, r);  // prevent overflow\n        long long d = extGcd(M, m, p,\
    \ q);   // p is inv of M/d (mod. m/d)\n        if ((r - R) % d != 0) return make_pair(0,\
    \ -1);\n        long long md = m / d;\n        long long tmp = (r - R) / d % md\
    \ * p % md;\n        R += M * tmp, M *= md;\n    }\n    R %= M;\n    if (R < 0)\
    \ R += M;\n    return make_pair(R, M);\n}\n"
  code: "#include \"math/number/ext-gcd.hpp\"\n\npair<long long, long long> crt(const\
    \ vector<long long>& vr, const vector<long long>& vm) {\n    if (vr.empty() ||\
    \ vm.empty()) return make_pair(0, 1);\n    long long R = vr[0], M = vm[0];\n \
    \   for (int i = 1; i < (int)vr.size(); ++i) {\n        long long p, q, r = vr[i],\
    \ m = vm[i];\n        if (M < m) swap(M, m), swap(R, r);  // prevent overflow\n\
    \        long long d = extGcd(M, m, p, q);   // p is inv of M/d (mod. m/d)\n \
    \       if ((r - R) % d != 0) return make_pair(0, -1);\n        long long md =\
    \ m / d;\n        long long tmp = (r - R) / d % md * p % md;\n        R += M *\
    \ tmp, M *= md;\n    }\n    R %= M;\n    if (R < 0) R += M;\n    return make_pair(R,\
    \ M);\n}"
  dependsOn:
  - math/number/ext-gcd.hpp
  isVerificationFile: false
  path: math/number/chinese-remainder-theorem.hpp
  requiredBy: []
  timestamp: '2023-01-23 15:58:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2659.test.cpp
documentation_of: math/number/chinese-remainder-theorem.hpp
layout: document
title: "\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406"
---
