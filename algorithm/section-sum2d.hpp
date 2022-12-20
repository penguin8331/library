template <class T>
vector<vector<T>> pre_process(vector<vector<T>> const &a) {
    int H = (int)a.size();
    int W = (int)a[0].size();
    vector<vector<T>> res(H + 1, vector<T>(W + 1));
    for (int h = 1; h < H + 1; h++) {
        for (int w = 1; w < W + 1; w++) {
            res[h][w] = a[h - 1][w - 1] + res[h][w - 1] + res[h - 1][w] - res[h - 1][w - 1];
        }
    }
    return res;
}
// [h1,h2)×[w1,w2) の区間和を求める
template <class T>
T query(int h1, int h2, int w1, int w2, vector<vector<T>> const &S) {
    return S[h2][w2] - S[h1][w2] - S[h2][w1] + S[h1][w1];
}