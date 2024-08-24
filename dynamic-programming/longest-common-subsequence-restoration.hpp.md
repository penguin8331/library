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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nstring LCSRestoration(const\
    \ string& a, const string& b) {\n    const int n = a.size(), m = b.size();\n \
    \   vector<vector<int> > X(n + 1, vector<int>(m + 1));\n    vector<vector<int>\
    \ > Y(n + 1, vector<int>(m + 1));\n    for (int i = 0; i < n; ++i) {\n       \
    \ for (int j = 0; j < m; ++j) {\n            if (a[i] == b[j]) {\n           \
    \     X[i + 1][j + 1] = X[i][j] + 1;\n                Y[i + 1][j + 1] = 0;\n \
    \           } else if (X[i + 1][j] < X[i][j + 1]) {\n                X[i + 1][j\
    \ + 1] = X[i][j + 1];\n                Y[i + 1][j + 1] = 1;\n            } else\
    \ {\n                X[i + 1][j + 1] = X[i + 1][j];\n                Y[i + 1][j\
    \ + 1] = -1;\n            }\n        }\n    }\n    string c;\n    for (int i =\
    \ n, j = m; i > 0 && j > 0;) {\n        if (Y[i][j] > 0)\n            --i;\n \
    \       else if (Y[i][j] < 0)\n            --j;\n        else {\n            c.push_back(a[i\
    \ - 1]);\n            --i;\n            --j;\n        }\n    }\n    reverse(c.begin(),\
    \ c.end());\n    return c;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: dynamic-programming/longest-common-subsequence-restoration.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dynamic-programming/longest-common-subsequence-restoration.hpp
layout: document
title: "LCS (\u5FA9\u5143\u3042\u308A)"
---
