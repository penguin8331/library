---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number/miller-rabin.hpp
    title: "\u78BA\u7387\u7684\u7D20\u6570\u5224\u5B9A (Miller-Rabin \u6CD5)"
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
  code: "#pragma once\n#include \"../../template/template.hpp\"\n#include \"miller-rabin.hpp\"\
    \n\nlong long pollard(long long N) {\n    if (N % 2 == 0) return 2;\n    if (is_prime(N))\
    \ return N;\n\n    auto f = [&](long long x) -> long long {\n        return (__int128_t(x)\
    \ * x + 1) % N;\n    };\n    long long step = 0;\n    while (true) {\n       \
    \ ++step;\n        long long x = step, y = f(x);\n        while (true) {\n   \
    \         long long p = gcd(y - x + N, N);\n            if (p == 0 || p == N)\
    \ break;\n            if (p != 1) return p;\n            x = f(x);\n         \
    \   y = f(f(y));\n        }\n    }\n}\n\nvector<long long> solve_for_prime_factorize(long\
    \ long N) {\n    if (N == 1) return {};\n    long long p = pollard(N);\n    if\
    \ (p == N) return {p};\n    vector<long long> left = solve_for_prime_factorize(p);\n\
    \    vector<long long> right = solve_for_prime_factorize(N / p);\n    left.insert(left.end(),\
    \ right.begin(), right.end());\n    sort(left.begin(), left.end());\n    return\
    \ left;\n}\n\nmap<long long, int> prime_factorize(long long N) {\n    auto res\
    \ = solve_for_prime_factorize(N);\n    map<long long, int> ret;\n    for (int\
    \ i = 0; i < res.size(); i++) {\n        ret[res[i]]++;\n    }\n    return ret;\n\
    }"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - math/number/miller-rabin.hpp
  isVerificationFile: false
  path: math/number/pollard-rho.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number/pollard-rho.hpp
layout: document
title: "\u78BA\u7387\u7684\u7D20\u56E0\u6570\u5206\u89E3 (Pollard \u306E\u30ED\u30FC\
  \u6CD5)"
---
