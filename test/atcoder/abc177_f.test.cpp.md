---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/lazy-segment-tree-arthmetic-ruq.hpp
    title: "\u7B49\u5DEE\u6570\u5217\u3092\u4F5C\u7528\u3055\u305B\u308B Lazy Segment\
      \ Tree"
  - icon: ':question:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: template/alias.hpp
    title: template/alias.hpp
  - icon: ':question:'
    path: template/debug.hpp
    title: template/debug.hpp
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc177/tasks/abc177_f
    links:
    - https://atcoder.jp/contests/abc177/tasks/abc177_f
  bundledCode: "#line 1 \"test/atcoder/abc177_f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_f\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define overload3(_1, _2, _3, name, ...) name\n#define all1(v) std::begin(v),\
    \ std::end(v)\n#define all2(v, a) std::begin(v), std::begin(v) + a\n#define all3(v,\
    \ a, b) std::begin(v) + a, std::begin(v) + b\n#define all(...) overload3(__VA_ARGS__,\
    \ all3, all2, all1)(__VA_ARGS__)\n#define rall1(v) std::rbegin(v), std::rend(v)\n\
    #define rall2(v, a) std::rbegin(v), std::rbegin(v) + a\n#define rall3(v, a, b)\
    \ std::rbegin(v) + a, std::rbegin(v) + b\n#define rall(...) overload3(__VA_ARGS__,\
    \ rall3, rall2, rall1)(__VA_ARGS__)\n#define elif else if\n#define updiv(N, X)\
    \ (((N) + (X) - 1) / (X))\n#define sigma(a, b) (((a) + (b)) * ((b) - (a) + 1)\
    \ / 2)\n#define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ STR(...)        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ CHR(...)      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...)\
    \        \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
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
    \ std;\n#line 3 \"data-structure/lazy-segment-tree.hpp\"\n\ntemplate <class Monoid,\
    \ class Action>\nstruct Lazy_SegTree {\n    using FuncMonoid = function<Monoid(Monoid,\
    \ Monoid)>;\n    using FuncAction = function<void(Monoid&, Action)>;\n    using\
    \ FuncComposition = function<void(Action&, Action)>;\n    FuncMonoid FM;\n   \
    \ FuncAction FA;\n    FuncComposition FC;\n    Monoid IDENTITY_MONOID;\n    Action\
    \ IDENTITY_LAZY;\n    int N, SIZE, HEIGHT;\n    vector<Monoid> dat;\n    vector<Action>\
    \ lazy;\n\n    Lazy_SegTree() {}\n    Lazy_SegTree(int n, const FuncMonoid fm,\
    \ const FuncAction fa,\n                 const FuncComposition fc,\n         \
    \        const Monoid& identity_monoid, const Action& identity_lazy)\n       \
    \ : FM(fm), FA(fa), FC(fc), IDENTITY_MONOID(identity_monoid), IDENTITY_LAZY(identity_lazy),\
    \ N(n) {\n        SIZE = 1, HEIGHT = 0;\n        while (SIZE < n) SIZE <<= 1,\
    \ ++HEIGHT;\n        dat.assign(SIZE * 2, IDENTITY_MONOID);\n        lazy.assign(SIZE\
    \ * 2, IDENTITY_LAZY);\n    }\n    void init(int n, const FuncMonoid fm, const\
    \ FuncAction fa,\n              const FuncComposition fc,\n              const\
    \ Monoid& identity_monoid, const Action& identity_lazy) {\n        FM = fm, FA\
    \ = fa, FC = fc;\n        IDENTITY_MONOID = identity_monoid, IDENTITY_LAZY = identity_lazy;\n\
    \        SIZE = 1, HEIGHT = 0;\n        while (SIZE < n) SIZE <<= 1, ++HEIGHT;\n\
    \        dat.assign(SIZE * 2, IDENTITY_MONOID);\n        lazy.assign(SIZE * 2,\
    \ IDENTITY_LAZY);\n    }\n\n    void set(int a, const Monoid& v) { dat[a + SIZE]\
    \ = v; }\n    void build() {\n        for (int k = SIZE - 1; k > 0; --k)\n   \
    \         dat[k] = FM(dat[k * 2], dat[k * 2 + 1]);\n    }\n\n    inline void evaluate(int\
    \ k) {\n        if (lazy[k] == IDENTITY_LAZY) return;\n        if (k < SIZE) FC(lazy[k\
    \ * 2], lazy[k]), FC(lazy[k * 2 + 1], lazy[k]);\n        FA(dat[k], lazy[k]);\n\
    \        lazy[k] = IDENTITY_LAZY;\n    }\n    inline void update(int a, int b,\
    \ const Action& v, int k, int l, int r) {\n        evaluate(k);\n        if (a\
    \ <= l && r <= b)\n            FC(lazy[k], v), evaluate(k);\n        else if (a\
    \ < r && l < b) {\n            update(a, b, v, k * 2, l, (l + r) >> 1);\n    \
    \        update(a, b, v, k * 2 + 1, (l + r) >> 1, r);\n            dat[k] = FM(dat[k\
    \ * 2], dat[k * 2 + 1]);\n        }\n    }\n    inline void update(int a, int\
    \ b, const Action& v) {\n        update(a, b, v, 1, 0, SIZE);\n    }\n\n    inline\
    \ Monoid get(int a, int b, int k, int l, int r) {\n        evaluate(k);\n    \
    \    if (a <= l && r <= b)\n            return dat[k];\n        else if (a < r\
    \ && l < b)\n            return FM(get(a, b, k * 2, l, (l + r) >> 1),\n      \
    \                get(a, b, k * 2 + 1, (l + r) >> 1, r));\n        else\n     \
    \       return IDENTITY_MONOID;\n    }\n    inline Monoid get(int a, int b) {\n\
    \        return get(a, b, 1, 0, SIZE);\n    }\n    inline Monoid operator[](int\
    \ a) {\n        return get(a, a + 1);\n    }\n\n    friend ostream& operator<<(ostream&\
    \ os, Lazy_SegTree seg) {\n        os << \"[ \";\n        for (int i = 0; i <\
    \ seg.N; i++) {\n            os << seg.get(i, i + 1) << \" \";\n        }\n  \
    \      os << ']';\n        return os;\n    }\n};\n#line 4 \"data-structure/lazy-segment-tree-arthmetic-ruq.hpp\"\
    \n\nstruct Lazy_SegTree_Arthmetic {\n    struct S {\n        ll min, max, sum;\n\
    \        int l, r;\n    };\n    struct F {\n        ll a, b;\n        bool operator==(const\
    \ F& other) {\n            if (a == other.a && b == other.b)\n               \
    \ return true;\n            else\n                return false;\n        }\n \
    \   };\n    function<S(S, S)> fm = [](S s, S t) -> S { return {min(s.min, t.min),\
    \ max(s.max, t.max), s.sum + t.sum, min(s.l, t.l), max(s.r, t.r)}; };\n    function<void(S&,\
    \ F)> fa = [](S& s, F f) {\n        if (f.a == INF) {\n            return;\n \
    \       }\n        if (f.a >= 0) {\n            s = {f.a * s.l + f.b, f.a * (s.r\
    \ - 1) + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};\n\
    \            return;\n        } else {\n            s = {f.a * (s.r - 1) + f.b,\
    \ f.a * s.l + f.b, (f.a * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l, s.r};\n\
    \            return;\n        }\n    };\n    function<void(F&, F)> fc = [](F&\
    \ f, F g) {\n        if (g.a != INF) {\n            f = g;\n        }\n    };\n\
    \    int N;\n    Lazy_SegTree<S, F> seg;\n    explicit Lazy_SegTree_Arthmetic(int\
    \ n) : N(n) {\n        seg.init(N, fm, fa, fc, S({INF, -INF, 0, inf, -inf}), F({INF,\
    \ INF}));\n        for (int i = 0; i < N; i++) {\n            seg.set(i, S({0,\
    \ 0, 0, i, i + 1}));\n        }\n        seg.build();\n    }\n    void init(vector<int>\
    \ v) {\n        for (int i = 0; i < N; i++) {\n            seg.set(i, S({v[i],\
    \ v[i], v[i], i, i + 1}));\n        }\n        seg.build();\n    }\n    void update(int\
    \ l, int r, F f) {\n        seg.update(l, r, F({f.a, f.b - f.a * seg.get(l, l\
    \ + 1).l}));\n    }\n    S get(int l, int r) {\n        return seg.get(l, r);\n\
    \    }\n};\n#line 4 \"test/atcoder/abc177_f.test.cpp\"\n\nint main() {\n    INT(H,\
    \ W);\n    Lazy_SegTree_Arthmetic seg(W);\n    for (int i = 0; i < H; i++) {\n\
    \        INT(l, r);\n        l--;\n        ll x = (l > 0 ? seg.get(l - 1, l).min\
    \ : INF);\n        seg.update(l, r, {1, x + 1});\n        ll ans = seg.get(0,\
    \ W).min;\n        print(ans >= INF ? -1 : ans + i + 1);\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc177/tasks/abc177_f\"\n#include\
    \ \"../../data-structure/lazy-segment-tree-arthmetic-ruq.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nint main() {\n    INT(H, W);\n    Lazy_SegTree_Arthmetic seg(W);\n    for\
    \ (int i = 0; i < H; i++) {\n        INT(l, r);\n        l--;\n        ll x =\
    \ (l > 0 ? seg.get(l - 1, l).min : INF);\n        seg.update(l, r, {1, x + 1});\n\
    \        ll ans = seg.get(0, W).min;\n        print(ans >= INF ? -1 : ans + i\
    \ + 1);\n    }\n}"
  dependsOn:
  - data-structure/lazy-segment-tree-arthmetic-ruq.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/lazy-segment-tree.hpp
  isVerificationFile: true
  path: test/atcoder/abc177_f.test.cpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc177_f.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc177_f.test.cpp
- /verify/test/atcoder/abc177_f.test.cpp.html
title: test/atcoder/abc177_f.test.cpp
---
