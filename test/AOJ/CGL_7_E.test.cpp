#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 0.000001
#include "../../template/template.hpp"
#include "../../geomeny/crosspoint.hpp"

int main() {
    Circle a, b;
    cin >> a.x >> a.y >> a.r >> b.x >> b.y >> b.r;
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