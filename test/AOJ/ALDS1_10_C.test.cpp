#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C"
#include "../../dynamic-programming/longest-common-subsequence.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s, t;
        cin >> s >> t;
        cout << LCS(s, t) << endl;
    }
}