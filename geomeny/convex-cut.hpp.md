---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geomeny/geomeny-template.hpp\"\ncout << fixed << setprecision(8);\n\
    using DD = long double;     // to be set appropriately\nconst DD EPS = 1e-10;\
    \  // to be set appropriately\nconst DD PI = acosl(-1.0);\nDD torad(int deg) {\
    \ return (DD)(deg)*PI / 180; }\nDD todeg(DD ang) { return ang * 180 / PI; }\n\n\
    /* Point */\nstruct Point {\n    DD x, y;\n    Point(DD x = 0.0, DD y = 0.0) :\
    \ x(x), y(y) {}\n    friend ostream &operator<<(ostream &s, const Point &p) {\
    \ return s << '(' << p.x << \", \" << p.y << ')'; }\n};\ninline Point operator+(const\
    \ Point &p, const Point &q) { return Point(p.x + q.x, p.y + q.y); }\ninline Point\
    \ operator-(const Point &p, const Point &q) { return Point(p.x - q.x, p.y - q.y);\
    \ }\ninline Point operator*(const Point &p, DD a) { return Point(p.x * a, p.y\
    \ * a); }\ninline Point operator*(DD a, const Point &p) { return Point(a * p.x,\
    \ a * p.y); }\ninline Point operator*(const Point &p, const Point &q) { return\
    \ Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x); }\ninline Point operator/(const\
    \ Point &p, DD a) { return Point(p.x / a, p.y / a); }\ninline Point conj(const\
    \ Point &p) { return Point(p.x, -p.y); }\ninline Point rot(const Point &p, DD\
    \ ang) { return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang)\
    \ * p.y); }\ninline Point rot90(const Point &p) { return Point(-p.y, p.x); }\n\
    inline DD cross(const Point &p, const Point &q) { return p.x * q.y - p.y * q.x;\
    \ }\ninline DD dot(const Point &p, const Point &q) { return p.x * q.x + p.y *\
    \ q.y; }\ninline DD norm(const Point &p) { return dot(p, p); }\ninline DD abs(const\
    \ Point &p) { return sqrt(dot(p, p)); }\ninline DD amp(const Point &p) {\n   \
    \ DD res = atan2(p.y, p.x);\n    if (res < 0) res += PI * 2;\n    return res;\n\
    }\ninline bool eq(const Point &p, const Point &q) { return abs(p - q) < EPS; }\n\
    inline bool operator<(const Point &p, const Point &q) { return (abs(p.x - q.x)\
    \ > EPS ? p.x < q.x : p.y < q.y); }\ninline bool operator>(const Point &p, const\
    \ Point &q) { return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y); }\ninline\
    \ Point operator/(const Point &p, const Point &q) { return p * conj(q) / norm(q);\
    \ }\n\n/* Line */\nstruct Line : vector<Point> {\n    Line(Point a = Point(0.0,\
    \ 0.0), Point b = Point(0.0, 0.0)) {\n        this->push_back(a);\n        this->push_back(b);\n\
    \    }\n    friend ostream &operator<<(ostream &s, const Line &l) { return s <<\
    \ '{' << l[0] << \", \" << l[1] << '}'; }\n};\n\n/* Circle */\nstruct Circle :\
    \ Point {\n    DD r;\n    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p),\
    \ r(r) {}\n    friend ostream &operator<<(ostream &s, const Circle &c) { return\
    \ s << '(' << c.x << \", \" << c.y << \", \" << c.r << ')'; }\n};\n#line 2 \"\
    geomeny/convex-cut.hpp\"\n\n// convex cut\nint ccw_for_convexcut(const Point &a,\
    \ const Point &b, const Point &c) {\n    if (cross(b-a, c-a) > EPS) return 1;\n\
    \    if (cross(b-a, c-a) < -EPS) return -1;\n    if (dot(b-a, c-a) < -EPS) return\
    \ 2;\n    if (norm(b-a) < norm(c-a) - EPS) return -2;\n    return 0;\n}\nvector<Point>\
    \ crosspoint_for_convexcut(const Line &l, const Line &m) {\n    vector<Point>\
    \ res;\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\n    if (abs(d) < EPS) return\
    \ vector<Point>();\n    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1] - m[0],\
    \ m[1] - l[0]) / d);\n    return res;\n}\nvector<Point> ConvexCut(const vector<Point>\
    \ &pol, const Line &l) {\n    vector<Point> res;\n    for (int i = 0; i < pol.size();\
    \ ++i) {\n        Point p = pol[i], q = pol[(i+1)%pol.size()];\n        if (ccw_for_convexcut(l[0],\
    \ l[1], p) != -1) {\n            if (res.size() == 0) res.push_back(p);\n    \
    \        else if (!eq(p, res[res.size()-1])) res.push_back(p);\n        }\n  \
    \      if (ccw_for_convexcut(l[0], l[1], p) * ccw_for_convexcut(l[0], l[1], q)\
    \ < 0) {\n            vector<Point> temp = crosspoint_for_convexcut(Line(p, q),\
    \ l);\n            if (temp.size() == 0) continue;\n            else if (res.size()\
    \ == 0) res.push_back(temp[0]);\n            else if (!eq(temp[0], res[res.size()-1]))\
    \ res.push_back(temp[0]);\n        }\n    }\n    return res;\n}\n"
  code: "#include\"geomeny/geomeny-template.hpp\"\n\n// convex cut\nint ccw_for_convexcut(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b-a, c-a) > EPS)\
    \ return 1;\n    if (cross(b-a, c-a) < -EPS) return -1;\n    if (dot(b-a, c-a)\
    \ < -EPS) return 2;\n    if (norm(b-a) < norm(c-a) - EPS) return -2;\n    return\
    \ 0;\n}\nvector<Point> crosspoint_for_convexcut(const Line &l, const Line &m)\
    \ {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\n   \
    \ if (abs(d) < EPS) return vector<Point>();\n    res.push_back(l[0] + (l[1] -\
    \ l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);\n    return res;\n}\nvector<Point>\
    \ ConvexCut(const vector<Point> &pol, const Line &l) {\n    vector<Point> res;\n\
    \    for (int i = 0; i < pol.size(); ++i) {\n        Point p = pol[i], q = pol[(i+1)%pol.size()];\n\
    \        if (ccw_for_convexcut(l[0], l[1], p) != -1) {\n            if (res.size()\
    \ == 0) res.push_back(p);\n            else if (!eq(p, res[res.size()-1])) res.push_back(p);\n\
    \        }\n        if (ccw_for_convexcut(l[0], l[1], p) * ccw_for_convexcut(l[0],\
    \ l[1], q) < 0) {\n            vector<Point> temp = crosspoint_for_convexcut(Line(p,\
    \ q), l);\n            if (temp.size() == 0) continue;\n            else if (res.size()\
    \ == 0) res.push_back(temp[0]);\n            else if (!eq(temp[0], res[res.size()-1]))\
    \ res.push_back(temp[0]);\n        }\n    }\n    return res;\n}"
  dependsOn:
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/convex-cut.hpp
  requiredBy: []
  timestamp: '2022-12-27 11:46:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geomeny/convex-cut.hpp
layout: document
title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
---
