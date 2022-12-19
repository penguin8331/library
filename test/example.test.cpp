#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B"
#include "template/template.hpp"

int main() {
    int N;
    cin >> N;
    vector<int> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    int Q;
    cin >> Q;
    int cnt = 0;
    while (Q--) {
        int t_i;
        cin >> t_i;
        cnt += binary_search(all(s), t_i);
    }
    cout << cnt << endl;
    return 0;
}