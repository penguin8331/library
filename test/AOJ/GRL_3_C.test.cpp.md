---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: Strongly Connected Component
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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"test/AOJ/GRL_3_C.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\n#line 2 \"\
    template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define overload3(_1, _2, _3, name, ...) name\n#define all1(v) std::begin(v),\
    \ std::end(v)\n#define all2(v, a) std::begin(v), std::begin(v) + a\n#define all3(v,\
    \ a, b) std::begin(v) + a, std::begin(v) + b\n#define all(...) overload3(__VA_ARGS__,\
    \ all3, all2, all1)(__VA_ARGS__)\n#define rall1(v) std::rbegin(v), std::rend(v)\n\
    #define rall2(v, a) std::rbegin(v), std::rbegin(v) + a\n#define rall3(v, a, b)\
    \ std::rbegin(v) + a, std::rbegin(v) + b\n#define rall(...) overload3(__VA_ARGS__,\
    \ rall3, rall2, rall1)(__VA_ARGS__)\n#define elif else if\n#define updiv(N, X)\
    \ (((N) + (X) - 1) / (X))\n#define sigma(a, b) (((a) + (b)) * ((b) - (a) + 1)\
    \ / 2)\n#define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ STR(...)        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ CHR(...)      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...)\
    \        \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
    \     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
    #define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <dump.hpp>\n#else\n#define\
    \ debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n\
    #line 3 \"graph/scc.hpp\"\n\nstruct SCC {\n    using Edge = int;\n    using SGraph\
    \ = vector<vector<Edge>>;\n\n    SGraph G, rG;\n\n    vector<vector<int>> scc;\n\
    \    vector<int> cmp;\n    SGraph dag;\n\n    explicit SCC(int N) : G(N), rG(N)\
    \ {}\n\n    void addedge(int u, int v) {\n        G[u].push_back(v);\n       \
    \ rG[v].push_back(u);\n    }\n\n    vector<bool> seen;\n    vector<int> vs, rvs;\n\
    \    void dfs(int v) {\n        seen[v] = true;\n        for (auto e : G[v])\n\
    \            if (!seen[e]) dfs(e);\n        vs.push_back(v);\n    }\n    void\
    \ rdfs(int v, int k) {\n        seen[v] = true;\n        cmp[v] = k;\n       \
    \ for (auto e : rG[v])\n            if (!seen[e]) rdfs(e, k);\n        rvs.push_back(v);\n\
    \    }\n\n    set<pair<int, int>> newEdges;\n    void reconstruct() {\n      \
    \  int N = (int)G.size();\n        int dV = (int)scc.size();\n        dag.assign(dV,\
    \ vector<Edge>());\n        newEdges.clear();\n        for (int i = 0; i < N;\
    \ ++i) {\n            int u = cmp[i];\n            for (auto e : G[i]) {\n   \
    \             int v = cmp[e];\n                if (u == v) continue;\n       \
    \         if (!newEdges.count({u, v})) {\n                    dag[u].push_back(v);\n\
    \                    newEdges.insert({u, v});\n                }\n           \
    \ }\n        }\n    }\n\n    void solve() {\n        int N = (int)G.size();\n\
    \        seen.assign(N, false);\n        vs.clear();\n        for (int v = 0;\
    \ v < N; ++v)\n            if (!seen[v]) dfs(v);\n\n        int k = 0;\n     \
    \   scc.clear();\n        cmp.assign(N, -1);\n        seen.assign(N, false);\n\
    \        for (int i = N - 1; i >= 0; --i) {\n            if (!seen[vs[i]]) {\n\
    \                rvs.clear();\n                rdfs(vs[i], k++);\n           \
    \     scc.push_back(rvs);\n            }\n        }\n\n        reconstruct();\n\
    \    }\n};\n#line 5 \"test/AOJ/GRL_3_C.test.cpp\"\n\nint main() {\n    int V,\
    \ E;\n    cin >> V >> E;\n    SCC scc(V);\n    for (int i = 0; i < E; i++) {\n\
    \        int a, b;\n        cin >> a >> b;\n        scc.addedge(a, b);\n    }\n\
    \    scc.solve();\n    int Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        cout << (scc.cmp[u] ==\
    \ scc.cmp[v] ? 1 : 0) << endl;\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n#include \"../../graph/scc.hpp\"\n#include \"../../template/template.hpp\"\n\
    \nint main() {\n    int V, E;\n    cin >> V >> E;\n    SCC scc(V);\n    for (int\
    \ i = 0; i < E; i++) {\n        int a, b;\n        cin >> a >> b;\n        scc.addedge(a,\
    \ b);\n    }\n    scc.solve();\n    int Q;\n    cin >> Q;\n    for (int i = 0;\
    \ i < Q; i++) {\n        int u, v;\n        cin >> u >> v;\n        cout << (scc.cmp[u]\
    \ == scc.cmp[v] ? 1 : 0) << endl;\n    }\n}"
  dependsOn:
  - graph/scc.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2024-08-24 11:50:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_3_C.test.cpp
- /verify/test/AOJ/GRL_3_C.test.cpp.html
title: test/AOJ/GRL_3_C.test.cpp
---
