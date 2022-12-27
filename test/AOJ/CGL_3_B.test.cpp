#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"
#include "template/template.hpp"
#include "geomeny/is-convex.hpp"

int main() {
    int N;
    cin >> N;
    vector<Point> G(N);
    for (int i = 0; i < N; i++) {
        cin >> G[i].x >> G[i].y;
    }
    cout << isConvex(G) << endl;
}