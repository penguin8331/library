---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/disjoint-sparse-table.hpp
    title: Disjoint Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static-range-sum-2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\n\n#define overload3(_1,\
    \ _2, _3, name, ...) name\n#define all1(v) std::begin(v), std::end(v)\n#define\
    \ all2(v, a) std::begin(v), std::begin(v) + a\n#define all3(v, a, b) std::begin(v)\
    \ + a, std::begin(v) + b\n#define all(...) overload3(__VA_ARGS__, all3, all2,\
    \ all1)(__VA_ARGS__)\n#define rall1(v) std::rbegin(v), std::rend(v)\n#define rall2(v,\
    \ a) std::rbegin(v), std::rbegin(v) + a\n#define rall3(v, a, b) std::rbegin(v)\
    \ + a, std::rbegin(v) + b\n#define rall(...) overload3(__VA_ARGS__, rall3, rall2,\
    \ rall1)(__VA_ARGS__)\n#define elif else if\n#define updiv(N, X) (((N) + (X) -\
    \ 1) / (X))\n#define sigma(a, b) (((a) + (b)) * ((b) - (a) + 1) / 2)\n#define\
    \ INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LL(...)\
    \     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)    \
    \    \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...) \
    \     \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...)  \
    \      \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
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
    \ std;\n#line 3 \"data-structure/disjoint-sparse-table.hpp\"\n\ntemplate <class\
    \ SemiGroup>\nstruct DisjointSparseTable {\n    using Func = function<SemiGroup(SemiGroup,\
    \ SemiGroup)>;\n    const Func F;\n    vector<vector<SemiGroup>> dat;\n    vector<int>\
    \ height;\n\n    explicit DisjointSparseTable(const Func& f) : F(f) {}\n    DisjointSparseTable(const\
    \ Func& f, const vector<SemiGroup>& vec) : F(f) { init(vec); }\n    void init(const\
    \ vector<SemiGroup>& vec) {\n        int n = (int)vec.size(), h = 1;\n       \
    \ while ((1 << h) <= n) ++h;\n        dat.assign(h, vector<SemiGroup>(n));\n \
    \       height.assign((1 << h), 0);\n        for (int i = 2; i < (1 << h); i++)\
    \ height[i] = height[i >> 1] + 1;\n        for (int i = 0; i < n; ++i) dat[0][i]\
    \ = vec[i];\n        for (int i = 1; i < h; ++i) {\n            int s = (1 <<\
    \ i);\n            for (int j = 0; j < n; j += (s << 1)) {\n                int\
    \ t = min(j + s, n);\n                dat[i][t - 1] = vec[t - 1];\n          \
    \      for (int k = t - 2; k >= j; --k) dat[i][k] = F(vec[k], dat[i][k + 1]);\n\
    \                if (n <= t) break;\n                dat[i][t] = vec[t];\n   \
    \             for (int k = t + 1; k < min(t + s, n); ++k) dat[i][k] = F(dat[i][k\
    \ - 1], vec[k]);\n            }\n        }\n    }\n    SemiGroup get(int a, int\
    \ b) {\n        if (a >= --b) return dat[0][a];\n        return F(dat[height[a\
    \ ^ b]][a], dat[height[a ^ b]][b]);\n    }\n};\n#line 4 \"test/yosupo/static-range-sum-2.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> A(N);\n  \
    \  for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    DisjointSparseTable<ll>\
    \ dst([](ll a, ll b) { return a + b; }, A);\n    for (int i = 0; i < Q; i++) {\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << dst.get(l, r) << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"../../data-structure/disjoint-sparse-table.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> A(N);\n  \
    \  for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    DisjointSparseTable<ll>\
    \ dst([](ll a, ll b) { return a + b; }, A);\n    for (int i = 0; i < Q; i++) {\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << dst.get(l, r) << endl;\n\
    \    }\n}"
  dependsOn:
  - data-structure/disjoint-sparse-table.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/yosupo/static-range-sum-2.test.cpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static-range-sum-2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-range-sum-2.test.cpp
- /verify/test/yosupo/static-range-sum-2.test.cpp.html
title: test/yosupo/static-range-sum-2.test.cpp
---
