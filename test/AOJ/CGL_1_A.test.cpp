#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A"
#include "template/template.hpp"
#include "geomeny/projection.hpp"

int main() {
    cout << fixed << setprecision(8);
    Line a(2);
    cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        Point b;
        cin >> b.x >> b.y;
        Point res = proj(b, a);
        cout << res.x << " " << res.y << endl;
    }
}