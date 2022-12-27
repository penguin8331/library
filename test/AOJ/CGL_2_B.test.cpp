#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B"
#include "template/template.hpp"
#include "geomeny/projection.hpp"

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Line a(2), b(2);
        cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> b[0].x >> b[0].y >> b[1].x >> b[1].y;
        cout << isinterSS(a, b) << endl;
    }
}