#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../data-structure/sparse-table.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, Q);
    vector<int> A(N);
    scan(A);
    SparseTable<int> st(A);
    while (Q--) {
        INT(l, r);
        print(st.get(l, r));
    }
}