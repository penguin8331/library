#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include "template/template.hpp"
#include "data-structure/disjoint-sparse-table.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    DisjointSparseTable<ll> dst([](ll a, ll b) { return a + b; }, A);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << dst.get(l, r) << endl;
    }
}