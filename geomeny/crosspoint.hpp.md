---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_2_C.test.cpp
    title: test/AOJ/CGL_2_C.test.cpp
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
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)\
    \        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...) \
    \       \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
    \     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
    #define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"geomeny/geomeny-template.hpp\"\n\nusing DD = long double;\n\
    const DD EPS = 1e-10;\nconst DD PI = acosl(-1.0);\nDD torad(int deg) { return\
    \ (DD)(deg)*PI / 180; }\nDD todeg(DD ang) { return ang * 180 / PI; }\n\n/* Point\
    \ */\nstruct Point {\n    DD x, y;\n    Point(DD x = 0.0, DD y = 0.0) : x(x),\
    \ y(y) {}\n    friend ostream &operator<<(ostream &s, const Point &p) { return\
    \ s << '(' << p.x << \", \" << p.y << ')'; }\n};\ninline Point operator+(const\
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
    \ Point {\n    DD r;\n    Circle(const Point &p = Point(0.0, 0.0), DD r = 0.0)\
    \ : Point(p), r(r) {}\n    friend ostream &operator<<(ostream &s, const Circle\
    \ &c) { return s << '(' << c.x << \", \" << c.y << \", \" << c.r << ')'; }\n};\n\
    #line 4 \"geomeny/crosspoint.hpp\"\n\nPoint proj_for_crosspoint(const Point &p,\
    \ const Line &l) {\n    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\n\
    \    return l[0] + (l[1] - l[0]) * t;\n}\nvector<Point> crosspoint(const Line\
    \ &l, const Line &m) {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0],\
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
    \    if (!eq(p1, p2)) res.push_back(p2);\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../geomeny/geomeny-template.hpp\"\
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
    \   return res;\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: false
  path: geomeny/crosspoint.hpp
  requiredBy: []
  timestamp: '2023-03-24 23:12:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/CGL_7_D.test.cpp
  - test/AOJ/CGL_2_C.test.cpp
  - test/AOJ/CGL_7_E.test.cpp
documentation_of: geomeny/crosspoint.hpp
layout: document
title: "\u4EA4\u70B9"
---
