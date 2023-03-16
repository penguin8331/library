#pragma once
#include "../template/template.hpp"

struct ran {
    mt19937 mt;
    ran() {
        mt.seed(std::chrono::system_clock::now().time_since_epoch().count());
    }
    ll get(ll A, ll B) {
        uniform_int_distribution<ll> dist(A, B);
        return dist(mt);
    }
};