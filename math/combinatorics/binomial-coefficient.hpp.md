---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
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
  - icon: ':x:'
    path: test/yosupo/binomial-cofficient-prime-mod.test.cpp
    title: test/yosupo/binomial-cofficient-prime-mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\ntemplate <class\
    \ T>\nstruct BiCoef {\n    vector<T> fact_, inv_, finv_;\n    constexpr BiCoef()\
    \ {}\n    explicit constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1),\
    \ finv_(n, 1) {\n        init(n);\n    }\n    constexpr void init(int n) noexcept\
    \ {\n        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);\n    \
    \    int modular = fact_[0].getmod();\n        for (int i = 2; i < n; i++) {\n\
    \            fact_[i] = fact_[i - 1] * i;\n            inv_[i] = -inv_[modular\
    \ % i] * (modular / i);\n            finv_[i] = finv_[i - 1] * inv_[i];\n    \
    \    }\n    }\n    constexpr T com(int n, int k) const noexcept {\n        assert(n\
    \ < (int)fact_.size() && n >= k && k >= 0);\n        return fact_[n] * finv_[k]\
    \ * finv_[n - k];\n    }\n    constexpr T hom(int n, int k) const noexcept {\n\
    \        n += k - 1;\n        assert(n < (int)fact_.size() && n >= k && k >= 0);\n\
    \        return fact_[n] * finv_[k] * finv_[n - k];\n    }\n    constexpr T fact(int\
    \ n) const noexcept {\n        assert(n >= 0);\n        return fact_[n];\n   \
    \ }\n    constexpr T inv(int n) const noexcept {\n        assert(n >= 0);\n  \
    \      return inv_[n];\n    }\n    constexpr T finv(int n) const noexcept {\n\
    \        assert(n >= 0);\n        return finv_[n];\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: math/combinatorics/binomial-coefficient.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/binomial-cofficient-prime-mod.test.cpp
documentation_of: math/combinatorics/binomial-coefficient.hpp
layout: document
title: "\u4E8C\u9805\u4FC2\u6570\u30C6\u30FC\u30D6\u30EB"
---
