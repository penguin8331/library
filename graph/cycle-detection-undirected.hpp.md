---
data:
  _extendedDependsOn:
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/cycle-detection-undirected.test.cpp
    title: test/yosupo/cycle-detection-undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)\
    \        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...) \
    \       \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug_print.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"graph/cycle-detection-undirected.hpp\"\n\nvoid cycle_detection(int\
    \ N, int M, vector<pair<int, int>> edges, vector<vector<pair<int, int>>> G, vector<int>&\
    \ V, vector<int>& E) {\n    // dfs tree\n    vector<bool> used_e(M);\n    vector<pair<int,\
    \ int>> par(N, {-1, -1});  // (vid, eid)\n    vector<int> dep(N, -1);\n    auto\
    \ dfs = [&](auto& dfs, int v, int d) -> void {\n        assert(dep[v] == -1);\n\
    \        dep[v] = d;\n        for (auto&& [eid, to] : G[v]) {\n            if\
    \ (dep[to] != -1) continue;\n            used_e[eid] = 1;\n            par[to]\
    \ = {v, eid};\n            dfs(dfs, to, d + 1);\n        }\n    };\n\n    for\
    \ (int v = 0; v < N; ++v) {\n        if (dep[v] == -1) dfs(dfs, v, 0);\n    }\n\
    \n    auto check = [&](vector<int> V, vector<int> E) -> bool {\n        int L\
    \ = V.size();\n        assert(L >= 1);\n        vector<int> used_v(N), used_e(M);\n\
    \        for (auto&& v : V) {\n            if (used_v[v]) return false;\n    \
    \        used_v[v] = 1;\n        }\n        for (auto&& e : E) {\n           \
    \ if (used_e[e]) return false;\n            used_e[e] = 1;\n        }\n      \
    \  for (int i = 0; i < L; ++i) {\n            auto [a, b] = edges[E[i]];\n   \
    \         int j = (i + 1 == L ? 0 : i + 1);\n            bool ok = 0;\n      \
    \      if (V[i] == a && V[j] == b) ok = 1;\n            if (V[i] == b && V[j]\
    \ == a) ok = 1;\n            if (!ok) return false;\n        }\n        return\
    \ true;\n    };\n\n    for (int eid = 0; eid < M; ++eid) {\n        if (used_e[eid])\
    \ continue;\n        auto [a, b] = edges[eid];\n        if (dep[a] > dep[b]) swap(a,\
    \ b);\n        assert(dep[a] <= dep[b]);\n\n        // \u5F8C\u9000\u8FBA e \u304B\
    \u3089\u3001\u30B5\u30A4\u30AF\u30EB\u304C\u51FA\u6765\u308B\n        V = {b};\n\
    \        while (V.back() != a) {\n            auto [v, e] = par[V.back()];\n \
    \           V.push_back(v);\n            E.push_back(e);\n        }\n        E.push_back(eid);\n\
    \        assert(check(V, E));\n        return;\n    }\n    return;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nvoid cycle_detection(int\
    \ N, int M, vector<pair<int, int>> edges, vector<vector<pair<int, int>>> G, vector<int>&\
    \ V, vector<int>& E) {\n    // dfs tree\n    vector<bool> used_e(M);\n    vector<pair<int,\
    \ int>> par(N, {-1, -1});  // (vid, eid)\n    vector<int> dep(N, -1);\n    auto\
    \ dfs = [&](auto& dfs, int v, int d) -> void {\n        assert(dep[v] == -1);\n\
    \        dep[v] = d;\n        for (auto&& [eid, to] : G[v]) {\n            if\
    \ (dep[to] != -1) continue;\n            used_e[eid] = 1;\n            par[to]\
    \ = {v, eid};\n            dfs(dfs, to, d + 1);\n        }\n    };\n\n    for\
    \ (int v = 0; v < N; ++v) {\n        if (dep[v] == -1) dfs(dfs, v, 0);\n    }\n\
    \n    auto check = [&](vector<int> V, vector<int> E) -> bool {\n        int L\
    \ = V.size();\n        assert(L >= 1);\n        vector<int> used_v(N), used_e(M);\n\
    \        for (auto&& v : V) {\n            if (used_v[v]) return false;\n    \
    \        used_v[v] = 1;\n        }\n        for (auto&& e : E) {\n           \
    \ if (used_e[e]) return false;\n            used_e[e] = 1;\n        }\n      \
    \  for (int i = 0; i < L; ++i) {\n            auto [a, b] = edges[E[i]];\n   \
    \         int j = (i + 1 == L ? 0 : i + 1);\n            bool ok = 0;\n      \
    \      if (V[i] == a && V[j] == b) ok = 1;\n            if (V[i] == b && V[j]\
    \ == a) ok = 1;\n            if (!ok) return false;\n        }\n        return\
    \ true;\n    };\n\n    for (int eid = 0; eid < M; ++eid) {\n        if (used_e[eid])\
    \ continue;\n        auto [a, b] = edges[eid];\n        if (dep[a] > dep[b]) swap(a,\
    \ b);\n        assert(dep[a] <= dep[b]);\n\n        // \u5F8C\u9000\u8FBA e \u304B\
    \u3089\u3001\u30B5\u30A4\u30AF\u30EB\u304C\u51FA\u6765\u308B\n        V = {b};\n\
    \        while (V.back() != a) {\n            auto [v, e] = par[V.back()];\n \
    \           V.push_back(v);\n            E.push_back(e);\n        }\n        E.push_back(eid);\n\
    \        assert(check(V, E));\n        return;\n    }\n    return;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/cycle-detection-undirected.hpp
  requiredBy: []
  timestamp: '2023-04-22 18:00:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/cycle-detection-undirected.test.cpp
documentation_of: graph/cycle-detection-undirected.hpp
layout: document
redirect_from:
- /library/graph/cycle-detection-undirected.hpp
- /library/graph/cycle-detection-undirected.hpp.html
title: graph/cycle-detection-undirected.hpp
---
