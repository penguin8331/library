long long nCk(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res *= (n - k + i) / i;
    }
    return res;
}