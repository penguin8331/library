---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/eratostenes.hpp
    title: data-structure/eratostenes.hpp
  - icon: ':question:'
    path: template/template.hpp
    title: template/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
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
    \ MOD = 1e9 + 7;\n#line 1 \"data-structure/eratostenes.hpp\"\nstruct Eratos {\n\
    \    vector<int> primes;\n    vector<bool> isprime;\n    vector<int> mebius;\n\
    \    vector<int> min_factor;\n\n    Eratos(int MAX) : primes(),\n            \
    \          isprime(MAX + 1, true),\n                      mebius(MAX + 1, 1),\n\
    \                      min_factor(MAX + 1, -1) {\n        isprime[0] = isprime[1]\
    \ = false;\n        min_factor[0] = 0, min_factor[1] = 1;\n        for (int i\
    \ = 2; i <= MAX; ++i) {\n            if (!isprime[i]) continue;\n            primes.push_back(i);\n\
    \            mebius[i] = -1;\n            min_factor[i] = i;\n            for\
    \ (int j = i * 2; j <= MAX; j += i) {\n                isprime[j] = false;\n \
    \               if ((j / i) % i == 0)\n                    mebius[j] = 0;\n  \
    \              else\n                    mebius[j] = -mebius[j];\n           \
    \     if (min_factor[j] == -1) min_factor[j] = i;\n            }\n        }\n\
    \    }\n\n    // \u7D20\u56E0\u6570\u5206\u89E3\n    vector<pair<int, int>> prime_factors(int\
    \ n) {\n        vector<pair<int, int>> res;\n        while (n != 1) {\n      \
    \      int prime = min_factor[n];\n            int exp = 0;\n            while\
    \ (min_factor[n] == prime) {\n                ++exp;\n                n /= prime;\n\
    \            }\n            res.push_back(make_pair(prime, exp));\n        }\n\
    \        return res;\n    }\n\n    // \u7D04\u6570\u5217\u6319\n    vector<int>\
    \ divisors(int n) {\n        vector<int> res({1});\n        auto pf = prime_factors(n);\n\
    \        for (auto p : pf) {\n            int siz = (int)res.size();\n       \
    \     for (int i = 0; i < siz; ++i) {\n                int v = 1;\n          \
    \      for (int j = 0; j < p.second; ++j) {\n                    v *= p.first;\n\
    \                    res.push_back(res[i] * v);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n\n    // \u7D04\u6570\u500B\u6570\
    \n    int divisors_num(int n) {\n        int res = 1;\n        auto pf = prime_factors(n);\n\
    \        for (auto p : pf) {\n            res *= p.second + 1;\n        }\n  \
    \      return res;\n    }\n};\nstruct IsPrime {\n    vector<bool> isprime;\n\n\
    \    IsPrime(int MAX) : isprime(MAX + 1, true) {\n        isprime[0] = isprime[1]\
    \ = false;\n        for (int i = 2; i <= MAX; ++i) {\n            if (!isprime[i])\
    \ continue;\n            for (int j = i * 2; j <= MAX; j += i) {\n           \
    \     isprime[j] = false;\n            }\n        }\n    }\n};\n#line 4 \"test/AOJ/ALDS1_1_C.test.cpp\"\
    \n\nint main() {\n    IsPrime era(100000000);\n    int N;\n    cin >> N;\n   \
    \ int ans = 0;\n    for (int i = 0; i < N; i++) {\n        int a;\n        cin\
    \ >> a;\n        ans += era.isprime(a);\n    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include \"template/template.hpp\"\n#include \"data-structure/eratostenes.hpp\"\
    \n\nint main() {\n    IsPrime era(100000000);\n    int N;\n    cin >> N;\n   \
    \ int ans = 0;\n    for (int i = 0; i < N; i++) {\n        int a;\n        cin\
    \ >> a;\n        ans += era.isprime(a);\n    }\n    cout << ans << endl;\n}"
  dependsOn:
  - template/template.hpp
  - data-structure/eratostenes.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2022-12-20 21:47:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_1_C.test.cpp
- /verify/test/AOJ/ALDS1_1_C.test.cpp.html
title: test/AOJ/ALDS1_1_C.test.cpp
---
