#pragma once
#include "geomeny/geomeny-template.hpp"

// 一直線上の3点を含めない
vector<Point> ConvexHull(vector<Point> &ps) {
    int n = (int)ps.size();
    vector<Point> res(2 * n);
    sort(ps.begin(), ps.end());
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (k >= 2) {
            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < EPS) {
                --k;
                if (k < 2) break;
            }
        }
        res[k] = ps[i];
        ++k;
    }
    int t = k + 1;
    for (int i = n - 2; i >= 0; --i) {
        if (k >= t) {
            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < EPS) {
                --k;
                if (k < t) break;
            }
        }
        res[k] = ps[i];
        ++k;
    }
    res.resize(k - 1);
    return res;
}

// 一直線上の3点を含める
vector<Point> ConvexHullCollinearOK(vector<Point> &ps) {
    int n = (int)ps.size();
    vector<Point> res(2 * n);
    sort(ps.begin(), ps.end());
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (k >= 2) {
            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < -EPS) {
                --k;
                if (k < 2) break;
            }
        }
        res[k] = ps[i];
        ++k;
    }
    int t = k + 1;
    for (int i = n - 2; i >= 0; --i) {
        if (k >= t) {
            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < -EPS) {
                --k;
                if (k < t) break;
            }
        }
        res[k] = ps[i];
        ++k;
    }
    res.resize(k - 1);
    return res;
}