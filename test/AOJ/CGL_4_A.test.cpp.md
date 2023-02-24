---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/convex-hull.hpp
    title: "\u51F8\u5305"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
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
    \ template/template.hpp: line 19: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n#include \"template/template.hpp\"\n#include \"geomeny/convex-hull.hpp\"\n\n\
    int main() {\n    int N;\n    cin >> N;\n    vector<Point> A(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i].x >> A[i].y;\n    }\n    auto pol\
    \ = ConvexHullCollinearOK(A);\n    pair<ld, ld> minv = {11000, 11000};\n    int\
    \ minp = -1;\n    for (int i = 0; i < (int)pol.size(); ++i) {\n        if (minv\
    \ > make_pair(pol[i].y, pol[i].x)) {\n            minv = make_pair(pol[i].y, pol[i].x);\n\
    \            minp = i;\n        }\n    }\n    cout << pol.size() << endl;\n  \
    \  for (int i = 0; i < (int)pol.size(); ++i) {\n        int j = (i + minp) % pol.size();\n\
    \        cout << fixed << setprecision(0) << pol[j].x << \" \" << pol[j].y <<\
    \ endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - geomeny/convex-hull.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_4_A.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 16:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_4_A.test.cpp
- /verify/test/AOJ/CGL_4_A.test.cpp.html
title: test/AOJ/CGL_4_A.test.cpp
---
