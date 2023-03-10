---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
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
  bundledCode: "#line 1 \"test/AOJ/DSL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define pb push_back\n#define mp make_pair\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ld = long double;\n\
    using pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int\
    \ inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1,\
    \ 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr\
    \ int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\
    \n\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a\
    \ = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b)\
    \ { return ((a > b) ? (a = b, true) : (false)); }\n#line 3 \"template/util.hpp\"\
    \n\nstruct IOSetup {\n    IOSetup() {\n        std::cin.tie(nullptr);\n      \
    \  std::ios::sync_with_stdio(false);\n        std::cout.tie(0);\n        std::cout\
    \ << std::fixed << std::setprecision(12);\n        std::cerr << std::fixed <<\
    \ std::setprecision(12);\n    }\n} IOSetup;\n#line 1 \"template/debug.hpp\"\n\
    #ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n#define debug(...)\n#define line\n\
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"data-structure/union-find.hpp\"\
    \n\nstruct UnionFind {\n    vector<int> par;\n\n    UnionFind() {}\n    UnionFind(int\
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
    \  }\n};\n#line 4 \"test/AOJ/DSL_1_A.test.cpp\"\n\nint main() {\n    int N, Q;\n\
    \    cin >> N >> Q;\n    UnionFind uf(N);\n    for (int i = 0; i < Q; i++) {\n\
    \        int com, x, y;\n        cin >> com >> x >> y;\n        if (com == 0)\
    \ {\n            uf.unite(x, y);\n        } else {\n            cout << uf.issame(x,\
    \ y) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../data-structure/union-find.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n  \
    \  for (int i = 0; i < Q; i++) {\n        int com, x, y;\n        cin >> com >>\
    \ x >> y;\n        if (com == 0) {\n            uf.unite(x, y);\n        } else\
    \ {\n            cout << uf.issame(x, y) << endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_1_A.test.cpp
- /verify/test/AOJ/DSL_1_A.test.cpp.html
title: test/AOJ/DSL_1_A.test.cpp
---
