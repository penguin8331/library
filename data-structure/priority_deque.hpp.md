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
  bundledCode: "#line 1 \"data-structure/priority_deque.hpp\"\ntemplate <class T>\n\
    struct priority_deque {\n    vector<T> d;\n    priority_deque() {}\n    priority_deque(const\
    \ vector<T>& d_) : d(d_) { make_heap(); }\n    template <class Iter>\n    priority_deque(Iter\
    \ first, Iter last) : d(first, last) {\n        make_heap();\n    }\n    void\
    \ push(const T& x) {\n        int k = d.size();\n        d.push_back(x);\n   \
    \     up(k);\n    }\n    void pop_min() {\n        if (d.size() < 3u) {\n    \
    \        d.pop_back();\n        } else {\n            swap(d[1], d.back());\n\
    \            d.pop_back();\n            int k = down(1);\n            up(k);\n\
    \        }\n    }\n    void pop_max() {\n        if (d.size() < 2u) {\n      \
    \      d.pop_back();\n        } else {\n            swap(d[0], d.back());\n  \
    \          d.pop_back();\n            int k = down(0);\n            up(k);\n \
    \       }\n    }\n    const T& get_min() const { return d.size() < 2u ? d[0] :\
    \ d[1]; }\n    const T& get_max() const { return d[0]; }\n    int size() const\
    \ { return d.size(); }\n    bool empty() const { return d.empty(); }\n    void\
    \ make_heap() {\n        for (int i = d.size(); i--;) {\n            if (i & 1\
    \ && d[i - 1] < d[i]) swap(d[i - 1], d[i]);\n            int k = down(i);\n  \
    \          up(k, i);\n        }\n    }\n    inline int parent(int k) const { return\
    \ ((k >> 1) - 1) & ~1; }\n    int down(int k) {\n        int n = d.size();\n \
    \       if (k & 1) {\n            while (2 * k + 1 < n) {\n                int\
    \ c = 2 * k + 3;\n                if (n <= c || d[c - 2] < d[c]) c -= 2;\n   \
    \             if (c < n && d[c] < d[k]) {\n                    swap(d[k], d[c]);\n\
    \                    k = c;\n                } else\n                    break;\n\
    \            }\n        } else {\n            while (2 * k + 2 < n) {\n      \
    \          int c = 2 * k + 4;\n                if (n <= c || d[c] < d[c - 2])\
    \ c -= 2;\n                if (c < n && d[k] < d[c]) {\n                    swap(d[k],\
    \ d[c]);\n                    k = c;\n                } else\n               \
    \     break;\n            }\n        }\n        return k;\n    }\n    int up(int\
    \ k, int root = 1) {\n        if ((k | 1) < (int)d.size() && d[k & ~1] < d[k |\
    \ 1]) {\n            swap(d[k & ~1], d[k | 1]);\n            k ^= 1;\n       \
    \ }\n        int p;\n        while (root < k && d[p = parent(k)] < d[k]) {\n \
    \           swap(d[p], d[k]);\n            k = p;\n        }\n        while (root\
    \ < k && d[k] < d[p = parent(k) | 1]) {\n            swap(d[p], d[k]);\n     \
    \       k = p;\n        }\n        return k;\n    }\n};\n"
  code: "template <class T>\nstruct priority_deque {\n    vector<T> d;\n    priority_deque()\
    \ {}\n    priority_deque(const vector<T>& d_) : d(d_) { make_heap(); }\n    template\
    \ <class Iter>\n    priority_deque(Iter first, Iter last) : d(first, last) {\n\
    \        make_heap();\n    }\n    void push(const T& x) {\n        int k = d.size();\n\
    \        d.push_back(x);\n        up(k);\n    }\n    void pop_min() {\n      \
    \  if (d.size() < 3u) {\n            d.pop_back();\n        } else {\n       \
    \     swap(d[1], d.back());\n            d.pop_back();\n            int k = down(1);\n\
    \            up(k);\n        }\n    }\n    void pop_max() {\n        if (d.size()\
    \ < 2u) {\n            d.pop_back();\n        } else {\n            swap(d[0],\
    \ d.back());\n            d.pop_back();\n            int k = down(0);\n      \
    \      up(k);\n        }\n    }\n    const T& get_min() const { return d.size()\
    \ < 2u ? d[0] : d[1]; }\n    const T& get_max() const { return d[0]; }\n    int\
    \ size() const { return d.size(); }\n    bool empty() const { return d.empty();\
    \ }\n    void make_heap() {\n        for (int i = d.size(); i--;) {\n        \
    \    if (i & 1 && d[i - 1] < d[i]) swap(d[i - 1], d[i]);\n            int k =\
    \ down(i);\n            up(k, i);\n        }\n    }\n    inline int parent(int\
    \ k) const { return ((k >> 1) - 1) & ~1; }\n    int down(int k) {\n        int\
    \ n = d.size();\n        if (k & 1) {\n            while (2 * k + 1 < n) {\n \
    \               int c = 2 * k + 3;\n                if (n <= c || d[c - 2] < d[c])\
    \ c -= 2;\n                if (c < n && d[c] < d[k]) {\n                    swap(d[k],\
    \ d[c]);\n                    k = c;\n                } else\n               \
    \     break;\n            }\n        } else {\n            while (2 * k + 2 <\
    \ n) {\n                int c = 2 * k + 4;\n                if (n <= c || d[c]\
    \ < d[c - 2]) c -= 2;\n                if (c < n && d[k] < d[c]) {\n         \
    \           swap(d[k], d[c]);\n                    k = c;\n                } else\n\
    \                    break;\n            }\n        }\n        return k;\n   \
    \ }\n    int up(int k, int root = 1) {\n        if ((k | 1) < (int)d.size() &&\
    \ d[k & ~1] < d[k | 1]) {\n            swap(d[k & ~1], d[k | 1]);\n          \
    \  k ^= 1;\n        }\n        int p;\n        while (root < k && d[p = parent(k)]\
    \ < d[k]) {\n            swap(d[p], d[k]);\n            k = p;\n        }\n  \
    \      while (root < k && d[k] < d[p = parent(k) | 1]) {\n            swap(d[p],\
    \ d[k]);\n            k = p;\n        }\n        return k;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/priority_deque.hpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/priority_deque.hpp
layout: document
redirect_from:
- /library/data-structure/priority_deque.hpp
- /library/data-structure/priority_deque.hpp.html
title: data-structure/priority_deque.hpp
---
