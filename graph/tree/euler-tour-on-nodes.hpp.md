---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/lazy-segment-tree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: data-structure/sparse-table.hpp
    title: data-structure/sparse-table.hpp
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
    path: test/AOJ/2667.test.cpp
    title: test/AOJ/2667.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../../data-structure/lazy-segment-tree.hpp\"\n#include\
    \ \"../../data-structure/sparse-table.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nstruct EulerTour {\n    using Graph = vector<vector<int>>;\n    using Node\
    \ = pair<long long, int>;\n    const function<Node(Node, Node)> fm = [](Node a,\
    \ Node b) { return Node(a.first + b.first, a.second + b.second); };\n    const\
    \ function<void(Node &, long long)> fa = [](Node &a, long long d) { a.first +=\
    \ d * a.second; };\n    const function<void(long long &, long long)> fl = [](long\
    \ long &d, long long e) { d += e; };\n\n    // main results\n    Graph tree;\n\
    \    vector<int> depth;\n    vector<int> node;    // the node-number of i-th element\
    \ of Euler-tour\n    vector<int> vf, ve;  // the index of Euler-tour of node v\n\
    \    vector<int> eid;     // the index of edge e (i*2 + (0: dir to leaf, 1: dir\
    \ to root))\n\n    // sub results\n    SparseTable<pair<int, int>> st;  // depth\
    \ (to find LCA)\n\n    // segtree\n    Lazy_SegTree<Node, long long> seg;\n\n\
    \    // initialization\n    EulerTour(const Graph &tree_) { init(tree_); }\n \
    \   void init(const Graph &tree_) {\n        tree = tree_;\n        int V = (int)tree.size();\n\
    \        depth.resize(V * 2 - 1);\n        node.resize(V * 2 - 1);\n        vf.resize(V);\n\
    \        ve.resize(V);\n        eid.resize((V - 1) * 2);\n        seg.init((V\
    \ - 1) * 2, fm, fa, fl, Node(0, 0), 0);\n        int k = 0;\n        dfs(0, -1,\
    \ 0, k);\n        vector<pair<int, int>> tmp(int(depth.size()));\n        for\
    \ (int i = 0; i < int(depth.size()); i++) {\n            tmp[i] = {depth[i], i};\n\
    \        }\n        st.init(tmp);\n        seg.build();\n    }\n\n    void dfs(int\
    \ v, int par, int dep, int &ord) {\n        node[ord] = v;\n        depth[ord]\
    \ = dep;\n        vf[v] = ve[v] = ord;\n        ++ord;\n        for (auto e :\
    \ tree[v]) {\n            if (e == par) continue;\n            seg.set(ord - 1,\
    \ Node(0, 1));\n            dfs(e, v, dep + 1, ord);\n            node[ord] =\
    \ v;\n            depth[ord] = dep;\n            ve[v] = ord;\n            seg.set(ord\
    \ - 1, Node(0, -1));\n            ++ord;\n        }\n    }\n\n    inline int LCA(int\
    \ u, int v) {\n        int a = vf[u], b = vf[v];\n        if (a > b) swap(a, b);\n\
    \        return node[st.get(a, b + 1).second];\n    }\n\n    inline void update(int\
    \ v, long long x) {\n        seg.update(vf[v], ve[v], x);\n    }\n\n    inline\
    \ long long get(int v) {\n        return seg.get(0, vf[v]).first;\n    }\n\n \
    \   inline long long get(int u, int v) {\n        int lca = LCA(u, v);\n     \
    \   return get(u) + get(v) - get(lca) * 2;\n    }\n};"
  dependsOn:
  - data-structure/lazy-segment-tree.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: graph/tree/euler-tour-on-nodes.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2667.test.cpp
documentation_of: graph/tree/euler-tour-on-nodes.hpp
layout: document
redirect_from:
- /library/graph/tree/euler-tour-on-nodes.hpp
- /library/graph/tree/euler-tour-on-nodes.hpp.html
title: graph/tree/euler-tour-on-nodes.hpp
---
