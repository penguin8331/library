#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2659"
#include "template/template.hpp"
#include "math/number/chinese-remainder-theorem.hpp"

int main() {
    long long N;
    int M, D;
    cin >> N >> M >> D;
    vector<long long> A(M);
    for (int i = 0; i < M; ++i) cin >> A[i];
    bool ok = true;
    for (int i = 0; i < D; ++i) {
        vector<long long> b, m;
        for (int j = 0; j < M; ++j) {
            int R;
            cin >> R;
            if (R != -1) b.push_back(R), m.push_back(A[j]);
        }
        if (b.empty()) continue;

        pair<long long, long long> tmp = crt(b, m);

        if (tmp.second == -1) ok = false;
        if (N < tmp.first) ok = false;

        N = N - (N - tmp.first) % tmp.second;
    }
    if (ok)
        cout << N << endl;
    else
        cout << -1 << endl;
}