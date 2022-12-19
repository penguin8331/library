---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"test/example_test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n\
    \    REP (i, n) {\n        cin >> s[i];\n    }\n    int q; cin >> q;\n    int\
    \ cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        cnt += binary_search(ALL(s),\
    \ t_i);\n    }\n    cout << cnt << endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++ (i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n; cin >> n;\n    vector<int> s(n);\n\
    \    REP (i, n) {\n        cin >> s[i];\n    }\n    int q; cin >> q;\n    int\
    \ cnt = 0;\n    while (q --) {\n        int t_i; cin >> t_i;\n        cnt += binary_search(ALL(s),\
    \ t_i);\n    }\n    cout << cnt << endl;\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: test/example_test.cpp
  requiredBy: []
  timestamp: '2022-12-19 20:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/example_test.cpp
layout: document
redirect_from:
- /library/test/example_test.cpp
- /library/test/example_test.cpp.html
title: test/example_test.cpp
---
