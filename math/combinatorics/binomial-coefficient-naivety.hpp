long long nCk(int n, int k) {
    assert(n >= k && k >= 0);
    chmin(k, n - k);
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res *= (n - k + i);
        res /= i;
    }
    return res;
}