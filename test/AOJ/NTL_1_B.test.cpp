#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../math/combinatorics/modpow.hpp"
#include "../../template/template.hpp"

int main() {
    int m, n;
    cin >> m >> n;
    cout << modpow(m, n, MOD) << endl;
}