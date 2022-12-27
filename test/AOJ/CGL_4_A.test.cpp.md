---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/convex-hull.hpp
    title: "\u51F8\u5305"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"test/AOJ/CGL_4_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing ld = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define pb push_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) ((N + X - 1) / X)\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct\
    \ fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename\
    \ T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false));\
    \ }\ntemplate <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a\
    \ = b, true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 2 \"geomeny/geomeny-template.hpp\"\nusing DD = long double;\
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
    \ \", \" << c.y << \", \" << c.r << ')'; }\n};\n#line 2 \"geomeny/convex-hull.hpp\"\
    \n\n// \u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u306A\u3044\nvector<Point>\
    \ ConvexHull(vector<Point> &ps) {\n    int n = (int)ps.size();\n    vector<Point>\
    \ res(2 * n);\n    sort(ps.begin(), ps.end());\n    int k = 0;\n    for (int i\
    \ = 0; i < n; ++i) {\n        if (k >= 2) {\n            while (cross(res[k -\
    \ 1] - res[k - 2], ps[i] - res[k - 2]) < EPS) {\n                --k;\n      \
    \          if (k < 2) break;\n            }\n        }\n        res[k] = ps[i];\n\
    \        ++k;\n    }\n    int t = k + 1;\n    for (int i = n - 2; i >= 0; --i)\
    \ {\n        if (k >= t) {\n            while (cross(res[k - 1] - res[k - 2],\
    \ ps[i] - res[k - 2]) < EPS) {\n                --k;\n                if (k <\
    \ t) break;\n            }\n        }\n        res[k] = ps[i];\n        ++k;\n\
    \    }\n    res.resize(k - 1);\n    return res;\n}\n\n// \u4E00\u76F4\u7DDA\u4E0A\
    \u306E3\u70B9\u3092\u542B\u3081\u308B\nvector<Point> ConvexHullCollinearOK(vector<Point>\
    \ &ps) {\n    int n = (int)ps.size();\n    vector<Point> res(2 * n);\n    sort(ps.begin(),\
    \ ps.end());\n    int k = 0;\n    for (int i = 0; i < n; ++i) {\n        if (k\
    \ >= 2) {\n            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2])\
    \ < -EPS) {\n                --k;\n                if (k < 2) break;\n       \
    \     }\n        }\n        res[k] = ps[i];\n        ++k;\n    }\n    int t =\
    \ k + 1;\n    for (int i = n - 2; i >= 0; --i) {\n        if (k >= t) {\n    \
    \        while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < -EPS) {\n\
    \                --k;\n                if (k < t) break;\n            }\n    \
    \    }\n        res[k] = ps[i];\n        ++k;\n    }\n    res.resize(k - 1);\n\
    \    return res;\n}\n#line 4 \"test/AOJ/CGL_4_A.test.cpp\"\n\nint main() {\n \
    \   int N;\n    cin >> N;\n    vector<Point> A(N);\n    for (int i = 0; i < N;\
    \ ++i) {\n        cin >> A[i].x >> A[i].y;\n    }\n    auto pol = ConvexHullCollinearOK(A);\n\
    \    pair<ld, ld> minv = {11000, 11000};\n    int minp = -1;\n    for (int i =\
    \ 0; i < (int)pol.size(); ++i) {\n        if (minv > make_pair(pol[i].y, pol[i].x))\
    \ {\n            minv = make_pair(pol[i].y, pol[i].x);\n            minp = i;\n\
    \        }\n    }\n    cout << pol.size() << endl;\n    for (int i = 0; i < (int)pol.size();\
    \ ++i) {\n        int j = (i + minp) % pol.size();\n        cout << fixed << setprecision(0)\
    \ << pol[j].x << \" \" << pol[j].y << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n#include \"template/template.hpp\"\n#include \"geomeny/convex-hull.hpp\"\n\n\
    int main() {\n    int N;\n    cin >> N;\n    vector<Point> A(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        cin >> A[i].x >> A[i].y;\n    }\n    auto pol\
    \ = ConvexHullCollinearOK(A);\n    pair<ld, ld> minv = {11000, 11000};\n    int\
    \ minp = -1;\n    for (int i = 0; i < (int)pol.size(); ++i) {\n        if (minv\
    \ > make_pair(pol[i].y, pol[i].x)) {\n            minv = make_pair(pol[i].y, pol[i].x);\n\
    \            minp = i;\n        }\n    }\n    cout << pol.size() << endl;\n  \
    \  for (int i = 0; i < (int)pol.size(); ++i) {\n        int j = (i + minp) % pol.size();\n\
    \        cout << fixed << setprecision(0) << pol[j].x << \" \" << pol[j].y <<\
    \ endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - geomeny/convex-hull.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_4_A.test.cpp
  requiredBy: []
  timestamp: '2022-12-27 15:24:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_4_A.test.cpp
- /verify/test/AOJ/CGL_4_A.test.cpp.html
title: test/AOJ/CGL_4_A.test.cpp
---
