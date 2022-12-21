template <class T>
struct sectionsum2d {
    vector<vector<T>> data;

    sectionsum2d(int H, int W) : data(H + 1, vector<T>(W + 1, 0)) {}

    void update(int x, int y, const T& z) {
        x++;
        y++;
        data[x][y] = z;
    }

    void build() {
        for (int i = 1; i < data.size(); i++) {
            for (int j = 1; j < data[i].size(); j++) {
                data[i][j] += data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1];
            }
        }
    }

    T get(int sx, int sy, int gx, int gy) const {
        return (data[gx][gy] - data[sx][gy] - data[gx][sy] + data[sx][sy]);
    }
};