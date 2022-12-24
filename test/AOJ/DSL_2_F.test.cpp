#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include "template/template.hpp"
#include "data-structure/lazy-segment-tree.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    auto fm = [](ll a, ll b) { return min(a, b); };
    auto fa = [](ll& a, ll d) { a = d; };
    auto fc = [](ll& d, ll e) { d = e; };
    Lazy_SegTree<long long, long long> seg(N, fm, fa, fc, (1LL << 31) - 1, 0);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, s;
            cin >> l >> r >> s;
            seg.update(l, r + 1, s);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.get(l, r + 1) << endl;
        }
        seg.print();
    }
}