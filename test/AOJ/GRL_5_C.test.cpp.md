---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/lca.hpp
    title: Lowest Common Ancestor
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/AOJ/GRL_5_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x),\
    \ std::rend(x)\n#define elif else if\n#define updiv(N, X) (((N) + (X) - (1)) /\
    \ (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n#define INT(...)    \
    \ \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LL(...)     \\\n\
    \    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)        \\\n \
    \   string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)      \\\n\
    \    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...)        \\\n\
    \    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)     \\\n \
    \   ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n#define eb\
    \ emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing\
    \ ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"graph/lca.hpp\"\n\nstruct LCA {\n    vector<vector<int>> parent;\
    \  // parent[d][v] := 2^d-th parent of v\n    vector<int> depth;\n    LCA() {}\n\
    \    LCA(const vector<vector<int>>& G, int r = 0) { init(G, r); }\n    void init(const\
    \ vector<vector<int>>& G, int r = 0) {\n        int V = (int)G.size();\n     \
    \   int h = 1;\n        while ((1 << h) < V) ++h;\n        parent.assign(h, vector<int>(V,\
    \ -1));\n        depth.assign(V, -1);\n        dfs(G, r, -1, 0);\n        for\
    \ (int i = 0; i + 1 < (int)parent.size(); ++i)\n            for (int v = 0; v\
    \ < V; ++v)\n                if (parent[i][v] != -1)\n                    parent[i\
    \ + 1][v] = parent[i][parent[i][v]];\n    }\n    void dfs(const vector<vector<int>>&\
    \ G, int v, int p, int d) {\n        parent[0][v] = p;\n        depth[v] = d;\n\
    \        for (auto e : G[v])\n            if (e != p) dfs(G, e, v, d + 1);\n \
    \   }\n    int after(int u, int k) {\n        for (int i = 0; i < (int)parent.size();\
    \ i++) {\n            if (k & (1 << i)) {\n                u = parent[i][u];\n\
    \            }\n        }\n        return u;\n    }\n    int get(int u, int v)\
    \ {\n        if (depth[u] > depth[v]) swap(u, v);\n        v = after(v, depth[v]\
    \ - depth[u]);\n        if (u == v) return u;\n        for (int i = (int)parent.size()\
    \ - 1; i >= 0; --i) {\n            if (parent[i][u] != parent[i][v]) {\n     \
    \           u = parent[i][u];\n                v = parent[i][v];\n           \
    \ }\n        }\n        return parent[0][u];\n    }\n    int dist(int u, int v)\
    \ {\n        return depth[u] + depth[v] - 2 * depth[get(u, v)];\n    }\n    bool\
    \ is_on_path(int u, int v, int a) {\n        return dist(u, a) + dist(a, v) ==\
    \ dist(u, v);\n    }\n};\n#line 4 \"test/AOJ/GRL_5_C.test.cpp\"\n\nint main()\
    \ {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; j++) {\n            int a;\n            cin >> a;\n\
    \            G[i].push_back(a);\n        }\n    }\n    LCA lca(G, 0);\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << lca.get(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/lca.hpp\"\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int k;\n        cin >> k;\n      \
    \  for (int j = 0; j < k; j++) {\n            int a;\n            cin >> a;\n\
    \            G[i].push_back(a);\n        }\n    }\n    LCA lca(G, 0);\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        int u, v;\n  \
    \      cin >> u >> v;\n        cout << lca.get(u, v) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/lca.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2023-03-21 18:23:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_5_C.test.cpp
- /verify/test/AOJ/GRL_5_C.test.cpp.html
title: test/AOJ/GRL_5_C.test.cpp
---
