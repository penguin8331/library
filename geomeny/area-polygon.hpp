#pragma once
#include "../template/template.hpp"
#include "../geomeny/geomeny-template.hpp"

DD CalcArea(const vector<Point> &pol) {
    DD res = 0.0;
    for (int i = 0; i < (int)pol.size(); ++i) {
        res += cross(pol[i], pol[(i + 1) % pol.size()]);
    }
    return res / 2.0L;
}