#include "math/number/miller-rabin.hpp"

long long pollard(long long N) {
    if (N % 2 == 0) return 2;
    if (is_prime(N)) return N;

    auto f = [&](long long x) -> long long {
        return (__int128_t(x) * x + 1) % N;
    };
    long long step = 0;
    while (true) {
        ++step;
        long long x = step, y = f(x);
        while (true) {
            long long p = gcd(y - x + N, N);
            if (p == 0 || p == N) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }
}

vector<long long> solve_for_prime_factorize(long long N) {
    if (N == 1) return {};
    long long p = pollard(N);
    if (p == N) return {p};
    vector<long long> left = solve_for_prime_factorize(p);
    vector<long long> right = solve_for_prime_factorize(N / p);
    left.insert(left.end(), right.begin(), right.end());
    sort(left.begin(), left.end());
    return left;
}

map<long long, int> prime_factorize(long long N) {
    auto res = solve_for_prime_factorize(N);
    map<long long, int> ret;
    for (int i = 0; i < res.size(); i++) {
        ret[res[i]]++;
    }
    return ret;
}