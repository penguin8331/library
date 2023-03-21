---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bfs.hpp
    title: BFS
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_11_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
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
    #line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/bfs.hpp\"\
    \n\nvector<int> BFS(const vector<vector<int>> &G, int s) {\n    int N = (int)G.size();\
    \    // \u9802\u70B9\u6570\n    vector<int> dist(N, -1);  // \u3059\u3079\u3066\
    \u306E\u9802\u70B9\u3092\u672A\u8A2A\u554F\u306B\u521D\u671F\u5316\n    queue<int>\
    \ que;\n\n    // \u521D\u671F\u6761\u4EF6 (\u9802\u70B9s\u3092\u521D\u671F\u9802\
    \u70B9\u3068\u3059\u308B)\n    dist[s] = 0;\n    que.push(s);  // s\u3092\u63A2\
    \u7D22\u6E08\u307F\u9802\u70B9\u306B\n\n    // BFS\u958B\u59CB\n    while (!que.empty())\
    \ {\n        int v = que.front();\n        que.pop();\n\n        // \u9802\u70B9\
    v\u304B\u3089\u305F\u3069\u308C\u308B\u9802\u70B9\u3092\u5168\u3066\u8ABF\u3079\
    \u308B\n        for (int x : G[v]) {\n            // \u3059\u3067\u306B\u767A\u898B\
    \u6E08\u307F\u306E\u9802\u70B9\u306F\u63A2\u7D22\u3057\u306A\u3044\n         \
    \   if (dist[x] != -1) continue;\n\n            // \u65B0\u305F\u306A\u672A\u63A2\
    \u7D22\u9802\u70B9x\u306B\u3064\u3044\u3066\u8DDD\u96E2\u60C5\u5831\u3092\u66F4\
    \u65B0\u3057\u3066\u30AD\u30E5\u30FC\u306B\u633F\u5165\n            dist[x] =\
    \ dist[v] + 1;\n            que.push(x);\n        }\n    }\n    return dist;\n\
    }\n#line 4 \"test/AOJ/ALDS1_11_C.test.cpp\"\n\nint main() {\n    int N;\n    cin\
    \ >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n    for (int i = 0; i\
    \ < N; i++) {\n        int u, k;\n        cin >> u >> k;\n        u--;\n     \
    \   for (int j = 0; j < k; j++) {\n            int v;\n            cin >> v;\n\
    \            v--;\n            G[u].push_back(v);\n        }\n    }\n    auto\
    \ res = BFS(G, 0);\n    for (int i = 0; i < N; i++) {\n        cout << i + 1 <<\
    \ \" \" << res[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/bfs.hpp\"\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N, vector<int>(0));\n\
    \    for (int i = 0; i < N; i++) {\n        int u, k;\n        cin >> u >> k;\n\
    \        u--;\n        for (int j = 0; j < k; j++) {\n            int v;\n   \
    \         cin >> v;\n            v--;\n            G[u].push_back(v);\n      \
    \  }\n    }\n    auto res = BFS(G, 0);\n    for (int i = 0; i < N; i++) {\n  \
    \      cout << i + 1 << \" \" << res[i] << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/bfs.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_11_C.test.cpp
  requiredBy: []
  timestamp: '2023-03-21 10:37:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_11_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_11_C.test.cpp
- /verify/test/AOJ/ALDS1_11_C.test.cpp.html
title: test/AOJ/ALDS1_11_C.test.cpp
---
