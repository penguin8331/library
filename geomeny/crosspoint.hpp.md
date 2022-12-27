---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_C.test.cpp
    title: test/AOJ/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_7_D.test.cpp
    title: test/AOJ/CGL_7_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ \", \" << c.y << \", \" << c.r << ')'; }\n};\n#line 2 \"geomeny/crosspoint.hpp\"\
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
    \   return res;\n}\n"
  code: "#include \"geomeny/geomeny-template.hpp\"\n\nPoint proj_for_crosspoint(const\
    \ Point &p, const Line &l) {\n    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1]\
    \ - l[0]);\n    return l[0] + (l[1] - l[0]) * t;\n}\nvector<Point> crosspoint(const\
    \ Line &l, const Line &m) {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0],\
    \ l[1] - l[0]);\n    if (abs(d) < EPS) return vector<Point>();\n    res.push_back(l[0]\
    \ + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);\n    return res;\n}\n\
    vector<Point> crosspoint(const Circle &e, const Circle &f) {\n    vector<Point>\
    \ res;\n    DD d = abs(e - f);\n    if (d < EPS) return vector<Point>();\n   \
    \ if (d > e.r + f.r + EPS) return vector<Point>();\n    if (d < abs(e.r - f.r)\
    \ - EPS) return vector<Point>();\n    DD rcos = (d * d + e.r * e.r - f.r * f.r)\
    \ / (2.0 * d), rsin;\n    if (e.r - abs(rcos) < EPS)\n        rsin = 0;\n    else\n\
    \        rsin = sqrt(e.r * e.r - rcos * rcos);\n    Point dir = (f - e) / d;\n\
    \    Point p1 = e + dir * Point(rcos, rsin);\n    Point p2 = e + dir * Point(rcos,\
    \ -rsin);\n    res.push_back(p1);\n    if (!eq(p1, p2)) res.push_back(p2);\n \
    \   return res;\n}\nvector<Point> crosspoint(const Circle &e, const Line &l) {\n\
    \    vector<Point> res;\n    Point p = proj_for_crosspoint(e, l);\n    DD rcos\
    \ = abs(e - p), rsin;\n    if (rcos > e.r + EPS)\n        return vector<Point>();\n\
    \    else if (e.r - rcos < EPS)\n        rsin = 0;\n    else\n        rsin = sqrt(e.r\
    \ * e.r - rcos * rcos);\n    Point dir = (l[1] - l[0]) / abs(l[1] - l[0]);\n \
    \   Point p1 = p + dir * rsin;\n    Point p2 = p - dir * rsin;\n    res.push_back(p1);\n\
    \    if (!eq(p1, p2)) res.push_back(p2);\n    return res;\n}"
  dependsOn:
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/crosspoint.hpp
  requiredBy: []
  timestamp: '2022-12-27 15:24:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/CGL_2_C.test.cpp
  - test/AOJ/CGL_7_D.test.cpp
documentation_of: geomeny/crosspoint.hpp
layout: document
title: "\u4EA4\u70B9"
---
