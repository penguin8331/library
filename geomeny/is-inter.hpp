#pragma once
#include "template/template.hpp"
#include "geomeny/projection.hpp"

int ccw_for_dis(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    if (dot(b - a, c - a) < -EPS) return 2;
    if (norm(b - a) < norm(c - a) - EPS) return -2;
    return 0;
}
bool isinterPL(const Point &p, const Line &l) {
    return (abs(p - proj(p, l)) < EPS);
}
bool isinterPS(const Point &p, const Line &s) {
    return (ccw_for_dis(s[0], s[1], p) == 0);
}
bool isinterLL(const Line &l, const Line &m) {
    return (abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||
            abs(cross(l[1] - l[0], m[0] - l[0])) < EPS);
}
bool isinterSS(const Line &s, const Line &t) {
    if (eq(s[0], s[1])) return isinterPS(s[0], t);
    if (eq(t[0], t[1])) return isinterPS(t[0], s);
    return (ccw_for_dis(s[0], s[1], t[0]) * ccw_for_dis(s[0], s[1], t[1]) <= 0 &&
            ccw_for_dis(t[0], t[1], s[0]) * ccw_for_dis(t[0], t[1], s[1]) <= 0);
}