#define PROBLEM "https://atcoder.jp/contests/abc214/tasks/abc214_e"
#include "../../others/range-set.hpp"
#include "../../template/template.hpp"

void solve() {
    INT(N);
    vector<pll> A(N);
    scan(A);
    sort(all(A), [&](pll a, pll b) { return a.second < b.second; });
    // すでに使われたボール
    RangeSet<ll> used;
    for (int i = 0; i < N; i++) {
        ll nxt = used.mex(A[i].first);
        if (nxt > A[i].second) {
            cout << "No" << endl;
            return;
        }
        used.insert(nxt, nxt);
    }
    cout << "Yes" << endl;
}
int main() {
    INT(T);
    while (T--) solve();
}