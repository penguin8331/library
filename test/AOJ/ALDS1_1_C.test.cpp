#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include "template/template.hpp"
#include "data-structure/eratostenes.hpp"

int main() {
    IsPrime era(100000000);
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ans += era.isprime(a);
    }
    cout << ans << endl;
}