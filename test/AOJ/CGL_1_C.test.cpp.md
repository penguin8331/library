---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/ccw.hpp
    title: "\u70B9\u3068\u7DDA\u5206\u306E\u4F4D\u7F6E\u95A2\u4FC2"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n#include \"template/template.hpp\"\n#include \"geomeny/ccw.hpp\"\n\nint main()\
    \ {\n    Point a, b;\n    cin >> a.x >> a.y >> b.x >> b.y;\n    int Q;\n    cin\
    \ >> Q;\n    for (int i = 0; i < Q; i++) {\n        Point c;\n        cin >> c.x\
    \ >> c.y;\n        int res = ccw(a, b, c);\n        if (res == -1) {\n       \
    \     cout << \"CLOCKWISE\" << endl;\n        }\n        elif (res == 1) {\n \
    \           cout << \"COUNTER_CLOCKWISE\" << endl;\n        }\n        elif (res\
    \ == 2) {\n            cout << \"ONLINE_BACK\" << endl;\n        }\n        elif\
    \ (res == -2) {\n            cout << \"ONLINE_FRONT\" << endl;\n        }\n  \
    \      else {\n            cout << \"ON_SEGMENT\" << endl;\n        }\n    }\n\
    }"
  dependsOn:
  - template/template.hpp
  - geomeny/ccw.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 16:23:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_1_C.test.cpp
- /verify/test/AOJ/CGL_1_C.test.cpp.html
title: test/AOJ/CGL_1_C.test.cpp
---
