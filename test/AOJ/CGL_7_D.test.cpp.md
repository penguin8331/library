---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/crosspoint.hpp
    title: "\u4EA4\u70B9"
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
    ERROR: '0.000001'
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D\"\
    \n#define ERROR 0.000001\n#include \"template/template.hpp\"\n#include \"geomeny/crosspoint.hpp\"\
    \n\nint main() {\n    Circle a;\n    cin >> a.x >> a.y >> a.r;\n    int N;\n \
    \   cin >> N;\n    for (int i = 0; i < N; i++) {\n        Line b(2);\n       \
    \ cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y;\n        auto res = crosspoint(a,\
    \ b);\n        sort(all(res), [](Point a, Point b) {\n            if (a.x != b.x)\
    \ {\n                return a.x < b.x;\n            }\n            return a.y\
    \ < b.y;\n        });\n        if (res.size() == 1) {\n            cout << res[0].x\
    \ << \" \" << res[0].y << \" \" << res[0].x << \" \" << res[0].y << endl;\n  \
    \      } else {\n            cout << res[0].x << \" \" << res[0].y << \" \" <<\
    \ res[1].x << \" \" << res[1].y << endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - geomeny/crosspoint.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_7_D.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 16:02:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_7_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_7_D.test.cpp
- /verify/test/AOJ/CGL_7_D.test.cpp.html
title: test/AOJ/CGL_7_D.test.cpp
---
