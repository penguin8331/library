#define PROBLEM "https://yukicoder.me/problems/no/674"
#include "../../others/range-set.hpp"
#include "../../template/template.hpp"

int main() {
    LL(D);
    INT(Q);
    RangeSet<ll> st;
    ll res = 0;
    while (Q--) {
        LL(L, R);
        st.insert(L, R);
        auto seg = st.covered_by(L, R);
        debug(seg);
        chmax(res, seg.second - seg.first + 1);
        print(res);
    }
}
