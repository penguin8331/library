---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/implicit-treap.hpp
    title: ImplicitTreap
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
    \ 3 \"template/macro.hpp\"\n\n#define pb push_back\n#define mp make_pair\n#define\
    \ all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n#define\
    \ elif else if\n#define updiv(N, X) (((N) + (X) - (1)) / (X))\n#define sigma(a,\
    \ b) ((a + b) * (b - a + 1) / 2)\n#line 3 \"template/alias.hpp\"\n\nusing ll =\
    \ long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\nusing\
    \ pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline\
    \ bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate\
    \ <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true)\
    \ : (false)); }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup()\
    \ {\n        std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n\
    \        std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 1 \"template/debug.hpp\"\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/implicit-treap.hpp\"\n\n// T0: \u5143\u306E\u914D\
    \u5217\u306E\u30E2\u30CE\u30A4\u30C9\n// T1: T0\u306B\u5BFE\u3059\u308B\u4F5C\u7528\
    \u7D20\u30E2\u30CE\u30A4\u30C9\ntemplate <class T0, class T1>\nclass BaseImplicitTreap\
    \ {\n    // T0\u4E0A\u306E\u6F14\u7B97\u3001\u5358\u4F4D\u5143\n    virtual T0\
    \ f0(T0, T0) = 0;\n    const T0 u0;\n    // T1\u4E0A\u306E\u6F14\u7B97\u3001\u5358\
    \u4F4D\u5143\n    virtual T1 f1(T1, T1) = 0;\n    const T1 u1;\n    // T0\u306B\
    \u5BFE\u3059\u308BT1\u306E\u4F5C\u7528\n    virtual T0 g(T0, T1) = 0;\n    //\
    \ \u591A\u6570\u306Et1(T1)\u306B\u5BFE\u3059\u308Bf1\u306E\u5408\u6210\n    virtual\
    \ T1 p(T1, int) = 0;\n\n    class xorshift {\n        uint64_t x;\n\n       public:\n\
    \        xorshift() {\n            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n\n        uint64_t random() {\n\
    \            x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n       \
    \ }\n    } rnd;\n\n    struct Node {\n        T0 value, acc;\n        T1 lazy;\n\
    \        int priority, cnt;\n        bool rev;\n        Node *l, *r;\n\n     \
    \   Node(T0 value_, int priority_, T0 u0_, T1 u1_)\n            : value(value_),\
    \ acc(u0_), lazy(u1_), priority(priority_), cnt(1), rev(false), l(nullptr), r(nullptr)\
    \ {}\n    }* root = nullptr;\n\n    using Tree = Node*;\n\n    int cnt(Tree t)\
    \ { return t ? t->cnt : 0; }\n\n    T0 acc(Tree t) { return t ? t->acc : u0; }\n\
    \n    void update_cnt(Tree t) {\n        if (t) {\n            t->cnt = 1 + cnt(t->l)\
    \ + cnt(t->r);\n        }\n    }\n\n    void update_acc(Tree t) {\n        if\
    \ (t) {\n            t->acc = f0(acc(t->l), f0(t->value, acc(t->r)));\n      \
    \  }\n    }\n\n    void pushup(Tree t) { update_cnt(t), update_acc(t); }\n\n \
    \   void pushdown(Tree t) {\n        if (t && t->rev) {\n            t->rev =\
    \ false;\n            swap(t->l, t->r);\n            if (t->l) t->l->rev ^= 1;\n\
    \            if (t->r) t->r->rev ^= 1;\n        }\n        if (t && t->lazy !=\
    \ u1) {\n            if (t->l) {\n                t->l->lazy = f1(t->l->lazy,\
    \ t->lazy);\n                t->l->acc = g(t->l->acc, p(t->lazy, cnt(t->l)));\n\
    \            }\n            if (t->r) {\n                t->r->lazy = f1(t->r->lazy,\
    \ t->lazy);\n                t->r->acc = g(t->r->acc, p(t->lazy, cnt(t->r)));\n\
    \            }\n            t->value = g(t->value, p(t->lazy, 1));\n         \
    \   t->lazy = u1;\n        }\n        pushup(t);\n    }\n\n    void split(Tree\
    \ t, int key, Tree& l, Tree& r) {\n        if (!t) {\n            l = r = nullptr;\n\
    \            return;\n        }\n        pushdown(t);\n        int implicit_key\
    \ = cnt(t->l) + 1;\n        if (key < implicit_key) {\n            split(t->l,\
    \ key, l, t->l), r = t;\n        } else {\n            split(t->r, key - implicit_key,\
    \ t->r, r), l = t;\n        }\n        pushup(t);\n    }\n\n    void insert(Tree&\
    \ t, int key, Tree item) {\n        Tree t1, t2;\n        split(t, key, t1, t2);\n\
    \        merge(t1, t1, item);\n        merge(t, t1, t2);\n    }\n\n    void merge(Tree&\
    \ t, Tree l, Tree r) {\n        pushdown(l);\n        pushdown(r);\n        if\
    \ (!l || !r) {\n            t = l ? l : r;\n        } else if (l->priority > r->priority)\
    \ {\n            merge(l->r, l->r, r), t = l;\n        } else {\n            merge(r->l,\
    \ l, r->l), t = r;\n        }\n        pushup(t);\n    }\n\n    void erase(Tree&\
    \ t, int key) {\n        Tree t1, t2, t3;\n        split(t, key + 1, t1, t2);\n\
    \        split(t1, key, t1, t3);\n        merge(t, t1, t2);\n    }\n\n    void\
    \ update(Tree t, int l, int r, T1 x) {\n        if (l >= r) return;\n        Tree\
    \ t1, t2, t3;\n        split(t, l, t1, t2);\n        split(t2, r - l, t2, t3);\n\
    \        t2->lazy = f1(t2->lazy, x);\n        t2->acc = g(t2->acc, p(x, cnt(t2)));\n\
    \        merge(t2, t2, t3);\n        merge(t, t1, t2);\n    }\n\n    T0 query(Tree\
    \ t, int l, int r) {\n        if (l == r) return u0;\n        Tree t1, t2, t3;\n\
    \        split(t, l, t1, t2);\n        split(t2, r - l, t2, t3);\n        T0 ret\
    \ = t2->acc;\n        merge(t2, t2, t3);\n        merge(t, t1, t2);\n        return\
    \ ret;\n    }\n\n    // [l, r)\u306E\u4E2D\u3067\u5DE6\u304B\u3089\u4F55\u756A\
    \u76EE\u304B\n    int find(Tree t, T0 x, int offset, bool left = true) {\n   \
    \     if (f0(t->acc, x) == x) {\n            return -1;\n        } else {\n  \
    \          if (left) {\n                if (t->l && f0(t->l->acc, x) != x) {\n\
    \                    return find(t->l, x, offset, left);\n                } else\
    \ {\n                    return (f0(t->value, x) != x) ? offset + cnt(t->l) :\
    \ find(t->r, x, offset + cnt(t->l) + 1, left);\n                }\n          \
    \  } else {\n                if (t->r && f0(t->r->acc, x) != x) {\n          \
    \          return find(t->r, x, offset + cnt(t->l) + 1, left);\n             \
    \   } else {\n                    return (f0(t->value, x) != x) ? offset + cnt(t->l)\
    \ : find(t->l, x, offset, left);\n                }\n            }\n        }\n\
    \    }\n\n    void reverse(Tree t, int l, int r) {\n        if (l > r) return;\n\
    \        Tree t1, t2, t3;\n        split(t, l, t1, t2);\n        split(t2, r -\
    \ l, t2, t3);\n        t2->rev ^= 1;\n        merge(t2, t2, t3);\n        merge(t,\
    \ t1, t2);\n    }\n\n    // [l, r)\u306E\u5148\u982D\u304Cm\u306B\u306A\u308B\u3088\
    \u3046\u306B\u30B7\u30D5\u30C8\u3055\u305B\u308B\u3002std::rotate\u3068\u540C\u3058\
    \u4ED5\u69D8\n    void rotate(Tree t, int l, int m, int r) {\n        reverse(t,\
    \ l, r);\n        reverse(t, l, l + r - m);\n        reverse(t, l + r - m, r);\n\
    \    }\n\n    void dump(Tree t) {\n        if (!t) return;\n        pushdown(t);\n\
    \        dump(t->l);\n        cout << t->value << \" \";\n        dump(t->r);\n\
    \    }\n\n   public:\n    BaseImplicitTreap(T0 u0_, T1 u1_) : u0(u0_), u1(u1_)\
    \ {}\n\n    void set_by_vector(const vector<T0>& a) {\n        for (int i = 0;\
    \ i < a.size(); i++) {\n            insert(i, a[i]);\n        }\n    }\n\n   \
    \ int size() { return cnt(root); }\n\n    void insert(int pos, T0 x) { insert(root,\
    \ pos, new Node(x, rnd.random(), u0, u1)); }\n\n    void update(int l, int r,\
    \ T1 x) { update(root, l, r, x); }\n\n    T0 query(int l, int r) { return query(root,\
    \ l, r); }\n\n    // \u4E8C\u5206\u63A2\u7D22\u3002[l, r)\u5185\u306Ek\u3067f0(tr[k],\
    \ x) != x\u3068\u306A\u308B\u6700\u5DE6/\u6700\u53F3\u306E\u3082\u306E\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u5834\u5408\u306F-1\n    // \u305F\u3068\u3048\u3070\
    MinMonoid\u306E\u5834\u5408\u3001x\u672A\u6E80\u306E\u6700\u5DE6/\u6700\u53F3\u306E\
    \u8981\u7D20\u306E\u4F4D\u7F6E\u3092\u8FD4\u3059\n    int binary_search(int l,\
    \ int r, T0 x, bool left = true) {\n        if (l >= r) return -1;\n        Tree\
    \ t1, t2, t3;\n        split(root, l, t1, t2);\n        split(t2, r - l, t2, t3);\n\
    \        int ret = find(t2, x, l, left);\n        merge(t2, t2, t3);\n       \
    \ merge(root, t1, t2);\n        return ret;\n    }\n\n    void erase(int pos)\
    \ { erase(root, pos); }\n\n    void reverse(int l, int r) { reverse(root, l, r);\
    \ }\n\n    void rotate(int l, int m, int r) { rotate(root, l, m, r); }\n\n   \
    \ void dump() {\n        dump(root);\n        cout << endl;\n    }\n\n    T0 operator[](int\
    \ pos) { return query(pos, pos + 1); }\n};\n\ntemplate <class T0, class T1>\n\
    struct MinUpdateQuery : public BaseImplicitTreap<T0, T1> {\n    using BaseImplicitTreap<T0,\
    \ T1>::BaseImplicitTreap;\n    MinUpdateQuery() : MinUpdateQuery(numeric_limits<T0>::max(),\
    \ numeric_limits<T1>::min()) {}\n    T0 f0(T0 x, T0 y) override { return min(x,\
    \ y); }\n    T1 f1(T1 x, T1 y) override { return y == numeric_limits<T1>::min()\
    \ ? x : y; }\n    T0 g(T0 x, T1 y) override { return y == numeric_limits<T1>::min()\
    \ ? x : y; }\n    T1 p(T1 x, int len) override { return x; }\n};\n\ntemplate <class\
    \ T0, class T1>\nstruct SumAddQuery : public BaseImplicitTreap<T0, T1> {\n   \
    \ using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n    SumAddQuery() : SumAddQuery(0,\
    \ 0) {}\n    T0 f0(T0 x, T0 y) override { return x + y; }\n    T1 f1(T1 x, T1\
    \ y) override { return x + y; }\n    T0 g(T0 x, T1 y) override { return x + y;\
    \ }\n    T1 p(T1 x, int len) override { return x * len; }\n};\n\ntemplate <class\
    \ T0, class T1>\nstruct MinAddQuery : public BaseImplicitTreap<T0, T1> {\n   \
    \ using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n    MinAddQuery() : MinAddQuery(numeric_limits<T0>::max(),\
    \ 0) {}\n    T0 f0(T0 x, T0 y) override { return min(x, y); }\n    T1 f1(T1 x,\
    \ T1 y) override { return x + y; }\n    T0 g(T0 x, T1 y) override { return x +\
    \ y; }\n    T1 p(T1 x, int len) override { return x; }\n};\n\ntemplate <class\
    \ T0, class T1>\nstruct SumUpdateQuery : public BaseImplicitTreap<T0, T1> {\n\
    \    using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n    SumUpdateQuery()\
    \ : SumUpdateQuery(0, numeric_limits<T1>::min()) {}\n    T0 f0(T0 x, T0 y) override\
    \ { return x + y; }\n    T1 f1(T1 x, T1 y) override { return y == numeric_limits<T1>::min()\
    \ ? x : y; }\n    T0 g(T0 x, T1 y) override { return y == numeric_limits<T1>::min()\
    \ ? x : y; }\n    T1 p(T1 x, int len) override { return x == numeric_limits<T1>::min()\
    \ ? numeric_limits<T1>::min() : x * len; }\n};\n\ntemplate <class T0>\nstruct\
    \ SumAffineQuery : public BaseImplicitTreap<T0, pair<T0, T0>> {\n    using T1\
    \ = pair<T0, T0>;  // first * x + second\n    using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n\
    \    SumAffineQuery() : SumAffineQuery(0, {1, 0}) {}\n    T0 f0(T0 x, T0 y) override\
    \ { return x + y; }\n    T1 f1(T1 x, T1 y) override { return {x.first * y.first,\
    \ x.second * y.first + y.second}; }\n    T0 g(T0 x, T1 y) override { return y.first\
    \ * x + y.second; }\n    T1 p(T1 x, int len) override { return {x.first, x.second\
    \ * len}; }\n    // update(i, j, {a, b}); // [i, j)\u306Bax + b\u3092\u4F5C\u7528\
    \n    // update(i, j, {0, a}); // update\n    // update(i, j, {1, a}); // \u52A0\
    \u7B97\n    // update(i, j, {a, 0}); // \u500D\n};\n\ntemplate <class T>\nstruct\
    \ MinmaxAffineQuery : public BaseImplicitTreap<pair<T, T>, pair<T, T>> {\n   \
    \ using T0 = pair<T, T>;  // {min, max}\n    using T1 = pair<T, T>;  // first\
    \ * x + second\n    using BaseImplicitTreap<T0, T1>::BaseImplicitTreap;\n    MinmaxAffineQuery()\n\
    \        : MinmaxAffineQuery({numeric_limits<T>::max(), -numeric_limits<T>::max()},\
    \ {1, 0}) {\n    }  // TODO: _u1\u3092\u4F7F\u3046\u3068\u30B3\u30F3\u30D1\u30A4\
    \u30EB\u901A\u3089\u306A\u3044\u539F\u56E0\u4E0D\u660E\n    T0 f0(T0 x, T0 y)\
    \ override { return {min(x.first, y.first), max(x.second, y.second)}; }\n    T1\
    \ f1(T1 x, T1 y) override { return {x.first * y.first, x.second * y.first + y.second};\
    \ }\n    T0 g(T0 x, T1 y) override {\n        T0 ret = {x.first * y.first + y.second,\
    \ x.second * y.first + y.second};\n        if (y.first < 0) swap(ret.first, ret.second);\n\
    \        return ret;\n    }\n    T1 p(T1 x, int len) override { return x; }\n\
    \    // update(i, j, {a, b}); // [i, j)\u306Bax + b\u3092\u4F5C\u7528\n    //\
    \ update(i, j, {0, a}); // update\n    // update(i, j, {1, a}); // \u52A0\u7B97\
    \n    // update(i, j, {a, 0}); // \u500D\n};\n#line 4 \"data-structure/pair-query-by-implicit-treap.hpp\"\
    \n\ntemplate <typename T0, typename T1, bool ascending = true>\nstruct PairQuery\
    \ {\n    // \u7D2F\u7A4D\u7528\u3002\u7B2C\u4E8C\u8981\u7D20\u3092\u7BA1\u7406\
    \n    SumUpdateQuery<T1, T1> tr;\n    // \u9806\u5E8F\u7BA1\u7406\u7528\n    MinUpdateQuery<pair<T0,\
    \ T1>, pair<T0, T1>> tr2;\n    int cnt = 0;\n\n    void add(const pair<T0, T1>&\
    \ a) {\n        int p = tr2.binary_search(0, tr2.size(), a, !ascending);\n   \
    \     if (ascending) {\n            tr.insert(p + 1, a.second);\n            tr2.insert(p\
    \ + 1, a);\n        } else {\n            if (p == -1) {\n                tr.insert(tr.size(),\
    \ a.second);\n                tr2.insert(tr2.size(), a);\n            } else {\n\
    \                tr.insert(p, a.second);\n                tr2.insert(p, a);\n\
    \            }\n        }\n        cnt++;\n    }\n\n    // \u7B2C\u4E00\u8981\u7D20\
    \u304Cx\u306E\u3082\u306E\u3068x\u3088\u308A\u5DE6\u5074\u306E\u3082\u306E\u306B\
    \u5BFE\u3057\u7B2C\u4E8C\u8981\u7D20\u306E\u7D2F\u7A4D\u3092\u8FD4\u3059\n   \
    \ T1 query(T0 x) {\n        if (ascending) {\n            int p = tr2.binary_search(0,\
    \ tr2.size(), {x, numeric_limits<T1>::max()}, false);\n            p++;\n    \
    \        return tr.query(0, p);\n        } else {\n            int p = tr2.binary_search(0,\
    \ tr2.size(), {x, numeric_limits<T1>::min()});\n            if (p == -1) p = cnt;\n\
    \            return tr.query(0, p);\n        }\n    }\n\n    void erase_at(int\
    \ k) {\n        assert(0 <= k && k < cnt);\n        tr.erase(k);\n        tr2.erase(k);\n\
    \        cnt--;\n    }\n\n    void erase_value(const pair<T0, T1>& a) {\n    \
    \    int p = tr2.binary_search(0, tr2.size(), a, !ascending);\n        if (ascending)\
    \ {\n            p++;\n        } else {\n            if (p == -1) p = cnt;\n \
    \           p--;\n        }\n        assert(0 <= p && p < cnt && tr2[p] == a);\n\
    \        erase_at(p);\n    }\n\n    int size() const { return cnt; }\n\n    T1\
    \ sum(int k) { return tr.query(0, k); }\n\n    pair<T0, T1> operator[](int k)\
    \ { return tr2[k]; }\n\n    void dump() { tr2.dump(); }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n#include \"../data-structure/implicit-treap.hpp\"\
    \n\ntemplate <typename T0, typename T1, bool ascending = true>\nstruct PairQuery\
    \ {\n    // \u7D2F\u7A4D\u7528\u3002\u7B2C\u4E8C\u8981\u7D20\u3092\u7BA1\u7406\
    \n    SumUpdateQuery<T1, T1> tr;\n    // \u9806\u5E8F\u7BA1\u7406\u7528\n    MinUpdateQuery<pair<T0,\
    \ T1>, pair<T0, T1>> tr2;\n    int cnt = 0;\n\n    void add(const pair<T0, T1>&\
    \ a) {\n        int p = tr2.binary_search(0, tr2.size(), a, !ascending);\n   \
    \     if (ascending) {\n            tr.insert(p + 1, a.second);\n            tr2.insert(p\
    \ + 1, a);\n        } else {\n            if (p == -1) {\n                tr.insert(tr.size(),\
    \ a.second);\n                tr2.insert(tr2.size(), a);\n            } else {\n\
    \                tr.insert(p, a.second);\n                tr2.insert(p, a);\n\
    \            }\n        }\n        cnt++;\n    }\n\n    // \u7B2C\u4E00\u8981\u7D20\
    \u304Cx\u306E\u3082\u306E\u3068x\u3088\u308A\u5DE6\u5074\u306E\u3082\u306E\u306B\
    \u5BFE\u3057\u7B2C\u4E8C\u8981\u7D20\u306E\u7D2F\u7A4D\u3092\u8FD4\u3059\n   \
    \ T1 query(T0 x) {\n        if (ascending) {\n            int p = tr2.binary_search(0,\
    \ tr2.size(), {x, numeric_limits<T1>::max()}, false);\n            p++;\n    \
    \        return tr.query(0, p);\n        } else {\n            int p = tr2.binary_search(0,\
    \ tr2.size(), {x, numeric_limits<T1>::min()});\n            if (p == -1) p = cnt;\n\
    \            return tr.query(0, p);\n        }\n    }\n\n    void erase_at(int\
    \ k) {\n        assert(0 <= k && k < cnt);\n        tr.erase(k);\n        tr2.erase(k);\n\
    \        cnt--;\n    }\n\n    void erase_value(const pair<T0, T1>& a) {\n    \
    \    int p = tr2.binary_search(0, tr2.size(), a, !ascending);\n        if (ascending)\
    \ {\n            p++;\n        } else {\n            if (p == -1) p = cnt;\n \
    \           p--;\n        }\n        assert(0 <= p && p < cnt && tr2[p] == a);\n\
    \        erase_at(p);\n    }\n\n    int size() const { return cnt; }\n\n    T1\
    \ sum(int k) { return tr.query(0, k); }\n\n    pair<T0, T1> operator[](int k)\
    \ { return tr2[k]; }\n\n    void dump() { tr2.dump(); }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/implicit-treap.hpp
  isVerificationFile: false
  path: data-structure/pair-query-by-implicit-treap.hpp
  requiredBy: []
  timestamp: '2023-03-14 23:16:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/pair-query-by-implicit-treap.hpp
layout: document
title: PairQuery (by Implicit Treap)
---

## 概要

pair 型の要素を第一要素の要素で sort したときの第二要素の累積を求める

## 宣言

```cpp
PairQuery<T0, T1, bool ascending = true> hoge;
```

`pair<T0,T1>` 集合が要素の型となる、 `accending` は要素を昇順にするかどうか

## クエリ

`void add(pair<T0, T1> a)` : 集合に `a` を追加 $O(log n)$

`void erase_at(int k)` : 位置を指定して要素を削除。先頭の削除なら `k = 0` を指定。 $O(log n)$

`void erase_value(pair<T0, T1> a)` : 要素を指定して削除。 `a` がすでに `add` されていることが仮定されている。 $O(log n)$

`int size()` : 現時点でのサイズを返す $O(1)$

`T1 query(T0 x)` : 第一要素が `x` の要素と `x` より左側にある要素に対し第二要素の累積を返します。 $O(log n)$

`pair<T0, T1> operator[](int k)` : インデックスアクセスができます。 $O(log n)$

`void dump()` : デバッグ用です。配列の中身をprintします。
