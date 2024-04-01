#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../data-structure/disjoint-sparse-table.hpp"
#include "../../template/template.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    DisjointSparseTable<int> dst([](int a, int b) { return min(a, b); }, A);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << dst.get(l, r) << endl;
    }
}