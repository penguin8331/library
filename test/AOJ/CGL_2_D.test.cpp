#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D"
#define ERROR 0.00000001
#include "template/template.hpp"
#include "geomeny/distance.hpp"

int main() {
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        Line a(2), b(2);
        cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> b[0].x >> b[0].y >> b[1].x >> b[1].y;
        cout << distanceSS(a, b) << endl;
    }
}