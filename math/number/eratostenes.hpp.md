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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\nstruct Eratos {\n\
    \    vector<int> primes;\n    vector<bool> isprime;\n    vector<int> mebius;\n\
    \    vector<int> min_factor;\n\n    explicit Eratos(int MAX)\n        : primes(),\n\
    \          isprime(MAX + 1, true),\n          mebius(MAX + 1, 1),\n          min_factor(MAX\
    \ + 1, -1) {\n        isprime[0] = isprime[1] = false;\n        min_factor[0]\
    \ = 0, min_factor[1] = 1;\n        for (int i = 2; i <= MAX; ++i) {\n        \
    \    if (!isprime[i]) continue;\n            primes.push_back(i);\n          \
    \  mebius[i] = -1;\n            min_factor[i] = i;\n            for (int j = i\
    \ * 2; j <= MAX; j += i) {\n                isprime[j] = false;\n            \
    \    if ((j / i) % i == 0)\n                    mebius[j] = 0;\n             \
    \   else\n                    mebius[j] = -mebius[j];\n                if (min_factor[j]\
    \ == -1) min_factor[j] = i;\n            }\n        }\n    }\n\n    vector<pair<int,\
    \ int>> prime_factors(int n) {\n        vector<pair<int, int>> res;\n        while\
    \ (n != 1) {\n            int prime = min_factor[n];\n            int exp = 0;\n\
    \            while (min_factor[n] == prime) {\n                ++exp;\n      \
    \          n /= prime;\n            }\n            res.push_back(make_pair(prime,\
    \ exp));\n        }\n        return res;\n    }\n\n    vector<int> divisors(int\
    \ n) {\n        vector<int> res({1});\n        auto pf = prime_factors(n);\n \
    \       for (auto p : pf) {\n            int siz = (int)res.size();\n        \
    \    for (int i = 0; i < siz; ++i) {\n                int v = 1;\n           \
    \     for (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n\n    int divisors_num(int n) {\n\
    \        auto pf = prime_factors(n);\n        int res = accumulate(all(pf), 1,\
    \ [](int a, pair<int, int> b) {\n            return a * (b.second + 1);\n    \
    \    });\n        return res;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: math/number/eratostenes.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/eratostenes.hpp
layout: document
title: "\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9"
---
