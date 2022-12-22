---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/0233.test.cpp
    title: test/AOJ/0233.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/number/convert-base.hpp\"\ntemplate <class T>\nvector<T>\
    \ convert_base(T x, T b) {\n    vector<T> ret;\n    T t = 1, k = abs(b);\n   \
    \ while (x) {\n        ret.emplace_back((x * t) % k);\n        if (ret.back()\
    \ < 0) ret.back() += k;\n        x -= ret.back() * t;\n        x /= k;\n     \
    \   t *= b / k;\n    }\n    if (ret.empty()) ret.emplace_back(0);\n    reverse(begin(ret),\
    \ end(ret));\n    return ret;\n}\n"
  code: "template <class T>\nvector<T> convert_base(T x, T b) {\n    vector<T> ret;\n\
    \    T t = 1, k = abs(b);\n    while (x) {\n        ret.emplace_back((x * t) %\
    \ k);\n        if (ret.back() < 0) ret.back() += k;\n        x -= ret.back() *\
    \ t;\n        x /= k;\n        t *= b / k;\n    }\n    if (ret.empty()) ret.emplace_back(0);\n\
    \    reverse(begin(ret), end(ret));\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number/convert-base.hpp
  requiredBy: []
  timestamp: '2022-12-22 15:03:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/0233.test.cpp
documentation_of: math/number/convert-base.hpp
layout: document
title: "\u9032\u6570\u5909\u63DB"
---
