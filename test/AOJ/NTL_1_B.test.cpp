#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "template/template.hpp"
#include "math/combinatorics/modpow.hpp"

int main() {
    int m, n;
    cin >> m >> n;
    cout << modpow(m, n, MOD)<<endl;
}