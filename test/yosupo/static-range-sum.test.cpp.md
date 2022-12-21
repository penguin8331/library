---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/section-sum.hpp
    title: "\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 19: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"template/template.hpp\"\n#include \"algorithm/section-sum.hpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    sectionsum<ll> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n        A.update(i,\
    \ a);\n    }\n    A.build();\n    for (int i = 0; i < Q; i++) {\n        int l,\
    \ r;\n        cin >> l >> r;\n        cout << A.get(l, r) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - algorithm/section-sum.hpp
  isVerificationFile: true
  path: test/yosupo/static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:31:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-range-sum.test.cpp
- /verify/test/yosupo/static-range-sum.test.cpp.html
title: test/yosupo/static-range-sum.test.cpp
---
