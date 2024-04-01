#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D"
#include "../../math/number/divisors.hpp"
#include "../../template/template.hpp"

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    auto res = divisors(c);
    int ans = 0;
    for (int i = 0; i < (int)res.size(); i++) {
        if (res[i] >= a && res[i] <= b) {
            ans++;
        }
    }
    cout << ans << endl;
}