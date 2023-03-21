---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/topological-sort.hpp
    title: "\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B
  bundledCode: "#line 1 \"test/AOJ/GRL_4_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
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
    #line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"graph/topological-sort.hpp\"\
    \n\nvoid dfs(const vector<vector<int>> &G, int v, vector<bool> &used, vector<int>\
    \ &ans) {\n    used[v] = true;\n    for (auto e : G[v]) {\n        if (!used[e])\
    \ {\n            dfs(G, e, used, ans);\n        }\n    }\n    ans.push_back(v);\
    \  // \u5E30\u308A\u304C\u3051\u306Bpush_back\n}\nvector<int> topo_sort(const\
    \ vector<vector<int>> &G) {  // bfs\n    vector<int> ans;\n    int n = (int)G.size();\n\
    \    vector<bool> used(n, false);\n    for (int v = 0; v < n; v++) {  // \u672A\
    \u63A2\u7D22\u306E\u9802\u70B9\u3054\u3068\u306BDFS\n        if (!used[v]) dfs(G,\
    \ v, used, ans);\n    }\n    reverse(ans.begin(), ans.end());  // \u9006\u5411\
    \u304D\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\u3059\n    return ans;\n\
    }\n#line 4 \"test/AOJ/GRL_4_B.test.cpp\"\n\nint main() {\n    int V, E;\n    cin\
    \ >> V >> E;\n    vector<vector<int>> G(V, vector<int>(0));\n    for (int i =\
    \ 0; i < E; i++) {\n        int s, t;\n        cin >> s >> t;\n        G[s].push_back(t);\n\
    \    }\n    auto ans = topo_sort(G);\n    for (int i = 0; i < ans.size(); i++)\
    \ {\n        cout << ans[i] << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../graph/topological-sort.hpp\"\
    \n\nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<vector<int>> G(V,\
    \ vector<int>(0));\n    for (int i = 0; i < E; i++) {\n        int s, t;\n   \
    \     cin >> s >> t;\n        G[s].push_back(t);\n    }\n    auto ans = topo_sort(G);\n\
    \    for (int i = 0; i < ans.size(); i++) {\n        cout << ans[i] << endl;\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/topological-sort.hpp
  isVerificationFile: true
  path: test/AOJ/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2023-03-21 10:37:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/GRL_4_B.test.cpp
- /verify/test/AOJ/GRL_4_B.test.cpp.html
title: test/AOJ/GRL_4_B.test.cpp
---
