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
  bundledCode: "#line 1 \"math/combinatorics/binomial-coefficient.hpp\"\ntemplate\
    \ <class T>\nstruct BiCoef {\n    vector<T> fact_, inv_, finv_;\n    constexpr\
    \ BiCoef() {}\n    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1),\
    \ finv_(n, 1) {\n        init(n);\n    }\n    constexpr void init(int n) noexcept\
    \ {\n        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);\n    \
    \    int MOD = fact_[0].getmod();\n        for (int i = 2; i < n; i++) {\n   \
    \         fact_[i] = fact_[i - 1] * i;\n            inv_[i] = -inv_[MOD % i] *\
    \ (MOD / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n        }\n    }\n\
    \    constexpr T com(int n, int k) const noexcept {\n        if (n < k || n <\
    \ 0 || k < 0) return 0;\n        return fact_[n] * finv_[k] * finv_[n - k];\n\
    \    }\n    constexpr T hom(int n, int k) const noexcept {\n        n += k - 1;\n\
    \        return fact_[n] * finv_[k] * finv_[n - k];\n    }\n    constexpr T fact(int\
    \ n) const noexcept {\n        if (n < 0) return 0;\n        return fact_[n];\n\
    \    }\n    constexpr T inv(int n) const noexcept {\n        if (n < 0) return\
    \ 0;\n        return inv_[n];\n    }\n    constexpr T finv(int n) const noexcept\
    \ {\n        if (n < 0) return 0;\n        return finv_[n];\n    }\n};\n"
  code: "template <class T>\nstruct BiCoef {\n    vector<T> fact_, inv_, finv_;\n\
    \    constexpr BiCoef() {}\n    constexpr BiCoef(int n) noexcept : fact_(n, 1),\
    \ inv_(n, 1), finv_(n, 1) {\n        init(n);\n    }\n    constexpr void init(int\
    \ n) noexcept {\n        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n,\
    \ 1);\n        int MOD = fact_[0].getmod();\n        for (int i = 2; i < n; i++)\
    \ {\n            fact_[i] = fact_[i - 1] * i;\n            inv_[i] = -inv_[MOD\
    \ % i] * (MOD / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n        }\n\
    \    }\n    constexpr T com(int n, int k) const noexcept {\n        if (n < k\
    \ || n < 0 || k < 0) return 0;\n        return fact_[n] * finv_[k] * finv_[n -\
    \ k];\n    }\n    constexpr T hom(int n, int k) const noexcept {\n        n +=\
    \ k - 1;\n        return fact_[n] * finv_[k] * finv_[n - k];\n    }\n    constexpr\
    \ T fact(int n) const noexcept {\n        if (n < 0) return 0;\n        return\
    \ fact_[n];\n    }\n    constexpr T inv(int n) const noexcept {\n        if (n\
    \ < 0) return 0;\n        return inv_[n];\n    }\n    constexpr T finv(int n)\
    \ const noexcept {\n        if (n < 0) return 0;\n        return finv_[n];\n \
    \   }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/binomial-coefficient.hpp
  requiredBy: []
  timestamp: '2022-12-21 22:45:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combinatorics/binomial-coefficient.hpp
layout: document
redirect_from:
- /library/math/combinatorics/binomial-coefficient.hpp
- /library/math/combinatorics/binomial-coefficient.hpp.html
title: math/combinatorics/binomial-coefficient.hpp
---
