vector<vector<bool>> seen;  //訪問済みかどうか v->始点
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
void dfs(int H, int W, const vector<string> &G, pair<int, int> v) {
    seen[v.first][v.second] = true;

    for (int i = 0; i < 4; i++) {
        int X = dx[i] + v.first;
        int Y = dy[i] + v.second;
        if (X < 0 || X >= H || Y < 0 || Y >= W) continue;
        if (seen[X][Y] || G[X][Y] == '#') continue;  //探索済みなら捜索しない
        dfs(H, W, G, make_pair(X, Y));
    }
}