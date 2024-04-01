#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "../../dynamic-programming/section-sum.hpp"
#include "../../template/template.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    SectionSum<ll> A(N);
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