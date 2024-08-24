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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class Abel>\n\
    struct BIT2D {\n    const Abel UNITY_SUM = 0;\n    vector<vector<Abel> > dat[2][2];\n\
    \    int N, M;\n\n    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),\
    \ N(n), M(m) {\n        init(n, m);\n    }\n    void init(int n, int m) {\n  \
    \      for (int i = 0; i < 2; ++i)\n            for (int j = 0; j < 2; ++j)\n\
    \                dat[i][j].assign(n + 1, vector<Abel>(m + 1, UNITY_SUM));\n  \
    \  }\n    \n    inline void subsub_add(int f, int s, int x, int y, Abel v) {\n\
    \        for (int i = x; i < (int)dat[f][s].size(); i |= i + 1)\n            for\
    \ (int j = y; j < (int)dat[f][s][0].size(); j |= j + 1)\n                dat[f][s][i][j]\
    \ = dat[f][s][i][j] + v;\n    }\n    inline void sub_add(int x, int y, Abel v)\
    \ {\n        subsub_add(0, 0, x, y, v * x * y);\n        subsub_add(1, 0, x, y,\
    \ -v * x);\n        subsub_add(0, 1, x, y, -v * y);\n        subsub_add(1, 1,\
    \ x, y, v);\n    }\n    inline void add(int x1, int x2, int y1, int y2, Abel v)\
    \ {\n        sub_add(x1, y1, v);\n        sub_add(x1, y2, -v);\n        sub_add(x2,\
    \ y1, -v);\n        sub_add(x2, y2, v);\n    }\n\n    inline Abel subsub_sum(int\
    \ f, int s, int x, int y) {\n        Abel res = 0;\n        for (int i = x; i\
    \ > 0; i = (i & (i + 1)) - 1)\n            for (int j = y; j > 0; j = (j & (j\
    \ + 1)) - 1)\n                res = res + dat[f][s][i][j];\n        return res;\n\
    \    }\n    inline Abel sub_sum(int x, int y) {\n        Abel res = 0;\n     \
    \   res += subsub_sum(0, 0, x, y);\n        res += subsub_sum(1, 0, x, y) * y;\n\
    \        res += subsub_sum(0, 1, x, y) * x;\n        res += subsub_sum(1, 1, x,\
    \ y) * x * y;\n        return res;\n    }\n    inline Abel sum(int x1, int x2,\
    \ int y1, int y2) {\n        return sub_sum(x2, y2) - sub_sum(x1, y2) - sub_sum(x2,\
    \ y1) + sub_sum(x1, y1);\n    }\n\n    friend ostream& operator<<(ostream& os,\
    \ BIT2D bit) {\n        for (int i = 0; i < bit.N; i++) {\n            os << \"\
    [ \";\n            for (int j = 0; j < bit.M; j++) {\n                os << bit.sum(i,\
    \ i + 1, j, j + 1) << \" \";\n            }\n            os << ']';\n        }\n\
    \        return os;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/binary-indexed-tree-2d-raq.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/binary-indexed-tree-2d-raq.hpp
layout: document
title: "BIT-2D (\u9818\u57DF\u52A0\u7B97, \u9818\u57DF\u548C\u53D6\u5F97\u306B\u4E21\
  \u5BFE\u5FDC)"
---
