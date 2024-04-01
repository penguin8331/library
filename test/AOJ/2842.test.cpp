#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"
#include "../../data-structure/binary-indexed-tree-2d.hpp"
#include "../../template/template.hpp"

int main() {
    int H, W, T, Q;
    cin >> H >> W >> T >> Q;
    BIT2D<int> fini(H, W), mada(H, W);
    queue<pair<pii, int>> que;
    for (int i = 0; i < Q; i++) {
        int t, c;
        cin >> t >> c;
        while (!que.empty()) {
            if (que.front().second + T <= t) {
                auto now = que.front();
                que.pop();
                mada.add(now.first.first, now.first.second, -1);
                fini.add(now.first.first, now.first.second, 1);
            } else {
                break;
            }
        }
        if (c == 0) {
            int h, w;
            cin >> h >> w;
            h--;
            w--;
            mada.add(h, w, 1);
            que.push({{h, w}, t});
        }
        elif (c == 1) {
            int h, w;
            cin >> h >> w;
            h--;
            w--;
            if (fini.sum(h, h + 1, w, w + 1) != 0) {
                fini.add(h, w, -1);
            }
        }
        else {
            int h, w, h1, w1;
            cin >> h >> w >> h1 >> w1;
            h--;
            w--;
            cout << fini.sum(h, h1, w, w1) << " " << mada.sum(h, h1, w, w1)
                 << endl;
        }
    }
}