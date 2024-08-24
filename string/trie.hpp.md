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
  code: "#pragma once\n#include \"../template/template.hpp\"\n\ntemplate <int char_size,\
    \ int base>\nstruct Trie {\n    struct Node {          // \u9802\u70B9\u3092\u8868\
    \u3059\u69CB\u9020\u4F53\n        vector<int> next;  // \u5B50\u306E\u9802\u70B9\
    \u756A\u53F7\u3092\u683C\u7D0D\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    -1\n        vector<int> accept;  // \u672B\u7AEF\u304C\u3053\u306E\u9802\u70B9\
    \u306B\u306A\u308B\u5358\u8A9E\u306E word_id \u3092\u4FDD\u5B58\n        int c;\
    \       // base \u304B\u3089\u306E\u9593\u9694\u3092int\u578B\u3067\u8868\u73FE\
    \u3057\u305F\u3082\u306E\n        int common;  // \u3044\u304F\u3064\u306E\u5358\
    \u8A9E\u304C\u3053\u306E\u9802\u70B9\u3092\u5171\u6709\u3057\u3066\u3044\u308B\
    \u304B\n        explicit Node(int c_) : c(c_), common(0) { next.assign(char_size,\
    \ -1); }\n    };\n    vector<Node> nodes;  // trie \u6728\u672C\u4F53\n    int\
    \ root;\n    Trie() : root(0) { nodes.push_back(Node(root)); }\n    // \u5358\u8A9E\
    \u306E\u633F\u5165\n    void insert(const string &word, int word_id) {\n     \
    \   int node_id = 0;\n        for (int i = 0; i < (int)word.size(); i++) {\n \
    \           int c = (int)(word[i] - base);\n            int &next_id = nodes[node_id].next[c];\n\
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
  timestamp: '2024-08-24 11:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/trie.hpp
layout: document
redirect_from:
- /library/string/trie.hpp
- /library/string/trie.hpp.html
title: string/trie.hpp
---
