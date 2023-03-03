---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: algorithm/section-sum.hpp
    title: "\u7D2F\u7A4D\u548C"
  - icon: ':x:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':x:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':x:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':x:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':x:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static-range-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\n\n#define pb push_back\n\
    #define mp make_pair\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(),\
    \ (x).rend()\n#define elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n\
    #define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\
    \n\nusing ll = long long;\nusing ld = long double;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"algorithm/section-sum.hpp\"\
    \n\r\ntemplate <class T>\r\nstruct sectionsum {\r\n    vector<T> data;\r\n\r\n\
    \    sectionsum(int n) : data(n + 1, 0) {}\r\n\r\n    void update(int k, const\
    \ T& x) {\r\n        data[k + 1] = x;\r\n    }\r\n\r\n    void build() {\r\n \
    \       for (int i = 1; i < (int)data.size(); i++) {\r\n            data[i] +=\
    \ data[i - 1];\r\n        }\r\n    }\r\n\r\n    T get(int r) const {\r\n     \
    \   assert(r >= 0 && r < (int)data.size());\r\n        return data[r];\r\n   \
    \ }\r\n    T get(int l, int r) const {\r\n        return get(r) - get(l);\r\n\
    \    }\r\n};\n#line 4 \"test/yosupo/static-range-sum.test.cpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    sectionsum<ll> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n        A.update(i,\
    \ a);\n    }\n    A.build();\n    for (int i = 0; i < Q; i++) {\n        int l,\
    \ r;\n        cin >> l >> r;\n        cout << A.get(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"template/template.hpp\"\n#include \"algorithm/section-sum.hpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    sectionsum<ll> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n        A.update(i,\
    \ a);\n    }\n    A.build();\n    for (int i = 0; i < Q; i++) {\n        int l,\
    \ r;\n        cin >> l >> r;\n        cout << A.get(l, r) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - algorithm/section-sum.hpp
  isVerificationFile: true
  path: test/yosupo/static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2023-03-03 14:53:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-range-sum.test.cpp
- /verify/test/yosupo/static-range-sum.test.cpp.html
title: test/yosupo/static-range-sum.test.cpp
---
