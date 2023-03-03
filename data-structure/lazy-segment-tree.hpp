#pragma once
#include "template/template.hpp"

template <class Monoid, class Action>
struct Lazy_SegTree {
    using FuncMonoid = function<Monoid(Monoid, Monoid)>;
    using FuncAction = function<void(Monoid&, Action)>;
    using FuncComposition = function<void(Action&, Action)>;
    FuncMonoid FM;
    FuncAction FA;
    FuncComposition FC;
    Monoid IDENTITY_MONOID;
    Action IDENTITY_LAZY;
    int N, SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;

    Lazy_SegTree() {}
    Lazy_SegTree(int n, const FuncMonoid fm, const FuncAction fa,
                 const FuncComposition fc,
                 const Monoid& identity_monoid, const Action& identity_lazy)
        : FM(fm), FA(fa), FC(fc), IDENTITY_MONOID(identity_monoid), IDENTITY_LAZY(identity_lazy), N(n) {
        SIZE = 1, HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, IDENTITY_MONOID);
        lazy.assign(SIZE * 2, IDENTITY_LAZY);
    }
    void init(int n, const FuncMonoid fm, const FuncAction fa,
              const FuncComposition fc,
              const Monoid& identity_monoid, const Action& identity_lazy) {
        FM = fm, FA = fa, FC = fc;
        IDENTITY_MONOID = identity_monoid, IDENTITY_LAZY = identity_lazy;
        SIZE = 1, HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, IDENTITY_MONOID);
        lazy.assign(SIZE * 2, IDENTITY_LAZY);
    }

    // set, a is 0-indexed
    void set(int a, const Monoid& v) { dat[a + SIZE] = v; }
    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
    }

    // update [a, b)
    inline void evaluate(int k) {
        if (lazy[k] == IDENTITY_LAZY) return;
        if (k < SIZE) FC(lazy[k * 2], lazy[k]), FC(lazy[k * 2 + 1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = IDENTITY_LAZY;
    }
    inline void update(int a, int b, const Action& v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            FC(lazy[k], v), evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k * 2, l, (l + r) >> 1);
            update(a, b, v, k * 2 + 1, (l + r) >> 1, r);
            dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);
        }
    }
    inline void update(int a, int b, const Action& v) {
        update(a, b, v, 1, 0, SIZE);
    }

    // get [a, b)
    inline Monoid get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k * 2, l, (l + r) >> 1),
                      get(a, b, k * 2 + 1, (l + r) >> 1, r));
        else
            return IDENTITY_MONOID;
    }
    inline Monoid get(int a, int b) {
        return get(a, b, 1, 0, SIZE);
    }
    inline Monoid operator[](int a) {
        return get(a, a + 1);
    }

    friend ostream& operator<<(ostream& os, Lazy_SegTree seg) {
        os << "[ ";
        for (int i = 0; i < seg.N; i++) {
            os << seg.get(i, i + 1) << " ";
        }
        os << ']';
        return os;
    }
};