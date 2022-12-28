#include "geomeny/geomeny-template.hpp"

Point proj(const Point &p, const Line &l) {
    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);
    return l[0] + (l[1] - l[0]) * t;
}
Point refl(const Point &p, const Line &l) {
    return p + (proj(p, l) - p) * 2;
}