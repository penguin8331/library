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
  bundledCode: "#line 1 \"String/RLE.hpp\"\nvector<pair<char, int>> rle(string s)\
    \ {\n    vector<pair<char, int>> ret;\n    int cnt = 1;\n    for (int i = 1; i\
    \ < (int)s.size(); i++) {\n        if (s[i] != s[i - 1]) {\n            ret.push_back({s[i\
    \ - 1], cnt});\n            cnt = 0;\n        }\n        cnt++;\n    }\n    ret.push_back({s.back(),\
    \ cnt});\n    return ret;\n}\n"
  code: "vector<pair<char, int>> rle(string s) {\n    vector<pair<char, int>> ret;\n\
    \    int cnt = 1;\n    for (int i = 1; i < (int)s.size(); i++) {\n        if (s[i]\
    \ != s[i - 1]) {\n            ret.push_back({s[i - 1], cnt});\n            cnt\
    \ = 0;\n        }\n        cnt++;\n    }\n    ret.push_back({s.back(), cnt});\n\
    \    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: String/RLE.hpp
  requiredBy: []
  timestamp: '2022-12-20 16:26:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/RLE.hpp
layout: document
redirect_from:
- /library/String/RLE.hpp
- /library/String/RLE.hpp.html
title: String/RLE.hpp
---
