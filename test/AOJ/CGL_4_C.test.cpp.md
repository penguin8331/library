---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/area-polygon.hpp
    title: "\u591A\u89D2\u5F62\u306E\u9762\u7A4D"
  - icon: ':heavy_check_mark:'
    path: geomeny/convex-cut.hpp
    title: "\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD"
  - icon: ':heavy_check_mark:'
    path: geomeny/geomeny-template.hpp
    title: "\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00001'
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C
  bundledCode: "#line 1 \"test/AOJ/CGL_4_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\"\
    \n#define ERROR 0.00001\n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"\
    avx2\")\n// #pragma GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\"\
    )\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\nusing\
    \ ld = long double;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    #define pb push_back\n#define mp make_pair\n#define mt make_tuple\n#define all(x)\
    \ (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define elif\
    \ else if\n#define updiv(N, X) ((N + X - 1) / X)\n#define sigma(a, b) ((a + b)\
    \ * (b - a + 1) / 2)\nstruct fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n\
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
    geomeny/area-polygon.hpp\"\n\nDD CalcArea(const vector<Point> &pol) {\n    DD\
    \ res = 0.0;\n    for (int i = 0; i < pol.size(); ++i) {\n        res += cross(pol[i],\
    \ pol[(i + 1) % pol.size()]);\n    }\n    return res / 2.0L;\n}\n#line 2 \"geomeny/convex-cut.hpp\"\
    \n\nint ccw_for_convexcut(const Point &a, const Point &b, const Point &c) {\n\
    \    if (cross(b-a, c-a) > EPS) return 1;\n    if (cross(b-a, c-a) < -EPS) return\
    \ -1;\n    if (dot(b-a, c-a) < -EPS) return 2;\n    if (norm(b-a) < norm(c-a)\
    \ - EPS) return -2;\n    return 0;\n}\nvector<Point> crosspoint_for_convexcut(const\
    \ Line &l, const Line &m) {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0],\
    \ l[1] - l[0]);\n    if (abs(d) < EPS) return vector<Point>();\n    res.push_back(l[0]\
    \ + (l[1] - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);\n    return res;\n}\n\
    vector<Point> ConvexCut(const vector<Point> &pol, const Line &l) {\n    vector<Point>\
    \ res;\n    for (int i = 0; i < pol.size(); ++i) {\n        Point p = pol[i],\
    \ q = pol[(i+1)%pol.size()];\n        if (ccw_for_convexcut(l[0], l[1], p) !=\
    \ -1) {\n            if (res.size() == 0) res.push_back(p);\n            else\
    \ if (!eq(p, res[res.size()-1])) res.push_back(p);\n        }\n        if (ccw_for_convexcut(l[0],\
    \ l[1], p) * ccw_for_convexcut(l[0], l[1], q) < 0) {\n            vector<Point>\
    \ temp = crosspoint_for_convexcut(Line(p, q), l);\n            if (temp.size()\
    \ == 0) continue;\n            else if (res.size() == 0) res.push_back(temp[0]);\n\
    \            else if (!eq(temp[0], res[res.size()-1])) res.push_back(temp[0]);\n\
    \        }\n    }\n    return res;\n}\n#line 6 \"test/AOJ/CGL_4_C.test.cpp\"\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<Point> G(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> G[i].x >> G[i].y;\n    }\n    int Q;\n\
    \    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        Line a(2);\n      \
    \  cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;\n        cout << CalcArea(ConvexCut(G,\
    \ a)) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\"\
    \n#define ERROR 0.00001\n#include \"template/template.hpp\"\n#include \"geomeny/area-polygon.hpp\"\
    \n#include \"geomeny/convex-cut.hpp\"\n\nint main() {\n    int N;\n    cin >>\
    \ N;\n    vector<Point> G(N);\n    for (int i = 0; i < N; i++) {\n        cin\
    \ >> G[i].x >> G[i].y;\n    }\n    int Q;\n    cin >> Q;\n    for (int i = 0;\
    \ i < Q; i++) {\n        Line a(2);\n        cin >> a[0].x >> a[0].y >> a[1].x\
    \ >> a[1].y;\n        cout << CalcArea(ConvexCut(G, a)) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - geomeny/area-polygon.hpp
  - geomeny/geomeny-template.hpp
  - geomeny/convex-cut.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_4_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-28 12:48:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_4_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_4_C.test.cpp
- /verify/test/AOJ/CGL_4_C.test.cpp.html
title: test/AOJ/CGL_4_C.test.cpp
---