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
    path: test/AOJ/2842.test.cpp
    title: test/AOJ/2842.test.cpp
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
    struct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel>> dat;\n\
    \n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\n              \
    \                            dat(n, vector<Abel>(m, UNITY_SUM)) {}\n    void init(int\
    \ n, int m) {\n        dat.assign(n, vector<Abel>(m, UNITY_SUM));\n    }\n\n \
    \   inline void add(int a, int b, Abel x) {\n        for (int i = a; i < (int)dat.size();\
    \ i |= i + 1)\n            for (int j = b; j < (int)dat[0].size(); j |= j + 1)\n\
    \                dat[i][j] = dat[i][j] + x;\n    }\n\n    inline Abel sum(int\
    \ p, int q) {\n        Abel res = UNITY_SUM;\n        for (int i = p - 1; i >=\
    \ 0; i = (i & (i + 1)) - 1)\n            for (int j = q - 1; j >= 0; j = (j &\
    \ (j + 1)) - 1)\n                res = res + dat[i][j];\n        return res;\n\
    \    }\n\n    inline Abel sum(int x1, int x2, int y1, int y2) {\n        return\
    \ sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);\n    }\n\n    friend\
    \ ostream& operator<<(ostream& os, BIT2D bit) {\n        for (int i = 0; i < (int)bit.dat.size();\
    \ i++) {\n            os << \"[ \";\n            for (int j = 0; j < (int)bit.dat[0].size();\
    \ j++) {\n                os << bit.sum(i, i + 1, j, j + 1) << \" \";\n      \
    \      }\n            os << ']';\n        }\n        return os;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-2d.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2842.test.cpp
documentation_of: data-structure/binary-indexed-tree-2d.hpp
layout: document
title: BIT-2D
---
