#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"
#include "../../template/template.hpp"
#include "../../algorithm/compress2d.hpp"

int main() {
    // 入力
    int N;
    cin >> N;
    vector<long long> X1(N), Y1(N), X2(N), Y2(N);
    for (int i = 0; i < N; i++) {
        cin >> X1.at(i) >> Y1.at(i) >> X2.at(i) >> Y2.at(i);
    }
    // 座標圧縮
    vector<long long> X = compress(X1, X2);
    vector<long long> Y = compress(Y1, Y2);
    // imos法で塗りつぶし
    int w = (int)X.size();
    int h = (int)Y.size();
    vector<vector<int>> G(w, vector<int>(h));
    for (int i = 0; i < N; i++) {
        G[X1[i]][Y1[i]]++;
        G[X2[i]][Y2[i]]++;
        G[X1[i]][Y2[i]]--;
        G[X2[i]][Y1[i]]--;
    }
    for (int x = 1; x < w; x++) {
        for (int y = 0; y < h; y++) {
            G[x][y] += G[x - 1][y];
        }
    }
    for (int x = 0; x < w; x++) {
        for (int y = 1; y < h; y++) {
            G[x][y] += G[x][y - 1];
        }
    }
    // 塗りつぶしたマスの面積を全て足し合わせる
    long long ans = 0;
    for (int x = 0; x < w - 1; x++) {
        for (int y = 0; y < h - 1; y++) {
            if (G[x][y]) {
                ans += (X[x + 1] - X[x]) * (Y[y + 1] - Y[y]);
            }
        }
    }
    cout << ans << endl;
}