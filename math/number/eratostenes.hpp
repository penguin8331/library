#pragma once
#include "../../template/template.hpp"

struct Eratos {
    vector<int> primes;
    vector<bool> isprime;
    vector<int> mebius;
    vector<int> min_factor;

    explicit Eratos(int MAX) : primes(),
                      isprime(MAX + 1, true),
                      mebius(MAX + 1, 1),
                      min_factor(MAX + 1, -1) {
        isprime[0] = isprime[1] = false;
        min_factor[0] = 0, min_factor[1] = 1;
        for (int i = 2; i <= MAX; ++i) {
            if (!isprime[i]) continue;
            primes.push_back(i);
            mebius[i] = -1;
            min_factor[i] = i;
            for (int j = i * 2; j <= MAX; j += i) {
                isprime[j] = false;
                if ((j / i) % i == 0)
                    mebius[j] = 0;
                else
                    mebius[j] = -mebius[j];
                if (min_factor[j] == -1) min_factor[j] = i;
            }
        }
    }

    vector<pair<int, int>> prime_factors(int n) {
        vector<pair<int, int>> res;
        while (n != 1) {
            int prime = min_factor[n];
            int exp = 0;
            while (min_factor[n] == prime) {
                ++exp;
                n /= prime;
            }
            res.push_back(make_pair(prime, exp));
        }
        return res;
    }

    vector<int> divisors(int n) {
        vector<int> res({1});
        auto pf = prime_factors(n);
        for (auto p : pf) {
            int siz = (int)res.size();
            for (int i = 0; i < siz; ++i) {
                int v = 1;
                for (int j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }

    int divisors_num(int n) {
        int res = 1;
        auto pf = prime_factors(n);
        for (auto p : pf) {
            res *= p.second + 1;
        }
        return res;
    }
};