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
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class Abel>\n\
    struct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat[2];\n    int N;\n\n\
    \    explicit BIT(int n, Abel unity = 0) : UNITY_SUM(unity), N(n) {\n        init(n);\n\
    \    }\n    void init(int n) {\n        for (int iter = 0; iter < 2; ++iter)\n\
    \            dat[iter].assign(n + 1, UNITY_SUM);\n    }\n\n    inline void sub_add(int\
    \ p, int a, Abel x) {\n        for (int i = a; i < (int)dat[p].size(); i |= i\
    \ + 1)\n            dat[p][i] = dat[p][i] + x;\n    }\n    inline void add(int\
    \ a, int b, Abel x) {\n        sub_add(0, a, x * (-a));\n        sub_add(1, a,\
    \ x);\n        sub_add(0, b, x * b);\n        sub_add(1, b, x * (-1));\n    }\n\
    \n    inline Abel sub_sum(int p, int a) {\n        Abel res = UNITY_SUM;\n   \
    \     for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n            res = res\
    \ + dat[p][i];\n        return res;\n    }\n    inline Abel sum(int a, int b)\
    \ {\n        return sub_sum(0, b) + sub_sum(1, b) * b - sub_sum(0, a) - sub_sum(1,\
    \ a) * a;\n    }\n    \n    friend ostream& operator<<(ostream& os, BIT bit) {\n\
    \        os << \"[ \";\n        for (int i = 0; i < bit.N; i++) {\n          \
    \  os << bit.sum(i, i + 1) << \" \";\n        }\n        os << ']';\n        return\
    \ os;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-raq.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_G.test.cpp
documentation_of: data-structure/binary-indexed-tree-raq.hpp
layout: document
title: "BIT (\u533A\u9593\u52A0\u7B97, \u533A\u9593\u548C\u53D6\u5F97\u306B\u4E21\u5BFE\
  \u5FDC)"
---
