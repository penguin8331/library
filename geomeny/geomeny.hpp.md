---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geomeny/geomeny.hpp\"\nusing DD = long double;\r\nconst\
    \ DD DDINF = 1LL << 60;  // to be set appropriately\r\nconst DD EPS = 1e-10; \
    \     // to be set appropriately\r\nconst DD PI = acosl(-1.0);\r\nDD torad(int\
    \ deg) { return (DD)(deg)*PI / 180; }\r\nDD todeg(DD ang) { return ang * 180 /\
    \ PI; }\r\nstruct Point {\r\n    DD x, y;\r\n    Point(DD x = 0.0, DD y = 0.0)\
    \ : x(x), y(y) {}\r\n    friend ostream &operator<<(ostream &s, const Point &p)\
    \ { return s << '(' << p.x << \", \" << p.y << ')'; }\r\n};\r\ninline Point operator+(const\
    \ Point &p, const Point &q) { return Point(p.x + q.x, p.y + q.y); }\r\ninline\
    \ Point operator-(const Point &p, const Point &q) { return Point(p.x - q.x, p.y\
    \ - q.y); }\r\ninline Point operator*(const Point &p, DD a) { return Point(p.x\
    \ * a, p.y * a); }\r\ninline Point operator*(DD a, const Point &p) { return Point(a\
    \ * p.x, a * p.y); }\r\ninline Point operator*(const Point &p, const Point &q)\
    \ { return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x); }\r\ninline Point\
    \ operator/(const Point &p, DD a) { return Point(p.x / a, p.y / a); }\r\ninline\
    \ Point conj(const Point &p) { return Point(p.x, -p.y); }\r\ninline Point rot(const\
    \ Point &p, DD ang) { return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) *\
    \ p.x + cos(ang) * p.y); }\r\ninline Point rot90(const Point &p) { return Point(-p.y,\
    \ p.x); }\r\ninline DD cross(const Point &p, const Point &q) { return p.x * q.y\
    \ - p.y * q.x; }\r\ninline DD dot(const Point &p, const Point &q) { return p.x\
    \ * q.x + p.y * q.y; }\r\ninline DD norm(const Point &p) { return dot(p, p); }\r\
    \ninline DD abs(const Point &p) { return sqrt(dot(p, p)); }\r\ninline DD amp(const\
    \ Point &p) {\r\n    DD res = atan2(p.y, p.x);\r\n    if (res < 0) res += PI *\
    \ 2;\r\n    return res;\r\n}\r\ninline bool eq(const Point &p, const Point &q)\
    \ { return abs(p - q) < EPS; }\r\ninline bool operator<(const Point &p, const\
    \ Point &q) { return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y); }\r\ninline\
    \ bool operator>(const Point &p, const Point &q) { return (abs(p.x - q.x) > EPS\
    \ ? p.x > q.x : p.y > q.y); }\r\ninline Point operator/(const Point &p, const\
    \ Point &q) { return p * conj(q) / norm(q); }\r\nstruct Line : vector<Point> {\r\
    \n    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {\r\n       \
    \ this->push_back(a);\r\n        this->push_back(b);\r\n    }\r\n    friend ostream\
    \ &operator<<(ostream &s, const Line &l) { return s << '{' << l[0] << \", \" <<\
    \ l[1] << '}'; }\r\n};\r\nstruct Circle : Point {\r\n    DD r;\r\n    Circle(Point\
    \ p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}\r\n    friend ostream &operator<<(ostream\
    \ &s, const Circle &c) { return s << '(' << c.x << \", \" << c.y << \", \" <<\
    \ c.r << ')'; }\r\n};\r\n\r\n////////////////////////////\r\n// \u70B9\u3084\u7DDA\
    \u5206\u306E\u4F4D\u7F6E\u95A2\u4FC2\r\n////////////////////////////\r\n// \u7C97\
    \r\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074(\u53CD\u6642\u8A08\
    \u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u53F3\u5074(\u6642\
    \u8A08\u56DE\u308A)\u30010\uFF1A\u4E00\u76F4\u7DDA\u4E0A\r\nint simple_ccw(const\
    \ Point &a, const Point &b, const Point &c) {\r\n    if (cross(b - a, c - a) >\
    \ EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS) return -1;\r\n    return\
    \ 0;\r\n}\r\n// \u7CBE\r\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074\
    (\u53CD\u6642\u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\
    \u53F3\u5074(\u6642\u8A08\u56DE\u308A)\r\n// 2\uFF1Ac-a-b\u306E\u9806\u306B\u4E00\
    \u76F4\u7DDA\u4E0A\u3001-2\uFF1Aa-b-c\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\
    \u30010\uFF1Aa-c-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\r\nint ccw(const\
    \ Point &a, const Point &b, const Point &c) {\r\n    if (cross(b - a, c - a) >\
    \ EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS) return -1;\r\n    if (dot(b\
    \ - a, c - a) < -EPS) return 2;\r\n    if (norm(b - a) < norm(c - a) - EPS) return\
    \ -2;\r\n    return 0;\r\n}\r\n// \u70B9\u3068\u4E09\u89D2\u5F62\u306E\u5305\u542B\
    \u95A2\u4FC2(\u8FBA\u4E0A\u306B\u3064\u3044\u3066\u306F\u5224\u5B9A\u3057\u3066\
    \u3044\u306A\u3044)\r\nbool is_contain(const Point &p, const Point &a, const Point\
    \ &b, const Point &c) {\r\n    int r1 = simple_ccw(p, b, c), r2 = simple_ccw(p,\
    \ c, a), r3 = simple_ccw(p, a, b);\r\n    if (r1 == 1 && r2 == 1 && r3 == 1) return\
    \ true;\r\n    if (r1 == -1 && r2 == -1 && r3 == -1) return true;\r\n    return\
    \ false;\r\n}\r\n\r\n////////////////////////////\r\n// \u7279\u6B8A\u306A\u76F4\
    \u7DDA, \u5186\u3092\u6C42\u3081\u308B\r\n////////////////////////////\r\n// AOJ\
    \ 1039\r\n// 2\u70B9\u306E\u6BD4\u7387a:b\u306E\u30A2\u30DD\u30ED\u30CB\u30A6\u30B9\
    \u306E\u5186\r\nCircle Apporonius(const Point &p, const Point &q, DD a, DD b)\
    \ {\r\n    if (abs(a - b) < EPS) return Circle(Point(0, 0), 0);\r\n    Point c1\
    \ = (p * b + q * a) / (a + b);\r\n    Point c2 = (p * b - q * a) / (b - a);\r\n\
    \    Point c = (c1 + c2) / 2;\r\n    DD r = abs(c - c1);\r\n    return Circle(c,\
    \ r);\r\n}\r\n\r\n////////////////////////////\r\n// \u5186\u3084\u76F4\u7DDA\u306E\
    \u4EA4\u5DEE\u5224\u5B9A, \u8DDD\u96E2\r\n////////////////////////////\r\n/*\r\
    \n    P: \u70B9\r\n    L: \u76F4\u7DDA\r\n    S: \u7DDA\u5206\r\n*/\r\nint ccw_for_dis(const\
    \ Point &a, const Point &b, const Point &c) {\r\n    if (cross(b - a, c - a) >\
    \ EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS) return -1;\r\n    if (dot(b\
    \ - a, c - a) < -EPS) return 2;\r\n    if (norm(b - a) < norm(c - a) - EPS) return\
    \ -2;\r\n    return 0;\r\n}\r\nPoint proj(const Point &p, const Line &l) {\r\n\
    \    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\r\n    return l[0]\
    \ + (l[1] - l[0]) * t;\r\n}\r\nPoint refl(const Point &p, const Line &l) {\r\n\
    \    return p + (proj(p, l) - p) * 2;\r\n}\r\nbool isinterPL(const Point &p, const\
    \ Line &l) {\r\n    return (abs(p - proj(p, l)) < EPS);\r\n}\r\nbool isinterPS(const\
    \ Point &p, const Line &s) {\r\n    return (ccw_for_dis(s[0], s[1], p) == 0);\r\
    \n}\r\nbool isinterLL(const Line &l, const Line &m) {\r\n    return (abs(cross(l[1]\
    \ - l[0], m[1] - m[0])) > EPS ||\r\n            abs(cross(l[1] - l[0], m[0] -\
    \ l[0])) < EPS);\r\n}\r\nbool isinterSS(const Line &s, const Line &t) {\r\n  \
    \  if (eq(s[0], s[1])) return isinterPS(s[0], t);\r\n    if (eq(t[0], t[1])) return\
    \ isinterPS(t[0], s);\r\n    return (ccw_for_dis(s[0], s[1], t[0]) * ccw_for_dis(s[0],\
    \ s[1], t[1]) <= 0 &&\r\n            ccw_for_dis(t[0], t[1], s[0]) * ccw_for_dis(t[0],\
    \ t[1], s[1]) <= 0);\r\n}\r\nDD distancePL(const Point &p, const Line &l) {\r\n\
    \    return abs(p - proj(p, l));\r\n}\r\nDD distancePS(const Point &p, const Line\
    \ &s) {\r\n    Point h = proj(p, s);\r\n    if (isinterPS(h, s)) return abs(p\
    \ - h);\r\n    return min(abs(p - s[0]), abs(p - s[1]));\r\n}\r\nDD distanceLL(const\
    \ Line &l, const Line &m) {\r\n    if (isinterLL(l, m))\r\n        return 0;\r\
    \n    else\r\n        return distancePL(m[0], l);\r\n}\r\nDD distanceSS(const\
    \ Line &s, const Line &t) {\r\n    if (isinterSS(s, t))\r\n        return 0;\r\
    \n    else\r\n        return min(min(distancePS(s[0], t), distancePS(s[1], t)),\
    \ min(distancePS(t[0], s), distancePS(t[1], s)));\r\n}\r\n\r\n////////////////////////////\r\
    \n// \u5186\u3084\u76F4\u7DDA\u306E\u4EA4\u70B9\r\n////////////////////////////\r\
    \nPoint proj_for_crosspoint(const Point &p, const Line &l) {\r\n    DD t = dot(p\
    \ - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\r\n    return l[0] + (l[1] - l[0])\
    \ * t;\r\n}\r\nvector<Point> crosspoint(const Line &l, const Line &m) {\r\n  \
    \  vector<Point> res;\r\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\r\n    if\
    \ (abs(d) < EPS) return vector<Point>();\r\n    res.push_back(l[0] + (l[1] - l[0])\
    \ * cross(m[1] - m[0], m[1] - l[0]) / d);\r\n    return res;\r\n}\r\nvector<Point>\
    \ crosspoint(const Circle &e, const Circle &f) {\r\n    vector<Point> res;\r\n\
    \    DD d = abs(e - f);\r\n    if (d < EPS) return vector<Point>();\r\n    if\
    \ (d > e.r + f.r + EPS) return vector<Point>();\r\n    if (d < abs(e.r - f.r)\
    \ - EPS) return vector<Point>();\r\n    DD rcos = (d * d + e.r * e.r - f.r * f.r)\
    \ / (2.0 * d), rsin;\r\n    if (e.r - abs(rcos) < EPS)\r\n        rsin = 0;\r\n\
    \    else\r\n        rsin = sqrt(e.r * e.r - rcos * rcos);\r\n    Point dir =\
    \ (f - e) / d;\r\n    Point p1 = e + dir * Point(rcos, rsin);\r\n    Point p2\
    \ = e + dir * Point(rcos, -rsin);\r\n    res.push_back(p1);\r\n    if (!eq(p1,\
    \ p2)) res.push_back(p2);\r\n    return res;\r\n}\r\nvector<Point> crosspoint(const\
    \ Circle &e, const Line &l) {\r\n    vector<Point> res;\r\n    Point p = proj_for_crosspoint(e,\
    \ l);\r\n    DD rcos = abs(e - p), rsin;\r\n    if (rcos > e.r + EPS)\r\n    \
    \    return vector<Point>();\r\n    else if (e.r - rcos < EPS)\r\n        rsin\
    \ = 0;\r\n    else\r\n        rsin = sqrt(e.r * e.r - rcos * rcos);\r\n    Point\
    \ dir = (l[1] - l[0]) / abs(l[1] - l[0]);\r\n    Point p1 = p + dir * rsin;\r\n\
    \    Point p2 = p - dir * rsin;\r\n    res.push_back(p1);\r\n    if (!eq(p1, p2))\
    \ res.push_back(p2);\r\n    return res;\r\n}\r\n\r\n///////////////////////\r\n\
    // \u591A\u89D2\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\r\n///////////////////////\r\
    \n// \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u9762\u7A4D\r\nDD calc_area(const\
    \ vector<Point> &pol) {\r\n    DD res = 0.0;\r\n    for (int i = 0; i < pol.size();\
    \ ++i) {\r\n        res += cross(pol[i], pol[(i + 1) % pol.size()]);\r\n    }\r\
    \n    return res / 2.0L;\r\n}\r\n// \u70B9\u3068\u591A\u89D2\u5F62\u306E\u5305\
    \u542B\u95A2\u4FC2\r\n// 2: in, 1: on, 0: out\r\nint is_contain(const vector<Point>\
    \ &pol, const Point &p) {\r\n    int n = (int)pol.size();\r\n    int isin = 0;\r\
    \n    for (int i = 0; i < n; ++i) {\r\n        Point a = pol[i] - p, b = pol[(i\
    \ + 1) % n] - p;\r\n        if (a.y > b.y) swap(a, b);\r\n        if (a.y <= 0\
    \ && b.y > 0)\r\n            if (cross(a, b) < 0) isin = 1 - isin;\r\n       \
    \ if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;\r\n    }\r\n    if (isin)\r\
    \n        return 2;\r\n    else\r\n        return 0;\r\n}\r\n// \u51F8\u6027\u5224\
    \u5B9A\r\nint ccw_for_isconvex(const Point &a, const Point &b, const Point &c)\
    \ {\r\n    if (cross(b - a, c - a) > EPS) return 1;\r\n    if (cross(b - a, c\
    \ - a) < -EPS) return -1;\r\n    return 0;\r\n}\r\nbool is_convex(vector<Point>\
    \ &ps) {\r\n    int n = (int)ps.size();\r\n    for (int i = 0; i < n; ++i) {\r\
    \n        if (ccw_for_isconvex(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]) == -1)\
    \ return false;\r\n    }\r\n    return true;\r\n}\r\n// \u51F8\u5305 (\u4E00\u76F4\
    \u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u306A\u3044)\r\nvector<Point> convex_hull(vector<Point>\
    \ &ps) {\r\n    int n = (int)ps.size();\r\n    vector<Point> res(2 * n);\r\n \
    \   sort(ps.begin(), ps.end());\r\n    int k = 0;\r\n    for (int i = 0; i < n;\
    \ ++i) {\r\n        if (k >= 2) {\r\n            while (cross(res[k - 1] - res[k\
    \ - 2], ps[i] - res[k - 2]) < EPS) {\r\n                --k;\r\n             \
    \   if (k < 2) break;\r\n            }\r\n        }\r\n        res[k] = ps[i];\r\
    \n        ++k;\r\n    }\r\n    int t = k + 1;\r\n    for (int i = n - 2; i >=\
    \ 0; --i) {\r\n        if (k >= t) {\r\n            while (cross(res[k - 1] -\
    \ res[k - 2], ps[i] - res[k - 2]) < EPS) {\r\n                --k;\r\n       \
    \         if (k < t) break;\r\n            }\r\n        }\r\n        res[k] =\
    \ ps[i];\r\n        ++k;\r\n    }\r\n    res.resize(k - 1);\r\n    return res;\r\
    \n}\r\n// \u51F8\u5305 (\u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\
    \u308B)\r\nvector<Point> convex_hull_colinear(vector<Point> &ps) {\r\n    int\
    \ n = (int)ps.size();\r\n    vector<Point> res(2 * n);\r\n    sort(ps.begin(),\
    \ ps.end());\r\n    int k = 0;\r\n    for (int i = 0; i < n; ++i) {\r\n      \
    \  if (k >= 2) {\r\n            while (cross(res[k - 1] - res[k - 2], ps[i] -\
    \ res[k - 2]) < -EPS) {\r\n                --k;\r\n                if (k < 2)\
    \ break;\r\n            }\r\n        }\r\n        res[k] = ps[i];\r\n        ++k;\r\
    \n    }\r\n    int t = k + 1;\r\n    for (int i = n - 2; i >= 0; --i) {\r\n  \
    \      if (k >= t) {\r\n            while (cross(res[k - 1] - res[k - 2], ps[i]\
    \ - res[k - 2]) < -EPS) {\r\n                --k;\r\n                if (k < t)\
    \ break;\r\n            }\r\n        }\r\n        res[k] = ps[i];\r\n        ++k;\r\
    \n    }\r\n    res.resize(k - 1);\r\n    return res;\r\n}\r\n// convex cut\r\n\
    int ccw_for_convexcut(const Point &a, const Point &b, const Point &c) {\r\n  \
    \  if (cross(b - a, c - a) > EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS)\
    \ return -1;\r\n    if (dot(b - a, c - a) < -EPS) return 2;\r\n    if (norm(b\
    \ - a) < norm(c - a) - EPS) return -2;\r\n    return 0;\r\n}\r\nvector<Point>\
    \ crosspoint_for_convexcut(const Line &l, const Line &m) {\r\n    vector<Point>\
    \ res;\r\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\r\n    if (abs(d) < EPS)\
    \ return vector<Point>();\r\n    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1]\
    \ - m[0], m[1] - l[0]) / d);\r\n    return res;\r\n}\r\nvector<Point> convex_cut(const\
    \ vector<Point> &pol, const Line &l) {\r\n    vector<Point> res;\r\n    for (int\
    \ i = 0; i < pol.size(); ++i) {\r\n        Point p = pol[i], q = pol[(i + 1) %\
    \ pol.size()];\r\n        if (ccw_for_convexcut(l[0], l[1], p) != -1) {\r\n  \
    \          if (res.size() == 0)\r\n                res.push_back(p);\r\n     \
    \       else if (!eq(p, res[res.size() - 1]))\r\n                res.push_back(p);\r\
    \n        }\r\n        if (ccw_for_convexcut(l[0], l[1], p) * ccw_for_convexcut(l[0],\
    \ l[1], q) < 0) {\r\n            vector<Point> temp = crosspoint_for_convexcut(Line(p,\
    \ q), l);\r\n            if (temp.size() == 0)\r\n                continue;\r\n\
    \            else if (res.size() == 0)\r\n                res.push_back(temp[0]);\r\
    \n            else if (!eq(temp[0], res[res.size() - 1]))\r\n                res.push_back(temp[0]);\r\
    \n        }\r\n    }\r\n    return res;\r\n}\r\n// Voronoi-diagram\r\n// pol:\
    \ outer polygon, ps: points\r\n// find the polygon nearest to ps[ind]\r\nLine\
    \ bisector(const Point &p, const Point &q) {\r\n    Point c = (p + q) / 2.0L;\r\
    \n    Point v = (q - p) * Point(0.0L, 1.0L);\r\n    v = v / abs(v);\r\n    return\
    \ Line(c - v, c + v);\r\n}\r\nvector<Point> voronoi(const vector<Point> &pol,\
    \ const vector<Point> &ps, int ind) {\r\n    vector<Point> res = pol;\r\n    for\
    \ (int i = 0; i < ps.size(); ++i) {\r\n        if (i == ind) continue;\r\n   \
    \     Line l = bisector(ps[ind], ps[i]);\r\n        res = convex_cut(res, l);\r\
    \n    }\r\n    return res;\r\n}\r\n\r\n///////////////////////\r\n// \u63A5\u7DDA\
    \r\n///////////////////////\r\n// tanline\r\nvector<Point> tanline(const Point\
    \ &p, const Circle &c) {\r\n    vector<Point> res;\r\n    DD d = norm(p - c);\r\
    \n    DD l = d - c.r * c.r;\r\n    if (l < -EPS) return res;\r\n    if (l <= 0.0)\
    \ l = 0.0;\r\n    Point cq = (p - c) * (c.r * c.r / d);\r\n    Point qs = rot90((p\
    \ - c) * (c.r * sqrt(l) / d));\r\n    Point s1 = c + cq + qs, s2 = c + cq - qs;\r\
    \n    res.push_back(s1);\r\n    res.push_back(s2);\r\n    return res;\r\n}\r\n\
    // common tanline, a and b must be different!\r\n// Line[0] is tangent point in\
    \ a\r\nvector<Line> comtanline(Circle a, Circle b) {\r\n    vector<Line> res;\r\
    \n    // intersect\r\n    if (abs(a - b) > abs(a.r - b.r) + EPS) {\r\n       \
    \ if (abs(a.r - b.r) < EPS) {\r\n            Point dir = b - a;\r\n          \
    \  dir = rot90(dir * (a.r / abs(dir)));\r\n            res.push_back(Line(a +\
    \ dir, b + dir));\r\n            res.push_back(Line(a - dir, b - dir));\r\n  \
    \      } else {\r\n            Point p = a * -b.r + b * a.r;\r\n            p\
    \ = p * (1.0 / (a.r - b.r));\r\n            vector<Point> bs = tanline(p, a);\r\
    \n            vector<Point> as = tanline(p, b);\r\n            for (int i = 0;\
    \ i < min(as.size(), bs.size()); ++i) {\r\n                res.push_back(Line(bs[i],\
    \ as[i]));\r\n            }\r\n        }\r\n    }\r\n    // inscribed\r\n    else\
    \ if (abs(abs(a - b) - abs(a.r - b.r)) <= EPS) {\r\n        Point dir = b - a;\r\
    \n        if (a.r > b.r)\r\n            dir = dir * (a.r / abs(dir));\r\n    \
    \    else\r\n            dir = dir * (-a.r / abs(dir));\r\n        Point p = a\
    \ + dir;\r\n        res.push_back(Line(p, p + rot90(dir)));\r\n    }\r\n    //\
    \ disjoint\r\n    if (abs(a - b) > a.r + b.r + EPS) {\r\n        Point p = a *\
    \ b.r + b * a.r;\r\n        p = p * (1.0 / (a.r + b.r));\r\n        vector<Point>\
    \ bs = tanline(p, a);\r\n        vector<Point> as = tanline(p, b);\r\n       \
    \ for (int i = 0; i < min(as.size(), bs.size()); ++i) {\r\n            res.push_back(Line(bs[i],\
    \ as[i]));\r\n        }\r\n    }\r\n    // circumscribed\r\n    else if (abs(abs(a\
    \ - b) - (a.r + b.r)) <= EPS) {\r\n        Point dir = b - a;\r\n        dir =\
    \ dir * (a.r / abs(dir));\r\n        Point p = a + dir;\r\n        res.push_back(Line(p,\
    \ p + rot90(dir)));\r\n    }\r\n    return res;\r\n}\r\n\r\n///////////////////////\r\
    \n// \u305D\u306E\u4ED6\r\n///////////////////////\r\n// \u6700\u8FD1\u70B9\u5BFE\
    \r\nbool compare_y(Point a, Point b) { return a.y < b.y; }\r\nDD DivideAndConqur(vector<Point>::iterator\
    \ it, int n) {\r\n    if (n <= 1) return DDINF;\r\n    int m = n / 2;\r\n    DD\
    \ x = it[m].x;\r\n    DD d = min(DivideAndConqur(it, m), DivideAndConqur(it +\
    \ m, n - m));\r\n    inplace_merge(it, it + m, it + n, compare_y);\r\n\r\n   \
    \ vector<Point> vec;\r\n    for (int i = 0; i < n; ++i) {\r\n        if (fabs(it[i].x\
    \ - x) >= d) continue;\r\n        for (int j = 0; j < vec.size(); ++j) {\r\n \
    \           DD dx = it[i].x - vec[vec.size() - j - 1].x;\r\n            DD dy\
    \ = it[i].y - vec[vec.size() - j - 1].y;\r\n            if (dy >= d) break;\r\n\
    \            d = min(d, sqrt(dx * dx + dy * dy));\r\n        }\r\n        vec.push_back(it[i]);\r\
    \n    }\r\n    return d;\r\n}\r\nDD Closet(vector<Point> ps) {\r\n    int n =\
    \ (int)ps.size();\r\n    sort(ps.begin(), ps.end());\r\n    return DivideAndConqur(ps.begin(),\
    \ n);\r\n}\n"
  code: "using DD = long double;\r\nconst DD DDINF = 1LL << 60;  // to be set appropriately\r\
    \nconst DD EPS = 1e-10;      // to be set appropriately\r\nconst DD PI = acosl(-1.0);\r\
    \nDD torad(int deg) { return (DD)(deg)*PI / 180; }\r\nDD todeg(DD ang) { return\
    \ ang * 180 / PI; }\r\nstruct Point {\r\n    DD x, y;\r\n    Point(DD x = 0.0,\
    \ DD y = 0.0) : x(x), y(y) {}\r\n    friend ostream &operator<<(ostream &s, const\
    \ Point &p) { return s << '(' << p.x << \", \" << p.y << ')'; }\r\n};\r\ninline\
    \ Point operator+(const Point &p, const Point &q) { return Point(p.x + q.x, p.y\
    \ + q.y); }\r\ninline Point operator-(const Point &p, const Point &q) { return\
    \ Point(p.x - q.x, p.y - q.y); }\r\ninline Point operator*(const Point &p, DD\
    \ a) { return Point(p.x * a, p.y * a); }\r\ninline Point operator*(DD a, const\
    \ Point &p) { return Point(a * p.x, a * p.y); }\r\ninline Point operator*(const\
    \ Point &p, const Point &q) { return Point(p.x * q.x - p.y * q.y, p.x * q.y +\
    \ p.y * q.x); }\r\ninline Point operator/(const Point &p, DD a) { return Point(p.x\
    \ / a, p.y / a); }\r\ninline Point conj(const Point &p) { return Point(p.x, -p.y);\
    \ }\r\ninline Point rot(const Point &p, DD ang) { return Point(cos(ang) * p.x\
    \ - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y); }\r\ninline Point rot90(const\
    \ Point &p) { return Point(-p.y, p.x); }\r\ninline DD cross(const Point &p, const\
    \ Point &q) { return p.x * q.y - p.y * q.x; }\r\ninline DD dot(const Point &p,\
    \ const Point &q) { return p.x * q.x + p.y * q.y; }\r\ninline DD norm(const Point\
    \ &p) { return dot(p, p); }\r\ninline DD abs(const Point &p) { return sqrt(dot(p,\
    \ p)); }\r\ninline DD amp(const Point &p) {\r\n    DD res = atan2(p.y, p.x);\r\
    \n    if (res < 0) res += PI * 2;\r\n    return res;\r\n}\r\ninline bool eq(const\
    \ Point &p, const Point &q) { return abs(p - q) < EPS; }\r\ninline bool operator<(const\
    \ Point &p, const Point &q) { return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y <\
    \ q.y); }\r\ninline bool operator>(const Point &p, const Point &q) { return (abs(p.x\
    \ - q.x) > EPS ? p.x > q.x : p.y > q.y); }\r\ninline Point operator/(const Point\
    \ &p, const Point &q) { return p * conj(q) / norm(q); }\r\nstruct Line : vector<Point>\
    \ {\r\n    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {\r\n  \
    \      this->push_back(a);\r\n        this->push_back(b);\r\n    }\r\n    friend\
    \ ostream &operator<<(ostream &s, const Line &l) { return s << '{' << l[0] <<\
    \ \", \" << l[1] << '}'; }\r\n};\r\nstruct Circle : Point {\r\n    DD r;\r\n \
    \   Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}\r\n    friend\
    \ ostream &operator<<(ostream &s, const Circle &c) { return s << '(' << c.x <<\
    \ \", \" << c.y << \", \" << c.r << ')'; }\r\n};\r\n\r\n////////////////////////////\r\
    \n// \u70B9\u3084\u7DDA\u5206\u306E\u4F4D\u7F6E\u95A2\u4FC2\r\n////////////////////////////\r\
    \n// \u7C97\r\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074(\u53CD\
    \u6642\u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u53F3\
    \u5074(\u6642\u8A08\u56DE\u308A)\u30010\uFF1A\u4E00\u76F4\u7DDA\u4E0A\r\nint simple_ccw(const\
    \ Point &a, const Point &b, const Point &c) {\r\n    if (cross(b - a, c - a) >\
    \ EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS) return -1;\r\n    return\
    \ 0;\r\n}\r\n// \u7CBE\r\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074\
    (\u53CD\u6642\u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\
    \u53F3\u5074(\u6642\u8A08\u56DE\u308A)\r\n// 2\uFF1Ac-a-b\u306E\u9806\u306B\u4E00\
    \u76F4\u7DDA\u4E0A\u3001-2\uFF1Aa-b-c\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\
    \u30010\uFF1Aa-c-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\r\nint ccw(const\
    \ Point &a, const Point &b, const Point &c) {\r\n    if (cross(b - a, c - a) >\
    \ EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS) return -1;\r\n    if (dot(b\
    \ - a, c - a) < -EPS) return 2;\r\n    if (norm(b - a) < norm(c - a) - EPS) return\
    \ -2;\r\n    return 0;\r\n}\r\n// \u70B9\u3068\u4E09\u89D2\u5F62\u306E\u5305\u542B\
    \u95A2\u4FC2(\u8FBA\u4E0A\u306B\u3064\u3044\u3066\u306F\u5224\u5B9A\u3057\u3066\
    \u3044\u306A\u3044)\r\nbool is_contain(const Point &p, const Point &a, const Point\
    \ &b, const Point &c) {\r\n    int r1 = simple_ccw(p, b, c), r2 = simple_ccw(p,\
    \ c, a), r3 = simple_ccw(p, a, b);\r\n    if (r1 == 1 && r2 == 1 && r3 == 1) return\
    \ true;\r\n    if (r1 == -1 && r2 == -1 && r3 == -1) return true;\r\n    return\
    \ false;\r\n}\r\n\r\n////////////////////////////\r\n// \u7279\u6B8A\u306A\u76F4\
    \u7DDA, \u5186\u3092\u6C42\u3081\u308B\r\n////////////////////////////\r\n// AOJ\
    \ 1039\r\n// 2\u70B9\u306E\u6BD4\u7387a:b\u306E\u30A2\u30DD\u30ED\u30CB\u30A6\u30B9\
    \u306E\u5186\r\nCircle Apporonius(const Point &p, const Point &q, DD a, DD b)\
    \ {\r\n    if (abs(a - b) < EPS) return Circle(Point(0, 0), 0);\r\n    Point c1\
    \ = (p * b + q * a) / (a + b);\r\n    Point c2 = (p * b - q * a) / (b - a);\r\n\
    \    Point c = (c1 + c2) / 2;\r\n    DD r = abs(c - c1);\r\n    return Circle(c,\
    \ r);\r\n}\r\n\r\n////////////////////////////\r\n// \u5186\u3084\u76F4\u7DDA\u306E\
    \u4EA4\u5DEE\u5224\u5B9A, \u8DDD\u96E2\r\n////////////////////////////\r\n/*\r\
    \n    P: \u70B9\r\n    L: \u76F4\u7DDA\r\n    S: \u7DDA\u5206\r\n*/\r\nint ccw_for_dis(const\
    \ Point &a, const Point &b, const Point &c) {\r\n    if (cross(b - a, c - a) >\
    \ EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS) return -1;\r\n    if (dot(b\
    \ - a, c - a) < -EPS) return 2;\r\n    if (norm(b - a) < norm(c - a) - EPS) return\
    \ -2;\r\n    return 0;\r\n}\r\nPoint proj(const Point &p, const Line &l) {\r\n\
    \    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\r\n    return l[0]\
    \ + (l[1] - l[0]) * t;\r\n}\r\nPoint refl(const Point &p, const Line &l) {\r\n\
    \    return p + (proj(p, l) - p) * 2;\r\n}\r\nbool isinterPL(const Point &p, const\
    \ Line &l) {\r\n    return (abs(p - proj(p, l)) < EPS);\r\n}\r\nbool isinterPS(const\
    \ Point &p, const Line &s) {\r\n    return (ccw_for_dis(s[0], s[1], p) == 0);\r\
    \n}\r\nbool isinterLL(const Line &l, const Line &m) {\r\n    return (abs(cross(l[1]\
    \ - l[0], m[1] - m[0])) > EPS ||\r\n            abs(cross(l[1] - l[0], m[0] -\
    \ l[0])) < EPS);\r\n}\r\nbool isinterSS(const Line &s, const Line &t) {\r\n  \
    \  if (eq(s[0], s[1])) return isinterPS(s[0], t);\r\n    if (eq(t[0], t[1])) return\
    \ isinterPS(t[0], s);\r\n    return (ccw_for_dis(s[0], s[1], t[0]) * ccw_for_dis(s[0],\
    \ s[1], t[1]) <= 0 &&\r\n            ccw_for_dis(t[0], t[1], s[0]) * ccw_for_dis(t[0],\
    \ t[1], s[1]) <= 0);\r\n}\r\nDD distancePL(const Point &p, const Line &l) {\r\n\
    \    return abs(p - proj(p, l));\r\n}\r\nDD distancePS(const Point &p, const Line\
    \ &s) {\r\n    Point h = proj(p, s);\r\n    if (isinterPS(h, s)) return abs(p\
    \ - h);\r\n    return min(abs(p - s[0]), abs(p - s[1]));\r\n}\r\nDD distanceLL(const\
    \ Line &l, const Line &m) {\r\n    if (isinterLL(l, m))\r\n        return 0;\r\
    \n    else\r\n        return distancePL(m[0], l);\r\n}\r\nDD distanceSS(const\
    \ Line &s, const Line &t) {\r\n    if (isinterSS(s, t))\r\n        return 0;\r\
    \n    else\r\n        return min(min(distancePS(s[0], t), distancePS(s[1], t)),\
    \ min(distancePS(t[0], s), distancePS(t[1], s)));\r\n}\r\n\r\n////////////////////////////\r\
    \n// \u5186\u3084\u76F4\u7DDA\u306E\u4EA4\u70B9\r\n////////////////////////////\r\
    \nPoint proj_for_crosspoint(const Point &p, const Line &l) {\r\n    DD t = dot(p\
    \ - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\r\n    return l[0] + (l[1] - l[0])\
    \ * t;\r\n}\r\nvector<Point> crosspoint(const Line &l, const Line &m) {\r\n  \
    \  vector<Point> res;\r\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\r\n    if\
    \ (abs(d) < EPS) return vector<Point>();\r\n    res.push_back(l[0] + (l[1] - l[0])\
    \ * cross(m[1] - m[0], m[1] - l[0]) / d);\r\n    return res;\r\n}\r\nvector<Point>\
    \ crosspoint(const Circle &e, const Circle &f) {\r\n    vector<Point> res;\r\n\
    \    DD d = abs(e - f);\r\n    if (d < EPS) return vector<Point>();\r\n    if\
    \ (d > e.r + f.r + EPS) return vector<Point>();\r\n    if (d < abs(e.r - f.r)\
    \ - EPS) return vector<Point>();\r\n    DD rcos = (d * d + e.r * e.r - f.r * f.r)\
    \ / (2.0 * d), rsin;\r\n    if (e.r - abs(rcos) < EPS)\r\n        rsin = 0;\r\n\
    \    else\r\n        rsin = sqrt(e.r * e.r - rcos * rcos);\r\n    Point dir =\
    \ (f - e) / d;\r\n    Point p1 = e + dir * Point(rcos, rsin);\r\n    Point p2\
    \ = e + dir * Point(rcos, -rsin);\r\n    res.push_back(p1);\r\n    if (!eq(p1,\
    \ p2)) res.push_back(p2);\r\n    return res;\r\n}\r\nvector<Point> crosspoint(const\
    \ Circle &e, const Line &l) {\r\n    vector<Point> res;\r\n    Point p = proj_for_crosspoint(e,\
    \ l);\r\n    DD rcos = abs(e - p), rsin;\r\n    if (rcos > e.r + EPS)\r\n    \
    \    return vector<Point>();\r\n    else if (e.r - rcos < EPS)\r\n        rsin\
    \ = 0;\r\n    else\r\n        rsin = sqrt(e.r * e.r - rcos * rcos);\r\n    Point\
    \ dir = (l[1] - l[0]) / abs(l[1] - l[0]);\r\n    Point p1 = p + dir * rsin;\r\n\
    \    Point p2 = p - dir * rsin;\r\n    res.push_back(p1);\r\n    if (!eq(p1, p2))\
    \ res.push_back(p2);\r\n    return res;\r\n}\r\n\r\n///////////////////////\r\n\
    // \u591A\u89D2\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\r\n///////////////////////\r\
    \n// \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u9762\u7A4D\r\nDD calc_area(const\
    \ vector<Point> &pol) {\r\n    DD res = 0.0;\r\n    for (int i = 0; i < pol.size();\
    \ ++i) {\r\n        res += cross(pol[i], pol[(i + 1) % pol.size()]);\r\n    }\r\
    \n    return res / 2.0L;\r\n}\r\n// \u70B9\u3068\u591A\u89D2\u5F62\u306E\u5305\
    \u542B\u95A2\u4FC2\r\n// 2: in, 1: on, 0: out\r\nint is_contain(const vector<Point>\
    \ &pol, const Point &p) {\r\n    int n = (int)pol.size();\r\n    int isin = 0;\r\
    \n    for (int i = 0; i < n; ++i) {\r\n        Point a = pol[i] - p, b = pol[(i\
    \ + 1) % n] - p;\r\n        if (a.y > b.y) swap(a, b);\r\n        if (a.y <= 0\
    \ && b.y > 0)\r\n            if (cross(a, b) < 0) isin = 1 - isin;\r\n       \
    \ if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;\r\n    }\r\n    if (isin)\r\
    \n        return 2;\r\n    else\r\n        return 0;\r\n}\r\n// \u51F8\u6027\u5224\
    \u5B9A\r\nint ccw_for_isconvex(const Point &a, const Point &b, const Point &c)\
    \ {\r\n    if (cross(b - a, c - a) > EPS) return 1;\r\n    if (cross(b - a, c\
    \ - a) < -EPS) return -1;\r\n    return 0;\r\n}\r\nbool is_convex(vector<Point>\
    \ &ps) {\r\n    int n = (int)ps.size();\r\n    for (int i = 0; i < n; ++i) {\r\
    \n        if (ccw_for_isconvex(ps[i], ps[(i + 1) % n], ps[(i + 2) % n]) == -1)\
    \ return false;\r\n    }\r\n    return true;\r\n}\r\n// \u51F8\u5305 (\u4E00\u76F4\
    \u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u306A\u3044)\r\nvector<Point> convex_hull(vector<Point>\
    \ &ps) {\r\n    int n = (int)ps.size();\r\n    vector<Point> res(2 * n);\r\n \
    \   sort(ps.begin(), ps.end());\r\n    int k = 0;\r\n    for (int i = 0; i < n;\
    \ ++i) {\r\n        if (k >= 2) {\r\n            while (cross(res[k - 1] - res[k\
    \ - 2], ps[i] - res[k - 2]) < EPS) {\r\n                --k;\r\n             \
    \   if (k < 2) break;\r\n            }\r\n        }\r\n        res[k] = ps[i];\r\
    \n        ++k;\r\n    }\r\n    int t = k + 1;\r\n    for (int i = n - 2; i >=\
    \ 0; --i) {\r\n        if (k >= t) {\r\n            while (cross(res[k - 1] -\
    \ res[k - 2], ps[i] - res[k - 2]) < EPS) {\r\n                --k;\r\n       \
    \         if (k < t) break;\r\n            }\r\n        }\r\n        res[k] =\
    \ ps[i];\r\n        ++k;\r\n    }\r\n    res.resize(k - 1);\r\n    return res;\r\
    \n}\r\n// \u51F8\u5305 (\u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\
    \u308B)\r\nvector<Point> convex_hull_colinear(vector<Point> &ps) {\r\n    int\
    \ n = (int)ps.size();\r\n    vector<Point> res(2 * n);\r\n    sort(ps.begin(),\
    \ ps.end());\r\n    int k = 0;\r\n    for (int i = 0; i < n; ++i) {\r\n      \
    \  if (k >= 2) {\r\n            while (cross(res[k - 1] - res[k - 2], ps[i] -\
    \ res[k - 2]) < -EPS) {\r\n                --k;\r\n                if (k < 2)\
    \ break;\r\n            }\r\n        }\r\n        res[k] = ps[i];\r\n        ++k;\r\
    \n    }\r\n    int t = k + 1;\r\n    for (int i = n - 2; i >= 0; --i) {\r\n  \
    \      if (k >= t) {\r\n            while (cross(res[k - 1] - res[k - 2], ps[i]\
    \ - res[k - 2]) < -EPS) {\r\n                --k;\r\n                if (k < t)\
    \ break;\r\n            }\r\n        }\r\n        res[k] = ps[i];\r\n        ++k;\r\
    \n    }\r\n    res.resize(k - 1);\r\n    return res;\r\n}\r\n// convex cut\r\n\
    int ccw_for_convexcut(const Point &a, const Point &b, const Point &c) {\r\n  \
    \  if (cross(b - a, c - a) > EPS) return 1;\r\n    if (cross(b - a, c - a) < -EPS)\
    \ return -1;\r\n    if (dot(b - a, c - a) < -EPS) return 2;\r\n    if (norm(b\
    \ - a) < norm(c - a) - EPS) return -2;\r\n    return 0;\r\n}\r\nvector<Point>\
    \ crosspoint_for_convexcut(const Line &l, const Line &m) {\r\n    vector<Point>\
    \ res;\r\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\r\n    if (abs(d) < EPS)\
    \ return vector<Point>();\r\n    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1]\
    \ - m[0], m[1] - l[0]) / d);\r\n    return res;\r\n}\r\nvector<Point> convex_cut(const\
    \ vector<Point> &pol, const Line &l) {\r\n    vector<Point> res;\r\n    for (int\
    \ i = 0; i < pol.size(); ++i) {\r\n        Point p = pol[i], q = pol[(i + 1) %\
    \ pol.size()];\r\n        if (ccw_for_convexcut(l[0], l[1], p) != -1) {\r\n  \
    \          if (res.size() == 0)\r\n                res.push_back(p);\r\n     \
    \       else if (!eq(p, res[res.size() - 1]))\r\n                res.push_back(p);\r\
    \n        }\r\n        if (ccw_for_convexcut(l[0], l[1], p) * ccw_for_convexcut(l[0],\
    \ l[1], q) < 0) {\r\n            vector<Point> temp = crosspoint_for_convexcut(Line(p,\
    \ q), l);\r\n            if (temp.size() == 0)\r\n                continue;\r\n\
    \            else if (res.size() == 0)\r\n                res.push_back(temp[0]);\r\
    \n            else if (!eq(temp[0], res[res.size() - 1]))\r\n                res.push_back(temp[0]);\r\
    \n        }\r\n    }\r\n    return res;\r\n}\r\n// Voronoi-diagram\r\n// pol:\
    \ outer polygon, ps: points\r\n// find the polygon nearest to ps[ind]\r\nLine\
    \ bisector(const Point &p, const Point &q) {\r\n    Point c = (p + q) / 2.0L;\r\
    \n    Point v = (q - p) * Point(0.0L, 1.0L);\r\n    v = v / abs(v);\r\n    return\
    \ Line(c - v, c + v);\r\n}\r\nvector<Point> voronoi(const vector<Point> &pol,\
    \ const vector<Point> &ps, int ind) {\r\n    vector<Point> res = pol;\r\n    for\
    \ (int i = 0; i < ps.size(); ++i) {\r\n        if (i == ind) continue;\r\n   \
    \     Line l = bisector(ps[ind], ps[i]);\r\n        res = convex_cut(res, l);\r\
    \n    }\r\n    return res;\r\n}\r\n\r\n///////////////////////\r\n// \u63A5\u7DDA\
    \r\n///////////////////////\r\n// tanline\r\nvector<Point> tanline(const Point\
    \ &p, const Circle &c) {\r\n    vector<Point> res;\r\n    DD d = norm(p - c);\r\
    \n    DD l = d - c.r * c.r;\r\n    if (l < -EPS) return res;\r\n    if (l <= 0.0)\
    \ l = 0.0;\r\n    Point cq = (p - c) * (c.r * c.r / d);\r\n    Point qs = rot90((p\
    \ - c) * (c.r * sqrt(l) / d));\r\n    Point s1 = c + cq + qs, s2 = c + cq - qs;\r\
    \n    res.push_back(s1);\r\n    res.push_back(s2);\r\n    return res;\r\n}\r\n\
    // common tanline, a and b must be different!\r\n// Line[0] is tangent point in\
    \ a\r\nvector<Line> comtanline(Circle a, Circle b) {\r\n    vector<Line> res;\r\
    \n    // intersect\r\n    if (abs(a - b) > abs(a.r - b.r) + EPS) {\r\n       \
    \ if (abs(a.r - b.r) < EPS) {\r\n            Point dir = b - a;\r\n          \
    \  dir = rot90(dir * (a.r / abs(dir)));\r\n            res.push_back(Line(a +\
    \ dir, b + dir));\r\n            res.push_back(Line(a - dir, b - dir));\r\n  \
    \      } else {\r\n            Point p = a * -b.r + b * a.r;\r\n            p\
    \ = p * (1.0 / (a.r - b.r));\r\n            vector<Point> bs = tanline(p, a);\r\
    \n            vector<Point> as = tanline(p, b);\r\n            for (int i = 0;\
    \ i < min(as.size(), bs.size()); ++i) {\r\n                res.push_back(Line(bs[i],\
    \ as[i]));\r\n            }\r\n        }\r\n    }\r\n    // inscribed\r\n    else\
    \ if (abs(abs(a - b) - abs(a.r - b.r)) <= EPS) {\r\n        Point dir = b - a;\r\
    \n        if (a.r > b.r)\r\n            dir = dir * (a.r / abs(dir));\r\n    \
    \    else\r\n            dir = dir * (-a.r / abs(dir));\r\n        Point p = a\
    \ + dir;\r\n        res.push_back(Line(p, p + rot90(dir)));\r\n    }\r\n    //\
    \ disjoint\r\n    if (abs(a - b) > a.r + b.r + EPS) {\r\n        Point p = a *\
    \ b.r + b * a.r;\r\n        p = p * (1.0 / (a.r + b.r));\r\n        vector<Point>\
    \ bs = tanline(p, a);\r\n        vector<Point> as = tanline(p, b);\r\n       \
    \ for (int i = 0; i < min(as.size(), bs.size()); ++i) {\r\n            res.push_back(Line(bs[i],\
    \ as[i]));\r\n        }\r\n    }\r\n    // circumscribed\r\n    else if (abs(abs(a\
    \ - b) - (a.r + b.r)) <= EPS) {\r\n        Point dir = b - a;\r\n        dir =\
    \ dir * (a.r / abs(dir));\r\n        Point p = a + dir;\r\n        res.push_back(Line(p,\
    \ p + rot90(dir)));\r\n    }\r\n    return res;\r\n}\r\n\r\n///////////////////////\r\
    \n// \u305D\u306E\u4ED6\r\n///////////////////////\r\n// \u6700\u8FD1\u70B9\u5BFE\
    \r\nbool compare_y(Point a, Point b) { return a.y < b.y; }\r\nDD DivideAndConqur(vector<Point>::iterator\
    \ it, int n) {\r\n    if (n <= 1) return DDINF;\r\n    int m = n / 2;\r\n    DD\
    \ x = it[m].x;\r\n    DD d = min(DivideAndConqur(it, m), DivideAndConqur(it +\
    \ m, n - m));\r\n    inplace_merge(it, it + m, it + n, compare_y);\r\n\r\n   \
    \ vector<Point> vec;\r\n    for (int i = 0; i < n; ++i) {\r\n        if (fabs(it[i].x\
    \ - x) >= d) continue;\r\n        for (int j = 0; j < vec.size(); ++j) {\r\n \
    \           DD dx = it[i].x - vec[vec.size() - j - 1].x;\r\n            DD dy\
    \ = it[i].y - vec[vec.size() - j - 1].y;\r\n            if (dy >= d) break;\r\n\
    \            d = min(d, sqrt(dx * dx + dy * dy));\r\n        }\r\n        vec.push_back(it[i]);\r\
    \n    }\r\n    return d;\r\n}\r\nDD Closet(vector<Point> ps) {\r\n    int n =\
    \ (int)ps.size();\r\n    sort(ps.begin(), ps.end());\r\n    return DivideAndConqur(ps.begin(),\
    \ n);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: geomeny/geomeny.hpp
  requiredBy: []
  timestamp: '2022-12-20 22:02:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geomeny/geomeny.hpp
layout: document
redirect_from:
- /library/geomeny/geomeny.hpp
- /library/geomeny/geomeny.hpp.html
title: geomeny/geomeny.hpp
---
