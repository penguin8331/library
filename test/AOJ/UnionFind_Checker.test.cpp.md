---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/AOJ/UnionFind_Checker.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N, Q;\n    cin\
    \ >> N >> Q;\n    UnionFind uf(N);\n    for (int i = 0; i < Q; i++) {\n      \
    \  int com, x, y;\n        cin >> com >> x >> y;\n        if (com == 0) {\n  \
    \          uf.unite(x, y);\n        } else {\n            cout << uf.issame(x,\
    \ y) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    int N, Q;\n\
    \    cin >> N >> Q;\n    UnionFind uf(N);\n    for (int i = 0; i < Q; i++) {\n\
    \        int com, x, y;\n        cin >> com >> x >> y;\n        if (com == 0)\
    \ {\n            uf.unite(x, y);\n        } else {\n            cout << uf.issame(x,\
    \ y) << endl;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/UnionFind_Checker.test.cpp
  requiredBy: []
  timestamp: '2022-12-19 21:17:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/UnionFind_Checker.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/UnionFind_Checker.test.cpp
- /verify/test/AOJ/UnionFind_Checker.test.cpp.html
title: test/AOJ/UnionFind_Checker.test.cpp
---
