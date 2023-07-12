#pragma once
#include "../template/template.hpp"

template <typename T>
struct Compress {
    vector<T> xs;

    Compress() {}

    explicit Compress(const vector<T>& vs) { add(vs); }

    explicit Compress(const initializer_list<vector<T>>& vs) { add(vs); }

    void add(const vector<T>& vs) { xs.insert(xs.end(), vs.begin(), vs.end()); }

    void add(const T& x) { xs.push_back(x); }

    void build() {
        sort(all(xs));
        xs.erase(unique(all(xs)), xs.end());
    }

    vector<int> get(const vector<T>& vs) const {
        vector<int> ret;
        transform(all(vs), back_inserter(ret), [&](const T& x) {
            return lower_bound(all(xs), x) - xs.begin();
        });
        return ret;
    }

    int get(const T& x) const { return lower_bound(all(xs), x) - xs.begin(); }

    const T& operator[](int k) const { return xs[k]; }
};