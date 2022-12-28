---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geomeny/crosspoint.hpp
    title: "\u4EA4\u70B9"
  - icon: ':question:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':question:'
    path: geomeny/is-inter.hpp
    title: "\u4EA4\u5DEE\u5224\u5B9A"
  - icon: ':question:'
    path: geomeny/projection.hpp
    title: "\u5C04\u5F71"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C
  bundledCode: "#line 1 \"test/AOJ/CGL_2_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\"\
    \n#define ERROR 0.00000001\n#line 1 \"template/template.hpp\"\n// #pragma GCC\
    \ target(\"avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"\
    unroll-loops\")\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long\
    \ long;\nusing ld = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll,\
    \ ll>;\n#define pb push_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) ((N + X - 1) / X)\n#define sigma(a, b) ((a\
    \ + b) * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n\
    \        ios::sync_with_stdio(false);\n        cout << fixed << setprecision(15);\n\
    \    };\n} fast_ios_;\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return\
    \ ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T&\
    \ a, T b) { return ((a > b) ? (a = b, true) : (false)); }\nconstexpr int inf =\
    \ 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1, 0,\
    \ 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr\
    \ int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 2 \"geomeny/geomeny-template.hpp\"\
    \nusing DD = long double;     // to be set appropriately\nconst DD EPS = 1e-10;\
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
    geomeny/projection.hpp\"\n\nPoint proj(const Point &p, const Line &l) {\n    DD\
    \ t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\n    return l[0] + (l[1]\
    \ - l[0]) * t;\n}\nPoint refl(const Point &p, const Line &l) {\n    return p +\
    \ (proj(p, l) - p) * 2;\n}\n#line 2 \"geomeny/is-inter.hpp\"\n\nint ccw_for_dis(const\
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
    \ t[1], s[0]) * ccw_for_dis(t[0], t[1], s[1]) <= 0);\n}\n#line 2 \"geomeny/crosspoint.hpp\"\
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
    \   return res;\n}\nvector<Point> crosspoint(const Circle &e, const Line &s) {\n\
    \    vector<Point> res;\n    Point p = proj_for_crosspoint(e, s);\n    DD rcos\
    \ = abs(e - p), rsin;\n    if (rcos > e.r + EPS)\n        return vector<Point>();\n\
    \    else if (e.r - rcos < EPS)\n        rsin = 0;\n    else\n        rsin = sqrt(e.r\
    \ * e.r - rcos * rcos);\n    Point dir = (s[1] - s[0]) / abs(s[1] - s[0]);\n \
    \   Point p1 = p - dir * rsin;\n    Point p2 = p + dir * rsin;\n    if (isinterPS(p1,\
    \ s)) res.push_back(p1);\n    if (isinterPS(p2, s) && !eq(p1, p2)) res.push_back(p2);\n\
    \    return res;\n}\n#line 5 \"test/AOJ/CGL_2_C.test.cpp\"\n\nint main() {\n \
    \   int N;\n    cin >> N;\n    for (int i = 0; i < N; i++) {\n        Line a(2),\
    \ b(2);\n        cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y >> b[0].x >> b[0].y\
    \ >> b[1].x >> b[1].y;\n        auto res = crosspoint(a, b);\n        cout <<\
    \ res[0].x << \" \" << res[0].y << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C\"\
    \n#define ERROR 0.00000001\n#include \"template/template.hpp\"\n#include \"geomeny/crosspoint.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    for (int i = 0; i < N; i++) {\n\
    \        Line a(2), b(2);\n        cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y\
    \ >> b[0].x >> b[0].y >> b[1].x >> b[1].y;\n        auto res = crosspoint(a, b);\n\
    \        cout << res[0].x << \" \" << res[0].y << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - geomeny/crosspoint.hpp
  - geomeny/is-inter.hpp
  - geomeny/projection.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_2_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-28 10:35:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/CGL_2_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_2_C.test.cpp
- /verify/test/AOJ/CGL_2_C.test.cpp.html
title: test/AOJ/CGL_2_C.test.cpp
---
