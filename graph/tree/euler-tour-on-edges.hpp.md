---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segment-tree.hpp
    title: Segment Tree
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
  code: "#pragma once\n#include \"../../data-structure/segment-tree.hpp\"\n#include\
    \ \"../../data-structure/sparse-table.hpp\"\n#include \"../../template/template.hpp\"\
    \n\nstruct Edge {\n    int next;\n    long long cost;\n    int idx;\n};\nstruct\
    \ EulerTour {\n    using pli = pair<long long, int>;\n    vector<int> edge;\n\
    \    vector<int> node;\n    vector<int> vf, ve;\n    vector<int> ef, ee;\n   \
    \ vector<int> depth;\n    vector<vector<Edge>> tree;\n    SparseTable<pair<int,\
    \ int>> st;\n    SegTree<pli> seg;\n    const function<pli(pli, pli)> fm = [](pli\
    \ a, pli b) { return pli{a.first * a.second + b.first * b.second, 1}; };\n   \
    \ EulerTour(const vector<vector<Edge>>& tree_) {\n        init(tree_);\n    }\n\
    \    void init(const vector<vector<Edge>>& tree_) {\n        tree = tree_;\n \
    \       int V = (int)tree.size();\n        depth.resize(V * 2 - 1);\n        edge.resize(V\
    \ * 2 - 2);\n        node.resize(V * 2 - 1);\n        vf.resize(V);\n        ve.resize(V);\n\
    \        ef.resize(V - 1);\n        ee.resize(V - 1);\n        seg.init((V - 1)\
    \ * 2, fm, pli({0, 0}));\n        int k = 0;\n        dfs(0, -1, 0, k);\n    \
    \    vector<pair<int, int>> tmp((int)depth.size());\n        for (int i = 0; i\
    \ < (int)depth.size(); i++) {\n            tmp[i] = {depth[i], i};\n        }\n\
    \        st.init(tmp);\n        seg.build();\n    }\n    void dfs(int now, int\
    \ prev, int dep, int& ord) {\n        node[ord] = now;\n        depth[ord] = dep;\n\
    \        vf[now] = ve[now] = ord;\n        ord++;\n        for (const auto& [next,\
    \ cost, idx] : tree[now]) {\n            if (next != prev) {\n               \
    \ seg.set(ord - 1, {cost, 1});\n                edge[ord - 1] = idx;\n       \
    \         ef[idx] = ord - 1;\n                dfs(next, now, dep + 1, ord);\n\
    \                node[ord] = now;\n                depth[ord] = dep;\n       \
    \         ve[next] = ord;\n                ee[idx] = ord - 1;\n              \
    \  seg.set(ord - 1, {cost, -1});\n                edge[ord - 1] = idx;\n     \
    \           ord++;\n            }\n        }\n    }\n    inline int LCA(int u,\
    \ int v) {\n        int a = vf[u], b = vf[v];\n        if (a > b) swap(a, b);\n\
    \        return node[st.get(a, b + 1).second];\n    }\n    inline void update(int\
    \ idx, int x) {\n        seg.update(ef[idx], {x, 1});\n        seg.update(ee[idx],\
    \ {x, -1});\n    }\n    inline long long get(int v) {\n        return seg.get(0,\
    \ vf[v]).first;\n    }\n    inline long long get(int u, int v) {\n        int\
    \ lca = LCA(u, v);\n        return get(u) + get(v) - get(lca) * 2;\n    }\n};"
  dependsOn:
  - data-structure/segment-tree.hpp
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - data-structure/sparse-table.hpp
  isVerificationFile: false
  path: graph/tree/euler-tour-on-edges.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/euler-tour-on-edges.hpp
layout: document
redirect_from:
- /library/graph/tree/euler-tour-on-edges.hpp
- /library/graph/tree/euler-tour-on-edges.hpp.html
title: graph/tree/euler-tour-on-edges.hpp
---
