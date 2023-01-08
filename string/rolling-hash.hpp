struct RollingHash {
    static const uint64_t mod = (1ull << 61ull) - 1;
    vector<uint64_t> power, hash;
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
 
    RollingHash(const string& S, uint64_t base_ = generate_base()) : base(base_) {
        int n = (int)S.size();
        hash.assign(n + 1, 0);
        power.assign(n + 1, 1);
        for (int i = 0; i < n; ++i) {
            hash[i + 1] = add(mul(hash[i], base), S[i]);
            power[i + 1] = mul(power[i], base);
        }
    }
 
    // hashの[l,r)のハッシュ値を返す
    inline uint64_t get(int l, int r) const {
        return add(hash[r], mod - mul(hash[l], power[r - l]));
    }
 
    // get lcp of S[a:] and S[b:]
    inline int getLCP(int a, int b) const {
        int len = min((int)hash.size() - a, (int)hash.size() - b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a + mid) != get(b, b + mid))
                high = mid;
            else
                low = mid;
        }
        return low;
    }
};