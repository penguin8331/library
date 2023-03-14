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
    \n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\n\n#define pb push_back\n\
    #define mp make_pair\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n\
    #define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\
    \n\nusing ll = long long;\nusing ld = long double;\nusing pii = std::pair<int,\
    \ int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr\
    \ ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr\
    \ int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr\
    \ int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n   \
    \ IOSetup() {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/disjoint-sparse-table.hpp\"\n\ntemplate <class\
    \ SemiGroup>\nstruct DisjointSparseTable {\n    using Func = function<SemiGroup(SemiGroup,\
    \ SemiGroup)>;\n    const Func F;\n    vector<vector<SemiGroup>> dat;\n    vector<int>\
    \ height;\n\n    DisjointSparseTable(const Func& f) : F(f) {}\n    DisjointSparseTable(const\
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
    \ \"../../template/template.hpp\"\n#include \"../../data-structure/disjoint-sparse-table.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> A(N);\n  \
    \  for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    DisjointSparseTable<ll>\
    \ dst([](ll a, ll b) { return a + b; }, A);\n    for (int i = 0; i < Q; i++) {\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << dst.get(l, r) << endl;\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/disjoint-sparse-table.hpp
  isVerificationFile: true
  path: test/yosupo/static-range-sum-2.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 23:16:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static-range-sum-2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-range-sum-2.test.cpp
- /verify/test/yosupo/static-range-sum-2.test.cpp.html
title: test/yosupo/static-range-sum-2.test.cpp
---
