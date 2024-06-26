#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D"
#include "../../dynamic-programming/longest-increasing-subsequence.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << LIS(A) << endl;
}