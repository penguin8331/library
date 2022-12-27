#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D"
#define ERROR 0.000001
#include "template/template.hpp"
#include "geomeny/crosspoint.hpp"

int main() {
    Circle a;
    cin >> a.x >> a.y >> a.r;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Line b(2);
        cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y;
        auto res = crosspoint(a, b);
        sort(all(res), [](Point a, Point b) {
            if (a.x != b.x) {
                return a.x < b.x;
            }
            return a.y < b.y;
        });
        if (res.size() == 1) {
            cout << res[0].x << " " << res[0].y << " " << res[0].x << " " << res[0].y << endl;
        } else {
            cout << res[0].x << " " << res[0].y << " " << res[1].x << " " << res[1].y << endl;
        }
    }
}