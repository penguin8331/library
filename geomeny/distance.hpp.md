---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: geomeny/is-inter.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':heavy_check_mark:'
    path: geomeny/projection.hpp
    title: "\u5C04\u5F71"
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
    \ \", \" << c.y << \", \" << c.r << ')'; }\n};\n#line 2 \"geomeny/projection.hpp\"\
    \n\nPoint proj(const Point &p, const Line &l) {\n    DD t = dot(p - l[0], l[1]\
    \ - l[0]) / norm(l[1] - l[0]);\n    return l[0] + (l[1] - l[0]) * t;\n}\nPoint\
    \ refl(const Point &p, const Line &l) {\n    return p + (proj(p, l) - p) * 2;\n\
    }\n#line 2 \"geomeny/is-inter.hpp\"\n\nint ccw_for_dis(const Point &a, const Point\
    \ &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS) return 1;\n    if\
    \ (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a, c - a) < -EPS) return\
    \ 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n    return 0;\n}\n\
    bool isinterPL(const Point &p, const Line &l) {\n    return (abs(p - proj(p, l))\
    \ < EPS);\n}\nbool isinterPS(const Point &p, const Line &s) {\n    return (ccw_for_dis(s[0],\
    \ s[1], p) == 0);\n}\nbool isinterLL(const Line &l, const Line &m) {\n    return\
    \ (abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||\n            abs(cross(l[1] -\
    \ l[0], m[0] - l[0])) < EPS);\n}\nbool isinterSS(const Line &s, const Line &t)\
    \ {\n    if (eq(s[0], s[1])) return isinterPS(s[0], t);\n    if (eq(t[0], t[1]))\
    \ return isinterPS(t[0], s);\n    return (ccw_for_dis(s[0], s[1], t[0]) * ccw_for_dis(s[0],\
    \ s[1], t[1]) <= 0 &&\n            ccw_for_dis(t[0], t[1], s[0]) * ccw_for_dis(t[0],\
    \ t[1], s[1]) <= 0);\n}\n#line 2 \"geomeny/distance.hpp\"\n\nDD distancePL(const\
    \ Point &p, const Line &l) {\n    return abs(p - proj(p, l));\n}\nDD distancePS(const\
    \ Point &p, const Line &s) {\n    Point h = proj(p, s);\n    if (isinterPS(h,\
    \ s)) return abs(p - h);\n    return min(abs(p - s[0]), abs(p - s[1]));\n}\nDD\
    \ distanceLL(const Line &l, const Line &m) {\n    if (isinterLL(l, m))\n     \
    \   return 0;\n    else\n        return distancePL(m[0], l);\n}\nDD distanceSS(const\
    \ Line &s, const Line &t) {\n    if (isinterSS(s, t))\n        return 0;\n   \
    \ else\n        return min(min(distancePS(s[0], t), distancePS(s[1], t)), min(distancePS(t[0],\
    \ s), distancePS(t[1], s)));\n}\n"
  code: "#include \"geomeny/is-inter.hpp\"\n\nDD distancePL(const Point &p, const\
    \ Line &l) {\n    return abs(p - proj(p, l));\n}\nDD distancePS(const Point &p,\
    \ const Line &s) {\n    Point h = proj(p, s);\n    if (isinterPS(h, s)) return\
    \ abs(p - h);\n    return min(abs(p - s[0]), abs(p - s[1]));\n}\nDD distanceLL(const\
    \ Line &l, const Line &m) {\n    if (isinterLL(l, m))\n        return 0;\n   \
    \ else\n        return distancePL(m[0], l);\n}\nDD distanceSS(const Line &s, const\
    \ Line &t) {\n    if (isinterSS(s, t))\n        return 0;\n    else\n        return\
    \ min(min(distancePS(s[0], t), distancePS(s[1], t)), min(distancePS(t[0], s),\
    \ distancePS(t[1], s)));\n}"
  dependsOn:
  - geomeny/is-inter.hpp
  - geomeny/projection.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/distance.hpp
  requiredBy: []
  timestamp: '2022-12-27 15:24:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geomeny/distance.hpp
layout: document
title: "\u8DDD\u96E2"
---
