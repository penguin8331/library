---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: Dijkstra
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/AOJ/GRL_1_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define pb push_back\n#define all(x) std::begin(x), std::end(x)\n#define rall(x)\
    \ std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N, X) (((N)\
    \ + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n#line\
    \ 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ld = long double;\n\
    using pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int\
    \ inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[8] = {1, 0,\
    \ -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\n\
    constexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\
    \n\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a\
    \ = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b)\
    \ { return ((a > b) ? (a = b, true) : (false)); }\ntemplate <typename T, typename\
    \ U>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {\n\
    \    os << p.first << \" \" << p.second;\n    return os;\n}\ntemplate <typename\
    \ T, typename U>\nstd::istream &operator>>(std::istream &is, std::pair<T, U> &p)\
    \ {\n    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename T>\n\
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {\n    for\
    \ (auto it = std::begin(v); it != std::end(v);) {\n        os << *it << ((++it)\
    \ != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate <typename\
    \ T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v) {\n    for\
    \ (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline void scan()\
    \ {}\ntemplate <class Head, class... Tail>\ninline void scan(Head &head, Tail\
    \ &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate <class T>\n\
    inline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate <class Head,\
    \ class... Tail>\ninline void print(const Head &head, const Tail &...tail) {\n\
    \    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate <class... T>\n\
    inline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n}\n#line 3 \"\
    template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n        std::cin.tie(nullptr);\n\
    \        std::ios::sync_with_stdio(false);\n        std::cout.tie(0);\n      \
    \  std::cout << std::fixed << std::setprecision(12);\n        std::cerr << std::fixed\
    \ << std::setprecision(12);\n    }\n} IOSetup;\n#line 3 \"template/debug.hpp\"\
    \n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n#define debug(...)\n#endif\n\
    #line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/dijkstra.hpp\"\
    \n\nstruct Edge {\n    long long to;\n    long long cost;\n};\nvector<long long>\
    \ dijkstra(const vector<vector<Edge>> &G, int s) {\n    int N = G.size();\n  \
    \  vector<long long> dis(N, INF);\n    priority_queue<pair<long long, int>, vector<pair<long\
    \ long, int>>, greater<pair<long long, int>>> pq;  // \u300C\u4EEE\u306E\u6700\
    \u77ED\u8DDD\u96E2, \u9802\u70B9\u300D\u304C\u5C0F\u3055\u3044\u9806\u306B\u4E26\
    \u3076\n    dis[s] = 0;\n    pq.emplace(dis[s], s);\n    while (!pq.empty()) {\n\
    \        pair<long long, int> p = pq.top();\n        pq.pop();\n        int v\
    \ = p.second;\n        if (dis[v] < p.first) {  // \u6700\u77ED\u8DDD\u96E2\u3067\
    \u7121\u3051\u308C\u3070\u7121\u8996\n            continue;\n        }\n     \
    \   for (auto &e : G[v]) {\n            if (dis[e.to] > dis[v] + e.cost) {  //\
    \ \u6700\u77ED\u8DDD\u96E2\u5019\u88DC\u306A\u3089 priority_queue \u306B\u8FFD\
    \u52A0\n                dis[e.to] = dis[v] + e.cost;\n                pq.emplace(dis[e.to],\
    \ e.to);\n            }\n        }\n    }\n    return dis;\n}\n#line 4 \"test/AOJ/GRL_1_A.test.cpp\"\
    \n\nint main() {\n    int N, E, r;\n    cin >> N >> E >> r;\n    vector<vector<Edge>>\
    \ G(N);\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin\
    \ >> s >> t >> d;\n        G[s].push_back({t, d});\n    }\n    auto res = dijkstra(G,\
    \ r);\n    for (int i = 0; i < N; i++) {\n        if (res[i] == INF) {\n     \
    \       cout << \"INF\" << endl;\n        } else {\n            cout << res[i]\
    \ << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/dijkstra.hpp\"\
    \n\nint main() {\n    int N, E, r;\n    cin >> N >> E >> r;\n    vector<vector<Edge>>\
    \ G(N);\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin\
    \ >> s >> t >> d;\n        G[s].push_back({t, d});\n    }\n    auto res = dijkstra(G,\
    \ r);\n    for (int i = 0; i < N; i++) {\n        if (res[i] == INF) {\n     \
    \       cout << \"INF\" << endl;\n        } else {\n            cout << res[i]\
    \ << endl;\n        }\n    }\n}\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/dijkstra.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-03-21 10:37:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_1_A.test.cpp
- /verify/test/AOJ/GRL_1_A.test.cpp.html
title: test/AOJ/GRL_1_A.test.cpp
---
