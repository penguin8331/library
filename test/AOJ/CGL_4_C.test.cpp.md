---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/area-polygon.hpp
    title: "\u591A\u89D2\u5F62\u306E\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geomeny/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
    ERROR: '0.00001'
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/template.hpp: line 18: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\"\
    \n#define ERROR 0.00001\n#include \"template/template.hpp\"\n#include \"geomeny/area-polygon.hpp\"\
    \n#include \"geomeny/convex-cut.hpp\"\n\nint main() {\n    int N;\n    cin >>\
    \ N;\n    vector<Point> G(N);\n    for (int i = 0; i < N; i++) {\n        cin\
    \ >> G[i].x >> G[i].y;\n    }\n    int Q;\n    cin >> Q;\n    for (int i = 0;\
    \ i < Q; i++) {\n        Line a(2);\n        cin >> a[0].x >> a[0].y >> a[1].x\
    \ >> a[1].y;\n        cout << CalcArea(ConvexCut(G, a)) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - geomeny/area-polygon.hpp
  - geomeny/geomeny-template.hpp
  - geomeny/convex-cut.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_4_C.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 16:23:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_4_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_4_C.test.cpp
- /verify/test/AOJ/CGL_4_C.test.cpp.html
title: test/AOJ/CGL_4_C.test.cpp
---
