#define PROBLEM "https://atcoder.jp/contests/abc177/tasks/abc177_f"
#include "../../data-structure/lazy-segment-tree-arthmetic-ruq.hpp"
#include "../../template/template.hpp"

int main() {
    INT(H, W);
    Lazy_SegTree_Arthmetic seg(W);
    for (int i = 0; i < H; i++) {
        INT(l, r);
        l--;
        ll x = (l > 0 ? seg.get(l - 1, l).min : INF);
        seg.update(l, r, {1, x + 1});
        ll ans = seg.get(0, W).min;
        print(ans >= INF ? -1 : ans + i + 1);
    }
}