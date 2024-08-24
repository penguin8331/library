---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: others/range-set.hpp
    title: "\u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u30C6\u30AF"
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc214/tasks/abc214_e
    links:
    - https://atcoder.jp/contests/abc214/tasks/abc214_e
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc214/tasks/abc214_e\"\n#include\
    \ \"../../others/range-set.hpp\"\n#include \"../../template/template.hpp\"\n\n\
    void solve() {\n    INT(N);\n    vector<pll> A(N);\n    scan(A);\n    sort(all(A),\
    \ [&](pll a, pll b) { return a.second < b.second; });\n    // \u3059\u3067\u306B\
    \u4F7F\u308F\u308C\u305F\u30DC\u30FC\u30EB\n    RangeSet<ll> used;\n    for (int\
    \ i = 0; i < N; i++) {\n        ll nxt = used.mex(A[i].first);\n        if (nxt\
    \ > A[i].second) {\n            cout << \"No\" << endl;\n            return;\n\
    \        }\n        used.insert(nxt, nxt);\n    }\n    cout << \"Yes\" << endl;\n\
    }\nint main() {\n    INT(T);\n    while (T--) solve();\n}"
  dependsOn:
  - others/range-set.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/atcoder/abc214_e.test.cpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc214_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc214_e.test.cpp
- /verify/test/atcoder/abc214_e.test.cpp.html
title: test/atcoder/abc214_e.test.cpp
---
