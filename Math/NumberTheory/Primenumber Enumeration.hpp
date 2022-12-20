vector<int> Era(int n) {
    vector<bool> isprime(n, true);
    vector<int> res;
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i < n; ++i) isprime[i] = true;
    for (int i = 2; i < n; ++i) {
        if (isprime[i]) {
            res.push_back(i);
            for (int j = i * 2; j < n; j += i) isprime[j] = false;
        }
    }
    return res;
}