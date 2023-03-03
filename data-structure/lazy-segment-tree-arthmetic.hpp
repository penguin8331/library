#pragma once
#include "template/template.hpp"
#include "data-structure/lazy-segment-tree.hpp"

struct Lazy_SegTree_Arthmetic {
    struct S {
        ll min, max, sum;
        int l, r;
    };
    struct F {
        ll a, b;
        bool operator==(F& other) {
            if (a == other.a && b == other.b)
                return true;
            else
                return false;
        }
    };
    function<S(S, S)> fm = [](S s, S t) -> S { return {min(s.min, t.min), max(s.max, t.max), s.sum + t.sum, min(s.l, t.l), max(s.r, t.r)}; };
    function<void(S&, F)> fa = [](S& s, F f) {
        if (f.a == INF) {
            return;
        }
        if (f.a >= 0) {
            s = {f.a * s.l + f.b, f.a * (s.r - 1) + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};
            return;
        } else {
            s = {f.a * (s.r - 1) + f.b, f.a * s.l + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};
            return;
        }
    };
    function<void(F&, F)> fc = [](F& f, F g) {
        if (g.a != INF) {
            f = g;
        }
    };
    int N;
    Lazy_SegTree<S, F> seg;
    Lazy_SegTree_Arthmetic(int n) : N(n) {
        seg.init(N, fm, fa, fc, S({INF, -INF, 0, inf, -inf}), F({INF, INF}));
        for (int i = 0; i < N; i++) {
            seg.set(i, S({0, 0, 0, i, i + 1}));
        }
        seg.build();
    }
    void init(vector<int> v) {
        for (int i = 0; i < N; i++) {
            seg.set(i, S({v[i], v[i], v[i], i, i + 1}));
        }
        seg.build();
    }
    void update(int l, int r, F f) {
        seg.update(l, r, F({f.a, f.b - f.a * seg.get(l, l + 1).l}));
    }
    S get(int l, int r) {
        return seg.get(l, r);
    }
};