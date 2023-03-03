#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../template/template.hpp"
#include "../../algorithm/section-sum.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    sectionsum<ll> A(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.update(i, a);
    }
    A.build();
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << A.get(l, r) << endl;
    }
}