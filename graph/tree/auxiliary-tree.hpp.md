---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/tree/lca.hpp
    title: Lowest Common Ancestor
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
  code: "#pragma once\n#include \"../../template/template.hpp\"\n#include \"lca.hpp\"\
    \n\nstruct AuxiliaryTree : LCA {\n    using super = LCA;\n\n    vector<int> idx;\n\
    \    vector<vector<int>> T;\n    explicit AuxiliaryTree(const vector<vector<int>>\
    \ &G, int r = 0)\n        : super(G, r) {\n        build(G, r);\n    }\n\n   \
    \ void dfs(const vector<vector<int>> &G, int v, int p, int &pos) {\n        idx[v]\
    \ = pos++;\n        for (int u : G[v])\n            if (u != p) dfs(G, u, v, pos);\n\
    \    }\n\n    void build(const vector<vector<int>> &G, int r = 0) {\n        int\
    \ V = (int)G.size();\n        idx.assign(V, 0);\n        T.assign(V, vector<int>());\n\
    \        int pos = 0;\n        dfs(G, r, -1, pos);\n    }\n\n    void add_aux_edge(int\
    \ u, int v) {\n        T[u].emplace_back(v);\n        T[v].emplace_back(u);\n\
    \    }\n\n    using super::get, super::depth;\n    void query(vector<int> &vs)\
    \ {\n        assert(!vs.empty());\n        sort(vs.begin(), vs.end(),\n      \
    \       [&](int a, int b) { return idx[a] < idx[b]; });\n        vs.erase(unique(vs.begin(),\
    \ vs.end()), vs.end());\n\n        int k = vs.size();\n        stack<int> st;\n\
    \        st.emplace(vs[0]);\n        for (int i = 0; i + 1 < k; i++) {\n     \
    \       int w = get(vs[i], vs[i + 1]);\n            if (w != vs[i]) {\n      \
    \          int l = st.top();\n                st.pop();\n                while\
    \ (!st.empty() and depth[w] < depth[st.top()]) {\n                    add_aux_edge(st.top(),\
    \ l);\n                    l = st.top();\n                    st.pop();\n    \
    \            }\n                if (st.empty() or st.top() != w) {\n         \
    \           st.emplace(w);\n                    vs.emplace_back(w);\n        \
    \        }\n                add_aux_edge(w, l);\n            }\n            st.emplace(vs[i\
    \ + 1]);\n        }\n\n        while (st.size() > 1) {\n            int c = st.top();\n\
    \            st.pop();\n            add_aux_edge(st.top(), c);\n        }\n  \
    \  }\n\n    void clear(const vector<int> &ws) {\n        for (int w : ws) T[w].clear();\n\
    \    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  - graph/tree/lca.hpp
  isVerificationFile: false
  path: graph/tree/auxiliary-tree.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree/auxiliary-tree.hpp
layout: document
title: Auxiliary Tree
---
