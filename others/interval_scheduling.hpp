#pragma once
#include "../template/template.hpp"

template <class T>
int interval_scheduling(vector<pair<T, T>> A) {
    sort(all(A), [](const pair<T, T> &a, const pair<T, T> &b) {
        return a.second < b.second;
    });

    int res = 0;
    T x = 0;
    for (auto &[l, r] : A) {
        if (l < x) continue;
        res++;
        x = r;
    }
    return res;
}