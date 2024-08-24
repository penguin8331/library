---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    path: test/AOJ/CGL_4_A.test.cpp
    title: test/AOJ/CGL_4_A.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../geomeny/geomeny-template.hpp\"\
    \n\nvector<Point> ConvexHull(vector<Point> &ps) {\n    int n = (int)ps.size();\n\
    \    vector<Point> res(2 * n);\n    sort(ps.begin(), ps.end());\n    int k = 0;\n\
    \    for (int i = 0; i < n; ++i) {\n        if (k >= 2) {\n            while (cross(res[k\
    \ - 1] - res[k - 2], ps[i] - res[k - 2]) < EPS) {\n                --k;\n    \
    \            if (k < 2) break;\n            }\n        }\n        res[k] = ps[i];\n\
    \        ++k;\n    }\n    int t = k + 1;\n    for (int i = n - 2; i >= 0; --i)\
    \ {\n        if (k >= t) {\n            while (cross(res[k - 1] - res[k - 2],\
    \ ps[i] - res[k - 2]) < EPS) {\n                --k;\n                if (k <\
    \ t) break;\n            }\n        }\n        res[k] = ps[i];\n        ++k;\n\
    \    }\n    res.resize(k - 1);\n    return res;\n}\n\nvector<Point> ConvexHullCollinearOK(vector<Point>\
    \ &ps) {\n    int n = (int)ps.size();\n    vector<Point> res(2 * n);\n    sort(ps.begin(),\
    \ ps.end());\n    int k = 0;\n    for (int i = 0; i < n; ++i) {\n        if (k\
    \ >= 2) {\n            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2])\
    \ < -EPS) {\n                --k;\n                if (k < 2) break;\n       \
    \     }\n        }\n        res[k] = ps[i];\n        ++k;\n    }\n    int t =\
    \ k + 1;\n    for (int i = n - 2; i >= 0; --i) {\n        if (k >= t) {\n    \
    \        while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < -EPS) {\n\
    \                --k;\n                if (k < t) break;\n            }\n    \
    \    }\n        res[k] = ps[i];\n        ++k;\n    }\n    res.resize(k - 1);\n\
    \    return res;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/convex-hull.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/CGL_4_A.test.cpp
documentation_of: geomeny/convex-hull.hpp
layout: document
title: "\u51F8\u5305"
---
