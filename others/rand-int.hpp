#pragma once
#include "../template/template.hpp"

struct Rand {
    mt19937 mt;

    using ResultType = mt19937::result_type;
    Rand() : Rand(random_device()()) {}
    explicit Rand(ResultType seed) : mt(seed) {}

    template <typename T = uint64_t>
    T get(T l, T r) {
        uniform_int_distribution<T> dist(l, r);
        return dist(mt);
    }

    vector<int> shuffle(int n) {
        vector<int> res(n);
        iota(res.begin(), res.end(), 0);
        for (int i = n - 1; i >= 0; i--) {
            swap(res[i], res[get(0, i)]);
        }
        return res;
    }
};