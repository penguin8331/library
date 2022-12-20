template <class T>
vector<T> pre_process(vector<T> const &a) {
    int n = (int)a.size();
    vector<T> res(n + 1);
    for (int i = 0; i < n; i++) {
        res[i + 1] = res[i] + a[i];
    }
    return res;
}

// [i,j) の区間和を求める
template <class T>
T query(int i, int j, vector<T> const &S) {
    return S[j] - S[i];
}