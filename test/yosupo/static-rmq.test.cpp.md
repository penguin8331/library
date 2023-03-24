---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segment-tree.hpp
    title: Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/static-rmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line 3 \"template/macro.hpp\"\
    \n\n#define all(x) std::begin(x), std::end(x)\n#define rall(x) std::rbegin(x),\
    \ std::rend(x)\n#define elif else if\n#define updiv(N, X) (((N) + (X) - (1)) /\
    \ (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n#define INT(...)    \
    \ \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LL(...)     \\\n\
    \    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)        \\\n \
    \   string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)      \\\n\
    \    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...)        \\\n\
    \    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)     \\\n \
    \   ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n#define eb\
    \ emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\nusing\
    \ ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <algo/debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"data-structure/segment-tree.hpp\"\n\ntemplate <class Monoid>\n\
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
    \      sum = F(sum, dat[l]);\n            ++l;\n        } while ((l & -l) != l);\n\
    \        return N;\n    }\n\n    /* get min l that f(get(l, r)) = True (0-indexed),\
    \ O(log N) */\n    /* f(IDENTITY) need to be True */\n    int min_left(const function<bool(Monoid)>\
    \ f, int r = -1) {\n        if (r == 0) return 0;\n        if (r == -1) r = N;\n\
    \        r += SIZE_R;\n        Monoid sum = IDENTITY;\n        do {\n        \
    \    --r;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(F(dat[r],\
    \ sum))) {\n                while (r < SIZE_R) {\n                    r = r *\
    \ 2 + 1;\n                    if (f(F(dat[r], sum))) {\n                     \
    \   sum = F(dat[r], sum);\n                        --r;\n                    }\n\
    \                }\n                return r + 1 - SIZE_R;\n            }\n  \
    \          sum = F(dat[r], sum);\n        } while ((r & -r) != r);\n        return\
    \ 0;\n    }\n\n    friend ostream& operator<<(ostream& os, SegTree seg) {\n  \
    \      os << \"[ \";\n        for (int i = 0; i < seg.N; i++) {\n            os\
    \ << seg.get(i, i + 1) << \" \";\n        }\n        os << ']';\n        return\
    \ os;\n    }\n};\n#line 4 \"test/yosupo/static-rmq.test.cpp\"\n\nint main() {\n\
    \    int N, Q;\n    cin >> N >> Q;\n    SegTree<ll> seg(\n        N, [](ll a,\
    \ ll b) { return min(a, b); }, INF);\n    for (int i = 0; i < N; i++) {\n    \
    \    ll a;\n        cin >> a;\n        seg.set(i, a);\n    }\n    seg.build();\n\
    \    for (int i = 0; i < Q; i++) {\n        int l, r;\n        cin >> l >> r;\n\
    \        cout << seg.get(l, r) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    ../../template/template.hpp\"\n#include \"../../data-structure/segment-tree.hpp\"\
    \n\nint main() {\n    int N, Q;\n    cin >> N >> Q;\n    SegTree<ll> seg(\n  \
    \      N, [](ll a, ll b) { return min(a, b); }, INF);\n    for (int i = 0; i <\
    \ N; i++) {\n        ll a;\n        cin >> a;\n        seg.set(i, a);\n    }\n\
    \    seg.build();\n    for (int i = 0; i < Q; i++) {\n        int l, r;\n    \
    \    cin >> l >> r;\n        cout << seg.get(l, r) << endl;\n    }\n}"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/segment-tree.hpp
  isVerificationFile: true
  path: test/yosupo/static-rmq.test.cpp
  requiredBy: []
  timestamp: '2023-03-24 23:12:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/static-rmq.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static-rmq.test.cpp
- /verify/test/yosupo/static-rmq.test.cpp.html
title: test/yosupo/static-rmq.test.cpp
---
