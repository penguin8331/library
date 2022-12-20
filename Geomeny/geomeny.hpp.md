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
  bundledCode: "#line 1 \"Geomeny/geomeny.hpp\"\nusing DD = long double;\nconst DD\
    \ DDINF = 1LL << 60;  // to be set appropriately\nconst DD EPS = 1e-10;      //\
    \ to be set appropriately\nconst DD PI = acosl(-1.0);\nDD torad(int deg) { return\
    \ (DD)(deg)*PI / 180; }\nDD todeg(DD ang) { return ang * 180 / PI; }\nstruct Point\
    \ {\n    DD x, y;\n    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}\n    friend\
    \ ostream &operator<<(ostream &s, const Point &p) { return s << '(' << p.x <<\
    \ \", \" << p.y << ')'; }\n};\ninline Point operator+(const Point &p, const Point\
    \ &q) { return Point(p.x + q.x, p.y + q.y); }\ninline Point operator-(const Point\
    \ &p, const Point &q) { return Point(p.x - q.x, p.y - q.y); }\ninline Point operator*(const\
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
    \ Point &q) { return p * conj(q) / norm(q); }\nstruct Line : vector<Point> {\n\
    \    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {\n        this->push_back(a);\n\
    \        this->push_back(b);\n    }\n    friend ostream &operator<<(ostream &s,\
    \ const Line &l) { return s << '{' << l[0] << \", \" << l[1] << '}'; }\n};\nstruct\
    \ Circle : Point {\n    DD r;\n    Circle(Point p = Point(0.0, 0.0), DD r = 0.0)\
    \ : Point(p), r(r) {}\n    friend ostream &operator<<(ostream &s, const Circle\
    \ &c) { return s << '(' << c.x << \", \" << c.y << \", \" << c.r << ')'; }\n};\n\
    \n////////////////////////////\n// \u70B9\u3084\u7DDA\u5206\u306E\u4F4D\u7F6E\u95A2\
    \u4FC2\n////////////////////////////\n// \u7C97\n// 1\uFF1Aa-b\u304B\u3089\u898B\
    \u3066c\u306F\u5DE6\u5074(\u53CD\u6642\u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\
    \u3089\u898B\u3066c\u306F\u53F3\u5074(\u6642\u8A08\u56DE\u308A)\u30010\uFF1A\u4E00\
    \u76F4\u7DDA\u4E0A\nint simple_ccw(const Point &a, const Point &b, const Point\
    \ &c) {\n    if (cross(b - a, c - a) > EPS) return 1;\n    if (cross(b - a, c\
    \ - a) < -EPS) return -1;\n    return 0;\n}\n// \u7CBE\n// 1\uFF1Aa-b\u304B\u3089\
    \u898B\u3066c\u306F\u5DE6\u5074(\u53CD\u6642\u8A08\u56DE\u308A)\u3001-1\uFF1A\
    a-b\u304B\u3089\u898B\u3066c\u306F\u53F3\u5074(\u6642\u8A08\u56DE\u308A)\n// 2\uFF1A\
    c-a-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u3001-2\uFF1Aa-b-c\u306E\u9806\
    \u306B\u4E00\u76F4\u7DDA\u4E0A\u30010\uFF1Aa-c-b\u306E\u9806\u306B\u4E00\u76F4\
    \u7DDA\u4E0A\nint ccw(const Point &a, const Point &b, const Point &c) {\n    if\
    \ (cross(b - a, c - a) > EPS) return 1;\n    if (cross(b - a, c - a) < -EPS) return\
    \ -1;\n    if (dot(b - a, c - a) < -EPS) return 2;\n    if (norm(b - a) < norm(c\
    \ - a) - EPS) return -2;\n    return 0;\n}\n// \u70B9\u3068\u4E09\u89D2\u5F62\u306E\
    \u5305\u542B\u95A2\u4FC2(\u8FBA\u4E0A\u306B\u3064\u3044\u3066\u306F\u5224\u5B9A\
    \u3057\u3066\u3044\u306A\u3044)\nbool is_contain(const Point &p, const Point &a,\
    \ const Point &b, const Point &c) {\n    int r1 = simple_ccw(p, b, c), r2 = simple_ccw(p,\
    \ c, a), r3 = simple_ccw(p, a, b);\n    if (r1 == 1 && r2 == 1 && r3 == 1) return\
    \ true;\n    if (r1 == -1 && r2 == -1 && r3 == -1) return true;\n    return false;\n\
    }\n\n////////////////////////////\n// \u7279\u6B8A\u306A\u76F4\u7DDA, \u5186\u3092\
    \u6C42\u3081\u308B\n////////////////////////////\n// AOJ 1039\n// 2\u70B9\u306E\
    \u6BD4\u7387a:b\u306E\u30A2\u30DD\u30ED\u30CB\u30A6\u30B9\u306E\u5186\nCircle\
    \ Apporonius(const Point &p, const Point &q, DD a, DD b) {\n    if (abs(a - b)\
    \ < EPS) return Circle(Point(0, 0), 0);\n    Point c1 = (p * b + q * a) / (a +\
    \ b);\n    Point c2 = (p * b - q * a) / (b - a);\n    Point c = (c1 + c2) / 2;\n\
    \    DD r = abs(c - c1);\n    return Circle(c, r);\n}\n\n////////////////////////////\n\
    // \u5186\u3084\u76F4\u7DDA\u306E\u4EA4\u5DEE\u5224\u5B9A, \u8DDD\u96E2\n////////////////////////////\n\
    /*\n    P: \u70B9\n    L: \u76F4\u7DDA\n    S: \u7DDA\u5206\n*/\nint ccw_for_dis(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a,\
    \ c - a) < -EPS) return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n\
    \    return 0;\n}\nPoint proj(const Point &p, const Line &l) {\n    DD t = dot(p\
    \ - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\n    return l[0] + (l[1] - l[0]) *\
    \ t;\n}\nPoint refl(const Point &p, const Line &l) {\n    return p + (proj(p,\
    \ l) - p) * 2;\n}\nbool isinterPL(const Point &p, const Line &l) {\n    return\
    \ (abs(p - proj(p, l)) < EPS);\n}\nbool isinterPS(const Point &p, const Line &s)\
    \ {\n    return (ccw_for_dis(s[0], s[1], p) == 0);\n}\nbool isinterLL(const Line\
    \ &l, const Line &m) {\n    return (abs(cross(l[1] - l[0], m[1] - m[0])) > EPS\
    \ ||\n            abs(cross(l[1] - l[0], m[0] - l[0])) < EPS);\n}\nbool isinterSS(const\
    \ Line &s, const Line &t) {\n    if (eq(s[0], s[1])) return isinterPS(s[0], t);\n\
    \    if (eq(t[0], t[1])) return isinterPS(t[0], s);\n    return (ccw_for_dis(s[0],\
    \ s[1], t[0]) * ccw_for_dis(s[0], s[1], t[1]) <= 0 &&\n            ccw_for_dis(t[0],\
    \ t[1], s[0]) * ccw_for_dis(t[0], t[1], s[1]) <= 0);\n}\nDD distancePL(const Point\
    \ &p, const Line &l) {\n    return abs(p - proj(p, l));\n}\nDD distancePS(const\
    \ Point &p, const Line &s) {\n    Point h = proj(p, s);\n    if (isinterPS(h,\
    \ s)) return abs(p - h);\n    return min(abs(p - s[0]), abs(p - s[1]));\n}\nDD\
    \ distanceLL(const Line &l, const Line &m) {\n    if (isinterLL(l, m))\n     \
    \   return 0;\n    else\n        return distancePL(m[0], l);\n}\nDD distanceSS(const\
    \ Line &s, const Line &t) {\n    if (isinterSS(s, t))\n        return 0;\n   \
    \ else\n        return min(min(distancePS(s[0], t), distancePS(s[1], t)), min(distancePS(t[0],\
    \ s), distancePS(t[1], s)));\n}\n\n////////////////////////////\n// \u5186\u3084\
    \u76F4\u7DDA\u306E\u4EA4\u70B9\n////////////////////////////\nPoint proj_for_crosspoint(const\
    \ Point &p, const Line &l) {\n    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1]\
    \ - l[0]);\n    return l[0] + (l[1] - l[0]) * t;\n}\nvector<Point> crosspoint(const\
    \ Line &l, const Line &m) {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0],\
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
    \    if (!eq(p1, p2)) res.push_back(p2);\n    return res;\n}\n\n///////////////////////\n\
    // \u591A\u89D2\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n///////////////////////\n\
    // \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u9762\u7A4D\nDD calc_area(const\
    \ vector<Point> &pol) {\n    DD res = 0.0;\n    for (int i = 0; i < pol.size();\
    \ ++i) {\n        res += cross(pol[i], pol[(i + 1) % pol.size()]);\n    }\n  \
    \  return res / 2.0L;\n}\n// \u70B9\u3068\u591A\u89D2\u5F62\u306E\u5305\u542B\u95A2\
    \u4FC2\n// 2: in, 1: on, 0: out\nint is_contain(const vector<Point> &pol, const\
    \ Point &p) {\n    int n = (int)pol.size();\n    int isin = 0;\n    for (int i\
    \ = 0; i < n; ++i) {\n        Point a = pol[i] - p, b = pol[(i + 1) % n] - p;\n\
    \        if (a.y > b.y) swap(a, b);\n        if (a.y <= 0 && b.y > 0)\n      \
    \      if (cross(a, b) < 0) isin = 1 - isin;\n        if (cross(a, b) == 0 &&\
    \ dot(a, b) <= 0) return 1;\n    }\n    if (isin)\n        return 2;\n    else\n\
    \        return 0;\n}\n// \u51F8\u6027\u5224\u5B9A\nint ccw_for_isconvex(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    return 0;\n}\n\
    bool is_convex(vector<Point> &ps) {\n    int n = (int)ps.size();\n    for (int\
    \ i = 0; i < n; ++i) {\n        if (ccw_for_isconvex(ps[i], ps[(i + 1) % n], ps[(i\
    \ + 2) % n]) == -1) return false;\n    }\n    return true;\n}\n// \u51F8\u5305\
    \ (\u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u306A\u3044)\nvector<Point>\
    \ convex_hull(vector<Point> &ps) {\n    int n = (int)ps.size();\n    vector<Point>\
    \ res(2 * n);\n    sort(ps.begin(), ps.end());\n    int k = 0;\n    for (int i\
    \ = 0; i < n; ++i) {\n        if (k >= 2) {\n            while (cross(res[k -\
    \ 1] - res[k - 2], ps[i] - res[k - 2]) < EPS) {\n                --k;\n      \
    \          if (k < 2) break;\n            }\n        }\n        res[k] = ps[i];\n\
    \        ++k;\n    }\n    int t = k + 1;\n    for (int i = n - 2; i >= 0; --i)\
    \ {\n        if (k >= t) {\n            while (cross(res[k - 1] - res[k - 2],\
    \ ps[i] - res[k - 2]) < EPS) {\n                --k;\n                if (k <\
    \ t) break;\n            }\n        }\n        res[k] = ps[i];\n        ++k;\n\
    \    }\n    res.resize(k - 1);\n    return res;\n}\n// \u51F8\u5305 (\u4E00\u76F4\
    \u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u308B)\nvector<Point> convex_hull_colinear(vector<Point>\
    \ &ps) {\n    int n = (int)ps.size();\n    vector<Point> res(2 * n);\n    sort(ps.begin(),\
    \ ps.end());\n    int k = 0;\n    for (int i = 0; i < n; ++i) {\n        if (k\
    \ >= 2) {\n            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2])\
    \ < -EPS) {\n                --k;\n                if (k < 2) break;\n       \
    \     }\n        }\n        res[k] = ps[i];\n        ++k;\n    }\n    int t =\
    \ k + 1;\n    for (int i = n - 2; i >= 0; --i) {\n        if (k >= t) {\n    \
    \        while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < -EPS) {\n\
    \                --k;\n                if (k < t) break;\n            }\n    \
    \    }\n        res[k] = ps[i];\n        ++k;\n    }\n    res.resize(k - 1);\n\
    \    return res;\n}\n// convex cut\nint ccw_for_convexcut(const Point &a, const\
    \ Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS) return 1;\n\
    \    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a, c - a) < -EPS)\
    \ return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n    return 0;\n\
    }\nvector<Point> crosspoint_for_convexcut(const Line &l, const Line &m) {\n  \
    \  vector<Point> res;\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\n    if (abs(d)\
    \ < EPS) return vector<Point>();\n    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1]\
    \ - m[0], m[1] - l[0]) / d);\n    return res;\n}\nvector<Point> convex_cut(const\
    \ vector<Point> &pol, const Line &l) {\n    vector<Point> res;\n    for (int i\
    \ = 0; i < pol.size(); ++i) {\n        Point p = pol[i], q = pol[(i + 1) % pol.size()];\n\
    \        if (ccw_for_convexcut(l[0], l[1], p) != -1) {\n            if (res.size()\
    \ == 0)\n                res.push_back(p);\n            else if (!eq(p, res[res.size()\
    \ - 1]))\n                res.push_back(p);\n        }\n        if (ccw_for_convexcut(l[0],\
    \ l[1], p) * ccw_for_convexcut(l[0], l[1], q) < 0) {\n            vector<Point>\
    \ temp = crosspoint_for_convexcut(Line(p, q), l);\n            if (temp.size()\
    \ == 0)\n                continue;\n            else if (res.size() == 0)\n  \
    \              res.push_back(temp[0]);\n            else if (!eq(temp[0], res[res.size()\
    \ - 1]))\n                res.push_back(temp[0]);\n        }\n    }\n    return\
    \ res;\n}\n// Voronoi-diagram\n// pol: outer polygon, ps: points\n// find the\
    \ polygon nearest to ps[ind]\nLine bisector(const Point &p, const Point &q) {\n\
    \    Point c = (p + q) / 2.0L;\n    Point v = (q - p) * Point(0.0L, 1.0L);\n \
    \   v = v / abs(v);\n    return Line(c - v, c + v);\n}\nvector<Point> voronoi(const\
    \ vector<Point> &pol, const vector<Point> &ps, int ind) {\n    vector<Point> res\
    \ = pol;\n    for (int i = 0; i < ps.size(); ++i) {\n        if (i == ind) continue;\n\
    \        Line l = bisector(ps[ind], ps[i]);\n        res = convex_cut(res, l);\n\
    \    }\n    return res;\n}\n\n///////////////////////\n// \u63A5\u7DDA\n///////////////////////\n\
    // tanline\nvector<Point> tanline(const Point &p, const Circle &c) {\n    vector<Point>\
    \ res;\n    DD d = norm(p - c);\n    DD l = d - c.r * c.r;\n    if (l < -EPS)\
    \ return res;\n    if (l <= 0.0) l = 0.0;\n    Point cq = (p - c) * (c.r * c.r\
    \ / d);\n    Point qs = rot90((p - c) * (c.r * sqrt(l) / d));\n    Point s1 =\
    \ c + cq + qs, s2 = c + cq - qs;\n    res.push_back(s1);\n    res.push_back(s2);\n\
    \    return res;\n}\n// common tanline, a and b must be different!\n// Line[0]\
    \ is tangent point in a\nvector<Line> comtanline(Circle a, Circle b) {\n    vector<Line>\
    \ res;\n    // intersect\n    if (abs(a - b) > abs(a.r - b.r) + EPS) {\n     \
    \   if (abs(a.r - b.r) < EPS) {\n            Point dir = b - a;\n            dir\
    \ = rot90(dir * (a.r / abs(dir)));\n            res.push_back(Line(a + dir, b\
    \ + dir));\n            res.push_back(Line(a - dir, b - dir));\n        } else\
    \ {\n            Point p = a * -b.r + b * a.r;\n            p = p * (1.0 / (a.r\
    \ - b.r));\n            vector<Point> bs = tanline(p, a);\n            vector<Point>\
    \ as = tanline(p, b);\n            for (int i = 0; i < min(as.size(), bs.size());\
    \ ++i) {\n                res.push_back(Line(bs[i], as[i]));\n            }\n\
    \        }\n    }\n    // inscribed\n    else if (abs(abs(a - b) - abs(a.r - b.r))\
    \ <= EPS) {\n        Point dir = b - a;\n        if (a.r > b.r)\n            dir\
    \ = dir * (a.r / abs(dir));\n        else\n            dir = dir * (-a.r / abs(dir));\n\
    \        Point p = a + dir;\n        res.push_back(Line(p, p + rot90(dir)));\n\
    \    }\n    // disjoint\n    if (abs(a - b) > a.r + b.r + EPS) {\n        Point\
    \ p = a * b.r + b * a.r;\n        p = p * (1.0 / (a.r + b.r));\n        vector<Point>\
    \ bs = tanline(p, a);\n        vector<Point> as = tanline(p, b);\n        for\
    \ (int i = 0; i < min(as.size(), bs.size()); ++i) {\n            res.push_back(Line(bs[i],\
    \ as[i]));\n        }\n    }\n    // circumscribed\n    else if (abs(abs(a - b)\
    \ - (a.r + b.r)) <= EPS) {\n        Point dir = b - a;\n        dir = dir * (a.r\
    \ / abs(dir));\n        Point p = a + dir;\n        res.push_back(Line(p, p +\
    \ rot90(dir)));\n    }\n    return res;\n}\n\n///////////////////////\n// \u305D\
    \u306E\u4ED6\n///////////////////////\n// \u6700\u8FD1\u70B9\u5BFE\nbool compare_y(Point\
    \ a, Point b) { return a.y < b.y; }\nDD DivideAndConqur(vector<Point>::iterator\
    \ it, int n) {\n    if (n <= 1) return DDINF;\n    int m = n / 2;\n    DD x =\
    \ it[m].x;\n    DD d = min(DivideAndConqur(it, m), DivideAndConqur(it + m, n -\
    \ m));\n    inplace_merge(it, it + m, it + n, compare_y);\n\n    vector<Point>\
    \ vec;\n    for (int i = 0; i < n; ++i) {\n        if (fabs(it[i].x - x) >= d)\
    \ continue;\n        for (int j = 0; j < vec.size(); ++j) {\n            DD dx\
    \ = it[i].x - vec[vec.size() - j - 1].x;\n            DD dy = it[i].y - vec[vec.size()\
    \ - j - 1].y;\n            if (dy >= d) break;\n            d = min(d, sqrt(dx\
    \ * dx + dy * dy));\n        }\n        vec.push_back(it[i]);\n    }\n    return\
    \ d;\n}\nDD Closet(vector<Point> ps) {\n    int n = (int)ps.size();\n    sort(ps.begin(),\
    \ ps.end());\n    return DivideAndConqur(ps.begin(), n);\n}\n"
  code: "using DD = long double;\nconst DD DDINF = 1LL << 60;  // to be set appropriately\n\
    const DD EPS = 1e-10;      // to be set appropriately\nconst DD PI = acosl(-1.0);\n\
    DD torad(int deg) { return (DD)(deg)*PI / 180; }\nDD todeg(DD ang) { return ang\
    \ * 180 / PI; }\nstruct Point {\n    DD x, y;\n    Point(DD x = 0.0, DD y = 0.0)\
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
    \ }\nstruct Line : vector<Point> {\n    Line(Point a = Point(0.0, 0.0), Point\
    \ b = Point(0.0, 0.0)) {\n        this->push_back(a);\n        this->push_back(b);\n\
    \    }\n    friend ostream &operator<<(ostream &s, const Line &l) { return s <<\
    \ '{' << l[0] << \", \" << l[1] << '}'; }\n};\nstruct Circle : Point {\n    DD\
    \ r;\n    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}\n\
    \    friend ostream &operator<<(ostream &s, const Circle &c) { return s << '('\
    \ << c.x << \", \" << c.y << \", \" << c.r << ')'; }\n};\n\n////////////////////////////\n\
    // \u70B9\u3084\u7DDA\u5206\u306E\u4F4D\u7F6E\u95A2\u4FC2\n////////////////////////////\n\
    // \u7C97\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074(\u53CD\u6642\
    \u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u53F3\u5074\
    (\u6642\u8A08\u56DE\u308A)\u30010\uFF1A\u4E00\u76F4\u7DDA\u4E0A\nint simple_ccw(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    return 0;\n}\n\
    // \u7CBE\n// 1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u5DE6\u5074(\u53CD\u6642\
    \u8A08\u56DE\u308A)\u3001-1\uFF1Aa-b\u304B\u3089\u898B\u3066c\u306F\u53F3\u5074\
    (\u6642\u8A08\u56DE\u308A)\n// 2\uFF1Ac-a-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\
    \u4E0A\u3001-2\uFF1Aa-b-c\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\u30010\uFF1A\
    a-c-b\u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\nint ccw(const Point &a, const\
    \ Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS) return 1;\n\
    \    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a, c - a) < -EPS)\
    \ return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n    return 0;\n\
    }\n// \u70B9\u3068\u4E09\u89D2\u5F62\u306E\u5305\u542B\u95A2\u4FC2(\u8FBA\u4E0A\
    \u306B\u3064\u3044\u3066\u306F\u5224\u5B9A\u3057\u3066\u3044\u306A\u3044)\nbool\
    \ is_contain(const Point &p, const Point &a, const Point &b, const Point &c) {\n\
    \    int r1 = simple_ccw(p, b, c), r2 = simple_ccw(p, c, a), r3 = simple_ccw(p,\
    \ a, b);\n    if (r1 == 1 && r2 == 1 && r3 == 1) return true;\n    if (r1 == -1\
    \ && r2 == -1 && r3 == -1) return true;\n    return false;\n}\n\n////////////////////////////\n\
    // \u7279\u6B8A\u306A\u76F4\u7DDA, \u5186\u3092\u6C42\u3081\u308B\n////////////////////////////\n\
    // AOJ 1039\n// 2\u70B9\u306E\u6BD4\u7387a:b\u306E\u30A2\u30DD\u30ED\u30CB\u30A6\
    \u30B9\u306E\u5186\nCircle Apporonius(const Point &p, const Point &q, DD a, DD\
    \ b) {\n    if (abs(a - b) < EPS) return Circle(Point(0, 0), 0);\n    Point c1\
    \ = (p * b + q * a) / (a + b);\n    Point c2 = (p * b - q * a) / (b - a);\n  \
    \  Point c = (c1 + c2) / 2;\n    DD r = abs(c - c1);\n    return Circle(c, r);\n\
    }\n\n////////////////////////////\n// \u5186\u3084\u76F4\u7DDA\u306E\u4EA4\u5DEE\
    \u5224\u5B9A, \u8DDD\u96E2\n////////////////////////////\n/*\n    P: \u70B9\n\
    \    L: \u76F4\u7DDA\n    S: \u7DDA\u5206\n*/\nint ccw_for_dis(const Point &a,\
    \ const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS) return\
    \ 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a, c - a)\
    \ < -EPS) return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n   \
    \ return 0;\n}\nPoint proj(const Point &p, const Line &l) {\n    DD t = dot(p\
    \ - l[0], l[1] - l[0]) / norm(l[1] - l[0]);\n    return l[0] + (l[1] - l[0]) *\
    \ t;\n}\nPoint refl(const Point &p, const Line &l) {\n    return p + (proj(p,\
    \ l) - p) * 2;\n}\nbool isinterPL(const Point &p, const Line &l) {\n    return\
    \ (abs(p - proj(p, l)) < EPS);\n}\nbool isinterPS(const Point &p, const Line &s)\
    \ {\n    return (ccw_for_dis(s[0], s[1], p) == 0);\n}\nbool isinterLL(const Line\
    \ &l, const Line &m) {\n    return (abs(cross(l[1] - l[0], m[1] - m[0])) > EPS\
    \ ||\n            abs(cross(l[1] - l[0], m[0] - l[0])) < EPS);\n}\nbool isinterSS(const\
    \ Line &s, const Line &t) {\n    if (eq(s[0], s[1])) return isinterPS(s[0], t);\n\
    \    if (eq(t[0], t[1])) return isinterPS(t[0], s);\n    return (ccw_for_dis(s[0],\
    \ s[1], t[0]) * ccw_for_dis(s[0], s[1], t[1]) <= 0 &&\n            ccw_for_dis(t[0],\
    \ t[1], s[0]) * ccw_for_dis(t[0], t[1], s[1]) <= 0);\n}\nDD distancePL(const Point\
    \ &p, const Line &l) {\n    return abs(p - proj(p, l));\n}\nDD distancePS(const\
    \ Point &p, const Line &s) {\n    Point h = proj(p, s);\n    if (isinterPS(h,\
    \ s)) return abs(p - h);\n    return min(abs(p - s[0]), abs(p - s[1]));\n}\nDD\
    \ distanceLL(const Line &l, const Line &m) {\n    if (isinterLL(l, m))\n     \
    \   return 0;\n    else\n        return distancePL(m[0], l);\n}\nDD distanceSS(const\
    \ Line &s, const Line &t) {\n    if (isinterSS(s, t))\n        return 0;\n   \
    \ else\n        return min(min(distancePS(s[0], t), distancePS(s[1], t)), min(distancePS(t[0],\
    \ s), distancePS(t[1], s)));\n}\n\n////////////////////////////\n// \u5186\u3084\
    \u76F4\u7DDA\u306E\u4EA4\u70B9\n////////////////////////////\nPoint proj_for_crosspoint(const\
    \ Point &p, const Line &l) {\n    DD t = dot(p - l[0], l[1] - l[0]) / norm(l[1]\
    \ - l[0]);\n    return l[0] + (l[1] - l[0]) * t;\n}\nvector<Point> crosspoint(const\
    \ Line &l, const Line &m) {\n    vector<Point> res;\n    DD d = cross(m[1] - m[0],\
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
    \    if (!eq(p1, p2)) res.push_back(p2);\n    return res;\n}\n\n///////////////////////\n\
    // \u591A\u89D2\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n///////////////////////\n\
    // \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u9762\u7A4D\nDD calc_area(const\
    \ vector<Point> &pol) {\n    DD res = 0.0;\n    for (int i = 0; i < pol.size();\
    \ ++i) {\n        res += cross(pol[i], pol[(i + 1) % pol.size()]);\n    }\n  \
    \  return res / 2.0L;\n}\n// \u70B9\u3068\u591A\u89D2\u5F62\u306E\u5305\u542B\u95A2\
    \u4FC2\n// 2: in, 1: on, 0: out\nint is_contain(const vector<Point> &pol, const\
    \ Point &p) {\n    int n = (int)pol.size();\n    int isin = 0;\n    for (int i\
    \ = 0; i < n; ++i) {\n        Point a = pol[i] - p, b = pol[(i + 1) % n] - p;\n\
    \        if (a.y > b.y) swap(a, b);\n        if (a.y <= 0 && b.y > 0)\n      \
    \      if (cross(a, b) < 0) isin = 1 - isin;\n        if (cross(a, b) == 0 &&\
    \ dot(a, b) <= 0) return 1;\n    }\n    if (isin)\n        return 2;\n    else\n\
    \        return 0;\n}\n// \u51F8\u6027\u5224\u5B9A\nint ccw_for_isconvex(const\
    \ Point &a, const Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS)\
    \ return 1;\n    if (cross(b - a, c - a) < -EPS) return -1;\n    return 0;\n}\n\
    bool is_convex(vector<Point> &ps) {\n    int n = (int)ps.size();\n    for (int\
    \ i = 0; i < n; ++i) {\n        if (ccw_for_isconvex(ps[i], ps[(i + 1) % n], ps[(i\
    \ + 2) % n]) == -1) return false;\n    }\n    return true;\n}\n// \u51F8\u5305\
    \ (\u4E00\u76F4\u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u306A\u3044)\nvector<Point>\
    \ convex_hull(vector<Point> &ps) {\n    int n = (int)ps.size();\n    vector<Point>\
    \ res(2 * n);\n    sort(ps.begin(), ps.end());\n    int k = 0;\n    for (int i\
    \ = 0; i < n; ++i) {\n        if (k >= 2) {\n            while (cross(res[k -\
    \ 1] - res[k - 2], ps[i] - res[k - 2]) < EPS) {\n                --k;\n      \
    \          if (k < 2) break;\n            }\n        }\n        res[k] = ps[i];\n\
    \        ++k;\n    }\n    int t = k + 1;\n    for (int i = n - 2; i >= 0; --i)\
    \ {\n        if (k >= t) {\n            while (cross(res[k - 1] - res[k - 2],\
    \ ps[i] - res[k - 2]) < EPS) {\n                --k;\n                if (k <\
    \ t) break;\n            }\n        }\n        res[k] = ps[i];\n        ++k;\n\
    \    }\n    res.resize(k - 1);\n    return res;\n}\n// \u51F8\u5305 (\u4E00\u76F4\
    \u7DDA\u4E0A\u306E3\u70B9\u3092\u542B\u3081\u308B)\nvector<Point> convex_hull_colinear(vector<Point>\
    \ &ps) {\n    int n = (int)ps.size();\n    vector<Point> res(2 * n);\n    sort(ps.begin(),\
    \ ps.end());\n    int k = 0;\n    for (int i = 0; i < n; ++i) {\n        if (k\
    \ >= 2) {\n            while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2])\
    \ < -EPS) {\n                --k;\n                if (k < 2) break;\n       \
    \     }\n        }\n        res[k] = ps[i];\n        ++k;\n    }\n    int t =\
    \ k + 1;\n    for (int i = n - 2; i >= 0; --i) {\n        if (k >= t) {\n    \
    \        while (cross(res[k - 1] - res[k - 2], ps[i] - res[k - 2]) < -EPS) {\n\
    \                --k;\n                if (k < t) break;\n            }\n    \
    \    }\n        res[k] = ps[i];\n        ++k;\n    }\n    res.resize(k - 1);\n\
    \    return res;\n}\n// convex cut\nint ccw_for_convexcut(const Point &a, const\
    \ Point &b, const Point &c) {\n    if (cross(b - a, c - a) > EPS) return 1;\n\
    \    if (cross(b - a, c - a) < -EPS) return -1;\n    if (dot(b - a, c - a) < -EPS)\
    \ return 2;\n    if (norm(b - a) < norm(c - a) - EPS) return -2;\n    return 0;\n\
    }\nvector<Point> crosspoint_for_convexcut(const Line &l, const Line &m) {\n  \
    \  vector<Point> res;\n    DD d = cross(m[1] - m[0], l[1] - l[0]);\n    if (abs(d)\
    \ < EPS) return vector<Point>();\n    res.push_back(l[0] + (l[1] - l[0]) * cross(m[1]\
    \ - m[0], m[1] - l[0]) / d);\n    return res;\n}\nvector<Point> convex_cut(const\
    \ vector<Point> &pol, const Line &l) {\n    vector<Point> res;\n    for (int i\
    \ = 0; i < pol.size(); ++i) {\n        Point p = pol[i], q = pol[(i + 1) % pol.size()];\n\
    \        if (ccw_for_convexcut(l[0], l[1], p) != -1) {\n            if (res.size()\
    \ == 0)\n                res.push_back(p);\n            else if (!eq(p, res[res.size()\
    \ - 1]))\n                res.push_back(p);\n        }\n        if (ccw_for_convexcut(l[0],\
    \ l[1], p) * ccw_for_convexcut(l[0], l[1], q) < 0) {\n            vector<Point>\
    \ temp = crosspoint_for_convexcut(Line(p, q), l);\n            if (temp.size()\
    \ == 0)\n                continue;\n            else if (res.size() == 0)\n  \
    \              res.push_back(temp[0]);\n            else if (!eq(temp[0], res[res.size()\
    \ - 1]))\n                res.push_back(temp[0]);\n        }\n    }\n    return\
    \ res;\n}\n// Voronoi-diagram\n// pol: outer polygon, ps: points\n// find the\
    \ polygon nearest to ps[ind]\nLine bisector(const Point &p, const Point &q) {\n\
    \    Point c = (p + q) / 2.0L;\n    Point v = (q - p) * Point(0.0L, 1.0L);\n \
    \   v = v / abs(v);\n    return Line(c - v, c + v);\n}\nvector<Point> voronoi(const\
    \ vector<Point> &pol, const vector<Point> &ps, int ind) {\n    vector<Point> res\
    \ = pol;\n    for (int i = 0; i < ps.size(); ++i) {\n        if (i == ind) continue;\n\
    \        Line l = bisector(ps[ind], ps[i]);\n        res = convex_cut(res, l);\n\
    \    }\n    return res;\n}\n\n///////////////////////\n// \u63A5\u7DDA\n///////////////////////\n\
    // tanline\nvector<Point> tanline(const Point &p, const Circle &c) {\n    vector<Point>\
    \ res;\n    DD d = norm(p - c);\n    DD l = d - c.r * c.r;\n    if (l < -EPS)\
    \ return res;\n    if (l <= 0.0) l = 0.0;\n    Point cq = (p - c) * (c.r * c.r\
    \ / d);\n    Point qs = rot90((p - c) * (c.r * sqrt(l) / d));\n    Point s1 =\
    \ c + cq + qs, s2 = c + cq - qs;\n    res.push_back(s1);\n    res.push_back(s2);\n\
    \    return res;\n}\n// common tanline, a and b must be different!\n// Line[0]\
    \ is tangent point in a\nvector<Line> comtanline(Circle a, Circle b) {\n    vector<Line>\
    \ res;\n    // intersect\n    if (abs(a - b) > abs(a.r - b.r) + EPS) {\n     \
    \   if (abs(a.r - b.r) < EPS) {\n            Point dir = b - a;\n            dir\
    \ = rot90(dir * (a.r / abs(dir)));\n            res.push_back(Line(a + dir, b\
    \ + dir));\n            res.push_back(Line(a - dir, b - dir));\n        } else\
    \ {\n            Point p = a * -b.r + b * a.r;\n            p = p * (1.0 / (a.r\
    \ - b.r));\n            vector<Point> bs = tanline(p, a);\n            vector<Point>\
    \ as = tanline(p, b);\n            for (int i = 0; i < min(as.size(), bs.size());\
    \ ++i) {\n                res.push_back(Line(bs[i], as[i]));\n            }\n\
    \        }\n    }\n    // inscribed\n    else if (abs(abs(a - b) - abs(a.r - b.r))\
    \ <= EPS) {\n        Point dir = b - a;\n        if (a.r > b.r)\n            dir\
    \ = dir * (a.r / abs(dir));\n        else\n            dir = dir * (-a.r / abs(dir));\n\
    \        Point p = a + dir;\n        res.push_back(Line(p, p + rot90(dir)));\n\
    \    }\n    // disjoint\n    if (abs(a - b) > a.r + b.r + EPS) {\n        Point\
    \ p = a * b.r + b * a.r;\n        p = p * (1.0 / (a.r + b.r));\n        vector<Point>\
    \ bs = tanline(p, a);\n        vector<Point> as = tanline(p, b);\n        for\
    \ (int i = 0; i < min(as.size(), bs.size()); ++i) {\n            res.push_back(Line(bs[i],\
    \ as[i]));\n        }\n    }\n    // circumscribed\n    else if (abs(abs(a - b)\
    \ - (a.r + b.r)) <= EPS) {\n        Point dir = b - a;\n        dir = dir * (a.r\
    \ / abs(dir));\n        Point p = a + dir;\n        res.push_back(Line(p, p +\
    \ rot90(dir)));\n    }\n    return res;\n}\n\n///////////////////////\n// \u305D\
    \u306E\u4ED6\n///////////////////////\n// \u6700\u8FD1\u70B9\u5BFE\nbool compare_y(Point\
    \ a, Point b) { return a.y < b.y; }\nDD DivideAndConqur(vector<Point>::iterator\
    \ it, int n) {\n    if (n <= 1) return DDINF;\n    int m = n / 2;\n    DD x =\
    \ it[m].x;\n    DD d = min(DivideAndConqur(it, m), DivideAndConqur(it + m, n -\
    \ m));\n    inplace_merge(it, it + m, it + n, compare_y);\n\n    vector<Point>\
    \ vec;\n    for (int i = 0; i < n; ++i) {\n        if (fabs(it[i].x - x) >= d)\
    \ continue;\n        for (int j = 0; j < vec.size(); ++j) {\n            DD dx\
    \ = it[i].x - vec[vec.size() - j - 1].x;\n            DD dy = it[i].y - vec[vec.size()\
    \ - j - 1].y;\n            if (dy >= d) break;\n            d = min(d, sqrt(dx\
    \ * dx + dy * dy));\n        }\n        vec.push_back(it[i]);\n    }\n    return\
    \ d;\n}\nDD Closet(vector<Point> ps) {\n    int n = (int)ps.size();\n    sort(ps.begin(),\
    \ ps.end());\n    return DivideAndConqur(ps.begin(), n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: Geomeny/geomeny.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geomeny/geomeny.hpp
layout: document
redirect_from:
- /library/Geomeny/geomeny.hpp
- /library/Geomeny/geomeny.hpp.html
title: Geomeny/geomeny.hpp
---
