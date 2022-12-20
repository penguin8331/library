---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: data-structure/union-find.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/AOJ/DSL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing ld = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define pb push_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) ((N + X - 1) / X)\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct\
    \ fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename\
    \ T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false));\
    \ }\ntemplate <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a\
    \ = b, true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 1 \"data-structure/union-find.hpp\"\nstruct UnionFind\
    \ {\n    vector<int> par;\n\n    UnionFind() {}\n    UnionFind(int n) : par(n,\
    \ -1) {}\n    void init(int n) { par.assign(n, -1); }\n\n    int root(int x) {\n\
    \        if (par[x] < 0)\n            return x;\n        else\n            return\
    \ par[x] = root(par[x]);\n    }\n\n    bool issame(int x, int y) {\n        return\
    \ root(x) == root(y);\n    }\n\n    bool unite(int x, int y) {\n        x = root(x);\n\
    \        y = root(y);\n        if (x == y) return false;\n        if (par[x] >\
    \ par[y]) swap(x, y);\n        par[x] += par[y];\n        par[y] = x;\n      \
    \  return true;\n    }\n\n    int size(int x) {\n        return -par[root(x)];\n\
    \    }\n\n    vector<vector<int>> groups() {\n        map<int, vector<int>> root_buf;\n\
    \        for (int i = 0; i < (int)par.size(); ++i) {\n            int r = root(i);\n\
    \            root_buf[r].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (const auto& i : root_buf) {\n            res.push_back(i.second);\n\
    \        }\n        return res;\n    }\n};\n#line 4 \"test/AOJ/DSL_1_A.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n  \
    \  for (int i = 0; i < Q; i++) {\n        int com, x, y;\n        cin >> com >>\
    \ x >> y;\n        if (com == 0) {\n            uf.unite(x, y);\n        } else\
    \ {\n            cout << uf.issame(x, y) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n#include \"template/template.hpp\"\n#include \"data-structure/union-find.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n  \
    \  for (int i = 0; i < Q; i++) {\n        int com, x, y;\n        cin >> com >>\
    \ x >> y;\n        if (com == 0) {\n            uf.unite(x, y);\n        } else\
    \ {\n            cout << uf.issame(x, y) << endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_1_A.test.cpp
- /verify/test/AOJ/DSL_1_A.test.cpp.html
title: test/AOJ/DSL_1_A.test.cpp
---
