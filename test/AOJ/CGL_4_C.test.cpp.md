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
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':heavy_check_mark:'
    path: template/debug.hpp
    title: template/debug.hpp
  - icon: ':heavy_check_mark:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':heavy_check_mark:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':heavy_check_mark:'
    path: template/util.hpp
    title: template/util.hpp
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
  bundledCode: "#line 1 \"test/AOJ/CGL_4_C.test.cpp\"\n#define PROBLEM \\\n    \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\"\n#define ERROR\
    \ 0.00001\n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
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
    #line 4 \"geomeny/area-polygon.hpp\"\n\nDD CalcArea(const vector<Point> &pol)\
    \ {\n    DD res = 0.0;\n    for (int i = 0; i < (int)pol.size(); ++i) {\n    \
    \    res += cross(pol[i], pol[(i + 1) % pol.size()]);\n    }\n    return res /\
    \ 2.0L;\n}\n#line 4 \"geomeny/convex-cut.hpp\"\n\nint ccw_for_convexcut(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a,\
    \ c - a) < -EPS) return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n\
    \    return 0;\n}\nvector<Point> crosspoint_for_convexcut(const Line &l, const\
    \ Line &m) {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\n\
    \    if (abs(d) < EPS) return vector<Point>();\n    res.push_back(l[0] + (l[1]\
    \ - l[0]) * cross(m[1] - m[0], m[1] - l[0]) / d);\n    return res;\n}\nvector<Point>\
    \ ConvexCut(const vector<Point> &pol, const Line &l) {\n    vector<Point> res;\n\
    \    for (int i = 0; i < (int)pol.size(); ++i) {\n        Point p = pol[i], q\
    \ = pol[(i + 1) % pol.size()];\n        if (ccw_for_convexcut(l[0], l[1], p) !=\
    \ -1) {\n            if (res.size() == 0)\n                res.push_back(p);\n\
    \            else if (!eq(p, res[res.size() - 1]))\n                res.push_back(p);\n\
    \        }\n        if (ccw_for_convexcut(l[0], l[1], p) * ccw_for_convexcut(l[0],\
    \ l[1], q) < 0) {\n            vector<Point> temp = crosspoint_for_convexcut(Line(p,\
    \ q), l);\n            if (temp.size() == 0)\n                continue;\n    \
    \        else if (res.size() == 0)\n                res.push_back(temp[0]);\n\
    \            else if (!eq(temp[0], res[res.size() - 1]))\n                res.push_back(temp[0]);\n\
    \        }\n    }\n    return res;\n}\n#line 7 \"test/AOJ/CGL_4_C.test.cpp\"\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<Point> G(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> G[i].x >> G[i].y;\n    }\n    int Q;\n\
    \    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        Line a(2);\n      \
    \  cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;\n        cout << CalcArea(ConvexCut(G,\
    \ a)) << endl;\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C\"\
    \n#define ERROR 0.00001\n#include \"../../geomeny/area-polygon.hpp\"\n#include\
    \ \"../../geomeny/convex-cut.hpp\"\n#include \"../../template/template.hpp\"\n\
    \nint main() {\n    int N;\n    cin >> N;\n    vector<Point> G(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> G[i].x >> G[i].y;\n    }\n    int Q;\n\
    \    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        Line a(2);\n      \
    \  cin >> a[0].x >> a[0].y >> a[1].x >> a[1].y;\n        cout << CalcArea(ConvexCut(G,\
    \ a)) << endl;\n    }\n}"
  dependsOn:
  - geomeny/area-polygon.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - geomeny/geomeny-template.hpp
  - geomeny/convex-cut.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_4_C.test.cpp
  requiredBy: []
  timestamp: '2024-04-01 15:21:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_4_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_4_C.test.cpp
- /verify/test/AOJ/CGL_4_C.test.cpp.html
title: test/AOJ/CGL_4_C.test.cpp
---
