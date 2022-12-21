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
  bundledCode: "#line 1 \"algorithm/doubling.hpp\"\nstruct doubling {\n    vector<int>\
    \ A;\n    vector<vector<int>> table;\n    int SIZE;\n    int logK = 1;\n    doubling(vector<int>\
    \ a, int max) : A(a) {\n        SIZE = A.size();\n        while ((1LL << logK)\
    \ <= max) logK++;\n        table.assign(logK, vector<int>(SIZE));\n        for\
    \ (int k = 0; k < logK - 1; k++) {\n            for (int i = 0; i < SIZE; i++)\
    \ {\n                table[k + 1][i] = table[k][table[k][i]];\n            }\n\
    \        }\n    }\n    int get(int a, int b) {\n        int now = a;\n       \
    \ for (int k = 0; b > 0; k++) {\n            if (b & 1) now = table[k][now];\n\
    \            b = b >> 1;\n        }\n        return now;\n    }\n};\n"
  code: "struct doubling {\n    vector<int> A;\n    vector<vector<int>> table;\n \
    \   int SIZE;\n    int logK = 1;\n    doubling(vector<int> a, int max) : A(a)\
    \ {\n        SIZE = A.size();\n        while ((1LL << logK) <= max) logK++;\n\
    \        table.assign(logK, vector<int>(SIZE));\n        for (int k = 0; k < logK\
    \ - 1; k++) {\n            for (int i = 0; i < SIZE; i++) {\n                table[k\
    \ + 1][i] = table[k][table[k][i]];\n            }\n        }\n    }\n    int get(int\
    \ a, int b) {\n        int now = a;\n        for (int k = 0; b > 0; k++) {\n \
    \           if (b & 1) now = table[k][now];\n            b = b >> 1;\n       \
    \ }\n        return now;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/doubling.hpp
  requiredBy: []
  timestamp: '2022-12-21 12:17:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/doubling.hpp
layout: document
title: "\u30C0\u30D6\u30EA\u30F3\u30B0"
---
