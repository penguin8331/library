template <class T>
struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int modular = fact_[0].getmod();
        for (int i = 2; i < n; i++) {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = -inv_[modular % i] * (modular / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        assert(n < (int)fact_.size() && n >= k && k >= 0);
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr T hom(int n, int k) const noexcept {
        n += k - 1;
        assert(n < (int)fact_.size() && n >= k && k >= 0);
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr T fact(int n) const noexcept {
        assert(n >= 0);
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        assert(n >= 0);
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        assert(n >= 0);
        return finv_[n];
    }
};