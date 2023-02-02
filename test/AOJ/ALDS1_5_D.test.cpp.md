---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/binary-indexed-tree.hpp
    title: BIT
  - icon: ':heavy_check_mark:'
    path: math/combinatorics/inversion-number.hpp
    title: "\u8EE2\u5012\u6570"
  - icon: ':heavy_check_mark:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/AOJ/ALDS1_5_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#line 1 \"template/template.hpp\"\n// #pragma GCC target(\"avx2\")\n// #pragma\
    \ GCC optimize(\"O3\")\n// #pragma GCC optimize(\"unroll-loops\")\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing ld = long double;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n#define pb push_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define all(x) (x).begin(), (x).end()\n\
    #define rall(x) (x).rbegin(), (x).rend()\n#define elif else if\n#define updiv(N,\
    \ X) ((N + X - 1) / X)\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\nstruct\
    \ fast_ios {\n    fast_ios() {\n        cin.tie(nullptr);\n        ios::sync_with_stdio(false);\n\
    \        cout << fixed << setprecision(15);\n    };\n} fast_ios_;\ntemplate <typename\
    \ T>\ninline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false));\
    \ }\ntemplate <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a\
    \ = b, true) : (false)); }\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL\
    \ << 60;\nconstexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int\
    \ MOD = 1e9 + 7;\n#line 1 \"data-structure/binary-indexed-tree.hpp\"\ntemplate\
    \ <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat;\n\
    \n    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity)\
    \ {}\n    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\n   \
    \ // a is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int i\
    \ = a; i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n  \
    \  }\n\n    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n        Abel\
    \ res = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n\
    \            res = res + dat[i];\n        return res;\n    }\n\n    // [a, b),\
    \ a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n        return sum(b)\
    \ - sum(a);\n    }\n\n    friend ostream& operator<<(ostream& os, BIT bit) {\n\
    \        os << \"[ \";\n        for (int i = 0; i < (int)bit.dat.size(); i++)\
    \ {\n            os << bit.sum(i, i + 1) << \" \";\n        }\n        os << ']';\n\
    \        return os;\n    }\n};\n#line 2 \"math/combinatorics/inversion-number.hpp\"\
    \n\r\ntemplate <class T>\r\nlong long inversion_number(const vector<T> &a) {\r\
    \n    int n = (int)a.size();\r\n    vector<T> b = a;\r\n    sort(b.begin(), b.end());\r\
    \n    b.erase(unique(b.begin(), b.end()), b.end());\r\n\r\n    long long res =\
    \ 0;\r\n    BIT<int> bit(n + 1);\r\n    for (int i = 0; i < n; ++i) {\r\n    \
    \    int order = lower_bound(b.begin(), b.end(), a[i]) - b.begin();\r\n      \
    \  ++order;\r\n        res += bit.sum(order + 1, n + 1);\r\n        bit.add(order,\
    \ 1);\r\n    }\r\n    return res;\r\n}\r\n#line 4 \"test/AOJ/ALDS1_5_D.test.cpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    cout << inversion_number(A)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include \"template/template.hpp\"\n#include \"math/combinatorics/inversion-number.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    cout << inversion_number(A)\
    \ << endl;\n}"
  dependsOn:
  - template/template.hpp
  - math/combinatorics/inversion-number.hpp
  - data-structure/binary-indexed-tree.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2023-01-16 22:52:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_5_D.test.cpp
- /verify/test/AOJ/ALDS1_5_D.test.cpp.html
title: test/AOJ/ALDS1_5_D.test.cpp
---
