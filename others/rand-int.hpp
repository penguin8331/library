#pragma once
#include "../template/template.hpp"

struct dsts {
    mt19937 mt;
    uniform_int_distribution<ll> dist;
    dsts(ll A, ll B) : dist(A, B) {
        mt.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }
    ll get() {
        return dist(mt);
    }
};