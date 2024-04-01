#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"
#include "../../graph/two-sat.hpp"

#include "../../template/template.hpp"

int main() {
    string p, cnf;
    int N, M;
    cin >> p >> cnf >> N >> M;
    TwoSat ts(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        string zero;
        cin >> zero;
        ts.add(abs(a) - 1, a > 0, abs(b) - 1, b > 0);
    }
    auto ans = ts.solve();
    if ((int)ans.size() == N) {
        cout << "s SATISFIABLE" << endl;
        cout << "v ";
        for (int i = 0; i < N; i++) {
            cout << (ans[i] ? i + 1 : -i - 1) << " ";
        }
        cout << 0 << endl;
    } else {
        cout << "s UNSATISFIABLE" << endl;
    }
}