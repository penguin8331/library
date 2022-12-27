#line 1 "test/AOJ/0143.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0143"
#line 1 "template/template.hpp"
// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define elif else if
#define updiv(N, X) ((N + X - 1) / X)
#define sigma(a, b) ((a + b) * (b - a + 1) / 2)
struct fast_ios {
    fast_ios() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    };
} fast_ios_;
template <typename T>
inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template <typename T>
inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }
constexpr int inf = 1 << 30;
constexpr ll INF = 1LL << 60;
constexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int mod = 998244353;
constexpr int MOD = 1e9 + 7;
#line 1 "geomeny/geomeny-template.hpp"
using DD = long double;     // to be set appropriately
const DD EPS = 1e-10;  // to be set appropriately
const DD PI = acosl(-1.0);
DD torad(int deg) { return (DD)(deg)*PI / 180; }
DD todeg(DD ang) { return ang * 180 / PI; }

/* Point */
struct Point {
    DD x, y;
    Point(DD x = 0.0, DD y = 0.0) : x(x), y(y) {}
    friend ostream &operator<<(ostream &s, const Point &p) { return s << '(' << p.x << ", " << p.y << ')'; }
};
inline Point operator+(const Point &p, const Point &q) { return Point(p.x + q.x, p.y + q.y); }
inline Point operator-(const Point &p, const Point &q) { return Point(p.x - q.x, p.y - q.y); }
inline Point operator*(const Point &p, DD a) { return Point(p.x * a, p.y * a); }
inline Point operator*(DD a, const Point &p) { return Point(a * p.x, a * p.y); }
inline Point operator*(const Point &p, const Point &q) { return Point(p.x * q.x - p.y * q.y, p.x * q.y + p.y * q.x); }
inline Point operator/(const Point &p, DD a) { return Point(p.x / a, p.y / a); }
inline Point conj(const Point &p) { return Point(p.x, -p.y); }
inline Point rot(const Point &p, DD ang) { return Point(cos(ang) * p.x - sin(ang) * p.y, sin(ang) * p.x + cos(ang) * p.y); }
inline Point rot90(const Point &p) { return Point(-p.y, p.x); }
inline DD cross(const Point &p, const Point &q) { return p.x * q.y - p.y * q.x; }
inline DD dot(const Point &p, const Point &q) { return p.x * q.x + p.y * q.y; }
inline DD norm(const Point &p) { return dot(p, p); }
inline DD abs(const Point &p) { return sqrt(dot(p, p)); }
inline DD amp(const Point &p) {
    DD res = atan2(p.y, p.x);
    if (res < 0) res += PI * 2;
    return res;
}
inline bool eq(const Point &p, const Point &q) { return abs(p - q) < EPS; }
inline bool operator<(const Point &p, const Point &q) { return (abs(p.x - q.x) > EPS ? p.x < q.x : p.y < q.y); }
inline bool operator>(const Point &p, const Point &q) { return (abs(p.x - q.x) > EPS ? p.x > q.x : p.y > q.y); }
inline Point operator/(const Point &p, const Point &q) { return p * conj(q) / norm(q); }

/* Line */
struct Line : vector<Point> {
    Line(Point a = Point(0.0, 0.0), Point b = Point(0.0, 0.0)) {
        this->push_back(a);
        this->push_back(b);
    }
    friend ostream &operator<<(ostream &s, const Line &l) { return s << '{' << l[0] << ", " << l[1] << '}'; }
};

/* Circle */
struct Circle : Point {
    DD r;
    Circle(Point p = Point(0.0, 0.0), DD r = 0.0) : Point(p), r(r) {}
    friend ostream &operator<<(ostream &s, const Circle &c) { return s << '(' << c.x << ", " << c.y << ", " << c.r << ')'; }
};
#line 2 "geomeny/ccw.hpp"

// 粗
// 1：a-bから見てcは左側(反時計回り)、-1：a-bから見てcは右側(時計回り)、0：一直線上
int simple_ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    return 0;
}

// 精
// 1：a-bから見てcは左側(反時計回り)、-1：a-bから見てcは右側(時計回り)
// 2：c-a-bの順に一直線上、-2：a-b-cの順に一直線上、0：a-c-bの順に一直線上
int ccw(const Point &a, const Point &b, const Point &c) {
    if (cross(b - a, c - a) > EPS) return 1;
    if (cross(b - a, c - a) < -EPS) return -1;
    if (dot(b - a, c - a) < -EPS) return 2;
    if (norm(b - a) < norm(c - a) - EPS) return -2;
    return 0;
}
#line 2 "geomeny/is-contain-in-the-triangle.hpp"

// 辺上については判定していない
bool is_contain(const Point &p, const Point &a, const Point &b, const Point &c) {
    int r1 = simple_ccw(p, b, c), r2 = simple_ccw(p, c, a), r3 = simple_ccw(p, a, b);
    if (r1 == 1 && r2 == 1 && r3 == 1) return true;
    if (r1 == -1 && r2 == -1 && r3 == -1) return true;
    return false;
}
#line 4 "test/AOJ/0143.test.cpp"

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Point a, b, c, d, e;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y >> e.x >> e.y;
        if (is_contain(d, a, b, c) == is_contain(e, a, b, c)) {
            cout << "NG" << endl;
        } else {
            cout << "OK" << endl;
        }
    }
}