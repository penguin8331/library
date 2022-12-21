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

    // debug
    void print() {
#ifdef LOCAL
        for (int i = 0; i < (int)dat.size(); ++i)
            cout << sum(i, i + 1) << ",";
        cout << endl;
#endif
    }
};