#pragma once
#include "../template/template.hpp"

template <typename T>
struct RangeSet {
    set<pair<T, T>> st;
    T TINF;

    RangeSet() : TINF(numeric_limits<T>::max() / 2) {
        st.emplace(TINF, TINF);
        st.emplace(-TINF, -TINF);
    }
    // [l,r] covered?
    bool covered(T l, T r) {
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        return ite->first <= l and r <= ite->second;
    }
    bool covered(T x) { return covered(x, x); }
    // [l, r]がカバーされているなら，その区間を返す.
    // されていないなら[-TINF,-TINF]を返す
    pair<T, T> covered_by(T l, T r) {
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        if (ite->first <= l and r <= ite->second) return *ite;
        return make_pair(-TINF, -TINF);
    }
    pair<T, T> covered_by(T x) { return covered_by(x, x); }
    // insert[l,r], 増加量を返す
    T insert(T l, T r) {
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        if (ite->first <= l and r <= ite->second) return T(0);
        T sum_erased = T(0);
        if (ite->first <= l and l <= ite->second + 1) {
            l = ite->first;
            sum_erased += ite->second - ite->first + 1;
            ite = st.erase(ite);
        } else
            ite = next(ite);
        while (r > ite->second) {
            sum_erased += ite->second - ite->first + 1;
            ite = st.erase(ite);
        }
        if (ite->first - 1 <= r) {
            sum_erased += ite->second - ite->first + 1;
            r = ite->second;
            st.erase(ite);
        }
        st.emplace(l, r);
        return r - l + 1 - sum_erased;
    }
    T insert(T x) { return insert(x, x); }
    // erase [l,r], 減少量を返す
    T erase(T l, T r) {
        assert(l <= r);
        auto ite = prev(st.lower_bound({l + 1, l + 1}));
        if (ite->first <= l and r <= ite->second) {
            // 完全に1つの区間に包含されている
            if (ite->first < l) st.emplace(ite->first, l - 1);
            if (r < ite->second) st.emplace(r + 1, ite->second);
            st.erase(ite);
            return r - l + 1;
        }

        T ret = T(0);
        if (ite->first <= l and l <= ite->second) {
            ret += ite->second - l + 1;  // 消えた
            if (ite->first < l) st.emplace(ite->first, l - 1);
            ite = st.erase(ite);  // 次へ
        } else
            ite = next(ite);
        while (ite->second <= r) {
            ret += ite->second - ite->first + 1;
            ite = st.erase(ite);
        }
        // 右端が区間の間にあるか
        if (ite->first <= r) {
            ret += r - ite->first + 1;
            st.emplace(r + 1, ite->second);
            st.erase(ite);
        }
        return ret;
    }
    T erase(T x) { return erase(x, x); }
    // number of range
    int size() { return (int)st.size() - 2; }
    // mex [x,~)
    T mex(T x = 0) {
        auto ite = prev(st.lower_bound({x + 1, x + 1}));
        if (ite->first <= x and x <= ite->second)
            return ite->second + 1;
        else
            return x;
    }
    void output() {
        cout << "RangeSet : ";
        for (auto &p : st) {
            if (p.first == -TINF or p.second == TINF) continue;
            cout << "[" << p.first << ", " << p.second << "] ";
        }
        cout << "\n";
    }
};
