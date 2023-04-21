---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc245/tasks/abc245_f
    links:
    - https://atcoder.jp/contests/abc245/tasks/abc245_f
  bundledCode: "#line 1 \"test/atcoder/abc245_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc245/tasks/abc245_f\"\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug_print.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"graph/scc.hpp\"\n\nstruct SCC {\n    using Edge = int;\n   \
    \ using SGraph = vector<vector<Edge>>;\n\n    SGraph G, rG;\n\n    vector<vector<int>>\
    \ scc;\n    vector<int> cmp;\n    SGraph dag;\n\n    explicit SCC(int N) : G(N),\
    \ rG(N) {}\n\n    void addedge(int u, int v) {\n        G[u].push_back(v);\n \
    \       rG[v].push_back(u);\n    }\n\n    vector<bool> seen;\n    vector<int>\
    \ vs, rvs;\n    void dfs(int v) {\n        seen[v] = true;\n        for (auto\
    \ e : G[v])\n            if (!seen[e]) dfs(e);\n        vs.push_back(v);\n   \
    \ }\n    void rdfs(int v, int k) {\n        seen[v] = true;\n        cmp[v] =\
    \ k;\n        for (auto e : rG[v])\n            if (!seen[e]) rdfs(e, k);\n  \
    \      rvs.push_back(v);\n    }\n\n    set<pair<int, int>> newEdges;\n    void\
    \ reconstruct() {\n        int N = (int)G.size();\n        int dV = (int)scc.size();\n\
    \        dag.assign(dV, vector<Edge>());\n        newEdges.clear();\n        for\
    \ (int i = 0; i < N; ++i) {\n            int u = cmp[i];\n            for (auto\
    \ e : G[i]) {\n                int v = cmp[e];\n                if (u == v) continue;\n\
    \                if (!newEdges.count({u, v})) {\n                    dag[u].push_back(v);\n\
    \                    newEdges.insert({u, v});\n                }\n           \
    \ }\n        }\n    }\n\n    void solve() {\n        int N = (int)G.size();\n\
    \        seen.assign(N, false);\n        vs.clear();\n        for (int v = 0;\
    \ v < N; ++v)\n            if (!seen[v]) dfs(v);\n\n        int k = 0;\n     \
    \   scc.clear();\n        cmp.assign(N, -1);\n        seen.assign(N, false);\n\
    \        for (int i = N - 1; i >= 0; --i) {\n            if (!seen[vs[i]]) {\n\
    \                rvs.clear();\n                rdfs(vs[i], k++);\n           \
    \     scc.push_back(rvs);\n            }\n        }\n\n        reconstruct();\n\
    \    }\n};\n#line 4 \"test/atcoder/abc245_f.test.cpp\"\n\nvector<vector<int>>\
    \ G;\nvector<int> dp;\nbool dfs(int u) {\n    if (dp[u] == 1) {\n        return\
    \ true;\n    }\n    if (dp[u] != -1) {\n        return dp[u];\n    }\n    for\
    \ (auto &i : G[u]) {\n        if (dfs(i)) {\n            return dp[u] = true;\n\
    \        }\n    }\n    return dp[u] = false;\n}\nint main() {\n    INT(N, M);\n\
    \    SCC scc(N);\n    for (int i = 0; i < M; i++) {\n        INT(a, b);\n    \
    \    a--;\n        b--;\n        scc.addedge(a, b);\n    }\n    scc.solve();\n\
    \    vector<vector<int>> res = scc.scc;\n    dp.resize(N, -1);\n    G = scc.G;\n\
    \    for (auto &i : res) {\n        if (i.size() >= 2) {\n            for (auto\
    \ &j : i) {\n                dp[j] = true;\n            }\n        }\n    }\n\
    \    for (int i = 0; i < N; i++) {\n        dfs(i);\n    }\n    int cnt = 0;\n\
    \    for (int i = 0; i < N; i++) {\n        cnt += dp[i];\n    }\n    print(cnt);\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc245/tasks/abc245_f\"\n#include\
    \ \"../../graph/scc.hpp\"\n#include \"../../template/template.hpp\"\n\nvector<vector<int>>\
    \ G;\nvector<int> dp;\nbool dfs(int u) {\n    if (dp[u] == 1) {\n        return\
    \ true;\n    }\n    if (dp[u] != -1) {\n        return dp[u];\n    }\n    for\
    \ (auto &i : G[u]) {\n        if (dfs(i)) {\n            return dp[u] = true;\n\
    \        }\n    }\n    return dp[u] = false;\n}\nint main() {\n    INT(N, M);\n\
    \    SCC scc(N);\n    for (int i = 0; i < M; i++) {\n        INT(a, b);\n    \
    \    a--;\n        b--;\n        scc.addedge(a, b);\n    }\n    scc.solve();\n\
    \    vector<vector<int>> res = scc.scc;\n    dp.resize(N, -1);\n    G = scc.G;\n\
    \    for (auto &i : res) {\n        if (i.size() >= 2) {\n            for (auto\
    \ &j : i) {\n                dp[j] = true;\n            }\n        }\n    }\n\
    \    for (int i = 0; i < N; i++) {\n        dfs(i);\n    }\n    int cnt = 0;\n\
    \    for (int i = 0; i < N; i++) {\n        cnt += dp[i];\n    }\n    print(cnt);\n\
    }"
  dependsOn:
  - graph/scc.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/atcoder/abc245_f.test.cpp
  requiredBy: []
  timestamp: '2023-04-21 23:32:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc245_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc245_f.test.cpp
- /verify/test/atcoder/abc245_f.test.cpp.html
title: test/atcoder/abc245_f.test.cpp
---
