---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rolling-hash.hpp\"\nstruct RollingHash {\n    static\
    \ const uint64_t mod = (1ull << 61ull) - 1;\n    vector<uint64_t> power, hash;\n\
    \    const uint64_t base;\n \n    static inline uint64_t generate_base() {\n \
    \       mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand((uint64_t)1, (uint64_t)mod -\
    \ 1);\n        return rand(engine);\n    }\n \n    static inline uint64_t add(uint64_t\
    \ a, uint64_t b) {\n        if ((a += b) >= mod) a -= mod;\n        return a;\n\
    \    }\n \n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n \n \
    \   RollingHash(const string& S, uint64_t base_ = generate_base()) : base(base_)\
    \ {\n        int n = (int)S.size();\n        hash.assign(n + 1, 0);\n        power.assign(n\
    \ + 1, 1);\n        for (int i = 0; i < n; ++i) {\n            hash[i + 1] = add(mul(hash[i],\
    \ base), S[i]);\n            power[i + 1] = mul(power[i], base);\n        }\n\
    \    }\n \n    // hash\u306E[l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8FD4\
    \u3059\n    inline uint64_t get(int l, int r) const {\n        return add(hash[r],\
    \ mod - mul(hash[l], power[r - l]));\n    }\n \n    // get lcp of S[a:] and S[b:]\n\
    \    inline int getLCP(int a, int b) const {\n        int len = min((int)hash.size()\
    \ - a, (int)hash.size() - b);\n        int low = 0, high = len;\n        while\
    \ (high - low > 1) {\n            int mid = (low + high) >> 1;\n            if\
    \ (get(a, a + mid) != get(b, b + mid))\n                high = mid;\n        \
    \    else\n                low = mid;\n        }\n        return low;\n    }\n\
    };\n"
  code: "struct RollingHash {\n    static const uint64_t mod = (1ull << 61ull) - 1;\n\
    \    vector<uint64_t> power, hash;\n    const uint64_t base;\n \n    static inline\
    \ uint64_t generate_base() {\n        mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<uint64_t> rand((uint64_t)1, (uint64_t)mod -\
    \ 1);\n        return rand(engine);\n    }\n \n    static inline uint64_t add(uint64_t\
    \ a, uint64_t b) {\n        if ((a += b) >= mod) a -= mod;\n        return a;\n\
    \    }\n \n    static inline uint64_t mul(uint64_t a, uint64_t b) {\n        __uint128_t\
    \ c = (__uint128_t)a * b;\n        return add(c >> 61, c & mod);\n    }\n \n \
    \   RollingHash(const string& S, uint64_t base_ = generate_base()) : base(base_)\
    \ {\n        int n = (int)S.size();\n        hash.assign(n + 1, 0);\n        power.assign(n\
    \ + 1, 1);\n        for (int i = 0; i < n; ++i) {\n            hash[i + 1] = add(mul(hash[i],\
    \ base), S[i]);\n            power[i + 1] = mul(power[i], base);\n        }\n\
    \    }\n \n    // hash\u306E[l,r)\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u3092\u8FD4\
    \u3059\n    inline uint64_t get(int l, int r) const {\n        return add(hash[r],\
    \ mod - mul(hash[l], power[r - l]));\n    }\n \n    // get lcp of S[a:] and S[b:]\n\
    \    inline int getLCP(int a, int b) const {\n        int len = min((int)hash.size()\
    \ - a, (int)hash.size() - b);\n        int low = 0, high = len;\n        while\
    \ (high - low > 1) {\n            int mid = (low + high) >> 1;\n            if\
    \ (get(a, a + mid) != get(b, b + mid))\n                high = mid;\n        \
    \    else\n                low = mid;\n        }\n        return low;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-01-08 14:46:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash.hpp
layout: document
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
---
