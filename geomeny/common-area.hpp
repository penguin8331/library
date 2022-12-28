#include "geomeny/crosspoint.hpp"

DD calc(const Circle &p, const Circle &q) {
    DD d = abs(p - q);
    if (d >= p.r + q.r - EPS) return 0;
    else if (d <= abs(p.r - q.r) + EPS) return min(p.r, q.r) * min(p.r, q.r) * PI;
    DD pcos = (p.r*p.r + d*d - q.r*q.r) / (p.r*d*2);
    DD pang = acosl(pcos);
    DD parea = p.r*p.r*pang - p.r*p.r*sin(pang*2)/2;
    DD qcos = (q.r*q.r + d*d - p.r*p.r) / (q.r*d*2);
    DD qang = acosl(qcos);
    DD qarea = q.r*q.r*qang - q.r*q.r*sin(qang*2)/2;
    return parea + qarea;
}

// 原点, 点 x, 点 y とで囲まれる領域の面積 (三角形 ver と扇型 ver)
DD calc_element(const Point &x, const Point &y, DD r, bool triangle) {
    if (triangle)
        return cross(x, y) / 2;
    else {
        Point tmp = y * Point(x.x, -x.y);
        DD ang = atan2(tmp.y, tmp.x);
        return r * r * ang / 2;
    }
}

// 円 C と、三角形 ((0, 0), ia, ib) との共通部分の面積
DD calc_common_area(const Circle &c, const Point &ia, const Point &ib) {
    Point a = ia - c, b = ib - c;
    if (abs(a - b) < EPS) return 0;
    bool isin_a = (abs(a) < c.r + EPS);
    bool isin_b = (abs(b) < c.r + EPS);
    if (isin_a && isin_b) return calc_element(a, b, c.r, true);
    Circle oc(Point(0, 0), c.r);
    Line seg(a, b);
    auto cr = crosspoint(oc, seg);
    if (cr.empty()) return calc_element(a, b, c.r, false);
    auto s = cr[0], t = cr.back();
    return calc_element(s, t, c.r, true) + calc_element(a, s, c.r, isin_a) + calc_element(t, b, c.r, isin_b);
}

// 円 c と多角形 pol の共通部分の面積
DD calc_common_area(const Circle &c, const vector<Point> &pol) {
    DD res = 0;
    int N = pol.size();
    for (int i = 0; i < N; ++i) {
        res += calc_common_area(c, pol[i], pol[(i + 1) % N]);
    }
    return res;
}