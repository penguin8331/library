#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A"
#include "../../template/template.hpp"
#include "../../dynamic-programming/traveling-salesman-problem.hpp"

int main() {
    cin >> V >> E;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            G[i][j] = inf / 3;
        }
    }
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G[s][t] = d;
    }
    int ans = rec((1 << V) - 1, 0);
    cout << (ans == inf / 3 ? -1 : ans) << endl;
}