#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C"
#define ERROR 0.00000001
#include "template/template.hpp"
#include "geomeny/crosspoint.hpp"

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Line a(2), b(2);
        cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> b[0].x >> b[0].y >> b[1].x >> b[1].y;
        auto res = crosspoint(a, b);
        cout << res[0].x << " " << res[0].y << endl;
    }
}