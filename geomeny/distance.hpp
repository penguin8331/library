#include "geomeny/is-inter.hpp"

DD distancePL(const Point &p, const Line &l) {
    return abs(p - proj(p, l));
}
DD distancePS(const Point &p, const Line &s) {
    Point h = proj(p, s);
    if (isinterPS(h, s)) return abs(p - h);
    return min(abs(p - s[0]), abs(p - s[1]));
}
DD distanceLL(const Line &l, const Line &m) {
    if (isinterLL(l, m))
        return 0;
    else
        return distancePL(m[0], l);
}
DD distanceSS(const Line &s, const Line &t) {
    if (isinterSS(s, t))
        return 0;
    else
        return min(min(distancePS(s[0], t), distancePS(s[1], t)), min(distancePS(t[0], s), distancePS(t[1], s)));
}