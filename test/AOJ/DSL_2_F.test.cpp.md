---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/func.hpp
    title: template/func.hpp
  - icon: ':question:'
    path: template/macro.hpp
    title: template/macro.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  - icon: ':question:'
    path: template/util.hpp
    title: template/util.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/AOJ/DSL_2_F.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
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
    \ std::setprecision(12);\n    }\n} IOSetup;\n#line 7 \"template/template.hpp\"\
    \nusing namespace std;\n#line 3 \"data-structure/lazy-segment-tree.hpp\"\n\ntemplate\
    \ <class Monoid, class Action>\nstruct Lazy_SegTree {\n    using FuncMonoid =\
    \ function<Monoid(Monoid, Monoid)>;\n    using FuncAction = function<void(Monoid&,\
    \ Action)>;\n    using FuncComposition = function<void(Action&, Action)>;\n  \
    \  FuncMonoid FM;\n    FuncAction FA;\n    FuncComposition FC;\n    Monoid IDENTITY_MONOID;\n\
    \    Action IDENTITY_LAZY;\n    int N, SIZE, HEIGHT;\n    vector<Monoid> dat;\n\
    \    vector<Action> lazy;\n\n    Lazy_SegTree() {}\n    Lazy_SegTree(int n, const\
    \ FuncMonoid fm, const FuncAction fa,\n                 const FuncComposition\
    \ fc,\n                 const Monoid& identity_monoid, const Action& identity_lazy)\n\
    \        : FM(fm), FA(fa), FC(fc), IDENTITY_MONOID(identity_monoid), IDENTITY_LAZY(identity_lazy),\
    \ N(n) {\n        SIZE = 1, HEIGHT = 0;\n        while (SIZE < n) SIZE <<= 1,\
    \ ++HEIGHT;\n        dat.assign(SIZE * 2, IDENTITY_MONOID);\n        lazy.assign(SIZE\
    \ * 2, IDENTITY_LAZY);\n    }\n    void init(int n, const FuncMonoid fm, const\
    \ FuncAction fa,\n              const FuncComposition fc,\n              const\
    \ Monoid& identity_monoid, const Action& identity_lazy) {\n        FM = fm, FA\
    \ = fa, FC = fc;\n        IDENTITY_MONOID = identity_monoid, IDENTITY_LAZY = identity_lazy;\n\
    \        SIZE = 1, HEIGHT = 0;\n        while (SIZE < n) SIZE <<= 1, ++HEIGHT;\n\
    \        dat.assign(SIZE * 2, IDENTITY_MONOID);\n        lazy.assign(SIZE * 2,\
    \ IDENTITY_LAZY);\n    }\n\n    // set, a is 0-indexed\n    void set(int a, const\
    \ Monoid& v) { dat[a + SIZE] = v; }\n    void build() {\n        for (int k =\
    \ SIZE - 1; k > 0; --k)\n            dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);\n\
    \    }\n\n    // update [a, b)\n    inline void evaluate(int k) {\n        if\
    \ (lazy[k] == IDENTITY_LAZY) return;\n        if (k < SIZE) FC(lazy[k * 2], lazy[k]),\
    \ FC(lazy[k * 2 + 1], lazy[k]);\n        FA(dat[k], lazy[k]);\n        lazy[k]\
    \ = IDENTITY_LAZY;\n    }\n    inline void update(int a, int b, const Action&\
    \ v, int k, int l, int r) {\n        evaluate(k);\n        if (a <= l && r <=\
    \ b)\n            FC(lazy[k], v), evaluate(k);\n        else if (a < r && l <\
    \ b) {\n            update(a, b, v, k * 2, l, (l + r) >> 1);\n            update(a,\
    \ b, v, k * 2 + 1, (l + r) >> 1, r);\n            dat[k] = FM(dat[k * 2], dat[k\
    \ * 2 + 1]);\n        }\n    }\n    inline void update(int a, int b, const Action&\
    \ v) {\n        update(a, b, v, 1, 0, SIZE);\n    }\n\n    // get [a, b)\n   \
    \ inline Monoid get(int a, int b, int k, int l, int r) {\n        evaluate(k);\n\
    \        if (a <= l && r <= b)\n            return dat[k];\n        else if (a\
    \ < r && l < b)\n            return FM(get(a, b, k * 2, l, (l + r) >> 1),\n  \
    \                    get(a, b, k * 2 + 1, (l + r) >> 1, r));\n        else\n \
    \           return IDENTITY_MONOID;\n    }\n    inline Monoid get(int a, int b)\
    \ {\n        return get(a, b, 1, 0, SIZE);\n    }\n    inline Monoid operator[](int\
    \ a) {\n        return get(a, a + 1);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, Lazy_SegTree seg) {\n        os << \"[ \";\n        for (int i = 0; i <\
    \ seg.N; i++) {\n            os << seg.get(i, i + 1) << \" \";\n        }\n  \
    \      os << ']';\n        return os;\n    }\n};\n#line 4 \"test/AOJ/DSL_2_F.test.cpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    auto fm = [](ll a, ll\
    \ b) { return min(a, b); };\n    auto fa = [](ll& a, ll d) { a = d; };\n    auto\
    \ fc = [](ll& d, ll e) { d = e; };\n    Lazy_SegTree<long long, long long> seg(N,\
    \ fm, fa, fc, (1LL << 31) - 1, (1LL << 31) - 1);\n    for (int i = 0; i < Q; i++)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            int\
    \ l, r, s;\n            cin >> l >> r >> s;\n            seg.update(l, r + 1,\
    \ s);\n        } else {\n            int l, r;\n            cin >> l >> r;\n \
    \           cout << seg.get(l, r + 1) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n#include \"../../template/template.hpp\"\n#include \"../../data-structure/lazy-segment-tree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    auto fm = [](ll a, ll\
    \ b) { return min(a, b); };\n    auto fa = [](ll& a, ll d) { a = d; };\n    auto\
    \ fc = [](ll& d, ll e) { d = e; };\n    Lazy_SegTree<long long, long long> seg(N,\
    \ fm, fa, fc, (1LL << 31) - 1, (1LL << 31) - 1);\n    for (int i = 0; i < Q; i++)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            int\
    \ l, r, s;\n            cin >> l >> r >> s;\n            seg.update(l, r + 1,\
    \ s);\n        } else {\n            int l, r;\n            cin >> l >> r;\n \
    \           cout << seg.get(l, r + 1) << endl;\n        }\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: test/AOJ/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2023-03-03 16:10:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DSL_2_F.test.cpp
- /verify/test/AOJ/DSL_2_F.test.cpp.html
title: test/AOJ/DSL_2_F.test.cpp
---