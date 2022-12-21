/*
    0->1->2->3->0が最短だとする
    dp[{0,1,2,3}][0]->dp[{1,2,3}][3]
    ->dp[{1,2}][2]->dp[{1}][1]->dp[{}][0]
    infの値を調整しオーバーフローしないようにする
    G->パスがあればその距離,なければINFをいれる
*/
int V, E;
int G[20][20];  // グラフ
int dp[50000][20];
// メモ化再帰
int rec(int S, int v) {
    if (S == 0) {
        if (v == 0) {
            return 0;
        } else {
            return inf / 3;
        }
    }
    if ((S & (1 << v)) == 0) {  // Sに{v}が含まれていない
        return inf / 3;
    }
    int &ret = dp[S][v];
    if (ret != 0) return ret;
    ret = inf / 3;
    for (int u = 0; u < V; u++) {
        chmin(ret, rec(S ^ (1 << v), u) + G[u][v]);
    }
    return ret;
}