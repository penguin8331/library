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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ template/debug.hpp: line 5: unable to process #include in #if / #ifdef / #ifndef\
    \ other than include guards\n"
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
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/matrix-det.test.cpp
documentation_of: math/algebra/matrix.hpp
layout: document
title: "Matrix (\u884C\u5217)"
---
