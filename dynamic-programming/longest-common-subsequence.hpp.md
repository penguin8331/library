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
  bundledCode: "#line 1 \"dynamic-programming/longest-common-subsequence.hpp\"\nint\
    \ LCS(const string& a, const string& b) {\n    const int n = a.size(), m = b.size();\n\
    \    vector<vector<int> > X(n + 1, vector<int>(m + 1));\n    for (int i = 0; i\
    \ < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n            if (a[i] ==\
    \ b[j]) {\n                X[i + 1][j + 1] = X[i][j] + 1;\n            } else\
    \ if (X[i + 1][j] < X[i][j + 1]) {\n                X[i + 1][j + 1] = X[i][j +\
    \ 1];\n            } else {\n                X[i + 1][j + 1] = X[i + 1][j];\n\
    \            }\n        }\n    }\n    return X[n][m];\n}\n"
  code: "int LCS(const string& a, const string& b) {\n    const int n = a.size(),\
    \ m = b.size();\n    vector<vector<int> > X(n + 1, vector<int>(m + 1));\n    for\
    \ (int i = 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n         \
    \   if (a[i] == b[j]) {\n                X[i + 1][j + 1] = X[i][j] + 1;\n    \
    \        } else if (X[i + 1][j] < X[i][j + 1]) {\n                X[i + 1][j +\
    \ 1] = X[i][j + 1];\n            } else {\n                X[i + 1][j + 1] = X[i\
    \ + 1][j];\n            }\n        }\n    }\n    return X[n][m];\n}"
  dependsOn: []
  isVerificationFile: false
  path: dynamic-programming/longest-common-subsequence.hpp
  requiredBy: []
  timestamp: '2022-12-21 12:17:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dynamic-programming/longest-common-subsequence.hpp
layout: document
redirect_from:
- /library/dynamic-programming/longest-common-subsequence.hpp
- /library/dynamic-programming/longest-common-subsequence.hpp.html
title: dynamic-programming/longest-common-subsequence.hpp
---
