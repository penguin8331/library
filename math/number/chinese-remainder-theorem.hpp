#pragma once
#include "template/template.hpp"
#include "math/number/ext-gcd.hpp"

pair<long long, long long> crt(const vector<long long>& vr, const vector<long long>& vm) {
    if (vr.empty() || vm.empty()) return make_pair(0, 1);
    long long R = vr[0], M = vm[0];
    for (int i = 1; i < (int)vr.size(); ++i) {
        long long p, q, r = vr[i], m = vm[i];
        if (M < m) swap(M, m), swap(R, r);  // prevent overflow
        long long d = extGcd(M, m, p, q);   // p is inv of M/d (mod. m/d)
        if ((r - R) % d != 0) return make_pair(0, -1);
        long long md = m / d;
        long long tmp = (r - R) / d % md * p % md;
        R += M * tmp, M *= md;
    }
    R %= M;
    if (R < 0) R += M;
    return make_pair(R, M);
}