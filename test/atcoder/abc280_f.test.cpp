#define PROBLEM "https://atcoder.jp/contests/abc280/tasks/abc280_f"
#include "../../data-structure/weighted-union-find.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, M, Q);
    WeightedUnionFind<ll> uf(N);
    vector<bool> isinf(N, false);
    for (int i = 0; i < M; i++) {
        INT(a, b);
        a--, b--;
        LL(c);
        if (uf.issame(a, b) && uf.get_diff(a, b) != c) {
            isinf[a] = true;
        } else {
            uf.unite(a, b, c);
        }
    }
    for (auto v : uf.groups()) {
        bool flag = false;
        for (auto x : v) {
            if (isinf[x]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            for (auto x : v) isinf[x] = true;
        }
    }
    for (int i = 0; i < Q; i++) {
        INT(a, b);
        a--, b--;
        if (!uf.issame(a, b)) {
            print("nan");
        }
        elif (isinf[a]) { print("inf"); }
        else {
            print(uf.get_diff(a, b));
        }
    }
}