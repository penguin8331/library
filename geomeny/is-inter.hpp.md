---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: geomeny/projection.hpp
    title: "\u5C04\u5F71"
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geomeny/distance.hpp
    title: "\u8DDD\u96E2"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_B.test.cpp
    title: test/AOJ/CGL_2_B.test.cpp
  - icon: ':x:'
    path: test/AOJ/CGL_2_D.test.cpp
    title: test/AOJ/CGL_2_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\nusing\
    \ pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n};\n#line 7\
    \ \"template/template.hpp\"\nusing namespace std;\n#line 3 \"geomeny/geomeny-template.hpp\"\
    \n\nusing DD = long double;  // to be set appropriately\nconst DD EPS = 1e-10;\
    \    // to be set appropriately\nconst DD PI = acosl(-1.0);\nDD torad(int deg)\
    \ { return (DD)(deg)*PI / 180; }\nDD todeg(DD ang) { return ang * 180 / PI; }\n\
    \n/* Point */\nstruct Point {\n    DD x, y;\n    Point(DD x = 0.0, DD y = 0.0)\
    \ : x(x), y(y) {}\n    friend ostream &operator<<(ostream &s, const Point &p)\
    \ { return s << '(' << p.x << \", \" << p.y << ')'; }\n};\ninline Point operator+(const\
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
    \ s << '(' << c.x << \", \" << c.y << \", \" << c.r << ')'; }\n};\n#line 4 \"\
    geomeny/projection.hpp\"\n\nPoint proj(const Point &p, const Line &l) {\n    DD\
    \ t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\n    return l[0] + (l[1]\
    \ - l[0]) * t;\n}\nPoint refl(const Point &p, const Line &l) {\n    return p +\
    \ (proj(p, l) - p) * 2;\n}\n#line 4 \"geomeny/is-inter.hpp\"\n\nint ccw_for_dis(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a,\
    \ c - a) < -EPS) return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n\
    \    return 0;\n}\nbool isinterPL(const Point &p, const Line &l) {\n    return\
    \ (abs(p - proj(p, l)) < EPS);\n}\nbool isinterPS(const Point &p, const Line &s)\
    \ {\n    return (ccw_for_dis(s[0], s[1], p) == 0);\n}\nbool isinterLL(const Line\
    \ &l, const Line &m) {\n    return (abs(cross(l[1] - l[0], m[1] - m[0])) > EPS\
    \ ||\n            abs(cross(l[1] - l[0], m[0] - l[0])) < EPS);\n}\nbool isinterSS(const\
    \ Line &s, const Line &t) {\n    if (eq(s[0], s[1])) return isinterPS(s[0], t);\n\
    \    if (eq(t[0], t[1])) return isinterPS(t[0], s);\n    return (ccw_for_dis(s[0],\
    \ s[1], t[0]) * ccw_for_dis(s[0], s[1], t[1]) <= 0 &&\n            ccw_for_dis(t[0],\
    \ t[1], s[0]) * ccw_for_dis(t[0], t[1], s[1]) <= 0);\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../geomeny/projection.hpp\"\
    \n\nint ccw_for_dis(const Point &a, const Point &b, const Point &c) {\n    if\
    \ (cross(b - a, c - a) > EPS) return 1;\n    if (cross(b - a, c - a) < -EPS) return\
    \ -1;\n    if (dot(b - a, c - a) < -EPS) return 2;\n    if (norm(b - a) < norm(c\
    \ - a) - EPS) return -2;\n    return 0;\n}\nbool isinterPL(const Point &p, const\
    \ Line &l) {\n    return (abs(p - proj(p, l)) < EPS);\n}\nbool isinterPS(const\
    \ Point &p, const Line &s) {\n    return (ccw_for_dis(s[0], s[1], p) == 0);\n\
    }\nbool isinterLL(const Line &l, const Line &m) {\n    return (abs(cross(l[1]\
    \ - l[0], m[1] - m[0])) > EPS ||\n            abs(cross(l[1] - l[0], m[0] - l[0]))\
    \ < EPS);\n}\nbool isinterSS(const Line &s, const Line &t) {\n    if (eq(s[0],\
    \ s[1])) return isinterPS(s[0], t);\n    if (eq(t[0], t[1])) return isinterPS(t[0],\
    \ s);\n    return (ccw_for_dis(s[0], s[1], t[0]) * ccw_for_dis(s[0], s[1], t[1])\
    \ <= 0 &&\n            ccw_for_dis(t[0], t[1], s[0]) * ccw_for_dis(t[0], t[1],\
    \ s[1]) <= 0);\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - geomeny/projection.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/is-inter.hpp
  requiredBy:
  - geomeny/distance.hpp
  timestamp: '2023-03-03 15:26:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/CGL_2_B.test.cpp
  - test/AOJ/CGL_2_D.test.cpp
documentation_of: geomeny/is-inter.hpp
layout: document
title: "\u4EA4\u5DEE\u5224\u5B9A"
---
