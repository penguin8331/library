#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_I"
#include "../../data-structure/lazy-segment-tree.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, Q);
    auto fm = [](int a, int b) { return min(a, b); };
    auto fa = [](int& a, int d) { a += d; };
    auto fc = [](int& d, int e) { d += e; };
    Lazy_SegTree<int, int> seg(N, fm, fa, fc, inf, 0);
    while (Q--) {
        INT(T, L, R);
        if (T == 0) {
            INT(V);
            seg.update(L, R + 1, V);
        } else {
            print(seg.get(L, R + 1));
        }
    }
}