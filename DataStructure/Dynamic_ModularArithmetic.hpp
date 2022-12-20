template <int IND = 0>
struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MODS[IND]) {
        if (val < 0) val += MODS[IND];
    }
    constexpr int getmod() const { return MODS[IND]; }
    constexpr Fp operator-() const noexcept {
        return val ? MODS[IND] - val : 0;
    }
    constexpr Fp operator+(const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator-(const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator*(const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator/(const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator+=(const Fp& r) noexcept {
        val += r.val;
        if (val >= MODS[IND]) val -= MODS[IND];
        return *this;
    }
    constexpr Fp& operator-=(const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MODS[IND];
        return *this;
    }
    constexpr Fp& operator*=(const Fp& r) noexcept {
        val = val * r.val % MODS[IND];
        return *this;
    }
    constexpr Fp& operator/=(const Fp& r) noexcept {
        long long a = r.val, b = MODS[IND], u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            swap(a, b);
            u -= t * v;
            swap(u, v);
        }
        val = val * u % MODS[IND];
        if (val < 0) val += MODS[IND];
        return *this;
    }
    constexpr bool operator==(const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator!=(const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr istream& operator>>(istream& is, Fp<IND>& x) noexcept {
        is >> x.val;
        x.val %= MODS[IND];
        if (x.val < 0) x.val += MODS[IND];
        return is;
    }
    friend constexpr ostream& operator<<(ostream& os, const Fp<IND>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<IND> modpow(const Fp<IND>& r, long long n) noexcept {
        if (n == 0) return 1;
        if (n < 0) return modpow(modinv(r), -n);
        auto t = modpow(r, n / 2);
        t = t * t;
        if (n & 1) t = t * r;
        return t;
    }
    friend constexpr Fp<IND> modinv(const Fp<IND>& r) noexcept {
        long long a = r.val, b = MODS[IND], u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        return Fp<IND>(u);
    }
};