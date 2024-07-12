---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/weighted-union-find.hpp
    title: WeightedUnionFind
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
    PROBLEM: https://atcoder.jp/contests/abc280/tasks/abc280_f
    links:
    - https://atcoder.jp/contests/abc280/tasks/abc280_f
  bundledCode: "#line 1 \"test/atcoder/abc280_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_f\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/weighted-union-find.hpp\"\n\ntemplate <class\
    \ T>\nstruct WeightedUnionFind {\n    // core member\n    vector<int> par;\n \
    \   vector<T> weight;\n\n    // constructor\n    WeightedUnionFind() {}\n    WeightedUnionFind(int\
    \ N, T zero = 0) : par(N, -1), weight(N, zero) {}\n    void init(int N, T zero\
    \ = 0) {\n        par.assign(N, -1);\n        weight.assign(N, zero);\n    }\n\
    \n    // core methods\n    int root(int x) {\n        if (par[x] < 0)\n      \
    \      return x;\n        else {\n            int r = root(par[x]);\n        \
    \    weight[x] += weight[par[x]];\n            return par[x] = r;\n        }\n\
    \    }\n    bool issame(int x, int y) { return root(x) == root(y); }\n\n    //\
    \ v[y] - v[x] = w\n    bool unite(int x, int y, T w) {\n        w += get_weight(x),\
    \ w -= get_weight(y);\n        x = root(x), y = root(y);\n        if (x == y)\
    \ return false;\n        if (par[x] > par[y]) swap(x, y), w = -w;  // merge technique\n\
    \        par[x] += par[y];\n        par[y] = x;\n        weight[y] = w;\n    \
    \    return true;\n    }\n\n    int size(int x) { return -par[root(x)]; }\n\n\
    \    // get v[x]\n    T get_weight(int x) {\n        root(x);\n        return\
    \ weight[x];\n    }\n\n    // get v[y] - v[x]\n    T get_diff(int x, int y) {\
    \ return get_weight(y) - get_weight(x); }\n\n    // get groups\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> member(par.size());\n        for (int\
    \ v = 0; v < (int)par.size(); ++v) {\n            member[root(v)].push_back(v);\n\
    \        }\n        vector<vector<int>> res;\n        for (int v = 0; v < (int)par.size();\
    \ ++v) {\n            if (!member[v].empty()) res.push_back(member[v]);\n    \
    \    }\n        return res;\n    }\n};\n#line 4 \"test/atcoder/abc280_f.test.cpp\"\
    \n\nint main() {\n    INT(N, M, Q);\n    WeightedUnionFind<ll> uf(N);\n    vector<bool>\
    \ isinf(N, false);\n    for (int i = 0; i < M; i++) {\n        INT(a, b);\n  \
    \      a--, b--;\n        LL(c);\n        if (uf.issame(a, b) && uf.get_diff(a,\
    \ b) != c) {\n            isinf[a] = true;\n        } else {\n            uf.unite(a,\
    \ b, c);\n        }\n    }\n    for (auto v : uf.groups()) {\n        bool flag\
    \ = false;\n        for (auto x : v) {\n            if (isinf[x]) {\n        \
    \        flag = true;\n                break;\n            }\n        }\n    \
    \    if (flag) {\n            for (auto x : v) isinf[x] = true;\n        }\n \
    \   }\n    for (int i = 0; i < Q; i++) {\n        INT(a, b);\n        a--, b--;\n\
    \        if (!uf.issame(a, b)) {\n            print(\"nan\");\n        }\n   \
    \     elif (isinf[a]) { print(\"inf\"); }\n        else {\n            print(uf.get_diff(a,\
    \ b));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc280/tasks/abc280_f\"\n#include\
    \ \"../../data-structure/weighted-union-find.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    INT(N, M, Q);\n    WeightedUnionFind<ll> uf(N);\n    vector<bool>\
    \ isinf(N, false);\n    for (int i = 0; i < M; i++) {\n        INT(a, b);\n  \
    \      a--, b--;\n        LL(c);\n        if (uf.issame(a, b) && uf.get_diff(a,\
    \ b) != c) {\n            isinf[a] = true;\n        } else {\n            uf.unite(a,\
    \ b, c);\n        }\n    }\n    for (auto v : uf.groups()) {\n        bool flag\
    \ = false;\n        for (auto x : v) {\n            if (isinf[x]) {\n        \
    \        flag = true;\n                break;\n            }\n        }\n    \
    \    if (flag) {\n            for (auto x : v) isinf[x] = true;\n        }\n \
    \   }\n    for (int i = 0; i < Q; i++) {\n        INT(a, b);\n        a--, b--;\n\
    \        if (!uf.issame(a, b)) {\n            print(\"nan\");\n        }\n   \
    \     elif (isinf[a]) { print(\"inf\"); }\n        else {\n            print(uf.get_diff(a,\
    \ b));\n        }\n    }\n}"
  dependsOn:
  - data-structure/weighted-union-find.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/atcoder/abc280_f.test.cpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/atcoder/abc280_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc280_f.test.cpp
- /verify/test/atcoder/abc280_f.test.cpp.html
title: test/atcoder/abc280_f.test.cpp
---
