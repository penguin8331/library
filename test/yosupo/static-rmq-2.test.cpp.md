---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/disjoint-sparse-table.hpp
    title: Disjoint Sparse Table
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/static-rmq-2.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/staticrmq\"\n#line 1 \"template/template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios() {\n      \
    \  cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout << fixed\
    \ << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename T>\ninline bool\
    \ chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename\
    \ T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false));\
    \ }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int\
    \ dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1,\
    \ -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line\
    \ 1 \"data-structure/disjoint-sparse-table.hpp\"\ntemplate <class SemiGroup>\n\
    struct DisjointSparseTable {\n    using Func = function<SemiGroup(SemiGroup, SemiGroup)>;\n\
    \    const Func F;\n    vector<vector<SemiGroup>> dat;\n    vector<int> height;\n\
    \n    DisjointSparseTable(const Func& f) : F(f) {}\n    DisjointSparseTable(const\
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
    \ ^ b]][a], dat[height[a ^ b]][b]);\n    }\n};\n#line 4 \"test/yosupo/static-rmq-2.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n \
    \   for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    DisjointSparseTable<int>\
    \ dst([](int a, int b) { return min(a, b); }, A);\n    for (int i = 0; i < Q;\
    \ i++) {\n        int l, r;\n        cin >> l >> r;\n        cout << dst.get(l,\
    \ r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    template/template.hpp\"\n#include \"data-structure/disjoint-sparse-table.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n \
    \   for (int i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    DisjointSparseTable<int>\
    \ dst([](int a, int b) { return min(a, b); }, A);\n    for (int i = 0; i < Q;\
    \ i++) {\n        int l, r;\n        cin >> l >> r;\n        cout << dst.get(l,\
    \ r) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/disjoint-sparse-table.hpp
  isVerificationFile: true
  path: test/yosupo/static-rmq-2.test.cpp
  requiredBy: []
  timestamp: '2023-02-27 22:06:25+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static-rmq-2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-rmq-2.test.cpp
- /verify/test/yosupo/static-rmq-2.test.cpp.html
title: test/yosupo/static-rmq-2.test.cpp
---
