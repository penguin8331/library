---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/section-sum.hpp
    title: "\u7D2F\u7A4D\u548C"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
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
  bundledCode: "#line 1 \"test/yosupo/static-range-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 1 \"template/template.hpp\"\
    \n// #pragma GCC target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma\
    \ GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\nusing ld = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n#define pb push_back\n#define mp make_pair\n#define\
    \ mt make_tuple\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) ((N + X - 1) / X)\n#define\
    \ sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios() {\n\
    \        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n        cout\
    \ << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL <<\
    \ 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[] =\
    \ {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 1 \"algorithm/section-sum.hpp\"\ntemplate <class T>\r\n\
    struct sectionsum {\r\n    vector<T> data;\r\n\r\n    sectionsum(int n) : data(n\
    \ + 1, 0) {}\r\n\r\n    void update(int k, const T& x) {\r\n        data[k + 1]\
    \ = x;\r\n    }\r\n\r\n    void build() {\r\n        for (int i = 1; i < (int)data.size();\
    \ i++) {\r\n            data[i] += data[i - 1];\r\n        }\r\n    }\r\n\r\n\
    \    T get(int r) const {\r\n        assert(r >= 0 && r < (int)data.size());\r\
    \n        return data[r];\r\n    }\r\n    T get(int l, int r) const {\r\n    \
    \    return get(r) - get(l);\r\n    }\r\n};\n#line 4 \"test/yosupo/static-range-sum.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    sectionsum<ll> A(N);\n\
    \    for (int i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n      \
    \  A.update(i, a);\n    }\n    A.build();\n    for (int i = 0; i < Q; i++) {\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << A.get(l, r) << endl;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"template/template.hpp\"\n#include \"algorithm/section-sum.hpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    sectionsum<ll> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n        A.update(i,\
    \ a);\n    }\n    A.build();\n    for (int i = 0; i < Q; i++) {\n        int l,\
    \ r;\n        cin >> l >> r;\n        cout << A.get(l, r) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - algorithm/section-sum.hpp
  isVerificationFile: true
  path: test/yosupo/static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-09 19:53:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-range-sum.test.cpp
- /verify/test/yosupo/static-range-sum.test.cpp.html
title: test/yosupo/static-range-sum.test.cpp
---
