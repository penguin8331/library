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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../template/template.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\n// edge class (for\
    \ network-flow)\ntemplate <class FLOWTYPE>\nstruct Edge {\n    int rev, from,\
    \ to;\n    FLOWTYPE cap, icap;\n    Edge(int r, int f, int t, FLOWTYPE c) : rev(r),\
    \ from(f), to(t), cap(c), icap(c) {}\n    friend ostream& operator<<(ostream&\
    \ s, Edge E) {\n        if (E.cap > 0)\n            return s << E.from << \"->\"\
    \ << E.to << '(' << E.cap << ')' << \" \";\n        else\n            return s;\n\
    \    }\n};\n\n// graph class (for network-flow)\ntemplate <class FLOWTYPE>\nstruct\
    \ Graph {\n    vector<vector<Edge<FLOWTYPE> > > list;\n\n    Graph(int n = 0)\
    \ : list(n) {}\n    void init(int n = 0) {\n        list.clear();\n        list.resize(n);\n\
    \    }\n    void reset() {\n        for (int i = 0; i < (int)list.size(); ++i)\n\
    \            for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap;\n\
    \    }\n    inline vector<Edge<FLOWTYPE> >& operator[](int i) { return list[i];\
    \ }\n    inline const size_t size() const { return list.size(); }\n\n    inline\
    \ Edge<FLOWTYPE>& redge(Edge<FLOWTYPE> e) {\n        if (e.from != e.to)\n   \
    \         return list[e.to][e.rev];\n        else\n            return list[e.to][e.rev\
    \ + 1];\n    }\n\n    void addedge(int from, int to, FLOWTYPE cap) {\n       \
    \ list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));\n\
    \        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from,\
    \ 0));\n    }\n\n    void add_undirected_edge(int from, int to, FLOWTYPE cap)\
    \ {\n        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to,\
    \ cap));\n        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1,\
    \ to, from, cap));\n    }\n\n    // debug\n    friend ostream& operator<<(ostream&\
    \ s, Graph G) {\n        s << endl;\n        for (int i = 0; i < G.size(); i++)\
    \ {\n            s << i << \": \";\n            for (Edge<FLOWTYPE> j : G.list[i])\
    \ {\n                s << j;\n            }\n            s << endl;\n        }\n\
    \        return s;\n    }\n};\n\ntemplate <class FLOWTYPE>\nstruct FordFulkerson\
    \ {\n    const FLOWTYPE INF = 1 << 30;  // to be set\n    vector<int> used;\n\n\
    \    FordFulkerson() {}\n    FLOWTYPE fodfs(Graph<FLOWTYPE>& G, int v, int t,\
    \ FLOWTYPE f) {\n        if (v == t) return f;\n        used[v] = true;\n    \
    \    for (auto& e : G[v]) {\n            if (!used[e.to] && e.cap > 0) {\n   \
    \             int d = fodfs(G, e.to, t, min(f, e.cap));\n                if (d\
    \ > 0) {\n                    e.cap -= d;\n                    G.redge(e).cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    FLOWTYPE solve(Graph<FLOWTYPE>& G, int\
    \ s, int t) {\n        FLOWTYPE res = 0;\n        while (true) {\n           \
    \ used.assign((int)G.size(), 0);\n            int flow = fodfs(G, s, t, INF);\n\
    \            if (flow == 0)\n                return res;\n            else\n \
    \               res += flow;\n        }\n        return 0;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/ford-fullkerson.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/flow/ford-fullkerson.hpp
layout: document
redirect_from:
- /library/graph/flow/ford-fullkerson.hpp
- /library/graph/flow/ford-fullkerson.hpp.html
title: graph/flow/ford-fullkerson.hpp
---
