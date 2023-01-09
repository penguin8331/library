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
  bundledCode: "#line 1 \"data-structure/disjointsparsetable.hpp\"\ntemplate <class\
    \ SemiGroup>\nstruct DisjointSparseTable {\n    using Func = function<SemiGroup(SemiGroup,\
    \ SemiGroup)>;\n    const Func F;\n    vector<vector<SemiGroup>> dat;\n    vector<int>\
    \ height;\n\n    DisjointSparseTable(const Func& f) : F(f) {}\n    DisjointSparseTable(const\
    \ Func& f, const vector<SemiGroup>& vec) : F(f) { init(vec); }\n    void init(const\
    \ vector<SemiGroup>& vec) {\n        int n = (int)vec.size(), h = 1;\n       \
    \ while ((1 << h) <= n) ++h;\n        dat.assign(h, vector<SemiGroup>(n));\n \
    \       height.assign((1 << h), 0);\n        for (int i = 2; i < (1 << h); i++)\
    \ height[i] = height[i >> 1] + 1;\n        for (int i = 0; i < n; ++i) dat[0][i]\
    \ = vec[i];\n        for (int i = 1; i < h; ++i) {\n            int s = (1 <<\
    \ i);\n            for (int j = 0; j < n; j += (s << 1)) {\n                int\
    \ t = min(j + s, n);\n                dat[i][t - 1] = vec[t - 1];\n          \
    \      for (int k = t - 2; k >= j; --k) dat[i][k] = F(vec[k], dat[i][k + 1]);\n\
    \                if (n <= t) break;\n                dat[i][t] = vec[t];\n   \
    \             for (int k = t + 1; k < min(t + s, n); ++k) dat[i][k] = F(dat[i][k\
    \ - 1], vec[k]);\n            }\n        }\n    }\n    SemiGroup get(int a, int\
    \ b) {\n        if (a >= --b) return dat[0][a];\n        return F(dat[height[a\
    \ ^ b]][a], dat[height[a ^ b]][b]);\n    }\n};\n"
  code: "template <class SemiGroup>\nstruct DisjointSparseTable {\n    using Func\
    \ = function<SemiGroup(SemiGroup, SemiGroup)>;\n    const Func F;\n    vector<vector<SemiGroup>>\
    \ dat;\n    vector<int> height;\n\n    DisjointSparseTable(const Func& f) : F(f)\
    \ {}\n    DisjointSparseTable(const Func& f, const vector<SemiGroup>& vec) : F(f)\
    \ { init(vec); }\n    void init(const vector<SemiGroup>& vec) {\n        int n\
    \ = (int)vec.size(), h = 1;\n        while ((1 << h) <= n) ++h;\n        dat.assign(h,\
    \ vector<SemiGroup>(n));\n        height.assign((1 << h), 0);\n        for (int\
    \ i = 2; i < (1 << h); i++) height[i] = height[i >> 1] + 1;\n        for (int\
    \ i = 0; i < n; ++i) dat[0][i] = vec[i];\n        for (int i = 1; i < h; ++i)\
    \ {\n            int s = (1 << i);\n            for (int j = 0; j < n; j += (s\
    \ << 1)) {\n                int t = min(j + s, n);\n                dat[i][t -\
    \ 1] = vec[t - 1];\n                for (int k = t - 2; k >= j; --k) dat[i][k]\
    \ = F(vec[k], dat[i][k + 1]);\n                if (n <= t) break;\n          \
    \      dat[i][t] = vec[t];\n                for (int k = t + 1; k < min(t + s,\
    \ n); ++k) dat[i][k] = F(dat[i][k - 1], vec[k]);\n            }\n        }\n \
    \   }\n    SemiGroup get(int a, int b) {\n        if (a >= --b) return dat[0][a];\n\
    \        return F(dat[height[a ^ b]][a], dat[height[a ^ b]][b]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/disjointsparsetable.hpp
  requiredBy: []
  timestamp: '2023-01-09 20:19:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/disjointsparsetable.hpp
layout: document
redirect_from:
- /library/data-structure/disjointsparsetable.hpp
- /library/data-structure/disjointsparsetable.hpp.html
title: data-structure/disjointsparsetable.hpp
---
