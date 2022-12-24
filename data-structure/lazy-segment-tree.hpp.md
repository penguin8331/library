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
redirect_from:
- /library/data-structure/lazy-segment-tree.hpp
- /library/data-structure/lazy-segment-tree.hpp.html
title: data-structure/lazy-segment-tree.hpp
---
