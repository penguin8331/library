#pragma once
#include "../template/template.hpp"
#include "../geomeny/geomeny-template.hpp"

int simple_ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    return 0;
}

int ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    if (dot(b - a, c - a) < -EPS) return 2;
    if (norm(b - a) < norm(c - a) - EPS) return -2;
    return 0;
}