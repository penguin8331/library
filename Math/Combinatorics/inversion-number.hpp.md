---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: DataStructure/Binary\
    \ Indexed Tree.hpp: line -1: no such header\n"
  code: "#include \"DataStructure/Binary Indexed Tree.hpp\"\n\ntemplate <class T>\n\
    long long inversion_number(const vector<T> &a) {\n    int n = (int)a.size();\n\
    \    vector<T> b = a;\n    sort(b.begin(), b.end());\n    b.erase(unique(b.begin(),\
    \ b.end()), b.end());\n\n    long long res = 0;\n    BIT<int> bit(n + 1);\n  \
    \  for (int i = 0; i < n; ++i) {\n        int order = lower_bound(b.begin(), b.end(),\
    \ a[i]) - b.begin();\n        ++order;\n        res += bit.sum(order + 1, n +\
    \ 1);\n        bit.add(order, 1);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: Math/Combinatorics/inversion-number.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/Combinatorics/inversion-number.hpp
layout: document
redirect_from:
- /library/Math/Combinatorics/inversion-number.hpp
- /library/Math/Combinatorics/inversion-number.hpp.html
title: Math/Combinatorics/inversion-number.hpp
---
