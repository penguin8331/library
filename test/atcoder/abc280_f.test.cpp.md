---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/weighted-union-find.hpp
    title: WeightedUnionFind
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
    PROBLEM: https://atcoder.jp/contests/abc280/tasks/abc280_f
    links:
    - https://atcoder.jp/contests/abc280/tasks/abc280_f
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_f\"\n#include\
    \ \"../../data-structure/weighted-union-find.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    INT(N, M, Q);\n    WeightedUnionFind<ll> uf(N);\n    vector<bool>\
    \ isinf(N, false);\n    for (int i = 0; i < M; i++) {\n        INT(a, b);\n  \
    \      a--, b--;\n        LL(c);\n        if (uf.issame(a, b) && uf.get_diff(a,\
    \ b) != c) {\n            isinf[a] = true;\n        } else {\n            uf.unite(a,\
    \ b, c);\n        }\n    }\n    for (auto v : uf.groups()) {\n        bool flag\
    \ = false;\n        for (auto x : v) {\n            if (isinf[x]) {\n        \
    \        flag = true;\n                break;\n            }\n        }\n    \
    \    if (flag) {\n            for (auto x : v) isinf[x] = true;\n        }\n \
    \   }\n    for (int i = 0; i < Q; i++) {\n        INT(a, b);\n        a--, b--;\n\
    \        if (!uf.issame(a, b)) {\n            print(\"nan\");\n        }\n   \
    \     elif (isinf[a]) { print(\"inf\"); }\n        else {\n            print(uf.get_diff(a,\
    \ b));\n        }\n    }\n}"
  dependsOn:
  - data-structure/weighted-union-find.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/atcoder/abc280_f.test.cpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc280_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc280_f.test.cpp
- /verify/test/atcoder/abc280_f.test.cpp.html
title: test/atcoder/abc280_f.test.cpp
---
