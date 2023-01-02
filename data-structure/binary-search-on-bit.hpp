template <class Abel>
struct BIT {
    Abel UNITY_SUM = 0;
    vector<Abel> dat;

    // [0, n)
    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) {}
    void init(int n) {
        dat.assign(n, UNITY_SUM);
    }

    // a is 0-indexed
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i |= i + 1)
            dat[i] = dat[i] + x;
    }

    // [0, a), a is 0-indexed
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)
            res = res + dat[i];
        return res;
    }

    // [a, b), a and b are 0-indexed
    inline Abel sum(int a, int b) {
        return sum(b) - sum(a);
    }

    // k-th number (k is 0-indexed)
    int get(long long k) {
        ++k;
        int res = 0;
        int N = 1;
        while (N < (int)dat.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i - 1 < (int)dat.size() && dat[res + i - 1] < k) {
                k = k - dat[res + i - 1];
                res = res + i;
            }
        }
        return res;
    }

    // debug
    void print() {
        for (int i = 0; i < (int)dat.size(); ++i)
            cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};