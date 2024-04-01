#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "../../data-structure/implicit-treap.hpp"
#include "../../template/template.hpp"

int main() {
    MinUpdateQuery<int, int> solve;
    INT(N, Q);
    for (int i = 0; i < N; i++) {
        INT(a);
        solve.insert(i, a);
    }
    for (int i = 0; i < Q; i++) {
        INT(l, r);
        print(solve.query(l, r));
    }
}