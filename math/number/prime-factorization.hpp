map<long long, int> prime_factorize(long long n) {
    map<long long, int> res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) {
            ++num;
            n /= p;
        }
        res[p] = num;
    }
    if (n != 1) res[n] = 1;
    return res;
}