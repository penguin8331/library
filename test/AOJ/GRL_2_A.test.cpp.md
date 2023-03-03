---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal (\u6700\u5C0F\u5168\u57DF\u6728) $O(E log V)$"
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/AOJ/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
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
    \ std::setprecision(12);\n    }\n};\n#line 7 \"template/template.hpp\"\nusing\
    \ namespace std;\n#line 3 \"data-structure/union-find.hpp\"\n\nstruct UnionFind\
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
    \        }\n        return res;\n    }\n};\n#line 4 \"graph/kruskal.hpp\"\n\n\
    struct Edge {\n    long long from;\n    long long to;\n    long long cost;\n};\n\
    bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }  //\
    \ \u8FBA\u3092\u76F4\u63A5\u6BD4\u8F03\u3059\u308B\u305F\u3081\u306E\u95A2\u6570\
    \nstruct Kruskal {\n    UnionFind uft;\n    long long sum;  // \u6700\u5C0F\u5168\
    \u57DF\u6728\u306E\u91CD\u307F\u306E\u7DCF\u548C\n    vector<Edge> edges;\n  \
    \  int V;\n    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_)\
    \ { init(); }\n    void init() {\n        sort(edges.begin(), edges.end(), comp_e);\
    \  // \u8FBA\u306E\u91CD\u307F\u3067\u30BD\u30FC\u30C8\n        uft = UnionFind(V);\n\
    \        sum = 0;\n        for (auto e : edges) {\n            if (!uft.issame(e.from,\
    \ e.to)) {  // \u9589\u8DEF\u306B\u306A\u3089\u306A\u3051\u308C\u3070\u52A0\u3048\
    \u308B\n                uft.unite(e.from, e.to);\n                sum += e.cost;\n\
    \            }\n        }\n    }\n};\n#line 4 \"test/AOJ/GRL_2_A.test.cpp\"\n\n\
    int main() {\n    int V, E;\n    cin >> V >> E;\n    vector<Edge> es(E);\n   \
    \ for (int i = 0; i < E; i++) {\n        cin >> es[i].from >> es[i].to >> es[i].cost;\n\
    \    }\n    Kruskal A(es, V);\n    cout << A.sum << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/kruskal.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<Edge> es(E);\n\
    \    for (int i = 0; i < E; i++) {\n        cin >> es[i].from >> es[i].to >> es[i].cost;\n\
    \    }\n    Kruskal A(es, V);\n    cout << A.sum << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - graph/kruskal.hpp
  - data-structure/union-find.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_2_A.test.cpp
- /verify/test/AOJ/GRL_2_A.test.cpp.html
title: test/AOJ/GRL_2_A.test.cpp
---
