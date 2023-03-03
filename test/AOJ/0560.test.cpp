#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0560"
#include "../../template/template.hpp"
#include "../../algorithm/section-sum2d.hpp"

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    sectionsum2d<int> JJ(H, W), OO(H, W), II(H, W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if (c == 'J') {
                JJ.update(i, j, 1);
            }
            elif (c == 'O') {
                OO.update(i, j, 1);
            }
            else {
                II.update(i, j, 1);
            }
        }
    }
    JJ.build();
    OO.build();
    II.build();
    for (int i = 0; i < Q; i++) {
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        sx--;
        sy--;
        cout << JJ.get(sx, sy, gx, gy) << " " << OO.get(sx, sy, gx, gy) << " " << II.get(sx, sy, gx, gy) << endl;
    }
}