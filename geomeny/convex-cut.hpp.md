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
    path: test/AOJ/CGL_4_C.test.cpp
    title: test/AOJ/CGL_4_C.test.cpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../geomeny/geomeny-template.hpp\"\n#include \"../template/template.hpp\"\
    \n\nint ccw_for_convexcut(const Point &a, const Point &b, const Point &c) {\n\
    \    if (cross(b - a, c - a) > EPS) return 1;\n    if (cross(b - a, c - a) < -EPS)\
    \ return -1;\n    if (dot(b - a, c - a) < -EPS) return 2;\n    if (norm(b - a)\
    \ < norm(c - a) - EPS) return -2;\n    return 0;\n}\nvector<Point> crosspoint_for_convexcut(const\
    \ Line &l, const Line &m) {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0],\
    \ l[1] - l[0]);\n    if (abs(d) < EPS) return vector<Point>();\n    res.push_back(l[0]\
    \ + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);\n    return res;\n}\n\
    vector<Point> ConvexCut(const vector<Point> &pol, const Line &l) {\n    vector<Point>\
    \ res;\n    for (int i = 0; i < (int)pol.size(); ++i) {\n        Point p = pol[i],\
    \ q = pol[(i + 1) % pol.size()];\n        if (ccw_for_convexcut(l[0], l[1], p)\
    \ != -1) {\n            if (res.size() == 0)\n                res.push_back(p);\n\
    \            else if (!eq(p, res[res.size() - 1]))\n                res.push_back(p);\n\
    \        }\n        if (ccw_for_convexcut(l[0], l[1], p) * ccw_for_convexcut(l[0],\
    \ l[1], q) < 0) {\n            vector<Point> temp = crosspoint_for_convexcut(Line(p,\
    \ q), l);\n            if (temp.size() == 0)\n                continue;\n    \
    \        else if (res.size() == 0)\n                res.push_back(temp[0]);\n\
    \            else if (!eq(temp[0], res[res.size() - 1]))\n                res.push_back(temp[0]);\n\
    \        }\n    }\n    return res;\n}"
  dependsOn:
  - geomeny/geomeny-template.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: geomeny/convex-cut.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/CGL_4_C.test.cpp
documentation_of: geomeny/convex-cut.hpp
layout: document
title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
---
