#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_A"
#include "../../template/template.hpp"
#include "../../graph/prim.hpp"

int main() {
    int N;
    cin >> N;
    vector<vector<Edge>> G(N, vector<Edge>(0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a != -1) {
                Edge A;
                A.to = j;
                A.cost = a;
                G[i].push_back(A);
            }
        }
    }
    Prim solve(G, N);
    cout << solve.sum << endl;
}