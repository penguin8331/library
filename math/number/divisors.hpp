#pragma once
#include "../../template/template.hpp"

vector<long long> divisors(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i * i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}