#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C"
#include "../../geomeny/ccw.hpp"
#include "../../template/template.hpp"

int main() {
    Point a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        Point c;
        cin >> c.x >> c.y;
        int res = ccw(a, b, c);
        if (res == -1) {
            cout << "CLOCKWISE" << endl;
        }
        elif (res == 1) { cout << "COUNTER_CLOCKWISE" << endl; }
        elif (res == 2) { cout << "ONLINE_BACK" << endl; }
        elif (res == -2) { cout << "ONLINE_FRONT" << endl; }
        else {
            cout << "ON_SEGMENT" << endl;
        }
    }
}