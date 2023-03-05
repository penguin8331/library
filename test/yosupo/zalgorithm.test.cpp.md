---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
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
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define pb push_back\n#define mp make_pair\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ld = long double;\n\
    using pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int\
    \ inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1,\
    \ 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr\
    \ int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\
    \n\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a\
    \ = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b)\
    \ { return ((a > b) ? (a = b, true) : (false)); }\n#line 3 \"template/util.hpp\"\
    \n\nstruct IOSetup {\n    IOSetup() {\n        std::cin.tie(nullptr);\n      \
    \  std::ios::sync_with_stdio(false);\n        std::cout.tie(0);\n        std::cout\
    \ << std::fixed << std::setprecision(12);\n        std::cerr << std::fixed <<\
    \ std::setprecision(12);\n    }\n} IOSetup;\n#line 1 \"template/debug.hpp\"\n\
    #ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n#define debug(...)\n#define line\n\
    #endif\n#line 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"string/rolling-hash.hpp\"\
    \n\nstruct RollingHash {\n    static const uint64_t mod = (1ull << 61ull) - 1;\n\
    \    vector<uint64_t> power;\n    const uint64_t base;\n\n    static inline uint64_t\
    \ generate_base() {\n        mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand((uint64_t)1, (uint64_t)mod -\
    \ 1);\n        return rand(engine);\n    }\n\n    static inline uint64_t add(uint64_t\
    \ a, uint64_t b) {\n        if ((a += b) >= mod) a -= mod;\n        return a;\n\
    \    }\n\n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n\n  \
    \  inline void expand(size_t sz) {\n        if (power.size() < sz + 1) {\n   \
    \         int pre_sz = (int)power.size();\n            power.resize(sz + 1);\n\
    \            for (int i = pre_sz - 1; i < sz; i++) {\n                power[i\
    \ + 1] = mul(power[i], base);\n            }\n        }\n    }\n\n    explicit\
    \ RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}\n\n \
    \   // \u6587\u5B57\u5217S\u306E\u30CF\u30C3\u30B7\u30E5\u3092\u8FD4\u3059\n \
    \   vector<uint64_t> build(string S) {\n        vector<uint64_t> hash(S.size()\
    \ + 1);\n        for (int i = 0; i < S.size(); i++) {\n            hash[i + 1]\
    \ = add(mul(hash[i], base), S[i]);\n        }\n        return hash;\n    }\n\n\
    \    // hash\u306E[l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8FD4\u3059\n\
    \    uint64_t query(vector<uint64_t>& hash, int l, int r) {\n        expand(r\
    \ - l);\n        return add(hash[r], mod - mul(hash[l], power[r - l]));\n    }\n\
    \n    // \u30CF\u30C3\u30B7\u30E5\u5024h1\u3068\u9577\u3055h2len\u306E\u30CF\u30C3\
    \u30B7\u30E5\u5024h2\u3092\u7D50\u5408\n    uint64_t combine(uint64_t h1, uint64_t\
    \ h2, size_t h2len) {\n        expand(h2len);\n        return add(mul(h1, power[h2len]),\
    \ h2);\n    }\n\n    // hash1\u306E\u533A\u9593[l1,r1)\u3068hash2\u306E\u533A\u9593\
    [l2,r2)\u306Elcp(\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E)\u306E\u9577\u3055\
    \u3092\u8FD4\u3059 (\u4E8C\u90E8\u63A2\u7D22\u3092\u7528\u3044\u308B)\n    int\
    \ lcp(vector<uint64_t>& hash1, int l1, int r1, vector<uint64_t>& hash2, int l2,\
    \ int r2) {\n        int len = min(r1 - l1, r2 - l2);\n        int ok = 0;\n \
    \       int ng = len + 1;\n        int mid;\n        while (ng - ok > 1) {\n \
    \           mid = (ok + ng) / 2;\n            if (query(hash1, l1, l1 + mid) ==\
    \ query(hash2, l2, l2 + mid))\n                ok = mid;\n            else\n \
    \               ng = mid;\n        }\n        return ok;\n    }\n};\n#line 4 \"\
    test/yosupo/zalgorithm.test.cpp\"\n\nint main() {\n    string S;\n    cin >> S;\n\
    \    RollingHash rh;\n    auto res = rh.build(S);\n    int N = S.size();\n   \
    \ cout << N;\n    for (int i = 1; i < N; i++) {\n        cout << \" \" << rh.lcp(res,\
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
  timestamp: '2023-03-05 09:55:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/zalgorithm.test.cpp
- /verify/test/yosupo/zalgorithm.test.cpp.html
title: test/yosupo/zalgorithm.test.cpp
---
