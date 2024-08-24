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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <class Str>\n\
    struct SuffixArray {\n    // data\n    Str str;\n    vector<int> sa;    // sa[i]\
    \ : the starting index of the i-th smallest suffix\n                       //\
    \ (i = 0, 1, ..., n)\n    vector<int> rank;  // rank[sa[i]] = i\n    vector<int>\n\
    \        lcp;  // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)\n\
    \    SparseTable<int> st;  // use for calcultating lcp(i, j)\n\n    // getter\n\
    \    int &operator[](int i) { return sa[i]; }\n    const int &operator[](int i)\
    \ const { return sa[i]; }\n    vector<int> get_sa() { return sa; }\n    vector<int>\
    \ get_rank() { return rank; }\n    vector<int> get_lcp() { return lcp; }\n\n \
    \   // constructor\n    SuffixArray() {}\n    SuffixArray(const Str &str_, bool\
    \ no_limit_elements = false) : str(str_) {\n        build_sa(no_limit_elements);\n\
    \    }\n    void init(const Str &str_, bool no_limit_elements = false) {\n   \
    \     str = str_;\n        build_sa(no_limit_elements);\n    }\n    void build_sa(bool\
    \ no_limit_elements = false) {\n        vector<int> s;\n        int num_of_chars\
    \ = 256;\n        if (!no_limit_elements) {\n            for (int i = 0; i < (int)str.size();\
    \ ++i) {\n                s.push_back(str[i] + 1);\n            }\n        } else\
    \ {\n            unordered_map<int, int> dict;\n            for (int i = 0; i\
    \ < (int)str.size(); ++i) {\n                if (!dict.count(str[i])) dict[str[i]]\
    \ = dict.size();\n            }\n            for (int i = 0; i < (int)str.size();\
    \ ++i) {\n                s.push_back(dict[str[i]] + 1);\n            }\n    \
    \        num_of_chars = (int)dict.size();\n        }\n        s.push_back(0);\n\
    \        sa = sa_is(s, num_of_chars);\n        build_lcp(s);\n        build_sparse_table();\n\
    \    }\n\n    // SA-IS\n    // num_of_chars: # of characters\n    vector<int>\
    \ sa_is(vector<int> &s, int num_of_chars) {\n        int N = (int)s.size();\n\
    \        if (N == 0)\n            return {};\n        else if (N == 1)\n     \
    \       return {0};\n        else if (N == 2) {\n            if (s[0] < s[1])\n\
    \                return {0, 1};\n            else\n                return {1,\
    \ 0};\n        }\n\n        vector<int> isa(N);\n        vector<bool> ls(N, false);\n\
    \        for (int i = N - 2; i >= 0; --i) {\n            ls[i] = (s[i] == s[i\
    \ + 1]) ? ls[i + 1] : (s[i] < s[i + 1]);\n        }\n        vector<int> sum_l(num_of_chars\
    \ + 1, 0), sum_s(num_of_chars + 1, 0);\n        for (int i = 0; i < N; ++i) {\n\
    \            if (!ls[i])\n                ++sum_s[s[i]];\n            else\n \
    \               ++sum_l[s[i] + 1];\n        }\n        for (int i = 0; i <= num_of_chars;\
    \ ++i) {\n            sum_s[i] += sum_l[i];\n            if (i < num_of_chars)\
    \ sum_l[i + 1] += sum_s[i];\n        }\n\n        auto induce = [&](const vector<int>\
    \ &lms) -> void {\n            fill(isa.begin(), isa.end(), -1);\n           \
    \ vector<int> buf(num_of_chars + 1);\n            copy(sum_s.begin(), sum_s.end(),\
    \ buf.begin());\n            for (auto d : lms) {\n                if (d == N)\
    \ continue;\n                isa[buf[s[d]]++] = d;\n            }\n          \
    \  copy(sum_l.begin(), sum_l.end(), buf.begin());\n            isa[buf[s[N - 1]]++]\
    \ = N - 1;\n            for (int i = 0; i < N; ++i) {\n                int v =\
    \ isa[i];\n                if (v >= 1 && !ls[v - 1]) {\n                    isa[buf[s[v\
    \ - 1]]++] = v - 1;\n                }\n            }\n            copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n            for (int i = N - 1; i >= 0; --i) {\n\
    \                int v = isa[i];\n                if (v >= 1 && ls[v - 1]) {\n\
    \                    isa[--buf[s[v - 1] + 1]] = v - 1;\n                }\n  \
    \          }\n        };\n\n        vector<int> lms, lms_map(N + 1, -1);\n   \
    \     int M = 0;\n        for (int i = 1; i < N; ++i) {\n            if (!ls[i\
    \ - 1] && ls[i]) {\n                lms_map[i] = M++;\n            }\n       \
    \ }\n        lms.reserve(M);\n        for (int i = 1; i < N; ++i) {\n        \
    \    if (!ls[i - 1] && ls[i]) {\n                lms.push_back(i);\n         \
    \   }\n        }\n        induce(lms);\n\n        if (M) {\n            vector<int>\
    \ lms2;\n            lms2.reserve(isa.size());\n            for (auto v : isa)\
    \ {\n                if (lms_map[v] != -1) lms2.push_back(v);\n            }\n\
    \            int rec_upper = 0;\n            vector<int> rec_s(M);\n         \
    \   rec_s[lms_map[lms2[0]]] = 0;\n            for (int i = 1; i < M; ++i) {\n\
    \                int l = lms2[i - 1], r = lms2[i];\n                int nl = (lms_map[l]\
    \ + 1 < M) ? lms[lms_map[l] + 1] : N;\n                int nr = (lms_map[r] +\
    \ 1 < M) ? lms[lms_map[r] + 1] : N;\n                bool same = true;\n     \
    \           if (nl - l != nr - r)\n                    same = false;\n       \
    \         else {\n                    while (l < nl) {\n                     \
    \   if (s[l] != s[r]) break;\n                        ++l, ++r;\n            \
    \        }\n                    if (l == N || s[l] != s[r]) same = false;\n  \
    \              }\n                if (!same) ++rec_upper;\n                rec_s[lms_map[lms2[i]]]\
    \ = rec_upper;\n            }\n            auto rec_sa = sa_is(rec_s, rec_upper);\n\
    \n            vector<int> sorted_lms(M);\n            for (int i = 0; i < M; ++i)\
    \ {\n                sorted_lms[i] = lms[rec_sa[i]];\n            }\n        \
    \    induce(sorted_lms);\n        }\n        return isa;\n    }\n\n    // find\
    \ min id that str.substr(sa[id]) >= T\n    int lower_bound(const Str &T) {\n \
    \       int left = -1, right = sa.size();\n        while (right - left > 1) {\n\
    \            int mid = (left + right) / 2;\n            if (str.compare(sa[mid],\
    \ string::npos, T) < 0)\n                left = mid;\n            else\n     \
    \           right = mid;\n        }\n        return right;\n    }\n\n    // find\
    \ min id that str.substr(sa[id], T.size()) > T\n    int upper_bound(const Str\
    \ &T) {\n        int left = -1, right = sa.size();\n        while (right - left\
    \ > 1) {\n            int mid = (left + right) / 2;\n            if (str.compare(sa[mid],\
    \ T.size(), T) <= 0)\n                left = mid;\n            else\n        \
    \        right = mid;\n        }\n        return right;\n    }\n\n    // find\
    \ min id that sa[id] >= str.substr(l, r-l)\n    int lower_bound(int l, int r)\
    \ {\n        int left = -1, right = rank[l];\n        while (right - left > 1)\
    \ {\n            int mid = (left + right) / 2;\n            if (st.get(mid, rank[l])\
    \ < r - l)\n                left = mid;\n            else\n                right\
    \ = mid;\n        }\n        return right;\n    }\n\n    // search\n    bool is_contain(const\
    \ Str &T) {\n        int lb = lower_bound(T);\n        if (lb >= sa.size()) return\
    \ false;\n        return str.compare(sa[lb], T.size(), T) == 0;\n    }\n\n   \
    \ // find lcp\n    void build_lcp(const vector<int> &s) {\n        int N = (int)s.size();\n\
    \        rank.assign(N, 0), lcp.assign(N - 1, 0);\n        for (int i = 0; i <\
    \ N; ++i) rank[sa[i]] = i;\n        int h = 0;\n        for (int i = 0; i < N\
    \ - 1; ++i) {\n            int pi = sa[rank[i] - 1];\n            if (h > 0) --h;\n\
    \            for (; pi + h < N && i + h < N; ++h) {\n                if (s[pi\
    \ + h] != s[i + h]) break;\n            }\n            lcp[rank[i] - 1] = h;\n\
    \        }\n    }\n\n    // build sparse table for calculating lcp\n    void build_sparse_table()\
    \ { st.init(lcp); }\n\n    // calc lcp of str.sutstr(a) and str.substr(b)\n  \
    \  int get_lcp(int a, int b) {\n        return st.get(min(rank[a], rank[b]), max(rank[a],\
    \ rank[b]));\n    }\n\n    // debug\n    void dump() {\n        for (int i = 0;\
    \ i < sa.size(); ++i) {\n            cout << i << \": \" << sa[i] << \", \" <<\
    \ str.substr(sa[i]) << endl;\n        }\n    }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: string/suffix-array.hpp
  requiredBy: []
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/suffix-array.hpp
layout: document
redirect_from:
- /library/string/suffix-array.hpp
- /library/string/suffix-array.hpp.html
title: string/suffix-array.hpp
---
