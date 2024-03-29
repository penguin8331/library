#pragma once
#include "../template/template.hpp"

template <class Abel>
struct BIT {
    Abel UNITY_SUM = 0;
    vector<Abel> dat;

    explicit BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity) {}
    void init(int n) {
        dat.assign(n, UNITY_SUM);
    }

    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i |= i + 1)
            dat[i] = dat[i] + x;
    }

    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)
            res = res + dat[i];
        return res;
    }

    inline Abel sum(int a, int b) {
        return sum(b) - sum(a);
    }

    friend ostream& operator<<(ostream& os, BIT bit) {
        os << "[ ";
        for (int i = 0; i < (int)bit.dat.size(); i++) {
            os << bit.sum(i, i + 1) << " ";
        }
        os << ']';
        return os;
    }
};