#pragma once
#include "../data-structure/lazy-segment-tree.hpp"
#include "../template/template.hpp"

struct Lazy_SegTree_Arthmetic {
    struct S {
        ll sum;
        int l, r;
    };
    struct F {
        ll a, b;
        bool operator==(const F& other) {
            if (a == other.a && b == other.b)
                return true;
            else
                return false;
        }
    };
    function<S(S, S)> fm = [](S s, S t) -> S {
        return {s.sum + t.sum, min(s.l, t.l), max(s.r, t.r)};
    };
    function<void(S&, F)> fa = [](S& s, F f) {
        s = {s.sum + (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l,
             s.r};
    };
    function<void(F&, F)> fc = [](F& f, F g) {
        f.a += g.a;
        f.b += g.b;
    };
    int N;
    Lazy_SegTree<S, F> seg;
    explicit Lazy_SegTree_Arthmetic(int n) : N(n) {
        seg.init(N, fm, fa, fc, S({0, inf, -inf}), F({0, 0}));
        for (int i = 0; i < N; i++) {
            seg.set(i, S({0, i, i + 1}));
        }
        seg.build();
    }
    void init(vector<int> v) {
        for (int i = 0; i < N; i++) {
            seg.set(i, S({v[i], i, i + 1}));
        }
        seg.build();
    }
    void update(int l, int r, F f) {
        seg.update(l, r, F({f.a, f.b - f.a * seg.get(l, l + 1).l}));
    }
    S get(int l, int r) { return seg.get(l, r); }
};