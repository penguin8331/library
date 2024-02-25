---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/compress2d.hpp
    title: "\u4E8C\u6B21\u5143\u5EA7\u6A19\u5727\u7E2E"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
  bundledCode: "#line 1 \"test/AOJ/DSL_4_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"algorithm/compress2d.hpp\"\n\r\ntemplate <typename T>\r\nvector<T>\
    \ compress(vector<T> &C1, vector<T> &C2) {\r\n    vector<T> vals;\r\n    int N\
    \ = (int)C1.size();\r\n    for (int i = 0; i < N; i++) {\r\n        for (T d =\
    \ 0; d <= 1; d++) {\r\n            T tc1 = C1[i] + d;\r\n            T tc2 = C2[i]\
    \ + d;\r\n            vals.push_back(tc1);\r\n            vals.push_back(tc2);\r\
    \n        }\r\n    }\r\n    sort(vals.begin(), vals.end());\r\n    vals.erase(unique(vals.begin(),\
    \ vals.end()), vals.end());\r\n    for (int i = 0; i < N; i++) {\r\n        C1[i]\
    \ = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();\r\n        C2[i]\
    \ = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();\r\n    }\r\n\
    \    return vals;\r\n}\n#line 4 \"test/AOJ/DSL_4_A.test.cpp\"\n\nint main() {\n\
    \    int N;\n    cin >> N;\n    vector<long long> X1(N), Y1(N), X2(N), Y2(N);\n\
    \    for (int i = 0; i < N; i++) {\n        cin >> X1.at(i) >> Y1.at(i) >> X2.at(i)\
    \ >> Y2.at(i);\n    }\n    vector<long long> X = compress(X1, X2);\n    vector<long\
    \ long> Y = compress(Y1, Y2);\n    int w = (int)X.size();\n    int h = (int)Y.size();\n\
    \    vector<vector<int>> G(w, vector<int>(h));\n    for (int i = 0; i < N; i++)\
    \ {\n        G[X1[i]][Y1[i]]++;\n        G[X2[i]][Y2[i]]++;\n        G[X1[i]][Y2[i]]--;\n\
    \        G[X2[i]][Y1[i]]--;\n    }\n    for (int x = 1; x < w; x++) {\n      \
    \  for (int y = 0; y < h; y++) {\n            G[x][y] += G[x - 1][y];\n      \
    \  }\n    }\n    for (int x = 0; x < w; x++) {\n        for (int y = 1; y < h;\
    \ y++) {\n            G[x][y] += G[x][y - 1];\n        }\n    }\n    long long\
    \ ans = 0;\n    for (int x = 0; x < w - 1; x++) {\n        for (int y = 0; y <\
    \ h - 1; y++) {\n            if (G[x][y]) {\n                ans += (X[x + 1]\
    \ - X[x]) * (Y[y + 1] - Y[y]);\n            }\n        }\n    }\n    cout << ans\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../algorithm/compress2d.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<long long> X1(N), Y1(N),\
    \ X2(N), Y2(N);\n    for (int i = 0; i < N; i++) {\n        cin >> X1.at(i) >>\
    \ Y1.at(i) >> X2.at(i) >> Y2.at(i);\n    }\n    vector<long long> X = compress(X1,\
    \ X2);\n    vector<long long> Y = compress(Y1, Y2);\n    int w = (int)X.size();\n\
    \    int h = (int)Y.size();\n    vector<vector<int>> G(w, vector<int>(h));\n \
    \   for (int i = 0; i < N; i++) {\n        G[X1[i]][Y1[i]]++;\n        G[X2[i]][Y2[i]]++;\n\
    \        G[X1[i]][Y2[i]]--;\n        G[X2[i]][Y1[i]]--;\n    }\n    for (int x\
    \ = 1; x < w; x++) {\n        for (int y = 0; y < h; y++) {\n            G[x][y]\
    \ += G[x - 1][y];\n        }\n    }\n    for (int x = 0; x < w; x++) {\n     \
    \   for (int y = 1; y < h; y++) {\n            G[x][y] += G[x][y - 1];\n     \
    \   }\n    }\n    long long ans = 0;\n    for (int x = 0; x < w - 1; x++) {\n\
    \        for (int y = 0; y < h - 1; y++) {\n            if (G[x][y]) {\n     \
    \           ans += (X[x + 1] - X[x]) * (Y[y + 1] - Y[y]);\n            }\n   \
    \     }\n    }\n    cout << ans << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - algorithm/compress2d.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_4_A.test.cpp
  requiredBy: []
  timestamp: '2024-02-25 20:07:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_4_A.test.cpp
- /verify/test/AOJ/DSL_4_A.test.cpp.html
title: test/AOJ/DSL_4_A.test.cpp
---
