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
  bundledCode: "#line 1 \"data-structure/lazy-segment-tree.hpp\"\ntemplate <class\
    \ Monoid, class Action>\nstruct Lazy_SegTree {\n    using FuncMonoid = function<Monoid(Monoid,\
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
    \ a) {\n        return get(a, a + 1);\n    }\n    \n    // debug\n    void print()\
    \ {\n#ifdef LOCAL\n        for (int i = 0; i < N; ++i) {\n            if (i) cout\
    \ << \",\";\n            cout << get(i, i + 1);\n        }\n        cout << endl;\n\
    #endif\n    }\n};\n"
  code: "template <class Monoid, class Action>\nstruct Lazy_SegTree {\n    using FuncMonoid\
    \ = function<Monoid(Monoid, Monoid)>;\n    using FuncAction = function<void(Monoid&,\
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
    \ a) {\n        return get(a, a + 1);\n    }\n    \n    // debug\n    void print()\
    \ {\n#ifdef LOCAL\n        for (int i = 0; i < N; ++i) {\n            if (i) cout\
    \ << \",\";\n            cout << get(i, i + 1);\n        }\n        cout << endl;\n\
    #endif\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-12-24 10:49:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/lazy-segment-tree.hpp
layout: document
title: "\u9045\u5EF6\u8A55\u4FA1\u4ED8\u304D\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要

セグメントツリーは「作用つきモノイド」上で定義される
FM(a, b): 2 つのモノイド間に定義される演算
FA(a, d): モノイド元 a への作用素 d による作用
FC(d, e): 作用素 d への作用素 e の合成
IDENTITY_MONOID: モノイドの単位元
IDENTITY_LAZY: 作用素の単位元

### 宣言

SegTree(N, fm, fa, fc, identity_monoid, identity_lazy)

### ex

- starry sky tree (区間加算、区間min取得)
  - auto fm = [](long long a, long long b) { return min(a, b); };
  - auto fa = [](long long &a, long long d) { a += d; };
  - auto fc = [](long long &d, long long e) { d += e; };
        SegTree<long long, long long> seg(N, fm, fa, fc, (1LL<<60), 0);

### 初期化

init(n): サイズ n に初期化
set(a, v): a 番目の値を v にセットする
build(): set した値を元にセグメントツリー全体を構築する、O(n)

### クエリ

update(a, b, v): 区間 [a, b) を作用素 v を用いて更新する, O(log n)<br>
get(a, b): 区間 [a, b) についての演算結果を返す, O(log n)
