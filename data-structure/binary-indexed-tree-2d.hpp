template <class Abel>
struct BIT2D {
    const Abel UNITY_SUM = 0;
    vector<vector<Abel>> dat;

    // [0, n) x [0, m)
    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity),
                                          dat(n, vector<Abel>(m, UNITY_SUM)) {}
    void init(int n, int m) {
        dat.assign(n, vector<Abel>(m, UNITY_SUM));
    }

    // add x on the point (a, b)
    inline void add(int a, int b, Abel x) {
        for (int i = a; i < (int)dat.size(); i |= i + 1)
            for (int j = b; j < (int)dat[0].size(); j |= j + 1)
                dat[i][j] = dat[i][j] + x;
    }

    // [0, p) x [0, q), 0-indexed
    inline Abel sum(int p, int q) {
        Abel res = UNITY_SUM;
        for (int i = p - 1; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = q - 1; j >= 0; j = (j & (j + 1)) - 1)
                res = res + dat[i][j];
        return res;
    }

    // x1 <= x < x2, y1 <= y < y2, 0-indexed
    inline Abel sum(int x1, int x2, int y1, int y2) {
        return sum(x2, y2) - sum(x1, y2) - sum(x2, y1) + sum(x1, y1);
    }

    // debug
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) {
            for (int j = 1; j < (int)dat[0].size(); ++j)
                cout << sum(i, j, i + 1, j + 1) << ",";
            cout << endl;
        }
    }
};