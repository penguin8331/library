#define PROBLEM "https://yukicoder.me/problems/no/649"
#include "../../data-structure/ext-pb_ds.hpp"
#include "../../template/template.hpp"

int main() {
    INT(Q, K);
    ordered_set<ll, less_equal<ll>> S;
    while (Q--) {
        INT(t);
        if (t == 1) {
            LL(v);
            S.insert(v);
        } else {
            if (S.size() < K) {
                print(-1);
            } else {
                auto itr = S.find_by_order(K - 1);
                print(*itr);
                S.erase(itr);
            }
        }
    }
    gp_hash_table<int, int> h;
}