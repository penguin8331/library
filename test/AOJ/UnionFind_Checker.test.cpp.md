---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/UnionFind.hpp
    title: DataStructure/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/AOJ/UnionFind_Checker.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#line 1 \"DataStructure/UnionFind.hpp\"\
    \nstruct UnionFind {\n    vector<int> par;\n\n    UnionFind() {}\n    UnionFind(int\
    \ n) : par(n, -1) {}\n    void init(int n) { par.assign(n, -1); }\n\n    int root(int\
    \ x) {\n        if (par[x] < 0)\n            return x;\n        else\n       \
    \     return par[x] = root(par[x]);\n    }\n\n    bool issame(int x, int y) {\n\
    \        return root(x) == root(y);\n    }\n\n    bool unite(int x, int y) {\n\
    \        x = root(x);\n        y = root(y);\n        if (x == y) return false;\n\
    \        if (par[x] > par[y]) swap(x, y);\n        par[x] += par[y];\n       \
    \ par[y] = x;\n        return true;\n    }\n\n    int size(int x) {\n        return\
    \ -par[root(x)];\n    }\n\n    vector<vector<int>> groups() {\n        map<int,\
    \ vector<int>> root_buf;\n        for (int i = 0; i < (int)par.size(); ++i) {\n\
    \            int r = root(i);\n            root_buf[r].push_back(i);\n       \
    \ }\n        vector<vector<int>> res;\n        for (const auto& i : root_buf)\
    \ {\n            res.push_back(i.second);\n        }\n        return res;\n  \
    \  }\n};\n#line 5 \"test/AOJ/UnionFind_Checker.test.cpp\"\n\nint main() {\n  \
    \  int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n    for (int i = 0; i\
    \ < Q; i++) {\n        int com, x, y;\n        cin >> com >> x >> y;\n       \
    \ if (com == 0) {\n            uf.unite(x, y);\n        } else {\n           \
    \ cout << uf.issame(x, y) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#include \"DataStructure/UnionFind.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n  \
    \  for (int i = 0; i < Q; i++) {\n        int com, x, y;\n        cin >> com >>\
    \ x >> y;\n        if (com == 0) {\n            uf.unite(x, y);\n        } else\
    \ {\n            cout << uf.issame(x, y) << endl;\n        }\n    }\n}"
  dependsOn:
  - DataStructure/UnionFind.hpp
  isVerificationFile: true
  path: test/AOJ/UnionFind_Checker.test.cpp
  requiredBy: []
  timestamp: '2022-12-19 21:21:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/UnionFind_Checker.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/UnionFind_Checker.test.cpp
- /verify/test/AOJ/UnionFind_Checker.test.cpp.html
title: test/AOJ/UnionFind_Checker.test.cpp
---
