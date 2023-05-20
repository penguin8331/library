#pragma once
#include "../template/template.hpp"

struct rand_int {
    mt19937 mt;
    rand_int() {
        mt.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }
    ll get(ll A, ll B) {
        uniform_int_distribution<ll> dist(A, B);
        return dist(mt);
    }
    vector<int> get_permutation(int N) {
        vector<int> ret(N);
        for (int i = 0; i < N; i++) {
            ret[i] = i;
        }
        for (int i = N - 1; i >= 0; i--) {
            int j = get(i, N - 1);
            swap(ret[i], ret[j]);
        }
        return ret;
    }
};