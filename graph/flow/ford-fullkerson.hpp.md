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
    path: test/AOJ/GRL_6_A.test.cpp
    title: test/AOJ/GRL_6_A.test.cpp
  - icon: ':x:'
    path: test/AOJ/GRL_7_A.test.cpp
    title: test/AOJ/GRL_7_A.test.cpp
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
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\ntemplate <class\
    \ FLOWTYPE>\nstruct Edge {\n    int rev, from, to;\n    FLOWTYPE cap, icap;\n\
    \    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c)\
    \ {}\n    friend ostream& operator<<(ostream& s, Edge E) {\n        if (E.cap\
    \ > 0)\n            return s << E.from << \"->\" << E.to << '(' << E.cap << ')'\
    \ << \" \";\n        else\n            return s;\n    }\n};\n\ntemplate <class\
    \ FLOWTYPE>\nstruct Graph {\n    vector<vector<Edge<FLOWTYPE> > > list;\n\n  \
    \  Graph(int n = 0) : list(n) {}\n    void init(int n = 0) {\n        list.clear();\n\
    \        list.resize(n);\n    }\n    void reset() {\n        for (int i = 0; i\
    \ < (int)list.size(); ++i)\n            for (int j = 0; j < list[i].size(); ++j)\
    \ list[i][j].cap = list[i][j].icap;\n    }\n    inline vector<Edge<FLOWTYPE> >&\
    \ operator[](int i) { return list[i]; }\n    inline const size_t size() const\
    \ { return list.size(); }\n\n    inline Edge<FLOWTYPE>& redge(Edge<FLOWTYPE> e)\
    \ {\n        if (e.from != e.to)\n            return list[e.to][e.rev];\n    \
    \    else\n            return list[e.to][e.rev + 1];\n    }\n\n    void addedge(int\
    \ from, int to, FLOWTYPE cap) {\n        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(),\
    \ from, to, cap));\n        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size()\
    \ - 1, to, from, 0));\n    }\n\n    void add_undirected_edge(int from, int to,\
    \ FLOWTYPE cap) {\n        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(),\
    \ from, to, cap));\n        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size()\
    \ - 1, to, from, cap));\n    }\n\n    friend ostream& operator<<(ostream& s, Graph\
    \ G) {\n        s << endl;\n        for (int i = 0; i < G.size(); i++) {\n   \
    \         s << i << \": \";\n            for (Edge<FLOWTYPE> j : G.list[i]) {\n\
    \                s << j;\n            }\n            s << endl;\n        }\n \
    \       return s;\n    }\n};\n\ntemplate <class FLOWTYPE>\nstruct FordFulkerson\
    \ {\n    const FLOWTYPE INF = 1 << 30;\n    vector<int> used;\n\n    FordFulkerson()\
    \ {}\n    FLOWTYPE fodfs(Graph<FLOWTYPE>& G, int v, int t, FLOWTYPE f) {\n   \
    \     if (v == t) return f;\n        used[v] = true;\n        for (auto& e : G[v])\
    \ {\n            if (!used[e.to] && e.cap > 0) {\n                int d = fodfs(G,\
    \ e.to, t, min(f, e.cap));\n                if (d > 0) {\n                   \
    \ e.cap -= d;\n                    G.redge(e).cap += d;\n                    return\
    \ d;\n                }\n            }\n        }\n        return 0;\n    }\n\
    \    FLOWTYPE solve(Graph<FLOWTYPE>& G, int s, int t) {\n        FLOWTYPE res\
    \ = 0;\n        while (true) {\n            used.assign((int)G.size(), 0);\n \
    \           int flow = fodfs(G, s, t, INF);\n            if (flow == 0)\n    \
    \            return res;\n            else\n                res += flow;\n   \
    \     }\n        return 0;\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: graph/flow/ford-fullkerson.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL_6_A.test.cpp
  - test/AOJ/GRL_7_A.test.cpp
documentation_of: graph/flow/ford-fullkerson.hpp
layout: document
title: "Ford Fullkerson (\u6700\u5927\u6D41)"
---
