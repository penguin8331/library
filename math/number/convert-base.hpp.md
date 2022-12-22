---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/0233.test.cpp
    title: test/AOJ/0233.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/convert-base.hpp\"\nvector<T> convert_base(T\
    \ x, T b) {\n    vector<T> ret;\n    T t = 1, k = abs(b);\n    while (x) {\n \
    \       ret.emplace_back((x * t) % k);\n        if (ret.back() < 0) ret.back()\
    \ += k;\n        x -= ret.back() * t;\n        x /= k;\n        t *= b / k;\n\
    \    }\n    if (ret.empty()) ret.emplace_back(0);\n    reverse(begin(ret), end(ret));\n\
    \    return ret;\n}\n"
  code: "vector<T> convert_base(T x, T b) {\n    vector<T> ret;\n    T t = 1, k =\
    \ abs(b);\n    while (x) {\n        ret.emplace_back((x * t) % k);\n        if\
    \ (ret.back() < 0) ret.back() += k;\n        x -= ret.back() * t;\n        x /=\
    \ k;\n        t *= b / k;\n    }\n    if (ret.empty()) ret.emplace_back(0);\n\
    \    reverse(begin(ret), end(ret));\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number/convert-base.hpp
  requiredBy: []
  timestamp: '2022-12-22 14:57:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/0233.test.cpp
documentation_of: math/number/convert-base.hpp
layout: document
title: "\u9032\u6570\u5909\u63DB"
---
