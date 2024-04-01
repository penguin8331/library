#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D"
#include "../../math/combinatorics/inversion-number.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << inversion_number(A) << endl;
}