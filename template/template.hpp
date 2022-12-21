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
#ifdef LOCAL
#include "debug.hpp"
#else
#define debug(...)
#endif
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