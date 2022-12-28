---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/crosspoint.hpp
    title: "\u4EA4\u70B9"
  - icon: ':heavy_check_mark:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geomeny/geomeny-template.hpp\"\nusing DD = long double;\
    \     // to be set appropriately\nconst DD EPS = 1e-10;  // to be set appropriately\n\
    const DD PI = acosl(-1.0);\nDD torad(int deg) { return (DD)(deg)*PI / 180; }\n\
    DD todeg(DD ang) { return ang * 180 / PI; }\n\n/* Point */\nstruct Point {\n \
    \   DD x, y;\n    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}\n    friend ostream\
    \ &operator<<(ostream &s, const Point &p) { return s << '(' << p.x << \", \" <<\
    \ p.y << ')'; }\n};\ninline Point operator+(const Point &p, const Point &q) {\
    \ return Point(p.x + q.x, p.y + q.y); }\ninline Point operator-(const Point &p,\
    \ const Point &q) { return Point(p.x - q.x, p.y - q.y); }\ninline Point operator*(const\
    \ Point &p, DD a) { return Point(p.x * a, p.y * a); }\ninline Point operator*(DD\
    \ a, const Point &p) { return Point(a * p.x, a * p.y); }\ninline Point operator*(const\
    \ Point &p, const Point &q) { return Point(p.x * q.x - p.y * q.y, p.x * q.y +\
    \ p.y * q.x); }\ninline Point operator/(const Point &p, DD a) { return Point(p.x\
    \ / a, p.y / a); }\ninline Point conj(const Point &p) { return Point(p.x, -p.y);\
    \ }\ninline Point rot(const Point &p, DD ang) { return Point(cos(ang) * p.x -\
    \ sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y); }\ninline Point rot90(const\
    \ Point &p) { return Point(-p.y, p.x); }\ninline DD cross(const Point &p, const\
    \ Point &q) { return p.x * q.y - p.y * q.x; }\ninline DD dot(const Point &p, const\
    \ Point &q) { return p.x * q.x + p.y * q.y; }\ninline DD norm(const Point &p)\
    \ { return dot(p, p); }\ninline DD abs(const Point &p) { return sqrt(dot(p, p));\
    \ }\ninline DD amp(const Point &p) {\n    DD res = atan2(p.y, p.x);\n    if (res\
    \ < 0) res += PI * 2;\n    return res;\n}\ninline bool eq(const Point &p, const\
    \ Point &q) { return abs(p - q) < EPS; }\ninline bool operator<(const Point &p,\
    \ const Point &q) { return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y); }\n\
    inline bool operator>(const Point &p, const Point &q) { return (abs(p.x - q.x)\
    \ > EPS ? p.x > q.x : p.y > q.y); }\ninline Point operator/(const Point &p, const\
    \ Point &q) { return p * conj(q) / norm(q); }\n\n/* Line */\nstruct Line : vector<Point>\
    \ {\n    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {\n      \
    \  this->push_back(a);\n        this->push_back(b);\n    }\n    friend ostream\
    \ &operator<<(ostream &s, const Line &l) { return s << '{' << l[0] << \", \" <<\
    \ l[1] << '}'; }\n};\n\n/* Circle */\nstruct Circle : Point {\n    DD r;\n   \
    \ Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}\n    friend\
    \ ostream &operator<<(ostream &s, const Circle &c) { return s << '(' << c.x <<\
    \ \", \" << c.y << \", \" << c.r << ')'; }\n};\n#line 3 \"geomeny/crosspoint.hpp\"\
    \n\nPoint proj_for_crosspoint(const Point &p, const Line &l) {\n    DD t = dot(p\
    \ - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\n    return l[0] + (l[1] - l[0]) *\
    \ t;\n}\nvector<Point> crosspoint(const Line &l, const Line &m) {\n    vector<Point>\
    \ res;\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\n    if (abs(d) < EPS) return\
    \ vector<Point>();\n    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0],\
    \ m[1] - l[0]) / d);\n    return res;\n}\nvector<Point> crosspoint(const Circle\
    \ &e, const Circle &f) {\n    vector<Point> res;\n    DD d = abs(e - f);\n   \
    \ if (d < EPS) return vector<Point>();\n    if (d > e.r + f.r + EPS) return vector<Point>();\n\
    \    if (d < abs(e.r - f.r) - EPS) return vector<Point>();\n    DD rcos = (d *\
    \ d + e.r * e.r - f.r * f.r) / (2.0 * d), rsin;\n    if (e.r - abs(rcos) < EPS)\n\
    \        rsin = 0;\n    else\n        rsin = sqrt(e.r * e.r - rcos * rcos);\n\
    \    Point dir = (f - e) / d;\n    Point p1 = e + dir * Point(rcos, rsin);\n \
    \   Point p2 = e + dir * Point(rcos, -rsin);\n    res.push_back(p1);\n    if (!eq(p1,\
    \ p2)) res.push_back(p2);\n    return res;\n}\nvector<Point> crosspoint(const\
    \ Circle &e, const Line &l) {\n    vector<Point> res;\n    Point p = proj_for_crosspoint(e,\
    \ l);\n    DD rcos = abs(e - p), rsin;\n    if (rcos > e.r + EPS)\n        return\
    \ vector<Point>();\n    else if (e.r - rcos < EPS)\n        rsin = 0;\n    else\n\
    \        rsin = sqrt(e.r * e.r - rcos * rcos);\n    Point dir = (l[1] - l[0])\
    \ / abs(l[1] - l[0]);\n    Point p1 = p + dir * rsin;\n    Point p2 = p - dir\
    \ * rsin;\n    res.push_back(p1);\n    if (!eq(p1, p2)) res.push_back(p2);\n \
    \   return res;\n}\n#line 3 \"geomeny/common-area.hpp\"\n\nDD calc(const Circle\
    \ &p, const Circle &q) {\n    DD d = abs(p - q);\n    if (d >= p.r + q.r - EPS)\
    \ return 0;\n    else if (d <= abs(p.r - q.r) + EPS) return min(p.r, q.r) * min(p.r,\
    \ q.r) * PI;\n    DD pcos = (p.r*p.r + d*d - q.r*q.r) / (p.r*d*2);\n    DD pang\
    \ = acosl(pcos);\n    DD parea = p.r*p.r*pang - p.r*p.r*sin(pang*2)/2;\n    DD\
    \ qcos = (q.r*q.r + d*d - p.r*p.r) / (q.r*d*2);\n    DD qang = acosl(qcos);\n\
    \    DD qarea = q.r*q.r*qang - q.r*q.r*sin(qang*2)/2;\n    return parea + qarea;\n\
    }\n\n// \u539F\u70B9, \u70B9 x, \u70B9 y \u3068\u3067\u56F2\u307E\u308C\u308B\u9818\
    \u57DF\u306E\u9762\u7A4D (\u4E09\u89D2\u5F62 ver \u3068\u6247\u578B ver)\nDD calc_element(const\
    \ Point &x, const Point &y, DD r, bool triangle) {\n    if (triangle)\n      \
    \  return cross(x, y) / 2;\n    else {\n        Point tmp = y * Point(x.x, -x.y);\n\
    \        DD ang = atan2(tmp.y, tmp.x);\n        return r * r * ang / 2;\n    }\n\
    }\n\n// \u5186 C \u3068\u3001\u4E09\u89D2\u5F62 ((0, 0), ia, ib) \u3068\u306E\u5171\
    \u901A\u90E8\u5206\u306E\u9762\u7A4D\nDD calc_common_area(const Circle &c, const\
    \ Point &ia, const Point &ib) {\n    Point a = ia - c, b = ib - c;\n    if (abs(a\
    \ - b) < EPS) return 0;\n    bool isin_a = (abs(a) < c.r + EPS);\n    bool isin_b\
    \ = (abs(b) < c.r + EPS);\n    if (isin_a && isin_b) return calc_element(a, b,\
    \ c.r, true);\n    Circle oc(Point(0, 0), c.r);\n    Line seg(a, b);\n    auto\
    \ cr = crosspoint(oc, seg);\n    if (cr.empty()) return calc_element(a, b, c.r,\
    \ false);\n    auto s = cr[0], t = cr.back();\n    return calc_element(s, t, c.r,\
    \ true) + calc_element(a, s, c.r, isin_a) + calc_element(t, b, c.r, isin_b);\n\
    }\n\n// \u5186 c \u3068\u591A\u89D2\u5F62 pol \u306E\u5171\u901A\u90E8\u5206\u306E\
    \u9762\u7A4D\nDD calc_common_area(const Circle &c, const vector<Point> &pol) {\n\
    \    DD res = 0;\n    int N = pol.size();\n    for (int i = 0; i < N; ++i) {\n\
    \        res += calc_common_area(c, pol[i], pol[(i + 1) % N]);\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"geomeny/crosspoint.hpp\"\n\nDD calc(const Circle\
    \ &p, const Circle &q) {\n    DD d = abs(p - q);\n    if (d >= p.r + q.r - EPS)\
    \ return 0;\n    else if (d <= abs(p.r - q.r) + EPS) return min(p.r, q.r) * min(p.r,\
    \ q.r) * PI;\n    DD pcos = (p.r*p.r + d*d - q.r*q.r) / (p.r*d*2);\n    DD pang\
    \ = acosl(pcos);\n    DD parea = p.r*p.r*pang - p.r*p.r*sin(pang*2)/2;\n    DD\
    \ qcos = (q.r*q.r + d*d - p.r*p.r) / (q.r*d*2);\n    DD qang = acosl(qcos);\n\
    \    DD qarea = q.r*q.r*qang - q.r*q.r*sin(qang*2)/2;\n    return parea + qarea;\n\
    }\n\n// \u539F\u70B9, \u70B9 x, \u70B9 y \u3068\u3067\u56F2\u307E\u308C\u308B\u9818\
    \u57DF\u306E\u9762\u7A4D (\u4E09\u89D2\u5F62 ver \u3068\u6247\u578B ver)\nDD calc_element(const\
    \ Point &x, const Point &y, DD r, bool triangle) {\n    if (triangle)\n      \
    \  return cross(x, y) / 2;\n    else {\n        Point tmp = y * Point(x.x, -x.y);\n\
    \        DD ang = atan2(tmp.y, tmp.x);\n        return r * r * ang / 2;\n    }\n\
    }\n\n// \u5186 C \u3068\u3001\u4E09\u89D2\u5F62 ((0, 0), ia, ib) \u3068\u306E\u5171\
    \u901A\u90E8\u5206\u306E\u9762\u7A4D\nDD calc_common_area(const Circle &c, const\
    \ Point &ia, const Point &ib) {\n    Point a = ia - c, b = ib - c;\n    if (abs(a\
    \ - b) < EPS) return 0;\n    bool isin_a = (abs(a) < c.r + EPS);\n    bool isin_b\
    \ = (abs(b) < c.r + EPS);\n    if (isin_a && isin_b) return calc_element(a, b,\
    \ c.r, true);\n    Circle oc(Point(0, 0), c.r);\n    Line seg(a, b);\n    auto\
    \ cr = crosspoint(oc, seg);\n    if (cr.empty()) return calc_element(a, b, c.r,\
    \ false);\n    auto s = cr[0], t = cr.back();\n    return calc_element(s, t, c.r,\
    \ true) + calc_element(a, s, c.r, isin_a) + calc_element(t, b, c.r, isin_b);\n\
    }\n\n// \u5186 c \u3068\u591A\u89D2\u5F62 pol \u306E\u5171\u901A\u90E8\u5206\u306E\
    \u9762\u7A4D\nDD calc_common_area(const Circle &c, const vector<Point> &pol) {\n\
    \    DD res = 0;\n    int N = pol.size();\n    for (int i = 0; i < N; ++i) {\n\
    \        res += calc_common_area(c, pol[i], pol[(i + 1) % N]);\n    }\n    return\
    \ res;\n}"
  dependsOn:
  - geomeny/crosspoint.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/common-area.hpp
  requiredBy: []
  timestamp: '2022-12-28 12:42:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geomeny/common-area.hpp
layout: document
redirect_from:
- /library/geomeny/common-area.hpp
- /library/geomeny/common-area.hpp.html
title: geomeny/common-area.hpp
---
