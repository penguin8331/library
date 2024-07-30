---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
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
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define overload3(_1, _2, _3, name, ...) name\n\
    #define all1(v) std::begin(v), std::end(v)\n#define all2(v, a) std::begin(v),\
    \ std::begin(v) + a\n#define all3(v, a, b) std::begin(v) + a, std::begin(v) +\
    \ b\n#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)\n\
    #define rall1(v) std::rbegin(v), std::rend(v)\n#define rall2(v, a) std::rbegin(v),\
    \ std::rbegin(v) + a\n#define rall3(v, a, b) std::rbegin(v) + a, std::rbegin(v)\
    \ + b\n#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)\n\
    #define elif else if\n#define updiv(N, X) (((N) + (X) - 1) / (X))\n#define sigma(a,\
    \ b) (((a) + (b)) * ((b) - (a) + 1) / 2)\n#define INT(...)     \\\n    int __VA_ARGS__;\
    \ \\\n    scan(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define STR(...)        \\\n    string __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define CHR(...)      \\\n    char __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define DOU(...)        \\\n    double __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define LD(...)     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define pb push_back\n#define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\
    \nusing ll = long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\n\
    using pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF\
    \ = 1LL << 60;\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr\
    \ int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr\
    \ int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\ntemplate <typename T, typename U>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n\
    \    return os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
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
    \      os << ']';\n        return os;\n    }\n};\n#line 4 \"data-structure/lazy-segment-tree-arthmetic-raq.hpp\"\
    \n\nstruct Lazy_SegTree_Arthmetic {\n    struct S {\n        ll sum;\n       \
    \ int l, r;\n    };\n    struct F {\n        ll a, b;\n        bool operator==(const\
    \ F& other) {\n            if (a == other.a && b == other.b)\n               \
    \ return true;\n            else\n                return false;\n        }\n \
    \   };\n    function<S(S, S)> fm = [](S s, S t) -> S {\n        return {s.sum\
    \ + t.sum, min(s.l, t.l), max(s.r, t.r)};\n    };\n    function<void(S&, F)> fa\
    \ = [](S& s, F f) {\n        s = {s.sum + (f.a * (s.l + s.r - 1) + f.b * 2) *\
    \ (s.r - s.l) / 2, s.l,\n             s.r};\n    };\n    function<void(F&, F)>\
    \ fc = [](F& f, F g) {\n        f.a += g.a;\n        f.b += g.b;\n    };\n   \
    \ int N;\n    Lazy_SegTree<S, F> seg;\n    explicit Lazy_SegTree_Arthmetic(int\
    \ n) : N(n) {\n        seg.init(N, fm, fa, fc, S({0, inf, -inf}), F({0, 0}));\n\
    \        for (int i = 0; i < N; i++) {\n            seg.set(i, S({0, i, i + 1}));\n\
    \        }\n        seg.build();\n    }\n    void init(vector<int> v) {\n    \
    \    for (int i = 0; i < N; i++) {\n            seg.set(i, S({v[i], i, i + 1}));\n\
    \        }\n        seg.build();\n    }\n    void update(int l, int r, F f) {\n\
    \        seg.update(l, r, F({f.a, f.b - f.a * seg.get(l, l + 1).l}));\n    }\n\
    \    S get(int l, int r) { return seg.get(l, r); }\n};\n"
  code: "#pragma once\n#include \"../data-structure/lazy-segment-tree.hpp\"\n#include\
    \ \"../template/template.hpp\"\n\nstruct Lazy_SegTree_Arthmetic {\n    struct\
    \ S {\n        ll sum;\n        int l, r;\n    };\n    struct F {\n        ll\
    \ a, b;\n        bool operator==(const F& other) {\n            if (a == other.a\
    \ && b == other.b)\n                return true;\n            else\n         \
    \       return false;\n        }\n    };\n    function<S(S, S)> fm = [](S s, S\
    \ t) -> S {\n        return {s.sum + t.sum, min(s.l, t.l), max(s.r, t.r)};\n \
    \   };\n    function<void(S&, F)> fa = [](S& s, F f) {\n        s = {s.sum + (f.a\
    \ * (s.l + s.r - 1) + f.b * 2) * (s.r - s.l) / 2, s.l,\n             s.r};\n \
    \   };\n    function<void(F&, F)> fc = [](F& f, F g) {\n        f.a += g.a;\n\
    \        f.b += g.b;\n    };\n    int N;\n    Lazy_SegTree<S, F> seg;\n    explicit\
    \ Lazy_SegTree_Arthmetic(int n) : N(n) {\n        seg.init(N, fm, fa, fc, S({0,\
    \ inf, -inf}), F({0, 0}));\n        for (int i = 0; i < N; i++) {\n          \
    \  seg.set(i, S({0, i, i + 1}));\n        }\n        seg.build();\n    }\n   \
    \ void init(vector<int> v) {\n        for (int i = 0; i < N; i++) {\n        \
    \    seg.set(i, S({v[i], i, i + 1}));\n        }\n        seg.build();\n    }\n\
    \    void update(int l, int r, F f) {\n        seg.update(l, r, F({f.a, f.b -\
    \ f.a * seg.get(l, l + 1).l}));\n    }\n    S get(int l, int r) { return seg.get(l,\
    \ r); }\n};"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/lazy-segment-tree-arthmetic-raq.hpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/lazy-segment-tree-arthmetic-raq.hpp
layout: document
title: "\u7B49\u5DEE\u6570\u5217\u3092\u4F5C\u7528\u3055\u305B\u308B Lazy Segment\
  \ Tree"
---

## 概要

区間に等差数列を作用させる遅延セグメントツリー
RSQ, RAQ に対応

## 参考

[区間に等差数列を作用させる遅延セグメントツリー-null mn](https://null-mn.hatenablog.com/entry/2021/08/22/064325)
