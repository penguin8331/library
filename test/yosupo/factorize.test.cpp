#define PROBLEM "https://judge.yosupo.jp/problem/factorize"
#include "template/template.hpp"
#include "math/number/pollard-rho.hpp"

int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll N;
        cin >> N;
        if (N == 1) {
            cout << 0 << endl;
            continue;
        }
        auto res = solve_for_prime_factorize(N);
        cout << res.size();
        for (int j = 0; j < res.size(); j++) {
            cout << " " << res[j];
        }
        cout << endl;
    }
}