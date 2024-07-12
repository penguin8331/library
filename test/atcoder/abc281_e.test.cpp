#define PROBLEM "https://atcoder.jp/contests/abc281/tasks/abc281_e"
#include "../../data-structure/binary-trie.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, M, K);
    vector<int> A(N);
    scan(A);
    BinaryTrie<int, 30> a, b;
    ll ans = 0;
    auto push = [&](int val) {
        a.insert(val);
        ans += val;
        if (a.size() > K) {
            int nval = a.get(a.get_max());
            ans -= nval;
            a.erase(nval);
            b.insert(nval);
        }
    };
    auto pop = [&](int val) {
        if (b.find(val)) {
            b.erase(val);
        } else {
            a.erase(val);
            ans -= val;
            if (b.size()) {
                int nval = b.get(b.get_min());
                b.erase(nval);
                a.insert(nval);
                ans += nval;
            }
        }
    };
    vector<ll> finans;
    for (int i = 0; i < N; i++) {
        push(A[i]);
        if (i >= M) {
            pop(A[i - M]);
        }
        if (i >= M - 1) {
            finans.push_back(ans);
        }
    }
    print(finans);
}