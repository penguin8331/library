#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"
#include "../../data-structure/lazy-segment-tree.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, Q);
    auto fm = [](pii a, pii b) {
        return pii(a.first + b.first, a.second + b.second);
    };
    auto fa = [](pii& a, int d) { a.first = d * a.second; };
    auto fc = [](int& d, int e) { d = e; };
    Lazy_SegTree<pii, int> seg(N, fm, fa, fc, {0, 1}, -inf);
    seg.build();
    while (Q--) {
        INT(T, L, R);
        if (T == 0) {
            INT(V);
            seg.update(L, R + 1, V);
        } else {
            print(seg.get(L, R + 1).first);
        }
    }
}