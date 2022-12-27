#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0143"
#include "template/template.hpp"
#include "geomeny/is-contain-in-the-triangle.hpp"

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Point a, b, c, d, e;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y >> e.x >> e.y;
        if (is_contain(d, a, b, c) == is_contain(e, a, b, c)) {
            cout << "NG" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
}