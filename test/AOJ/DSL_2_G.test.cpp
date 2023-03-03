#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include "../../template/template.hpp"
#include "../../data-structure/binary-indexed-tree-raq.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    BIT<ll> bit(N);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, v;
            cin >> l >> r >> v;
            bit.add(l, r + 1, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r + 1) << endl;
        }
    }
}