#pragma once
#include "../template/template.hpp"
#include "../geomeny/geomeny-template.hpp"

// 粗
// 1：a-bから見てcは左側(反時計回り)、-1：a-bから見てcは右側(時計回り)、0：一直線上
int simple_ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    return 0;
}

// 精
// 1：a-bから見てcは左側(反時計回り)、-1：a-bから見てcは右側(時計回り)
// 2：c-a-bの順に一直線上、-2：a-b-cの順に一直線上、0：a-c-bの順に一直線上
int ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    if (dot(b - a, c - a) < -EPS) return 2;
    if (norm(b - a) < norm(c - a) - EPS) return -2;
    return 0;
}