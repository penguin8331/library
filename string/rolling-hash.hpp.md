---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling-hash.hpp\"\nstruct RollingHash {\n    static\
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
    \               ng = mid;\n        }\n        return ok;\n    }\n};\n"
  code: "struct RollingHash {\n    static const uint64_t mod = (1ull << 61ull) - 1;\n\
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
    \               ng = mid;\n        }\n        return ok;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-01-08 17:07:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/zalgorithm.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---

## 使い方

- `build(S)` : 文字列Sのハッシュを返す
- `query(hash,l,r)` : hashを用いて[l,r)のハッシュ値を求める
- `combine(h1,h2,h2len)` : ハッシュ値h1とハッシュ値h2のものを連結する
- `lcp(hash1,l,r,hash2,l,r)` : hash1の[l,r)とhash2の[l,r)の最長共通接頭辞の長さを返す (二分探索を用いる)