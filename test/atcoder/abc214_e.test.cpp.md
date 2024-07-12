---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: others/range-set.hpp
    title: "\u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u30C6\u30AF"
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
    PROBLEM: https://atcoder.jp/contests/abc214/tasks/abc214_e
    links:
    - https://atcoder.jp/contests/abc214/tasks/abc214_e
  bundledCode: "#line 1 \"test/atcoder/abc214_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc214/tasks/abc214_e\"\
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
    \ std;\n#line 3 \"others/range-set.hpp\"\n\ntemplate <typename T>\nstruct RangeSet\
    \ {\n    set<pair<T, T>> st;\n    T TINF;\n\n    RangeSet() : TINF(numeric_limits<T>::max()\
    \ / 2) {\n        st.emplace(TINF, TINF);\n        st.emplace(-TINF, -TINF);\n\
    \    }\n    // [l,r] covered?\n    bool covered(T l, T r) {\n        assert(l\
    \ <= r);\n        auto ite = prev(st.lower_bound({l + 1, l + 1}));\n        return\
    \ ite->first <= l and r <= ite->second;\n    }\n    bool covered(T x) { return\
    \ covered(x, x); }\n    // [l, r]\u304C\u30AB\u30D0\u30FC\u3055\u308C\u3066\u3044\
    \u308B\u306A\u3089\uFF0C\u305D\u306E\u533A\u9593\u3092\u8FD4\u3059.\n    // \u3055\
    \u308C\u3066\u3044\u306A\u3044\u306A\u3089[-TINF,-TINF]\u3092\u8FD4\u3059\n  \
    \  pair<T, T> covered_by(T l, T r) {\n        assert(l <= r);\n        auto ite\
    \ = prev(st.lower_bound({l + 1, l + 1}));\n        if (ite->first <= l and r <=\
    \ ite->second) return *ite;\n        return make_pair(-TINF, -TINF);\n    }\n\
    \    pair<T, T> covered_by(T x) { return covered_by(x, x); }\n    // insert[l,r],\
    \ \u5897\u52A0\u91CF\u3092\u8FD4\u3059\n    T insert(T l, T r) {\n        assert(l\
    \ <= r);\n        auto ite = prev(st.lower_bound({l + 1, l + 1}));\n        if\
    \ (ite->first <= l and r <= ite->second) return T(0);\n        T sum_erased =\
    \ T(0);\n        if (ite->first <= l and l <= ite->second + 1) {\n           \
    \ l = ite->first;\n            sum_erased += ite->second - ite->first + 1;\n \
    \           ite = st.erase(ite);\n        } else\n            ite = next(ite);\n\
    \        while (r > ite->second) {\n            sum_erased += ite->second - ite->first\
    \ + 1;\n            ite = st.erase(ite);\n        }\n        if (ite->first -\
    \ 1 <= r) {\n            sum_erased += ite->second - ite->first + 1;\n       \
    \     r = ite->second;\n            st.erase(ite);\n        }\n        st.emplace(l,\
    \ r);\n        return r - l + 1 - sum_erased;\n    }\n    T insert(T x) { return\
    \ insert(x, x); }\n    // erase [l,r], \u6E1B\u5C11\u91CF\u3092\u8FD4\u3059\n\
    \    T erase(T l, T r) {\n        assert(l <= r);\n        auto ite = prev(st.lower_bound({l\
    \ + 1, l + 1}));\n        if (ite->first <= l and r <= ite->second) {\n      \
    \      // \u5B8C\u5168\u306B1\u3064\u306E\u533A\u9593\u306B\u5305\u542B\u3055\u308C\
    \u3066\u3044\u308B\n            if (ite->first < l) st.emplace(ite->first, l -\
    \ 1);\n            if (r < ite->second) st.emplace(r + 1, ite->second);\n    \
    \        st.erase(ite);\n            return r - l + 1;\n        }\n\n        T\
    \ ret = T(0);\n        if (ite->first <= l and l <= ite->second) {\n         \
    \   ret += ite->second - l + 1;  // \u6D88\u3048\u305F\n            if (ite->first\
    \ < l) st.emplace(ite->first, l - 1);\n            ite = st.erase(ite);  // \u6B21\
    \u3078\n        } else\n            ite = next(ite);\n        while (ite->second\
    \ <= r) {\n            ret += ite->second - ite->first + 1;\n            ite =\
    \ st.erase(ite);\n        }\n        // \u53F3\u7AEF\u304C\u533A\u9593\u306E\u9593\
    \u306B\u3042\u308B\u304B\n        if (ite->first <= r) {\n            ret += r\
    \ - ite->first + 1;\n            st.emplace(r + 1, ite->second);\n           \
    \ st.erase(ite);\n        }\n        return ret;\n    }\n    T erase(T x) { return\
    \ erase(x, x); }\n    // number of range\n    int size() { return (int)st.size()\
    \ - 2; }\n    // mex [x,~)\n    T mex(T x = 0) {\n        auto ite = prev(st.lower_bound({x\
    \ + 1, x + 1}));\n        if (ite->first <= x and x <= ite->second)\n        \
    \    return ite->second + 1;\n        else\n            return x;\n    }\n   \
    \ void output() {\n        cout << \"RangeSet : \";\n        for (auto &p : st)\
    \ {\n            if (p.first == -TINF or p.second == TINF) continue;\n       \
    \     cout << \"[\" << p.first << \", \" << p.second << \"] \";\n        }\n \
    \       cout << \"\\n\";\n    }\n};\n#line 4 \"test/atcoder/abc214_e.test.cpp\"\
    \n\nvoid solve() {\n    INT(N);\n    vector<pll> A(N);\n    scan(A);\n    sort(all(A),\
    \ [&](pll a, pll b) { return a.second < b.second; });\n    // \u3059\u3067\u306B\
    \u4F7F\u308F\u308C\u305F\u30DC\u30FC\u30EB\n    RangeSet<ll> used;\n    for (int\
    \ i = 0; i < N; i++) {\n        ll nxt = used.mex(A[i].first);\n        if (nxt\
    \ > A[i].second) {\n            cout << \"No\" << endl;\n            return;\n\
    \        }\n        used.insert(nxt, nxt);\n    }\n    cout << \"Yes\" << endl;\n\
    }\nint main() {\n    INT(T);\n    while (T--) solve();\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc214/tasks/abc214_e\"\n#include\
    \ \"../../others/range-set.hpp\"\n#include \"../../template/template.hpp\"\n\n\
    void solve() {\n    INT(N);\n    vector<pll> A(N);\n    scan(A);\n    sort(all(A),\
    \ [&](pll a, pll b) { return a.second < b.second; });\n    // \u3059\u3067\u306B\
    \u4F7F\u308F\u308C\u305F\u30DC\u30FC\u30EB\n    RangeSet<ll> used;\n    for (int\
    \ i = 0; i < N; i++) {\n        ll nxt = used.mex(A[i].first);\n        if (nxt\
    \ > A[i].second) {\n            cout << \"No\" << endl;\n            return;\n\
    \        }\n        used.insert(nxt, nxt);\n    }\n    cout << \"Yes\" << endl;\n\
    }\nint main() {\n    INT(T);\n    while (T--) solve();\n}"
  dependsOn:
  - others/range-set.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: true
  path: test/atcoder/abc214_e.test.cpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc214_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc214_e.test.cpp
- /verify/test/atcoder/abc214_e.test.cpp.html
title: test/atcoder/abc214_e.test.cpp
---
