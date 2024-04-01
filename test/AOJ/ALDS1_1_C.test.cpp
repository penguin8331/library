#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "../../math/number/isprime.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ans += is_prime(a);
    }
    cout << ans << endl;
}