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
  bundledCode: "#line 2 \"template/template.hpp\"\n#include <bits/stdc++.h>\n#line\
    \ 3 \"template/macro.hpp\"\n\n#define overload3(_1, _2, _3, name, ...) name\n\
    #define all1(v) std::begin(v), std::end(v)\n#define all2(v, a) std::begin(v),\
    \ std::begin(v) + a\n#define all3(v, a, b) std::begin(v) + a, std::begin(v) +\
    \ b\n#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)\n\
    #define rall1(v) std::rbegin(v), std::rend(v)\n#define rall2(v, a) std::rbegin(v),\
    \ std::rbegin(v) + a\n#define rall3(v, a, b) std::rbegin(v) + a, std::rbegin(v)\
    \ + b\n#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)\n\
    #define elif else if\n#define updiv(N, X) (((N) + (X) - 1) / (X))\n#define sigma(a,\
    \ b) (((a) + (b)) * ((b) - (a) + 1) / 2)\n#define INT(...)     \\\n    int __VA_ARGS__;\
    \ \\\n    scan(__VA_ARGS__)\n#define LL(...)     \\\n    ll __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define STR(...)        \\\n    string __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define CHR(...)      \\\n    char __VA_ARGS__; \\\n\
    \    scan(__VA_ARGS__)\n#define DOU(...)        \\\n    double __VA_ARGS__; \\\
    \n    scan(__VA_ARGS__)\n#define LD(...)     \\\n    ld __VA_ARGS__; \\\n    scan(__VA_ARGS__)\n\
    #define pb push_back\n#define eb emplace_back\n#line 3 \"template/alias.hpp\"\n\
    \nusing ll = long long;\nusing ld = long double;\nusing pii = std::pair<int, int>;\n\
    using pll = std::pair<ll, ll>;\nconstexpr int inf = 1 << 30;\nconstexpr ll INF\
    \ = 1LL << 60;\nconstexpr int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};\nconstexpr\
    \ int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};\nconstexpr int mod = 998244353;\nconstexpr\
    \ int MOD = 1e9 + 7;\n#line 3 \"template/func.hpp\"\n\ntemplate <typename T>\n\
    inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }\n\
    template <typename T>\ninline bool chmin(T& a, T b) { return ((a > b) ? (a = b,\
    \ true) : (false)); }\ntemplate <typename T, typename U>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, U> &p) {\n    os << p.first << \" \" << p.second;\n\
    \    return os;\n}\ntemplate <typename T, typename U>\nstd::istream &operator>>(std::istream\
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
    #line 3 \"template/debug.hpp\"\n\n#ifdef LOCAL\n#include <debug.hpp>\n#else\n\
    #define debug(...)\n#endif\n#line 8 \"template/template.hpp\"\nusing namespace\
    \ std;\n#line 3 \"string/trie.hpp\"\n\ntemplate <int char_size, int base>\nstruct\
    \ Trie {\n    struct Node {          // \u9802\u70B9\u3092\u8868\u3059\u69CB\u9020\
    \u4F53\n        vector<int> next;  // \u5B50\u306E\u9802\u70B9\u756A\u53F7\u3092\
    \u683C\u7D0D\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070-1\n        vector<int>\
    \ accept;  // \u672B\u7AEF\u304C\u3053\u306E\u9802\u70B9\u306B\u306A\u308B\u5358\
    \u8A9E\u306E word_id \u3092\u4FDD\u5B58\n        int c;       // base \u304B\u3089\
    \u306E\u9593\u9694\u3092int\u578B\u3067\u8868\u73FE\u3057\u305F\u3082\u306E\n\
    \        int common;  // \u3044\u304F\u3064\u306E\u5358\u8A9E\u304C\u3053\u306E\
    \u9802\u70B9\u3092\u5171\u6709\u3057\u3066\u3044\u308B\u304B\n        Node(int\
    \ c_) : c(c_), common(0) { next.assign(char_size, -1); }\n    };\n    vector<Node>\
    \ nodes;  // trie \u6728\u672C\u4F53\n    int root;\n    Trie() : root(0) { nodes.push_back(Node(root));\
    \ }\n    // \u5358\u8A9E\u306E\u633F\u5165\n    void insert(const string &word,\
    \ int word_id) {\n        int node_id = 0;\n        for (int i = 0; i < (int)word.size();\
    \ i++) {\n            int c = (int)(word[i] - base);\n            int &next_id\
    \ = nodes[node_id].next[c];\n            if (next_id == -1) {  // \u6B21\u306E\
    \u9802\u70B9\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\u8FFD\u52A0\n   \
    \             next_id = (int)nodes.size();\n                nodes.push_back(Node(c));\n\
    \            }\n            ++nodes[node_id].common;\n            node_id = next_id;\n\
    \        }\n        ++nodes[node_id].common;\n        nodes[node_id].accept.push_back(word_id);\n\
    \    }\n    void insert(const string &word) { insert(word, nodes[0].common); }\n\
    \    // \u5358\u8A9E\u3068prefix\u306E\u691C\u7D22\n    bool search(const string\
    \ &word, bool prefix = false) {\n        int node_id = 0;\n        for (int i\
    \ = 0; i < (int)word.size(); i++) {\n            int c = (int)(word[i] - base);\n\
    \            int &next_id = nodes[node_id].next[c];\n            if (next_id ==\
    \ -1) {  // \u6B21\u306E\u9802\u70B9\u304C\u5B58\u5728\u3057\u306A\u3051\u308C\
    \u3070\u7D42\u4E86\n                return false;\n            }\n           \
    \ node_id = next_id;\n        }\n        return (prefix) ? true : nodes[node_id].accept.size()\
    \ > 0;\n    }\n    // prefix \u3092\u6301\u3064\u5358\u8A9E\u304C\u5B58\u5728\u3059\
    \u308B\u304B\u306E\u691C\u7D22\n    bool start_with(const string &prefix) { return\
    \ search(prefix, true); }\n    // \u633F\u5165\u3057\u305F\u5358\u8A9E\u306E\u6570\
    \n    int count() const { return (nodes[0].common); }\n    // Trie\u6728\u306E\
    \u30CE\u30FC\u30C9\u6570\n    int size() const { return ((int)nodes.size()); }\n\
    };\n"
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <int char_size,\
    \ int base>\nstruct Trie {\n    struct Node {          // \u9802\u70B9\u3092\u8868\
    \u3059\u69CB\u9020\u4F53\n        vector<int> next;  // \u5B50\u306E\u9802\u70B9\
    \u756A\u53F7\u3092\u683C\u7D0D\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    -1\n        vector<int> accept;  // \u672B\u7AEF\u304C\u3053\u306E\u9802\u70B9\
    \u306B\u306A\u308B\u5358\u8A9E\u306E word_id \u3092\u4FDD\u5B58\n        int c;\
    \       // base \u304B\u3089\u306E\u9593\u9694\u3092int\u578B\u3067\u8868\u73FE\
    \u3057\u305F\u3082\u306E\n        int common;  // \u3044\u304F\u3064\u306E\u5358\
    \u8A9E\u304C\u3053\u306E\u9802\u70B9\u3092\u5171\u6709\u3057\u3066\u3044\u308B\
    \u304B\n        Node(int c_) : c(c_), common(0) { next.assign(char_size, -1);\
    \ }\n    };\n    vector<Node> nodes;  // trie \u6728\u672C\u4F53\n    int root;\n\
    \    Trie() : root(0) { nodes.push_back(Node(root)); }\n    // \u5358\u8A9E\u306E\
    \u633F\u5165\n    void insert(const string &word, int word_id) {\n        int\
    \ node_id = 0;\n        for (int i = 0; i < (int)word.size(); i++) {\n       \
    \     int c = (int)(word[i] - base);\n            int &next_id = nodes[node_id].next[c];\n\
    \            if (next_id == -1) {  // \u6B21\u306E\u9802\u70B9\u304C\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070\u8FFD\u52A0\n                next_id = (int)nodes.size();\n\
    \                nodes.push_back(Node(c));\n            }\n            ++nodes[node_id].common;\n\
    \            node_id = next_id;\n        }\n        ++nodes[node_id].common;\n\
    \        nodes[node_id].accept.push_back(word_id);\n    }\n    void insert(const\
    \ string &word) { insert(word, nodes[0].common); }\n    // \u5358\u8A9E\u3068\
    prefix\u306E\u691C\u7D22\n    bool search(const string &word, bool prefix = false)\
    \ {\n        int node_id = 0;\n        for (int i = 0; i < (int)word.size(); i++)\
    \ {\n            int c = (int)(word[i] - base);\n            int &next_id = nodes[node_id].next[c];\n\
    \            if (next_id == -1) {  // \u6B21\u306E\u9802\u70B9\u304C\u5B58\u5728\
    \u3057\u306A\u3051\u308C\u3070\u7D42\u4E86\n                return false;\n  \
    \          }\n            node_id = next_id;\n        }\n        return (prefix)\
    \ ? true : nodes[node_id].accept.size() > 0;\n    }\n    // prefix \u3092\u6301\
    \u3064\u5358\u8A9E\u304C\u5B58\u5728\u3059\u308B\u304B\u306E\u691C\u7D22\n   \
    \ bool start_with(const string &prefix) { return search(prefix, true); }\n   \
    \ // \u633F\u5165\u3057\u305F\u5358\u8A9E\u306E\u6570\n    int count() const {\
    \ return (nodes[0].common); }\n    // Trie\u6728\u306E\u30CE\u30FC\u30C9\u6570\
    \n    int size() const { return ((int)nodes.size()); }\n};"
  dependsOn:
  - template/template.hpp
  - template/macro.hpp
  - template/alias.hpp
  - template/func.hpp
  - template/util.hpp
  - template/debug.hpp
  isVerificationFile: false
  path: string/trie.hpp
  requiredBy: []
  timestamp: '2024-07-12 09:17:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
