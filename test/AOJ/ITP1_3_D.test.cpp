#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "template/template.hpp"
#include "math/number/divisors.hpp"

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    auto res = divisors(c);
    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] >= a && res[i] <= b) {
            ans++;
        }
    }
    cout << ans << endl;
}