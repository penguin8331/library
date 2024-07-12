---
data:
  _extendedDependsOn:
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc281_e.test.cpp
    title: test/atcoder/abc281_e.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ std;\n#line 3 \"data-structure/binary-trie.hpp\"\n\ntemplate <typename INT,\
    \ size_t MAX_DIGIT>\nstruct BinaryTrie {\n    struct Node {\n        size_t count;\n\
    \        Node *prev, *left, *right;\n        explicit Node(Node *prev)\n     \
    \       : count(0), prev(prev), left(nullptr), right(nullptr) {}\n    };\n   \
    \ INT lazy;\n    Node *root;\n\n    // constructor\n    BinaryTrie() : lazy(0),\
    \ root(emplace(nullptr)) {}\n    inline size_t get_count(Node *v) const { return\
    \ v ? v->count : 0; }\n    inline size_t size() const { return get_count(root);\
    \ }\n\n    // add and get value of Node\n    inline void add(INT val) { lazy ^=\
    \ val; }\n    inline INT get(Node *v) {\n        if (!v) return -1;\n        INT\
    \ res = 0;\n        for (int i = 0; i < MAX_DIGIT; ++i) {\n            if (v ==\
    \ v->prev->right) res |= (1 << i);\n            v = v->prev;\n        }\n    \
    \    return res ^ lazy;\n    }\n\n    // find Node* whose value is val\n    Node\
    \ *find(INT val) {\n        INT nval = val ^ lazy;\n        Node *v = root;\n\
    \        for (int i = MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (nval\
    \ >> i) & 1;\n            if (flag)\n                v = v->right;\n         \
    \   else\n                v = v->left;\n            if (!v) return v;\n      \
    \  }\n        return v;\n    }\n\n    // insert\n    inline Node *emplace(Node\
    \ *prev) { return new Node(prev); }\n    void insert(INT val, size_t k = 1) {\n\
    \        INT nval = val ^ lazy;\n        Node *v = root;\n        for (int i =\
    \ MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (nval >> i) & 1;\n  \
    \          if (flag && !v->right) v->right = emplace(v);\n            if (!flag\
    \ && !v->left) v->left = emplace(v);\n            if (flag)\n                v\
    \ = v->right;\n            else\n                v = v->left;\n        }\n   \
    \     v->count += k;\n        while ((v = v->prev))\n            v->count = get_count(v->left)\
    \ + get_count(v->right);\n    }\n\n    // erase\n    Node *clear(Node *v) {\n\
    \        if (!v || get_count(v)) return v;\n        delete (v);\n        return\
    \ nullptr;\n    }\n    bool erase(Node *v, size_t k = 1) {\n        if (!v) return\
    \ false;\n        v->count -= k;\n        while ((v = v->prev)) {\n          \
    \  v->left = clear(v->left);\n            v->right = clear(v->right);\n      \
    \      v->count = get_count(v->left) + get_count(v->right);\n        }\n     \
    \   return true;\n    }\n    bool erase(INT val) {\n        auto v = find(val);\n\
    \        return erase(v);\n    }\n\n    // max (with xor-addition of val) and\
    \ min (with xor-addition of val)\n    Node *get_max(INT val = 0) {\n        INT\
    \ nval = val ^ lazy;\n        Node *v = root;\n        for (int i = MAX_DIGIT\
    \ - 1; i >= 0; --i) {\n            bool flag = (nval >> i) & 1;\n            if\
    \ (!v->right)\n                v = v->left;\n            else if (!v->left)\n\
    \                v = v->right;\n            else if (flag)\n                v\
    \ = v->left;\n            else\n                v = v->right;\n        }\n   \
    \     return v;\n    }\n    Node *get_min(INT val = 0) {\n        return get_max(~val\
    \ & ((1 << MAX_DIGIT) - 1));\n    }\n\n    // lower_bound, upper_bound\n    Node\
    \ *get_cur_node(Node *v, int i) {\n        if (!v) return v;\n        Node *left\
    \ = v->left, *right = v->right;\n        if ((lazy >> i) & 1) swap(left, right);\n\
    \        if (left)\n            return get_cur_node(left, i + 1);\n        else\
    \ if (right)\n            return get_cur_node(right, i + 1);\n        return v;\n\
    \    }\n    Node *get_next_node(Node *v, int i) {\n        if (!v->prev) return\
    \ nullptr;\n        Node *left = v->prev->left, *right = v->prev->right;\n   \
    \     if ((lazy >> (i + 1)) & 1) swap(left, right);\n        if (v == left &&\
    \ right)\n            return get_cur_node(right, i);\n        else\n         \
    \   return get_next_node(v->prev, i + 1);\n    }\n    Node *lower_bound(INT val)\
    \ {\n        INT nval = val ^ lazy;\n        Node *v = root;\n        for (int\
    \ i = MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (nval >> i) & 1;\n\
    \            if (flag && v->right)\n                v = v->right;\n          \
    \  else if (!flag && v->left)\n                v = v->left;\n            else\
    \ if ((val >> i) & 1)\n                return get_next_node(v, i);\n         \
    \   else\n                return get_cur_node(v, i);\n        }\n        return\
    \ v;\n    }\n    Node *upper_bound(INT val) { return lower_bound(val + 1); }\n\
    \    size_t order_of_val(INT val) {\n        Node *v = root;\n        size_t res\
    \ = 0;\n        for (int i = MAX_DIGIT - 1; i >= 0; --i) {\n            Node *left\
    \ = v->left, *right = v->right;\n            if ((lazy >> i) & 1) swap(left, right);\n\
    \            bool flag = (val >> i) & 1;\n            if (flag) {\n          \
    \      res += get_count(left);\n                v = right;\n            } else\n\
    \                v = left;\n        }\n        return res;\n    }\n\n    // k-th,\
    \ k is 0-indexed\n    Node *get_kth(size_t k, INT val = 0) {\n        Node *v\
    \ = root;\n        if (get_count(v) <= k) return nullptr;\n        for (int i\
    \ = MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (lazy >> i) & 1;\n\
    \            Node *left = (flag ? v->right : v->left);\n            Node *right\
    \ = (flag ? v->left : v->right);\n            if (get_count(left) <= k)\n    \
    \            k -= get_count(left), v = right;\n            else\n            \
    \    v = left;\n        }\n        return v;\n    }\n\n    // debug\n    void\
    \ print(Node *v, const string &prefix = \"\") {\n        if (!v) return;\n   \
    \     cout << prefix << \": \" << v->count << endl;\n        print(v->left, prefix\
    \ + \"0\");\n        print(v->right, prefix + \"1\");\n    }\n    void print()\
    \ { print(root); }\n};\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <typename\
    \ INT, size_t MAX_DIGIT>\nstruct BinaryTrie {\n    struct Node {\n        size_t\
    \ count;\n        Node *prev, *left, *right;\n        explicit Node(Node *prev)\n\
    \            : count(0), prev(prev), left(nullptr), right(nullptr) {}\n    };\n\
    \    INT lazy;\n    Node *root;\n\n    // constructor\n    BinaryTrie() : lazy(0),\
    \ root(emplace(nullptr)) {}\n    inline size_t get_count(Node *v) const { return\
    \ v ? v->count : 0; }\n    inline size_t size() const { return get_count(root);\
    \ }\n\n    // add and get value of Node\n    inline void add(INT val) { lazy ^=\
    \ val; }\n    inline INT get(Node *v) {\n        if (!v) return -1;\n        INT\
    \ res = 0;\n        for (int i = 0; i < MAX_DIGIT; ++i) {\n            if (v ==\
    \ v->prev->right) res |= (1 << i);\n            v = v->prev;\n        }\n    \
    \    return res ^ lazy;\n    }\n\n    // find Node* whose value is val\n    Node\
    \ *find(INT val) {\n        INT nval = val ^ lazy;\n        Node *v = root;\n\
    \        for (int i = MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (nval\
    \ >> i) & 1;\n            if (flag)\n                v = v->right;\n         \
    \   else\n                v = v->left;\n            if (!v) return v;\n      \
    \  }\n        return v;\n    }\n\n    // insert\n    inline Node *emplace(Node\
    \ *prev) { return new Node(prev); }\n    void insert(INT val, size_t k = 1) {\n\
    \        INT nval = val ^ lazy;\n        Node *v = root;\n        for (int i =\
    \ MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (nval >> i) & 1;\n  \
    \          if (flag && !v->right) v->right = emplace(v);\n            if (!flag\
    \ && !v->left) v->left = emplace(v);\n            if (flag)\n                v\
    \ = v->right;\n            else\n                v = v->left;\n        }\n   \
    \     v->count += k;\n        while ((v = v->prev))\n            v->count = get_count(v->left)\
    \ + get_count(v->right);\n    }\n\n    // erase\n    Node *clear(Node *v) {\n\
    \        if (!v || get_count(v)) return v;\n        delete (v);\n        return\
    \ nullptr;\n    }\n    bool erase(Node *v, size_t k = 1) {\n        if (!v) return\
    \ false;\n        v->count -= k;\n        while ((v = v->prev)) {\n          \
    \  v->left = clear(v->left);\n            v->right = clear(v->right);\n      \
    \      v->count = get_count(v->left) + get_count(v->right);\n        }\n     \
    \   return true;\n    }\n    bool erase(INT val) {\n        auto v = find(val);\n\
    \        return erase(v);\n    }\n\n    // max (with xor-addition of val) and\
    \ min (with xor-addition of val)\n    Node *get_max(INT val = 0) {\n        INT\
    \ nval = val ^ lazy;\n        Node *v = root;\n        for (int i = MAX_DIGIT\
    \ - 1; i >= 0; --i) {\n            bool flag = (nval >> i) & 1;\n            if\
    \ (!v->right)\n                v = v->left;\n            else if (!v->left)\n\
    \                v = v->right;\n            else if (flag)\n                v\
    \ = v->left;\n            else\n                v = v->right;\n        }\n   \
    \     return v;\n    }\n    Node *get_min(INT val = 0) {\n        return get_max(~val\
    \ & ((1 << MAX_DIGIT) - 1));\n    }\n\n    // lower_bound, upper_bound\n    Node\
    \ *get_cur_node(Node *v, int i) {\n        if (!v) return v;\n        Node *left\
    \ = v->left, *right = v->right;\n        if ((lazy >> i) & 1) swap(left, right);\n\
    \        if (left)\n            return get_cur_node(left, i + 1);\n        else\
    \ if (right)\n            return get_cur_node(right, i + 1);\n        return v;\n\
    \    }\n    Node *get_next_node(Node *v, int i) {\n        if (!v->prev) return\
    \ nullptr;\n        Node *left = v->prev->left, *right = v->prev->right;\n   \
    \     if ((lazy >> (i + 1)) & 1) swap(left, right);\n        if (v == left &&\
    \ right)\n            return get_cur_node(right, i);\n        else\n         \
    \   return get_next_node(v->prev, i + 1);\n    }\n    Node *lower_bound(INT val)\
    \ {\n        INT nval = val ^ lazy;\n        Node *v = root;\n        for (int\
    \ i = MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (nval >> i) & 1;\n\
    \            if (flag && v->right)\n                v = v->right;\n          \
    \  else if (!flag && v->left)\n                v = v->left;\n            else\
    \ if ((val >> i) & 1)\n                return get_next_node(v, i);\n         \
    \   else\n                return get_cur_node(v, i);\n        }\n        return\
    \ v;\n    }\n    Node *upper_bound(INT val) { return lower_bound(val + 1); }\n\
    \    size_t order_of_val(INT val) {\n        Node *v = root;\n        size_t res\
    \ = 0;\n        for (int i = MAX_DIGIT - 1; i >= 0; --i) {\n            Node *left\
    \ = v->left, *right = v->right;\n            if ((lazy >> i) & 1) swap(left, right);\n\
    \            bool flag = (val >> i) & 1;\n            if (flag) {\n          \
    \      res += get_count(left);\n                v = right;\n            } else\n\
    \                v = left;\n        }\n        return res;\n    }\n\n    // k-th,\
    \ k is 0-indexed\n    Node *get_kth(size_t k, INT val = 0) {\n        Node *v\
    \ = root;\n        if (get_count(v) <= k) return nullptr;\n        for (int i\
    \ = MAX_DIGIT - 1; i >= 0; --i) {\n            bool flag = (lazy >> i) & 1;\n\
    \            Node *left = (flag ? v->right : v->left);\n            Node *right\
    \ = (flag ? v->left : v->right);\n            if (get_count(left) <= k)\n    \
    \            k -= get_count(left), v = right;\n            else\n            \
    \    v = left;\n        }\n        return v;\n    }\n\n    // debug\n    void\
    \ print(Node *v, const string &prefix = \"\") {\n        if (!v) return;\n   \
    \     cout << prefix << \": \" << v->count << endl;\n        print(v->left, prefix\
    \ + \"0\");\n        print(v->right, prefix + \"1\");\n    }\n    void print()\
    \ { print(root); }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/binary-trie.hpp
  requiredBy: []
  timestamp: '2024-07-12 09:43:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/atcoder/abc281_e.test.cpp
documentation_of: data-structure/binary-trie.hpp
layout: document
redirect_from:
- /library/data-structure/binary-trie.hpp
- /library/data-structure/binary-trie.hpp.html
title: data-structure/binary-trie.hpp
---
