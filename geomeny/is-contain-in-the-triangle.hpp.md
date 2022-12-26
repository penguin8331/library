---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geomeny/ccw.hpp
    title: "\u70B9\u3068\u7DDA\u5206\u306E\u4F4D\u7F6E\u95A2\u4FC2"
  - icon: ':warning:'
    path: geomeny/geomeny-template.hpp
    title: geomeny/geomeny-template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geomeny/geomeny-template.hpp\"\nusing DD = double;     //\
    \ to be set appropriately\nconst DD EPS = 1e-10;  // to be set appropriately\n\
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
    \ \", \" << c.y << \", \" << c.r << ')'; }\n};\n#line 2 \"geomeny/ccw.hpp\"\n\n\
    // \u7C97\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074(\u53CD\u6642\
    \u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u53F3\u5074\
    (\u6642\u8A08\u56DE\u308A)\u30010\uFF1A\u4E00\u76F4\u7DDA\u4E0A\nint simple_ccw(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    return 0;\n}\n\
    \n// \u7CBE\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074(\u53CD\u6642\
    \u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u53F3\u5074\
    (\u6642\u8A08\u56DE\u308A)\n// 2\uFF1Ac-a-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\
    \u4E0A\u3001-2\uFF1Aa-b-c\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u30010\uFF1A\
    a-c-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\nint ccw(const Point &a, const\
    \ Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS) return 1;\n\
    \    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a, c - a) < -EPS)\
    \ return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n    return 0;\n\
    }\n#line 2 \"geomeny/is-contain-in-the-triangle.hpp\"\n\n// \u8FBA\u4E0A\u306B\
    \u3064\u3044\u3066\u306F\u5224\u5B9A\u3057\u3066\u3044\u306A\u3044\nbool is_contain(const\
    \ Point &p, const Point &a, const Point &b, const Point &c) {\n    int r1 = simple_ccw(p,\
    \ b, c), r2 = simple_ccw(p, c, a), r3 = simple_ccw(p, a, b);\n    if (r1 == 1\
    \ && r2 == 1 && r3 == 1) return true;\n    if (r1 == -1 && r2 == -1 && r3 == -1)\
    \ return true;\n    return false;\n}\n"
  code: "#include\"geomeny/ccw.hpp\"\n\n// \u8FBA\u4E0A\u306B\u3064\u3044\u3066\u306F\
    \u5224\u5B9A\u3057\u3066\u3044\u306A\u3044\nbool is_contain(const Point &p, const\
    \ Point &a, const Point &b, const Point &c) {\n    int r1 = simple_ccw(p, b, c),\
    \ r2 = simple_ccw(p, c, a), r3 = simple_ccw(p, a, b);\n    if (r1 == 1 && r2 ==\
    \ 1 && r3 == 1) return true;\n    if (r1 == -1 && r2 == -1 && r3 == -1) return\
    \ true;\n    return false;\n}"
  dependsOn:
  - geomeny/ccw.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/is-contain-in-the-triangle.hpp
  requiredBy: []
  timestamp: '2022-12-26 18:00:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geomeny/is-contain-in-the-triangle.hpp
layout: document
redirect_from:
- /library/geomeny/is-contain-in-the-triangle.hpp
- /library/geomeny/is-contain-in-the-triangle.hpp.html
title: geomeny/is-contain-in-the-triangle.hpp
---