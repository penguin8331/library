#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include "template/template.hpp"
#include "geomeny/convex-cut.hpp"

int main() {
    cout << fixed << setprecision(8);
    int N;
    cin >> N;
    vector<Point> G(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i].x >> G[i].y;
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        Line a(2);
        cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;
        cout << ConvexCut(G, a) << endl;
    }
}