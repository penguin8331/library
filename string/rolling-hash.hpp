#pragma once
#include "../template/template.hpp"

struct RollingHash {
    static const uint64_t mod = (1ull << 61ull) - 1;
    vector<uint64_t> power;
    const uint64_t base;

    static inline uint64_t generate_base() {
        mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<uint64_t> rand((uint64_t)1, (uint64_t)mod - 1);
        return rand(engine);
    }

    static inline uint64_t add(uint64_t a, uint64_t b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline uint64_t mul(uint64_t a, uint64_t b) {
        __uint128_t c = (__uint128_t)a * b;
        return add(c >> 61, c & mod);
    }

    inline void expand(size_t sz) {
        if (power.size() < sz + 1) {
            int pre_sz = (int)power.size();
            power.resize(sz + 1);
            for (int i = pre_sz - 1; i < (int)sz; i++) {
                power[i + 1] = mul(power[i], base);
            }
        }
    }

    explicit RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}

    // 文字列Sのハッシュを返す
    vector<uint64_t> build(string S) {
        vector<uint64_t> hash(S.size() + 1);
        for (int i = 0; i < (int)S.size(); i++) {
            hash[i + 1] = add(mul(hash[i], base), S[i]);
        }
        return hash;
    }

    // hashの[l,r)のハッシュ値を返す
    uint64_t query(vector<uint64_t>& hash, int l, int r) {
        expand(r - l);
        return add(hash[r], mod - mul(hash[l], power[r - l]));
    }

    // ハッシュ値h1と長さh2lenのハッシュ値h2を結合
    uint64_t combine(uint64_t h1, uint64_t h2, size_t h2len) {
        expand(h2len);
        return add(mul(h1, power[h2len]), h2);
    }

    // hash1の区間[l1,r1)とhash2の区間[l2,r2)のlcp(最長共通接頭辞)の長さを返す (二部探索を用いる)
    int lcp(vector<uint64_t>& hash1, int l1, int r1, vector<uint64_t>& hash2, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2);
        int ok = 0;
        int ng = len + 1;
        int mid;
        while (ng - ok > 1) {
            mid = (ok + ng) / 2;
            if (query(hash1, l1, l1 + mid) == query(hash2, l2, l2 + mid))
                ok = mid;
            else
                ng = mid;
        }
        return ok;
    }
};