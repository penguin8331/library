---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: others/compress2d.hpp
    title: "\u4E8C\u6B21\u5143\u5EA7\u6A19\u5727\u7E2E"
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../others/compress2d.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<long long> X1(N), Y1(N),\
    \ X2(N), Y2(N);\n    for (int i = 0; i < N; i++) {\n        cin >> X1.at(i) >>\
    \ Y1.at(i) >> X2.at(i) >> Y2.at(i);\n    }\n    vector<long long> X = compress(X1,\
    \ X2);\n    vector<long long> Y = compress(Y1, Y2);\n    int w = (int)X.size();\n\
    \    int h = (int)Y.size();\n    vector<vector<int>> G(w, vector<int>(h));\n \
    \   for (int i = 0; i < N; i++) {\n        G[X1[i]][Y1[i]]++;\n        G[X2[i]][Y2[i]]++;\n\
    \        G[X1[i]][Y2[i]]--;\n        G[X2[i]][Y1[i]]--;\n    }\n    for (int x\
    \ = 1; x < w; x++) {\n        for (int y = 0; y < h; y++) {\n            G[x][y]\
    \ += G[x - 1][y];\n        }\n    }\n    for (int x = 0; x < w; x++) {\n     \
    \   for (int y = 1; y < h; y++) {\n            G[x][y] += G[x][y - 1];\n     \
    \   }\n    }\n    long long ans = 0;\n    for (int x = 0; x < w - 1; x++) {\n\
    \        for (int y = 0; y < h - 1; y++) {\n            if (G[x][y]) {\n     \
    \           ans += (X[x + 1] - X[x]) * (Y[y + 1] - Y[y]);\n            }\n   \
    \     }\n    }\n    cout << ans << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - others/compress2d.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_4_A.test.cpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_4_A.test.cpp
- /verify/test/AOJ/DSL_4_A.test.cpp.html
title: test/AOJ/DSL_4_A.test.cpp
---
