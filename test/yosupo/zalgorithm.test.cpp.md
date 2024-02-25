---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
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
    \ std;\n#line 3 \"string/rolling-hash.hpp\"\n\nstruct RollingHash {\n    static\
    \ const uint64_t mod = (1ull << 61ull) - 1;\n    vector<uint64_t> power;\n   \
    \ const uint64_t base;\n\n    static inline uint64_t generate_base() {\n     \
    \   mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand((uint64_t)1, (uint64_t)mod -\
    \ 1);\n        return rand(engine);\n    }\n\n    static inline uint64_t add(uint64_t\
    \ a, uint64_t b) {\n        if ((a += b) >= mod) a -= mod;\n        return a;\n\
    \    }\n\n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n  \
    \  inline void expand(size_t sz) {\n        if (power.size() < sz + 1) {\n   \
    \         int pre_sz = (int)power.size();\n            power.resize(sz + 1);\n\
    \            for (int i = pre_sz - 1; i < (int)sz; i++) {\n                power[i\
    \ + 1] = mul(power[i], base);\n            }\n        }\n    }\n\n    explicit\
    \ RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}\n\n \
    \   vector<uint64_t> build(string S) {\n        vector<uint64_t> hash(S.size()\
    \ + 1);\n        for (int i = 0; i < (int)S.size(); i++) {\n            hash[i\
    \ + 1] = add(mul(hash[i], base), S[i]);\n        }\n        return hash;\n   \
    \ }\n\n    uint64_t query(const vector<uint64_t>& hash, int l, int r) {\n    \
    \    expand(r - l);\n        return add(hash[r], mod - mul(hash[l], power[r -\
    \ l]));\n    }\n\n    uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len)\
    \ {\n        expand(h2len);\n        return add(mul(h1, power[h2len]), h2);\n\
    \    }\n\n    int lcp(const vector<uint64_t>& hash1, int l1, int r1, const vector<uint64_t>&\
    \ hash2, int l2, int r2) {\n        int len = min(r1 - l1, r2 - l2);\n       \
    \ int ok = 0;\n        int ng = len + 1;\n        while (ng - ok > 1) {\n    \
    \        int mid = (ok + ng) / 2;\n            if (query(hash1, l1, l1 + mid)\
    \ == query(hash2, l2, l2 + mid))\n                ok = mid;\n            else\n\
    \                ng = mid;\n        }\n        return ok;\n    }\n};\n#line 4\
    \ \"test/yosupo/zalgorithm.test.cpp\"\n\nint main() {\n    string S;\n    cin\
    \ >> S;\n    RollingHash rh;\n    auto res = rh.build(S);\n    int N = S.size();\n\
    \    cout << N;\n    for (int i = 1; i < N; i++) {\n        cout << \" \" << rh.lcp(res,\
    \ i, N, res, 0, N);\n    }\n    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n#include\
    \ \"../../template/template.hpp\"\n#include \"../../string/rolling-hash.hpp\"\n\
    \nint main() {\n    string S;\n    cin >> S;\n    RollingHash rh;\n    auto res\
    \ = rh.build(S);\n    int N = S.size();\n    cout << N;\n    for (int i = 1; i\
    \ < N; i++) {\n        cout << \" \" << rh.lcp(res, i, N, res, 0, N);\n    }\n\
    \    cout << endl;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - string/rolling-hash.hpp
  isVerificationFile: true
  path: test/yosupo/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2024-02-25 20:07:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/zalgorithm.test.cpp
- /verify/test/yosupo/zalgorithm.test.cpp.html
title: test/yosupo/zalgorithm.test.cpp
---
