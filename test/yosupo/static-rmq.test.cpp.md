---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segment-tree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/static-rmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"data-structure/segment-tree.hpp\"\ntemplate <class\
    \ Monoid>\nstruct SegTree {\n    using Func = function<Monoid(Monoid, Monoid)>;\n\
    \    int N;\n    Func F;\n    Monoid IDENTITY;\n    int SIZE_R;\n    vector<Monoid>\
    \ dat;\n\n    /* initialization */\n    SegTree() {}\n    SegTree(int n, const\
    \ Func f, const Monoid& identity)\n        : N(n), F(f), IDENTITY(identity) {\n\
    \        SIZE_R = 1;\n        while (SIZE_R < n) SIZE_R *= 2;\n        dat.assign(SIZE_R\
    \ * 2, IDENTITY);\n    }\n    void init(int n, const Func f, const Monoid& identity)\
    \ {\n        N = n;\n        F = f;\n        IDENTITY = identity;\n        SIZE_R\
    \ = 1;\n        while (SIZE_R < n) SIZE_R *= 2;\n        dat.assign(SIZE_R * 2,\
    \ IDENTITY);\n    }\n\n    /* set, a is 0-indexed */\n    /* build(): O(N) */\n\
    \    void set(int a, const Monoid& v) { dat[a + SIZE_R] = v; }\n    void build()\
    \ {\n        for (int k = SIZE_R - 1; k > 0; --k)\n            dat[k] = F(dat[k\
    \ * 2], dat[k * 2 + 1]);\n    }\n\n    /* update a, a is 0-indexed, O(log N) */\n\
    \    void update(int a, const Monoid& v) {\n        int k = a + SIZE_R;\n    \
    \    dat[k] = v;\n        while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);\n\
    \    }\n\n    /* get [a, b), a and b are 0-indexed, O(log N) */\n    Monoid get(int\
    \ a, int b) {\n        Monoid vleft = IDENTITY, vright = IDENTITY;\n        for\
    \ (int left = a + SIZE_R, right = b + SIZE_R; left < right;\n             left\
    \ >>= 1, right >>= 1) {\n            if (left & 1) vleft = F(vleft, dat[left++]);\n\
    \            if (right & 1) vright = F(dat[--right], vright);\n        }\n   \
    \     return F(vleft, vright);\n    }\n    Monoid all_get() { return dat[1]; }\n\
    \    Monoid operator[](int a) { return dat[a + SIZE_R]; }\n\n    /* get max r\
    \ that f(get(l, r)) = True (0-indexed), O(log N) */\n    /* f(IDENTITY) need to\
    \ be True */\n    int max_right(const function<bool(Monoid)> f, int l = 0) {\n\
    \        if (l == N) return N;\n        l += SIZE_R;\n        Monoid sum = IDENTITY;\n\
    \        do {\n            while (l % 2 == 0) l >>= 1;\n            if (!f(F(sum,\
    \ dat[l]))) {\n                while (l < SIZE_R) {\n                    l = l\
    \ * 2;\n                    if (f(F(sum, dat[l]))) {\n                       \
    \ sum = F(sum, dat[l]);\n                        ++l;\n                    }\n\
    \                }\n                return l - SIZE_R;\n            }\n      \
    \      sum = F(sum, dat[l]);\n            ++l;\n        } while ((l & -l) != l);\
    \  // stop if l = 2^e\n        return N;\n    }\n\n    /* get min l that f(get(l,\
    \ r)) = True (0-indexed), O(log N) */\n    /* f(IDENTITY) need to be True */\n\
    \    int min_left(const function<bool(Monoid)> f, int r = -1) {\n        if (r\
    \ == 0) return 0;\n        if (r == -1) r = N;\n        r += SIZE_R;\n       \
    \ Monoid sum = IDENTITY;\n        do {\n            --r;\n            while (r\
    \ > 1 && (r % 2)) r >>= 1;\n            if (!f(F(dat[r], sum))) {\n          \
    \      while (r < SIZE_R) {\n                    r = r * 2 + 1;\n            \
    \        if (f(F(dat[r], sum))) {\n                        sum = F(dat[r], sum);\n\
    \                        --r;\n                    }\n                }\n    \
    \            return r + 1 - SIZE_R;\n            }\n            sum = F(dat[r],\
    \ sum);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n    /*\
    \ debug */\n    void print() {\n#ifdef LOCAL\n        for (int i = 0; i < N; ++i)\
    \ {\n            cout << (*this)[i];\n            if (i != N - 1) cout << \",\"\
    ;\n        }\n        cout << endl;\n#endif\n    }\n};\n#line 4 \"test/yosupo/static-rmq.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    SegTree<ll> seg(\n  \
    \      N, [](ll a, ll b) { return min(a, b); }, INF);\n    for (int i = 0; i <\
    \ N; i++) {\n        ll a;\n        cin >> a;\n        seg.set(i, a);\n    }\n\
    \    seg.build();\n    for (int i = 0; i < Q; i++) {\n        int l, r;\n    \
    \    cin >> l >> r;\n        cout << seg.get(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    template/template.hpp\"\n#include \"data-structure/segment-tree.hpp\"\n\nint main()\
    \ {\n    int N, Q;\n    cin >> N >> Q;\n    SegTree<ll> seg(\n        N, [](ll\
    \ a, ll b) { return min(a, b); }, INF);\n    for (int i = 0; i < N; i++) {\n \
    \       ll a;\n        cin >> a;\n        seg.set(i, a);\n    }\n    seg.build();\n\
    \    for (int i = 0; i < Q; i++) {\n        int l, r;\n        cin >> l >> r;\n\
    \        cout << seg.get(l, r) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: test/yosupo/static-rmq.test.cpp
  requiredBy: []
  timestamp: '2022-12-24 11:41:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static-rmq.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-rmq.test.cpp
- /verify/test/yosupo/static-rmq.test.cpp.html
title: test/yosupo/static-rmq.test.cpp
---
