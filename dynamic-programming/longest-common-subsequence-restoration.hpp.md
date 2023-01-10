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
  bundledCode: "#line 1 \"dynamic-programming/longest-common-subsequence-restoration.hpp\"\
    \nstring LCSRestoration(const string& a, const string& b) {\n    const int n =\
    \ a.size(), m = b.size();\n    vector<vector<int> > X(n + 1, vector<int>(m + 1));\n\
    \    vector<vector<int> > Y(n + 1, vector<int>(m + 1));\n    for (int i = 0; i\
    \ < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n            if (a[i] ==\
    \ b[j]) {\n                X[i + 1][j + 1] = X[i][j] + 1;\n                Y[i\
    \ + 1][j + 1] = 0;\n            } else if (X[i + 1][j] < X[i][j + 1]) {\n    \
    \            X[i + 1][j + 1] = X[i][j + 1];\n                Y[i + 1][j + 1] =\
    \ 1;\n            } else {\n                X[i + 1][j + 1] = X[i + 1][j];\n \
    \               Y[i + 1][j + 1] = -1;\n            }\n        }\n    }\n    string\
    \ c;\n    for (int i = n, j = m; i > 0 && j > 0;) {\n        if (Y[i][j] > 0)\n\
    \            --i;\n        else if (Y[i][j] < 0)\n            --j;\n        else\
    \ {\n            c.push_back(a[i - 1]);\n            --i;\n            --j;\n\
    \        }\n    }\n    reverse(c.begin(), c.end());\n    return c;\n}\n"
  code: "string LCSRestoration(const string& a, const string& b) {\n    const int\
    \ n = a.size(), m = b.size();\n    vector<vector<int> > X(n + 1, vector<int>(m\
    \ + 1));\n    vector<vector<int> > Y(n + 1, vector<int>(m + 1));\n    for (int\
    \ i = 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n            if\
    \ (a[i] == b[j]) {\n                X[i + 1][j + 1] = X[i][j] + 1;\n         \
    \       Y[i + 1][j + 1] = 0;\n            } else if (X[i + 1][j] < X[i][j + 1])\
    \ {\n                X[i + 1][j + 1] = X[i][j + 1];\n                Y[i + 1][j\
    \ + 1] = 1;\n            } else {\n                X[i + 1][j + 1] = X[i + 1][j];\n\
    \                Y[i + 1][j + 1] = -1;\n            }\n        }\n    }\n    string\
    \ c;\n    for (int i = n, j = m; i > 0 && j > 0;) {\n        if (Y[i][j] > 0)\n\
    \            --i;\n        else if (Y[i][j] < 0)\n            --j;\n        else\
    \ {\n            c.push_back(a[i - 1]);\n            --i;\n            --j;\n\
    \        }\n    }\n    reverse(c.begin(), c.end());\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dynamic-programming/longest-common-subsequence-restoration.hpp
  requiredBy: []
  timestamp: '2022-12-21 12:17:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dynamic-programming/longest-common-subsequence-restoration.hpp
layout: document
title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u6587\u5B57\u5217 (\u5FA9\u5143\u3042\
  \u308A)"
---
