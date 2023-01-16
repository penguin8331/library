template <class Monoid>
struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    int N;
    Func F;
    Monoid IDENTITY;
    int SIZE_R;
    vector<Monoid> dat;

    /* initialization */
    SegTree() {}
    SegTree(int n, const Func f, const Monoid& identity)
        : N(n), F(f), IDENTITY(identity) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, IDENTITY);
    }
    void init(int n, const Func f, const Monoid& identity) {
        N = n;
        F = f;
        IDENTITY = identity;
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, IDENTITY);
    }

    /* set, a is 0-indexed */
    /* build(): O(N) */
    void set(int a, const Monoid& v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    /* update a, a is 0-indexed, O(log N) */
    void update(int a, const Monoid& v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    /* get [a, b), a and b are 0-indexed, O(log N) */
    Monoid get(int a, int b) {
        Monoid vleft = IDENTITY, vright = IDENTITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right;
             left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    Monoid all_get() { return dat[1]; }
    Monoid operator[](int a) { return dat[a + SIZE_R]; }

    /* get max r that f(get(l, r)) = True (0-indexed), O(log N) */
    /* f(IDENTITY) need to be True */
    int max_right(const function<bool(Monoid)> f, int l = 0) {
        if (l == N) return N;
        l += SIZE_R;
        Monoid sum = IDENTITY;
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(F(sum, dat[l]))) {
                while (l < SIZE_R) {
                    l = l * 2;
                    if (f(F(sum, dat[l]))) {
                        sum = F(sum, dat[l]);
                        ++l;
                    }
                }
                return l - SIZE_R;
            }
            sum = F(sum, dat[l]);
            ++l;
        } while ((l & -l) != l);  // stop if l = 2^e
        return N;
    }

    /* get min l that f(get(l, r)) = True (0-indexed), O(log N) */
    /* f(IDENTITY) need to be True */
    int min_left(const function<bool(Monoid)> f, int r = -1) {
        if (r == 0) return 0;
        if (r == -1) r = N;
        r += SIZE_R;
        Monoid sum = IDENTITY;
        do {
            --r;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(F(dat[r], sum))) {
                while (r < SIZE_R) {
                    r = r * 2 + 1;
                    if (f(F(dat[r], sum))) {
                        sum = F(dat[r], sum);
                        --r;
                    }
                }
                return r + 1 - SIZE_R;
            }
            sum = F(dat[r], sum);
        } while ((r & -r) != r);
        return 0;
    }

    friend ostream& operator<<(ostream& os, SegTree seg) {
        os << "[ ";
        for (int i = 0; i < seg.N; i++) {
            os << seg.get(i, i + 1) << " ";
        }
        os << ']';
        return os;
    }
};