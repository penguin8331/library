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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class VAL>\n\
    struct RBST {\n    VAL SUM_UNITY = 0;\n\n    unsigned int randInt() {\n      \
    \  static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;\n\
    \        unsigned int tt = (tx ^ (tx << 11));\n        tx = ty;\n        ty =\
    \ tz;\n        tz = tw;\n        return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >>\
    \ 8)));\n    }\n\n    struct NODE {\n        NODE *left, *right;\n        VAL\
    \ val;\n        int size;\n        VAL sum;\n\n        NODE() : val(SUM_UNITY),\
    \ size(1), sum(SUM_UNITY) {\n            left = right = NULL;\n        }\n\n \
    \       NODE(VAL v) : val(v), size(1), sum(v) {\n            left = right = NULL;\n\
    \        }\n\n        inline void update() {\n        }\n\n        inline void\
    \ push() {\n        }\n    };\n    NODE *root;\n    RBST() : root(NULL) {}\n \
    \   RBST(NODE *node) : root(node) {}\n\n    inline int size(NODE *node) {\n  \
    \      return !node ? 0 : node->size;\n    }\n    inline int size() {\n      \
    \  return this->size(this->root);\n    }\n\n    inline VAL sum(NODE *node) {\n\
    \        return !node ? SUM_UNITY : node->sum;\n    }\n    inline VAL sum() {\n\
    \        return this->sum(this->root);\n    }\n\n    inline NODE *update(NODE\
    \ *node) {\n        node->size = size(node->left) + size(node->right) + 1;\n \
    \       node->sum = sum(node->left) + sum(node->right) + node->val;\n        node->update();\n\
    \        return node;\n    }\n\n    inline void push(NODE *node) {\n        if\
    \ (!node) return;\n        node->push();\n    }\n\n    inline int lowerBound(NODE\
    \ *node, VAL val) {\n        push(node);\n        if (!node) return 0;\n     \
    \   if (val <= node->val)\n            return lowerBound(node->left, val);\n \
    \       else\n            return size(node->left) + lowerBound(node->right, val)\
    \ + 1;\n    }\n    inline int lowerBound(VAL val) {\n        return this->lowerBound(this->root,\
    \ val);\n    }\n\n    inline int upperBound(NODE *node, VAL val) {\n        push(node);\n\
    \        if (!node) return 0;\n        if (val >= node->val)\n            return\
    \ size(node->left) + upperBound(node->right, val) + 1;\n        else\n       \
    \     return upperBound(node->left, val);\n    }\n    inline int upperBound(VAL\
    \ val) {\n        return this->upperBound(this->root, val);\n    }\n\n    inline\
    \ int count(VAL val) {\n        return upperBound(val) - lowerBound(val);\n  \
    \  }\n\n    inline VAL get(NODE *node, int k) {\n        push(node);\n       \
    \ if (!node) return -1;\n        if (k == size(node->left)) return node->val;\n\
    \        if (k < size(node->left))\n            return get(node->left, k);\n \
    \       else\n            return get(node->right, k - size(node->left) - 1);\n\
    \    }\n    inline VAL get(int k) {\n        return get(this->root, k);\n    }\n\
    \n    NODE *merge(NODE *left, NODE *right) {\n        push(left);\n        push(right);\n\
    \        if (!left || !right) {\n            if (left)\n                return\
    \ left;\n            else\n                return right;\n        }\n        if\
    \ (randInt() % (left->size + right->size) < left->size) {\n            left->right\
    \ = merge(left->right, right);\n            return update(left);\n        } else\
    \ {\n            right->left = merge(left, right->left);\n            return update(right);\n\
    \        }\n    }\n    void merge(RBST add) {\n        this->root = this->merge(this->root,\
    \ add.root);\n    }\n    pair<NODE *, NODE *> split(NODE *node, int k) {  // [0,\
    \ k), [k, n)\n        push(node);\n        if (!node) return make_pair(node, node);\n\
    \        if (k <= size(node->left)) {\n            pair<NODE *, NODE *> sub =\
    \ split(node->left, k);\n            node->left = sub.second;\n            return\
    \ make_pair(sub.first, update(node));\n        } else {\n            pair<NODE\
    \ *, NODE *> sub = split(node->right, k - size(node->left) - 1);\n           \
    \ node->right = sub.first;\n            return make_pair(update(node), sub.second);\n\
    \        }\n    }\n    RBST split(int k) {\n        pair<NODE *, NODE *> sub =\
    \ split(this->root, k);\n        this->root = sub.first;\n        return RBST(sub.second);\n\
    \    }\n\n    void insert(const VAL val) {\n        pair<NODE *, NODE *> sub =\
    \ this->split(this->root, this->lowerBound(val));\n        this->root = this->merge(this->merge(sub.first,\
    \ new NODE(val)), sub.second);\n    }\n\n    void erase(const VAL val) {\n   \
    \     if (!this->count(val)) return;\n        pair<NODE *, NODE *> sub = this->split(this->root,\
    \ this->lowerBound(val));\n        this->root = this->merge(sub.first, this->split(sub.second,\
    \ 1).second);\n    }\n\n    void print(NODE *node) {\n        if (!node) return;\n\
    \        push(node);\n        print(node->left);\n        cout << node->val <<\
    \ \" \";\n        print(node->right);\n    }\n    void print() {\n        cout\
    \ << \"{\";\n        print(this->root);\n        cout << \"}\" << endl;\n    }\n\
    };"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/randomized-binary-search-tree.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/randomized-binary-search-tree.hpp
layout: document
redirect_from:
- /library/data-structure/randomized-binary-search-tree.hpp
- /library/data-structure/randomized-binary-search-tree.hpp.html
title: data-structure/randomized-binary-search-tree.hpp
---
