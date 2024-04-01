#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A"
#include "../../geomeny/area-polygon.hpp"
#include "../../template/template.hpp"

int main() {
    cout << fixed << setprecision(1);
    int N;
    cin >> N;
    vector<Point> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].x >> A[i].y;
    }
    cout << CalcArea(A) << endl;
}