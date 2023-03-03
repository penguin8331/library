#pragma once
#include "template/template.hpp"
#include "geomeny/geomeny-template.hpp"

int ccw_for_isconvex(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    return 0;
}

bool isConvex(vector<Point> &ps) {
    int n = (int)ps.size();
    for (int i = 0; i < n; ++i) {
        if (ccw_for_isconvex(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]) == -1) return false;
    }
    return true;
}