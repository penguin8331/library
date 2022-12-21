struct doubling {
    vector<int> A;
    vector<vector<int>> table;
    int SIZE;
    int logK = 1;
    doubling(vector<int> a, int max) : A(a) {
        SIZE = A.size();
        while ((1LL << logK) <= max) logK++;
        table.assign(logK, vector<int>(SIZE));
        for (int k = 0; k < logK - 1; k++) {
            for (int i = 0; i < SIZE; i++) {
                table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }
    int get(int a, int b) {
        int now = a;
        for (int k = 0; b > 0; k++) {
            if (b & 1) now = table[k][now];
            b = b >> 1;
        }
        return now;
    }
};