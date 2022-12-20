#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160"
#include "template/template.hpp"
#include "data-structure/union-find.hpp"

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0) {
            return 0;
        }
        vector<vector<int>> G(h, vector<int>(w));
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int a;
                cin >> a;
                if (a == 1) {
                    G[i][j] = cnt;
                    cnt++;
                } else {
                    G[i][j] = -1;
                }
            }
        }
        UnionFind uf(cnt);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (G[i][j] >= 0) {
                    for (int k = 0; k < 8; k++) {
                        int X = i + dx[k];
                        int Y = j + dy[k];
                        if (X < 0 || X >= h || Y < 0 || Y >= w) continue;
                        if (G[X][Y] >= 0) {
                            uf.unite(G[X][Y], G[i][j]);
                        }
                    }
                }
            }
        }
        cout << uf.groups().size() << endl;
    }
}