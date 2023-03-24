#pragma once
#include "../template/template.hpp"
#include "../geomeny/geomeny-template.hpp"

int is_contain(const vector<Point> &pol, const Point &p) {
    int n = (int)pol.size();
    int isin = 0;
    for (int i = 0; i < n; ++i) {
        Point a = pol[i] - p, b = pol[(i + 1) % n] - p;
        if (a.y > b.y) swap(a, b);
        if (a.y <= 0 && b.y > 0)
            if (cross(a, b) < 0) isin = 1 - isin;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;
    }
    if (isin)
        return 2;
    else
        return 0;
}