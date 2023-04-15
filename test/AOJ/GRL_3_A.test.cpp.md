---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low-link.hpp
    title: "Low-Link (\u6A4B, \u95A2\u7BC0\u70B9\u5217\u6319)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/AOJ/GRL_3_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
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
    \ std;\n#line 3 \"graph/low-link.hpp\"\n\nstruct LowLink {\n    vector<int> aps;\n\
    \    vector<pair<int, int>> brs;\n\n    vector<int> seen, ord, low;\n    void\
    \ dfs_lowlink(const vector<vector<int>> &G, int v, int p = -1) {\n        static\
    \ int time = 0;\n        seen[v] = true;\n        ord[v] = low[v] = time++;\n\
    \        int num_of_child = 0;\n        bool exist = false;\n        for (auto\
    \ ch : G[v]) {\n            if (seen[ch]) {\n                if (ch != p) low[v]\
    \ = min(low[v], ord[ch]);\n                continue;\n            }\n        \
    \    dfs_lowlink(G, ch, v);\n            low[v] = min(low[v], low[ch]);\n    \
    \        if (ord[v] < low[ch]) brs.emplace_back(v, ch);\n            if (ord[v]\
    \ <= low[ch]) exist = true;\n            ++num_of_child;\n        }\n        if\
    \ ((p == -1 && num_of_child > 1) || (p != -1 && exist)) aps.emplace_back(v);\n\
    \    }\n    void solve(const vector<vector<int>> &G) {\n        int N = (int)G.size();\n\
    \        seen.assign(N, 0);\n        ord.resize(N);\n        low.resize(N);\n\
    \        aps.clear();\n        brs.clear();\n        for (int v = 0; v < N; ++v)\n\
    \            if (!seen[v]) dfs_lowlink(G, v);\n    }\n};\n#line 4 \"test/AOJ/GRL_3_A.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V,\
    \ vector<int>(0));\n    for (int i = 0; i < E; i++) {\n        int s, t;\n   \
    \     cin >> s >> t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    LowLink A;\n    A.solve(G);\n    auto ans = A.aps;\n    sort(all(ans));\n\
    \    for (int i = 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/low-link.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V,\
    \ vector<int>(0));\n    for (int i = 0; i < E; i++) {\n        int s, t;\n   \
    \     cin >> s >> t;\n        G[s].push_back(t);\n        G[t].push_back(s);\n\
    \    }\n    LowLink A;\n    A.solve(G);\n    auto ans = A.aps;\n    sort(all(ans));\n\
    \    for (int i = 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/low-link.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-24 23:12:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_3_A.test.cpp
- /verify/test/AOJ/GRL_3_A.test.cpp.html
title: test/AOJ/GRL_3_A.test.cpp
---
