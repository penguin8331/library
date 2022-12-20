---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/Binary Indexed Tree.hpp
    title: DataStructure/Binary Indexed Tree.hpp
  - icon: ':heavy_check_mark:'
    path: DataStructure/Inversion Number.hpp
    title: DataStructure/Inversion Number.hpp
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
    \ MOD = 1e9 + 7;\n#line 1 \"DataStructure/Binary Indexed Tree.hpp\"\ntemplate\
    \ <class Abel>\nstruct BIT {\n    Abel UNITY_SUM = 0;\n    vector<Abel> dat;\n\
    \n    // [0, n)\n    BIT(int n, Abel unity = 0) : UNITY_SUM(unity), dat(n, unity)\
    \ {}\n    void init(int n) {\n        dat.assign(n, UNITY_SUM);\n    }\n\n   \
    \ // a is 0-indexed\n    inline void add(int a, Abel x) {\n        for (int i\
    \ = a; i < (int)dat.size(); i |= i + 1)\n            dat[i] = dat[i] + x;\n  \
    \  }\n\n    // [0, a), a is 0-indexed\n    inline Abel sum(int a) {\n        Abel\
    \ res = UNITY_SUM;\n        for (int i = a - 1; i >= 0; i = (i & (i + 1)) - 1)\n\
    \            res = res + dat[i];\n        return res;\n    }\n\n    // [a, b),\
    \ a and b are 0-indexed\n    inline Abel sum(int a, int b) {\n        return sum(b)\
    \ - sum(a);\n    }\n\n    // debug\n    void print() {\n#ifdef LOCAL\n       \
    \ for (int i = 0; i < (int)dat.size(); ++i)\n            cout << sum(i, i + 1)\
    \ << \",\";\n        cout << endl;\n#endif\n    }\n};\n#line 2 \"DataStructure/Inversion\
    \ Number.hpp\"\n\ntemplate <class T>\nlong long inversion_number(const vector<T>\
    \ &a) {\n    int n = (int)a.size();\n    vector<T> b = a;\n    sort(b.begin(),\
    \ b.end());\n    b.erase(unique(b.begin(), b.end()), b.end());\n\n    long long\
    \ res = 0;\n    BIT<int> bit(n + 1);\n    for (int i = 0; i < n; ++i) {\n    \
    \    int order = lower_bound(b.begin(), b.end(), a[i]) - b.begin();\n        ++order;\n\
    \        res += bit.sum(order + 1, n + 1);\n        bit.add(order, 1);\n    }\n\
    \    return res;\n}\n#line 4 \"test/AOJ/ALDS1_5_D.test.cpp\"\n\nint main() {\n\
    \    int N;\n    cin >> N;\n    vector<int> A(N);\n    for (int i = 0; i < N;\
    \ i++) {\n        cin >> A[i];\n    }\n    cout << inversion_number(A) << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include \"template/template.hpp\"\n#include \"DataStructure/Inversion Number.hpp\"\
    \n\nint main() {\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n    }\n    cout << inversion_number(A)\
    \ << endl;\n}"
  dependsOn:
  - template/template.hpp
  - DataStructure/Inversion Number.hpp
  - DataStructure/Binary Indexed Tree.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2022-12-20 15:19:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_5_D.test.cpp
- /verify/test/AOJ/ALDS1_5_D.test.cpp.html
title: test/AOJ/ALDS1_5_D.test.cpp
---
