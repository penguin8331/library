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
    path: test/yosupo/matrix-det.test.cpp
    title: test/yosupo/matrix-det.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define all(x) std::begin(x), std::end(x)\n#define\
    \ rall(x) std::rbegin(x), std::rend(x)\n#define elif else if\n#define updiv(N,\
    \ X) (((N) + (X) - (1)) / (X))\n#define sigma(a, b) ((a + b) * (b - a + 1) / 2)\n\
    #define INT(...)     \\\n    int __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define\
    \ LL(...)     \\\n    ll __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define STR(...)\
    \        \\\n    string __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define CHR(...)\
    \      \\\n    char __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define DOU(...) \
    \       \\\n    double __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define LD(...)\
    \     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n#define pb push_back\n\
    #define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\nusing ll = long long;\n\
    using ld = long double;\nusing pii = std::pair<int, int>;\nusing pll = std::pair<ll,\
    \ ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF = 1LL << 60;\nconstexpr\
    \ int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr int dy[8] = {0, 1, 0, -1,\
    \ 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr int MOD = 1e9 + 7;\n\
    #line 3 \"template/func.hpp\"\n\ntemplate <typename T>\ninline bool chmax(T& a,\
    \ T b) { return ((a < b) ? (a = b, true) : (false)); }\ntemplate <typename T>\n\
    inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n    return\
    \ os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
    \ &is, std::pair<T, U> &p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::vector<T>\
    \ &v) {\n    for (auto it = std::begin(v); it != std::end(v);) {\n        os <<\
    \ *it << ((++it) != std::end(v) ? \" \" : \"\");\n    }\n    return os;\n}\ntemplate\
    \ <typename T>\nstd::istream &operator>>(std::istream &is, std::vector<T> &v)\
    \ {\n    for (T &in : v) {\n        is >> in;\n    }\n    return is;\n}\ninline\
    \ void scan() {}\ntemplate <class Head, class... Tail>\ninline void scan(Head\
    \ &head, Tail &...tail) {\n    std::cin >> head;\n    scan(tail...);\n}\ntemplate\
    \ <class T>\ninline void print(const T &t) { std::cout << t << '\\n'; }\ntemplate\
    \ <class Head, class... Tail>\ninline void print(const Head &head, const Tail\
    \ &...tail) {\n    std::cout << head << ' ';\n    print(tail...);\n}\ntemplate\
    \ <class... T>\ninline void fin(const T &...a) {\n    print(a...);\n    exit(0);\n\
    }\n#line 3 \"template/util.hpp\"\n\nstruct IOSetup {\n    IOSetup() {\n      \
    \  std::cin.tie(nullptr);\n        std::ios::sync_with_stdio(false);\n       \
    \ std::cout.tie(0);\n        std::cout << std::fixed << std::setprecision(12);\n\
    \        std::cerr << std::fixed << std::setprecision(12);\n    }\n} IOSetup;\n\
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug_print.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"math/algebra/matrix.hpp\"\n\ntemplate <class T>\nstruct Matrix\
    \ {\n    vector<vector<T>> val;\n    size_t height, width;\n\n    Matrix(int n\
    \ = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)), height(n), width(m) {}\n\
    \    void init(int n, int m, T v = 0) {\n        val.assign(n, vector<T>(m, v));\n\
    \        height = n;\n        width = m;\n    }\n    void resize(int n, int m)\
    \ {\n        val.resize(n);\n        for (int i = 0; i < n; ++i) val[i].resize(m);\n\
    \        height = n;\n        width = m;\n    }\n    vector<T> &operator[](int\
    \ i) { return val[i]; }\n    const vector<T> &operator[](int i) const { return\
    \ val[i]; }\n    Matrix &operator=(const Matrix &A) {\n        val = A.val;\n\
    \        return *this;\n    }\n    Matrix &operator+=(const Matrix &r) {\n   \
    \     for (int i = 0; i < height; ++i)\n            for (int j = 0; j < width;\
    \ ++j)\n                (*this)[i][j] += r[i][j];\n        return (*this);\n \
    \   }\n    Matrix &operator-=(const Matrix &r) {\n        for (int i = 0; i <\
    \ height; ++i)\n            for (int j = 0; j < width; ++j)\n                (*this)[i][j]\
    \ -= r[i][j];\n        return (*this);\n    }\n    Matrix &operator*=(const Matrix\
    \ &r) {\n        vector<vector<T>> res(height, vector<T>(r.width));\n        for\
    \ (int i = 0; i < height; ++i)\n            for (int j = 0; j < r.width; ++j)\n\
    \                for (int k = 0; k < width; ++k)\n                    res[i][j]\
    \ += (*this)[i][k] * r[k][j];\n        val.swap(res);\n        return (*this);\n\
    \    }\n    Matrix operator+(const Matrix &r) { return Matrix(*this) += r; }\n\
    \    Matrix operator-(const Matrix &r) { return Matrix(*this) -= r; }\n    Matrix\
    \ operator*(const Matrix &r) { return Matrix(*this) *= r; }\n    friend Matrix<T>\
    \ pow(const Matrix<T> &A, long long n) {\n        Matrix<T> R(A.height, A.height);\n\
    \        Matrix<T> B = A;\n        for (int i = 0; i < A.height; ++i) R[i][i]\
    \ = 1;\n        while (n > 0) {\n            if (n & 1) R = R * B;\n         \
    \   B = B * B;\n            n >>= 1;\n        }\n        return R;\n    }\n  \
    \  friend T det(Matrix<T> A) {\n        T ret = 1;\n        for (int i = 0; i\
    \ < A.width; i++) {\n            int idx = -1;\n            for (int j = i; j\
    \ < A.width; j++) {\n                if (A[j][i] != 0) {\n                   \
    \ idx = j;\n                    break;\n                }\n            }\n   \
    \         if (idx == -1) return T(0);\n            if (i != idx) {\n         \
    \       ret *= T(-1);\n                swap(A[i], A[idx]);\n            }\n  \
    \          ret *= A[i][i];\n            T tmp = A[i][i];\n            for (int\
    \ j = 0; j < A.width; j++) A[i][j] /= tmp;\n            for (int j = i + 1; j\
    \ < A.width; j++) {\n                T now = A[j][i];\n                for (int\
    \ k = 0; k < A.width; k++) A[j][k] -= A[i][k] * now;\n            }\n        }\n\
    \        return ret;\n    }\n};\n"
  code: "#pragma once\n#include \"../../template/template.hpp\"\n\ntemplate <class\
    \ T>\nstruct Matrix {\n    vector<vector<T>> val;\n    size_t height, width;\n\
    \n    Matrix(int n = 1, int m = 1, T v = 0) : val(n, vector<T>(m, v)), height(n),\
    \ width(m) {}\n    void init(int n, int m, T v = 0) {\n        val.assign(n, vector<T>(m,\
    \ v));\n        height = n;\n        width = m;\n    }\n    void resize(int n,\
    \ int m) {\n        val.resize(n);\n        for (int i = 0; i < n; ++i) val[i].resize(m);\n\
    \        height = n;\n        width = m;\n    }\n    vector<T> &operator[](int\
    \ i) { return val[i]; }\n    const vector<T> &operator[](int i) const { return\
    \ val[i]; }\n    Matrix &operator=(const Matrix &A) {\n        val = A.val;\n\
    \        return *this;\n    }\n    Matrix &operator+=(const Matrix &r) {\n   \
    \     for (int i = 0; i < height; ++i)\n            for (int j = 0; j < width;\
    \ ++j)\n                (*this)[i][j] += r[i][j];\n        return (*this);\n \
    \   }\n    Matrix &operator-=(const Matrix &r) {\n        for (int i = 0; i <\
    \ height; ++i)\n            for (int j = 0; j < width; ++j)\n                (*this)[i][j]\
    \ -= r[i][j];\n        return (*this);\n    }\n    Matrix &operator*=(const Matrix\
    \ &r) {\n        vector<vector<T>> res(height, vector<T>(r.width));\n        for\
    \ (int i = 0; i < height; ++i)\n            for (int j = 0; j < r.width; ++j)\n\
    \                for (int k = 0; k < width; ++k)\n                    res[i][j]\
    \ += (*this)[i][k] * r[k][j];\n        val.swap(res);\n        return (*this);\n\
    \    }\n    Matrix operator+(const Matrix &r) { return Matrix(*this) += r; }\n\
    \    Matrix operator-(const Matrix &r) { return Matrix(*this) -= r; }\n    Matrix\
    \ operator*(const Matrix &r) { return Matrix(*this) *= r; }\n    friend Matrix<T>\
    \ pow(const Matrix<T> &A, long long n) {\n        Matrix<T> R(A.height, A.height);\n\
    \        Matrix<T> B = A;\n        for (int i = 0; i < A.height; ++i) R[i][i]\
    \ = 1;\n        while (n > 0) {\n            if (n & 1) R = R * B;\n         \
    \   B = B * B;\n            n >>= 1;\n        }\n        return R;\n    }\n  \
    \  friend T det(Matrix<T> A) {\n        T ret = 1;\n        for (int i = 0; i\
    \ < A.width; i++) {\n            int idx = -1;\n            for (int j = i; j\
    \ < A.width; j++) {\n                if (A[j][i] != 0) {\n                   \
    \ idx = j;\n                    break;\n                }\n            }\n   \
    \         if (idx == -1) return T(0);\n            if (i != idx) {\n         \
    \       ret *= T(-1);\n                swap(A[i], A[idx]);\n            }\n  \
    \          ret *= A[i][i];\n            T tmp = A[i][i];\n            for (int\
    \ j = 0; j < A.width; j++) A[i][j] /= tmp;\n            for (int j = i + 1; j\
    \ < A.width; j++) {\n                T now = A[j][i];\n                for (int\
    \ k = 0; k < A.width; k++) A[j][k] -= A[i][k] * now;\n            }\n        }\n\
    \        return ret;\n    }\n};\n"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: math/algebra/matrix.hpp
  requiredBy: []
  timestamp: '2023-04-21 23:32:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/matrix-det.test.cpp
documentation_of: math/algebra/matrix.hpp
layout: document
title: "Matrix (\u884C\u5217)"
---
