template <class Abel>
struct BIT2D {
    const Abel UNITY_SUM = 0;
    vector<vector<Abel> > dat[2][2];

    BIT2D(int n, int m, Abel unity = 0) : UNITY_SUM(unity) {
        init(n, m);
    }
    void init(int n, int m) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                dat[i][j].assign(n + 1, vector<Abel>(m + 1, UNITY_SUM));
    }

    // x1 <= x < x2, y1 <= y < y2, 0-indexed
    inline void subsub_add(int f, int s, int x, int y, Abel v) {
        for (int i = x; i < (int)dat[f][s].size(); i |= i + 1)
            for (int j = y; j < (int)dat[f][s][0].size(); j |= j + 1)
                dat[f][s][i][j] = dat[f][s][i][j] + v;
    }
    inline void sub_add(int x, int y, Abel v) {
        subsub_add(0, 0, x, y, v * x * y);
        subsub_add(1, 0, x, y, -v * x);
        subsub_add(0, 1, x, y, -v * y);
        subsub_add(1, 1, x, y, v);
    }
    inline void add(int x1, int x2, int y1, int y2, Abel v) {
        sub_add(x1, y1, v);
        sub_add(x1, y2, -v);
        sub_add(x2, y1, -v);
        sub_add(x2, y2, v);
    }

    // x1 <= x < x2, y1 <= y < y2, 0-indexed
    inline Abel subsub_sum(int f, int s, int x, int y) {
        Abel res = 0;
        for (int i = x; i > 0; i = (i & (i + 1)) - 1)
            for (int j = y; j > 0; j = (j & (j + 1)) - 1)
                res = res + dat[f][s][i][j];
        return res;
    }
    inline Abel sub_sum(int x, int y) {
        Abel res = 0;
        res += subsub_sum(0, 0, x, y);
        res += subsub_sum(1, 0, x, y) * y;
        res += subsub_sum(0, 1, x, y) * x;
        res += subsub_sum(1, 1, x, y) * x * y;
        return res;
    }
    inline Abel sum(int x1, int x2, int y1, int y2) {
        return sub_sum(x2, y2) - sub_sum(x1, y2) - sub_sum(x2, y1) + sub_sum(x1, y1);
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