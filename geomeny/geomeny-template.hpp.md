---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geomeny/area-polygon.hpp
    title: "\u591A\u89D2\u5F62\u306E\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geomeny/ccw.hpp
    title: "\u70B9\u3068\u7DDA\u5206\u306E\u4F4D\u7F6E\u95A2\u4FC2"
  - icon: ':heavy_check_mark:'
    path: geomeny/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geomeny/convex-hull.hpp
    title: "\u51F8\u5305"
  - icon: ':heavy_check_mark:'
    path: geomeny/crosspoint.hpp
    title: "\u4EA4\u70B9"
  - icon: ':heavy_check_mark:'
    path: geomeny/distance.hpp
    title: "\u8DDD\u96E2"
  - icon: ':heavy_check_mark:'
    path: geomeny/is-contain-in-the-polygon.hpp
    title: "\u70B9\u3068\u591A\u89D2\u5F62\u306E\u5305\u542B\u95A2\u4FC2"
  - icon: ':heavy_check_mark:'
    path: geomeny/is-convex.hpp
    title: "\u51F8\u6027\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geomeny/is-inter.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geomeny/projection.hpp
    title: "\u5C04\u5F71"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_A.test.cpp
    title: test/AOJ/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_1_C.test.cpp
    title: test/AOJ/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_B.test.cpp
    title: test/AOJ/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_C.test.cpp
    title: test/AOJ/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_D.test.cpp
    title: test/AOJ/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_A.test.cpp
    title: test/AOJ/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_B.test.cpp
    title: test/AOJ/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_3_C.test.cpp
    title: test/AOJ/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_4_A.test.cpp
    title: test/AOJ/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_4_C.test.cpp
    title: test/AOJ/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_7_D.test.cpp
    title: test/AOJ/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_7_E.test.cpp
    title: test/AOJ/CGL_7_E.test.cpp
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
    \ \", \" << c.y << \", \" << c.r << ')'; }\n};\n"
  code: "#pragma once\nusing DD = long double;     // to be set appropriately\nconst\
    \ DD EPS = 1e-10;  // to be set appropriately\nconst DD PI = acosl(-1.0);\nDD\
    \ torad(int deg) { return (DD)(deg)*PI / 180; }\nDD todeg(DD ang) { return ang\
    \ * 180 / PI; }\n\n/* Point */\nstruct Point {\n    DD x, y;\n    Point(DD x =\
    \ 0.0, DD y = 0.0) : x(x), y(y) {}\n    friend ostream &operator<<(ostream &s,\
    \ const Point &p) { return s << '(' << p.x << \", \" << p.y << ')'; }\n};\ninline\
    \ Point operator+(const Point &p, const Point &q) { return Point(p.x + q.x, p.y\
    \ + q.y); }\ninline Point operator-(const Point &p, const Point &q) { return Point(p.x\
    \ - q.x, p.y - q.y); }\ninline Point operator*(const Point &p, DD a) { return\
    \ Point(p.x * a, p.y * a); }\ninline Point operator*(DD a, const Point &p) { return\
    \ Point(a * p.x, a * p.y); }\ninline Point operator*(const Point &p, const Point\
    \ &q) { return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x); }\ninline\
    \ Point operator/(const Point &p, DD a) { return Point(p.x / a, p.y / a); }\n\
    inline Point conj(const Point &p) { return Point(p.x, -p.y); }\ninline Point rot(const\
    \ Point &p, DD ang) { return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) *\
    \ p.x + cos(ang) * p.y); }\ninline Point rot90(const Point &p) { return Point(-p.y,\
    \ p.x); }\ninline DD cross(const Point &p, const Point &q) { return p.x * q.y\
    \ - p.y * q.x; }\ninline DD dot(const Point &p, const Point &q) { return p.x *\
    \ q.x + p.y * q.y; }\ninline DD norm(const Point &p) { return dot(p, p); }\ninline\
    \ DD abs(const Point &p) { return sqrt(dot(p, p)); }\ninline DD amp(const Point\
    \ &p) {\n    DD res = atan2(p.y, p.x);\n    if (res < 0) res += PI * 2;\n    return\
    \ res;\n}\ninline bool eq(const Point &p, const Point &q) { return abs(p - q)\
    \ < EPS; }\ninline bool operator<(const Point &p, const Point &q) { return (abs(p.x\
    \ - q.x) > EPS ? p.x < q.x : p.y < q.y); }\ninline bool operator>(const Point\
    \ &p, const Point &q) { return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y);\
    \ }\ninline Point operator/(const Point &p, const Point &q) { return p * conj(q)\
    \ / norm(q); }\n\n/* Line */\nstruct Line : vector<Point> {\n    Line(Point a\
    \ = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {\n        this->push_back(a);\n\
    \        this->push_back(b);\n    }\n    friend ostream &operator<<(ostream &s,\
    \ const Line &l) { return s << '{' << l[0] << \", \" << l[1] << '}'; }\n};\n\n\
    /* Circle */\nstruct Circle : Point {\n    DD r;\n    Circle(Point p = Point(0.0,\
    \ 0.0), DD r = 0.0) : Point(p), r(r) {}\n    friend ostream &operator<<(ostream\
    \ &s, const Circle &c) { return s << '(' << c.x << \", \" << c.y << \", \" <<\
    \ c.r << ')'; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: geomeny/geomeny-template.hpp
  requiredBy:
  - geomeny/convex-cut.hpp
  - geomeny/projection.hpp
  - geomeny/is-contain-in-the-polygon.hpp
  - geomeny/area-polygon.hpp
  - geomeny/distance.hpp
  - geomeny/is-inter.hpp
  - geomeny/ccw.hpp
  - geomeny/is-convex.hpp
  - geomeny/convex-hull.hpp
  - geomeny/crosspoint.hpp
  timestamp: '2022-12-27 15:24:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/CGL_3_C.test.cpp
  - test/AOJ/CGL_2_C.test.cpp
  - test/AOJ/CGL_2_B.test.cpp
  - test/AOJ/CGL_1_A.test.cpp
  - test/AOJ/CGL_7_E.test.cpp
  - test/AOJ/CGL_1_C.test.cpp
  - test/AOJ/CGL_7_D.test.cpp
  - test/AOJ/CGL_3_B.test.cpp
  - test/AOJ/CGL_4_A.test.cpp
  - test/AOJ/CGL_4_C.test.cpp
  - test/AOJ/CGL_3_A.test.cpp
  - test/AOJ/CGL_2_D.test.cpp
documentation_of: geomeny/geomeny-template.hpp
layout: document
title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
