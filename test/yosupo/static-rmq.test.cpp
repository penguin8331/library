#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "template/template.hpp"
#include "data-structure/segment-tree.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SegTree<ll> seg(
        N, [](ll a, ll b) { return min(a, b); }, INF);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        seg.set(i, a);
    }
    seg.build();
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << seg.get(l, r) << endl;
    }
}