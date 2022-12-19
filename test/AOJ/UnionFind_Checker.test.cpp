#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include <bits/stdc++.h>
using namespace std;
#include "DataStructure/UnionFind.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    for (int i = 0; i < Q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) {
            uf.unite(x, y);
        } else {
            cout << uf.issame(x, y) << endl;
        }
    }
}