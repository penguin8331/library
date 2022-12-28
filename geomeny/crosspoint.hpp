#include "geomeny/geomeny-template.hpp"

Point proj_for_crosspoint(const Point &p, const Line &l) {
    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
    return l[0] + (l[1] - l[0]) * t;
}
vector<Point> crosspoint(const Line &l, const Line &m) {
    vector<Point> res;
    DD d = cross(m[1] - m[0], l[1] - l[0]);
    if (abs(d) < EPS) return vector<Point>();
    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);
    return res;
}
vector<Point> crosspoint(const Circle &e, const Circle &f) {
    vector<Point> res;
    DD d = abs(e - f);
    if (d < EPS) return vector<Point>();
    if (d > e.r + f.r + EPS) return vector<Point>();
    if (d < abs(e.r - f.r) - EPS) return vector<Point>();
    DD rcos = (d * d + e.r * e.r - f.r * f.r) / (2.0 * d), rsin;
    if (e.r - abs(rcos) < EPS)
        rsin = 0;
    else
        rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (f - e) / d;
    Point p1 = e + dir * Point(rcos, rsin);
    Point p2 = e + dir * Point(rcos, -rsin);
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}
vector<Point> crosspoint(const Circle &e, const Line &l) {
    vector<Point> res;
    Point p = proj_for_crosspoint(e, l);
    DD rcos = abs(e - p), rsin;
    if (rcos > e.r + EPS)
        return vector<Point>();
    else if (e.r - rcos < EPS)
        rsin = 0;
    else
        rsin = sqrt(e.r * e.r - rcos * rcos);
    Point dir = (l[1] - l[0]) / abs(l[1] - l[0]);
    Point p1 = p + dir * rsin;
    Point p2 = p - dir * rsin;
    res.push_back(p1);
    if (!eq(p1, p2)) res.push_back(p2);
    return res;
}