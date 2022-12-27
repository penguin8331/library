#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C"
#include "template/template.hpp"
#include "geomeny/is-contain-in-the-polygon.hpp"

int main() {
    int N;
    cin >> N;
    vector<Point> G(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i].x >> G[i].y;
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        Point a;
        cin >> a.x >> a.y;
        cout << is_contain(G, a);
    }
}