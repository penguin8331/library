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
    path: test/yosupo/binomial-cofficient-prime-mod.test.cpp
    title: test/yosupo/binomial-cofficient-prime-mod.test.cpp
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\nvector<int> MODS;\n\
    template <int IND = 0>\nstruct Fp {\n    long long val;\n    constexpr Fp(long\
    \ long v = 0) noexcept : val(v % MODS[IND]) {\n        if (val < 0) val += MODS[IND];\n\
    \    }\n    constexpr int getmod() const { return MODS[IND]; }\n    constexpr\
    \ Fp operator-() const noexcept {\n        return val ? MODS[IND] - val : 0;\n\
    \    }\n    constexpr Fp operator+(const Fp& r) const noexcept { return Fp(*this)\
    \ += r; }\n    constexpr Fp operator-(const Fp& r) const noexcept { return Fp(*this)\
    \ -= r; }\n    constexpr Fp operator*(const Fp& r) const noexcept { return Fp(*this)\
    \ *= r; }\n    constexpr Fp operator/(const Fp& r) const noexcept { return Fp(*this)\
    \ /= r; }\n    constexpr Fp& operator+=(const Fp& r) noexcept {\n        val +=\
    \ r.val;\n        if (val >= MODS[IND]) val -= MODS[IND];\n        return *this;\n\
    \    }\n    constexpr Fp& operator-=(const Fp& r) noexcept {\n        val -= r.val;\n\
    \        if (val < 0) val += MODS[IND];\n        return *this;\n    }\n    constexpr\
    \ Fp& operator*=(const Fp& r) noexcept {\n        val = val * r.val % MODS[IND];\n\
    \        return *this;\n    }\n    constexpr Fp& operator/=(const Fp& r) noexcept\
    \ {\n        long long a = r.val, b = MODS[IND], u = 1, v = 0;\n        while\
    \ (b) {\n            long long t = a / b;\n            a -= t * b;\n         \
    \   swap(a, b);\n            u -= t * v;\n            swap(u, v);\n        }\n\
    \        val = val * u % MODS[IND];\n        if (val < 0) val += MODS[IND];\n\
    \        return *this;\n    }\n    constexpr bool operator==(const Fp& r) const\
    \ noexcept {\n        return this->val == r.val;\n    }\n    constexpr bool operator!=(const\
    \ Fp& r) const noexcept {\n        return this->val != r.val;\n    }\n    friend\
    \ constexpr istream& operator>>(istream& is, Fp<IND>& x) noexcept {\n        is\
    \ >> x.val;\n        x.val %= MODS[IND];\n        if (x.val < 0) x.val += MODS[IND];\n\
    \        return is;\n    }\n    friend constexpr ostream& operator<<(ostream&\
    \ os, const Fp<IND>& x) noexcept {\n        return os << x.val;\n    }\n    friend\
    \ constexpr Fp<IND> modpow(const Fp<IND>& r, long long n) noexcept {\n       \
    \ if (n == 0) return 1;\n        if (n < 0) return modpow(modinv(r), -n);\n  \
    \      auto t = modpow(r, n / 2);\n        t = t * t;\n        if (n & 1) t =\
    \ t * r;\n        return t;\n    }\n    friend constexpr Fp<IND> modinv(const\
    \ Fp<IND>& r) noexcept {\n        long long a = r.val, b = MODS[IND], u = 1, v\
    \ = 0;\n        while (b) {\n            long long t = a / b;\n            a -=\
    \ t * b, swap(a, b);\n            u -= t * v, swap(u, v);\n        }\n       \
    \ return Fp<IND>(u);\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: data-structure/dynamic_modular-arithmetic.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/binomial-cofficient-prime-mod.test.cpp
documentation_of: data-structure/dynamic_modular-arithmetic.hpp
layout: document
title: Dynamic-ModInt
---
