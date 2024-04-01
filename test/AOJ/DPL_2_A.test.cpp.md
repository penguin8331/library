---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dynamic-programming/traveling-salesman-problem.hpp
    title: "\u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (by bitDP)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A
  bundledCode: "#line 1 \"test/AOJ/DPL_2_A.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\n#line 2 \"\
    template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"dynamic-programming/traveling-salesman-problem.hpp\"\n\nstruct\
    \ traveling_salesman {\n    int V;\n    vector<vector<ll>> dp;\n    vector<vector<ll>>\
    \ G;\n    ll ans;\n    traveling_salesman(vector<vector<ll>> G) : G(G) {\n   \
    \     V = G.size();\n        dp.assign(1 << V, vector<ll>(V, 0));\n        ans\
    \ = solve((1 << V) - 1, 0);\n    }\n    ll solve(int S, int v) {\n        if (S\
    \ == 0) {\n            if (v == 0) {\n                return 0;\n            }\
    \ else {\n                return inf;\n            }\n        }\n        if ((S\
    \ & (1 << v)) == 0) {\n            return inf;\n        }\n        ll& ret = dp[S][v];\n\
    \        if (ret != 0) return ret;\n        ret = inf;\n        for (int u = 0;\
    \ u < V; u++) {\n            chmin(ret, solve(S ^ (1 << v), u) + G[u][v]);\n \
    \       }\n        return ret;\n    }\n};\n#line 5 \"test/AOJ/DPL_2_A.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<ll>> G(V,\
    \ vector<ll>(V));\n    for (int i = 0; i < V; i++) {\n        for (int j = 0;\
    \ j < V; j++) {\n            G[i][j] = inf;\n        }\n    }\n    for (int i\
    \ = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >> t >> d;\n    \
    \    G[s][t] = d;\n    }\n    traveling_salesman tsp(G);\n    ll ans = tsp.ans;\n\
    \    cout << (ans == inf ? -1 : ans) << endl;\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A\"\
    \n#include \"../../dynamic-programming/traveling-salesman-problem.hpp\"\n#include\
    \ \"../../template/template.hpp\"\n\nint main() {\n    int V, E;\n    cin >> V\
    \ >> E;\n    vector<vector<ll>> G(V, vector<ll>(V));\n    for (int i = 0; i <\
    \ V; i++) {\n        for (int j = 0; j < V; j++) {\n            G[i][j] = inf;\n\
    \        }\n    }\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n \
    \       cin >> s >> t >> d;\n        G[s][t] = d;\n    }\n    traveling_salesman\
    \ tsp(G);\n    ll ans = tsp.ans;\n    cout << (ans == inf ? -1 : ans) << endl;\n\
    }"
  dependsOn:
  - dynamic-programming/traveling-salesman-problem.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/AOJ/DPL_2_A.test.cpp
  requiredBy: []
  timestamp: '2024-04-01 15:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DPL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL_2_A.test.cpp
- /verify/test/AOJ/DPL_2_A.test.cpp.html
title: test/AOJ/DPL_2_A.test.cpp
---
