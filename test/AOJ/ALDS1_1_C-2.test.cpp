#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "../../math/number/miller-rabin.hpp"
#include "../../template/template.hpp"

int main() {
    int Q;
    cin >> Q;
    int cnt = 0;
    for (int i = 0; i < Q; i++) {
        int N;
        cin >> N;
        cnt += is_prime(N);
    }
    cout << cnt << endl;
}