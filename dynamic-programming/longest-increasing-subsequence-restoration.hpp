template <class T>
vector<T> LISRestoration(vector<T> a, bool is_strong = true) {
    int n = (int)a.size();
    vector<T> dp;
    vector<int> positions;
    for (int i = 0; i < n; ++i) {
        auto it = (is_strong ? lower_bound(dp.begin(), dp.end(), a[i]) : upper_bound(dp.begin(), dp.end(), a[i]));
        positions.push_back(distance(dp.begin(), it));
        if (it == dp.end())
            dp.push_back(a[i]);
        else
            *it = a[i];
    }
    vector<T> subseq(dp.size());
    int si = ((int)subseq.size()) - 1;
    int pi = ((int)positions.size()) - 1;
    while ((0 <= si) && (0 <= pi)) {
        if (positions[pi] == si) {
            subseq[si] = pi;
            --si;
        }
        --pi;
    }
    return subseq;
}