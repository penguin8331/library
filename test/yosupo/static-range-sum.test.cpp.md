---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/section-sum.hpp
    title: "\u7D2F\u7A4D\u548C"
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/yosupo/static-range-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n#line 2 \"template/template.hpp\"\
    \n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x),\
    \ std::end(x)\n#define rall(x) std::rbegin(x), std::rend(x)\n#define elif else\
    \ if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a +\
    \ b) * (b - a + 1) / 2)\n#define INT(...)     \\\n    int __VA_ARGS__; \\\n  \
    \  scan(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define STR(...)        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define CHR(...)      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ DOU(...)        \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LD(...)     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug_print.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"algorithm/section-sum.hpp\"\n\r\ntemplate <class T>\r\nstruct\
    \ SectionSum {\r\n    vector<T> data;\r\n\r\n    explicit SectionSum(int n) :\
    \ data(n + 1, 0) {}\r\n\r\n    void update(int k, const T& x) { data[k + 1] =\
    \ x; }\r\n\r\n    void push_back(const T& x) { data.push_back(x); }\r\n\r\n  \
    \  void build() {\r\n        for (int i = 1; i < (int)data.size(); i++) {\r\n\
    \            data[i] += data[i - 1];\r\n        }\r\n    }\r\n\r\n    T get(int\
    \ r) const {\r\n        assert(r >= 0 && r < (int)data.size());\r\n        return\
    \ data[r];\r\n    }\r\n    T get(int l, int r) const { return get(r) - get(l);\
    \ }\r\n};\n#line 4 \"test/yosupo/static-range-sum.test.cpp\"\n\nint main() {\n\
    \    int N, Q;\n    cin >> N >> Q;\n    SectionSum<ll> A(N);\n    for (int i =\
    \ 0; i < N; i++) {\n        int a;\n        cin >> a;\n        A.update(i, a);\n\
    \    }\n    A.build();\n    for (int i = 0; i < Q; i++) {\n        int l, r;\n\
    \        cin >> l >> r;\n        cout << A.get(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../algorithm/section-sum.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    SectionSum<ll> A(N);\n\
    \    for (int i = 0; i < N; i++) {\n        int a;\n        cin >> a;\n      \
    \  A.update(i, a);\n    }\n    A.build();\n    for (int i = 0; i < Q; i++) {\n\
    \        int l, r;\n        cin >> l >> r;\n        cout << A.get(l, r) << endl;\n\
    \    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - algorithm/section-sum.hpp
  isVerificationFile: true
  path: test/yosupo/static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2023-07-12 18:18:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-range-sum.test.cpp
- /verify/test/yosupo/static-range-sum.test.cpp.html
title: test/yosupo/static-range-sum.test.cpp
---
