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
  - icon: ':x:'
    path: test/atcoder/abc281_e.test.cpp
    title: test/atcoder/abc281_e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
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
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc281_e.test.cpp
documentation_of: data-structure/binary-trie.hpp
layout: document
redirect_from:
- /library/data-structure/binary-trie.hpp
- /library/data-structure/binary-trie.hpp.html
title: data-structure/binary-trie.hpp
---
