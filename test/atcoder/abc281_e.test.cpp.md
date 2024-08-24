---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/binary-trie.hpp
    title: data-structure/binary-trie.hpp
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc281/tasks/abc281_e
    links:
    - https://atcoder.jp/contests/abc281/tasks/abc281_e
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc281/tasks/abc281_e\"\n#include\
    \ \"../../data-structure/binary-trie.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    INT(N, M, K);\n    vector<int> A(N);\n    scan(A);\n   \
    \ BinaryTrie<int, 30> a, b;\n    ll ans = 0;\n    auto push = [&](int val) {\n\
    \        a.insert(val);\n        ans += val;\n        if (a.size() > K) {\n  \
    \          int nval = a.get(a.get_max());\n            ans -= nval;\n        \
    \    a.erase(nval);\n            b.insert(nval);\n        }\n    };\n    auto\
    \ pop = [&](int val) {\n        if (b.find(val)) {\n            b.erase(val);\n\
    \        } else {\n            a.erase(val);\n            ans -= val;\n      \
    \      if (b.size()) {\n                int nval = b.get(b.get_min());\n     \
    \           b.erase(nval);\n                a.insert(nval);\n                ans\
    \ += nval;\n            }\n        }\n    };\n    vector<ll> finans;\n    for\
    \ (int i = 0; i < N; i++) {\n        push(A[i]);\n        if (i >= M) {\n    \
    \        pop(A[i - M]);\n        }\n        if (i >= M - 1) {\n            finans.push_back(ans);\n\
    \        }\n    }\n    print(finans);\n}"
  dependsOn:
  - data-structure/binary-trie.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/atcoder/abc281_e.test.cpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc281_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc281_e.test.cpp
- /verify/test/atcoder/abc281_e.test.cpp.html
title: test/atcoder/abc281_e.test.cpp
---
