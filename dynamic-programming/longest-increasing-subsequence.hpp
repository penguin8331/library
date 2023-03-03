#pragma once
#include "../template/template.hpp"

template <class T>
int LIS(vector<T> a, bool is_strong = true) {
    int n = (int)a.size();
    vector<T> dp;
    for (int i = 0; i < n; ++i) {
        auto it = (is_strong ? lower_bound(dp.begin(), dp.end(), a[i]) : upper_bound(dp.begin(), dp.end(), a[i]));
        if (it == dp.end())
            dp.push_back(a[i]);
        else
            *it = a[i];
    }
    return dp.size();
}