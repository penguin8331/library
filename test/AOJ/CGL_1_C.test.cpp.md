---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geomeny/ccw.hpp
    title: "\u70B9\u3068\u7DDA\u5206\u306E\u4F4D\u7F6E\u95A2\u4FC2"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C
  bundledCode: "#line 1 \"test/AOJ/CGL_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define pb push_back\n#define mp make_pair\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing ld = long double;\n\
    using pii = std::pair<int, int>;\nusing pll = std::pair<ll, ll>;\nconstexpr int\
    \ inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr int dx[] = {1, 0, -1,\
    \ 0, 1, -1, 1, -1};\nconstexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr\
    \ int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\
    \n\ntemplate <typename T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a\
    \ = b, true) : (false)); }\ntemplate <typename T>\ninline bool chmin(T& a, T b)\
    \ { return ((a > b) ? (a = b, true) : (false)); }\n#line 3 \"template/util.hpp\"\
    \n\nstruct IOSetup {\n    IOSetup() {\n        std::cin.tie(nullptr);\n      \
    \  std::ios::sync_with_stdio(false);\n        std::cout.tie(0);\n        std::cout\
    \ << std::fixed << std::setprecision(12);\n        std::cerr << std::fixed <<\
    \ std::setprecision(12);\n    }\n} IOSetup;\n#line 1 \"template/debug.hpp\"\n\
    #ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n#define debug(...)\n#endif\n#line\
    \ 8 \"template/template.hpp\"\nusing namespace std;\n#line 3 \"geomeny/geomeny-template.hpp\"\
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
    geomeny/ccw.hpp\"\n\n// \u7C97\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\
    \u5074(\u53CD\u6642\u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066\
    c\u306F\u53F3\u5074(\u6642\u8A08\u56DE\u308A)\u30010\uFF1A\u4E00\u76F4\u7DDA\u4E0A\
    \nint simple_ccw(const Point &a, const Point &b, const Point &c) {\n    if (cross(b\
    \ - a, c - a) > EPS) return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n\
    \    return 0;\n}\n\n// \u7CBE\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\
    \u5074(\u53CD\u6642\u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066\
    c\u306F\u53F3\u5074(\u6642\u8A08\u56DE\u308A)\n// 2\uFF1Ac-a-b\u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A\u3001-2\uFF1Aa-b-c\u306E\u9806\u306B\u4E00\u76F4\u7DDA\
    \u4E0A\u30010\uFF1Aa-c-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\nint ccw(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a,\
    \ c - a) < -EPS) return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n\
    \    return 0;\n}\n#line 4 \"test/AOJ/CGL_1_C.test.cpp\"\n\nint main() {\n   \
    \ Point a, b;\n    cin >> a.x >> a.y >> b.x >> b.y;\n    int Q;\n    cin >> Q;\n\
    \    for (int i = 0; i < Q; i++) {\n        Point c;\n        cin >> c.x >> c.y;\n\
    \        int res = ccw(a, b, c);\n        if (res == -1) {\n            cout <<\
    \ \"CLOCKWISE\" << endl;\n        }\n        elif (res == 1) {\n            cout\
    \ << \"COUNTER_CLOCKWISE\" << endl;\n        }\n        elif (res == 2) {\n  \
    \          cout << \"ONLINE_BACK\" << endl;\n        }\n        elif (res == -2)\
    \ {\n            cout << \"ONLINE_FRONT\" << endl;\n        }\n        else {\n\
    \            cout << \"ON_SEGMENT\" << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../geomeny/ccw.hpp\"\
    \n\nint main() {\n    Point a, b;\n    cin >> a.x >> a.y >> b.x >> b.y;\n    int\
    \ Q;\n    cin >> Q;\n    for (int i = 0; i < Q; i++) {\n        Point c;\n   \
    \     cin >> c.x >> c.y;\n        int res = ccw(a, b, c);\n        if (res ==\
    \ -1) {\n            cout << \"CLOCKWISE\" << endl;\n        }\n        elif (res\
    \ == 1) {\n            cout << \"COUNTER_CLOCKWISE\" << endl;\n        }\n   \
    \     elif (res == 2) {\n            cout << \"ONLINE_BACK\" << endl;\n      \
    \  }\n        elif (res == -2) {\n            cout << \"ONLINE_FRONT\" << endl;\n\
    \        }\n        else {\n            cout << \"ON_SEGMENT\" << endl;\n    \
    \    }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - geomeny/ccw.hpp
  - geomeny/geomeny-template.hpp
  isVerificationFile: true
  path: test/AOJ/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-03-14 23:16:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/CGL_1_C.test.cpp
- /verify/test/AOJ/CGL_1_C.test.cpp.html
title: test/AOJ/CGL_1_C.test.cpp
---
