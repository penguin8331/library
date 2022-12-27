#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include "template/template.hpp"
#include "geomeny/convex-hull.hpp"

int main() {
    int N;
    cin >> N;
    vector<Point> G(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i].x >> G[i].y;
    }
    auto res = ConvexHull(G);
    cout << res.size() << endl;
    for (const auto &i : res) {
        cout << i.x << " " << i.y << endl;
    }
}