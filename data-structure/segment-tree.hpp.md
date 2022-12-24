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
  bundledCode: "#line 1 \"data-structure/segment-tree.hpp\"\ntemplate <class Monoid>\n\
    struct SegTree {\n    using Func = function<Monoid(Monoid, Monoid)>;\n    int\
    \ N;\n    Func F;\n    Monoid IDENTITY;\n    int SIZE_R;\n    vector<Monoid> dat;\n\
    \n    /* initialization */\n    SegTree() {}\n    SegTree(int n, const Func f,\
    \ const Monoid& identity)\n        : N(n), F(f), IDENTITY(identity) {\n      \
    \  SIZE_R = 1;\n        while (SIZE_R < n) SIZE_R *= 2;\n        dat.assign(SIZE_R\
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
    ;\n        }\n        cout << endl;\n#endif\n    }\n};\n"
  code: "template <class Monoid>\nstruct SegTree {\n    using Func = function<Monoid(Monoid,\
    \ Monoid)>;\n    int N;\n    Func F;\n    Monoid IDENTITY;\n    int SIZE_R;\n\
    \    vector<Monoid> dat;\n\n    /* initialization */\n    SegTree() {}\n    SegTree(int\
    \ n, const Func f, const Monoid& identity)\n        : N(n), F(f), IDENTITY(identity)\
    \ {\n        SIZE_R = 1;\n        while (SIZE_R < n) SIZE_R *= 2;\n        dat.assign(SIZE_R\
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
    ;\n        }\n        cout << endl;\n#endif\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segment-tree.hpp
  requiredBy: []
  timestamp: '2022-12-24 10:49:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segment-tree.hpp
layout: document
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---

## 概要


セグメントツリーは二項演算の定義されたモノイド上で定義される<br>
二項演算関数 f(x, y) を構造体に渡す<br>

### 宣言

SegTree(n, f, unity): サイズ n に初期化、f は二項演算、unity は単位元 (min なら INF, + なら 0)<br>

### ex
- 区間和: SegTree<int> seg(n, [](int a, int b){ return a + b; }, 0);
- 区間min: SegTree<int> seg(n, [](int a, int b}{ return min(a, b); }, INF);


### 初期化

init(n): サイズ n に初期化<br>
set(a, v): a 番目の値を v にセットする<br>
build(): set した値を元にセグメントツリー全体を構築する、O(n)<br>

### クエリ

update(a, v): a 番目の値を v に更新する, O(log n)<br>
get(a, b): 区間 [a, b) についての演算結果を返す, O(log n)<br>