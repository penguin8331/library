#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include "../../math/number/prime-factorization.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    auto res = prime_factorize(N);
    cout << N << ":";
    for (const auto &i : res) {
        for (int j = 0; j < i.second; j++) {
            cout << " " << i.first;
        }
    }
    cout << endl;
}