---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number/isprime.hpp
    title: "\u7D20\u6570\u5224\u5B9A\u6CD5"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \r\n#include \"template/template.hpp\"\r\n#include \"math/number/isprime.hpp\"\
    \r\n\r\nint main() {\r\n    int N;\r\n    cin >> N;\r\n    int ans = 0;\r\n  \
    \  for (int i = 0; i < N; i++) {\r\n        int a;\r\n        cin >> a;\r\n  \
    \      ans += is_prime(a);\r\n    }\r\n    cout << ans << endl;\r\n}"
  dependsOn:
  - template/template.hpp
  - math/number/isprime.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-21 18:31:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_1_C.test.cpp
- /verify/test/AOJ/ALDS1_1_C.test.cpp.html
title: test/AOJ/ALDS1_1_C.test.cpp
---
