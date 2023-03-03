#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A"
#include "../../template/template.hpp"
#include "../../geomeny/convex-hull.hpp"

int main() {
    int N;
    cin >> N;
    vector<Point> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i].x >> A[i].y;
    }
    auto pol = ConvexHullCollinearOK(A);
    pair<ld, ld> minv = {11000, 11000};
    int minp = -1;
    for (int i = 0; i < (int)pol.size(); ++i) {
        if (minv > make_pair(pol[i].y, pol[i].x)) {
            minv = make_pair(pol[i].y, pol[i].x);
            minp = i;
        }
    }
    cout << pol.size() << endl;
    for (int i = 0; i < (int)pol.size(); ++i) {
        int j = (i + minp) % pol.size();
        cout << fixed << setprecision(0) << pol[j].x << " " << pol[j].y << endl;
    }
}