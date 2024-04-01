#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "../../string/rolling-hash.hpp"
#include "../../template/template.hpp"

int main() {
    string S;
    cin >> S;
    RollingHash rh;
    auto res = rh.build(S);
    int N = S.size();
    cout << N;
    for (int i = 1; i < N; i++) {
        cout << " " << rh.lcp(res, i, N, res, 0, N);
    }
    cout << endl;
}