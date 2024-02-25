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
  bundledCode: "#line 1 \"debug.hpp\"\n#include <bits/stdc++.h>\n\n#ifndef DEBUG_PRINT_HPP\n\
    #define DEBUG_PRINT_HPP\n#define debug(...) debug_print::multi_print(#__VA_ARGS__,\
    \ __VA_ARGS__)\n\n#define INCLUDED(n) ((defined _GLIBCXX_##n) || (defined _LIBCPP_##n))\n\
    \n#if __cplusplus < 201703L\n#warning Please use C++17 (or later version).\n#endif\n\
    #if !INCLUDED(ALGORITHM)\n#warning Please include <algorithm> before including\
    \ debug_print.hpp.\n#endif\n#if !INCLUDED(CCTYPE)\n#warning Please include <cctype>\
    \ before including debug_print.hpp.\n#endif\n#if !INCLUDED(IOSTREAM)\n#warning\
    \ Please include <iostream> before including debug_print.hpp.\n#endif\n#if !INCLUDED(ITERATOR)\n\
    #warning Please include <iterator> before including debug_print.hpp.\n#endif\n\
    #if !INCLUDED(STRING_VIEW)\n#warning Please include <string_view> before including\
    \ debug_print.hpp.\n#endif\n#if !INCLUDED(TYPE_TRAITS)\n#warning Please include\
    \ <type_traits> before including debug_print.hpp.\n#endif\n\nnamespace debug_print\
    \ {\nstd::ostream& os = std::cerr;\n\ntemplate <class Tp>\nauto has_cbegin(int)\
    \ -> decltype(std::cbegin(std::declval<Tp>()), std::true_type{});\ntemplate <class\
    \ Tp>\nauto has_cbegin(...) -> std::false_type;\ntemplate <class Tp>\nauto has_value_type(int)\
    \ -> decltype(std::declval<typename Tp::value_type>(), std::true_type{});\ntemplate\
    \ <class Tp>\nauto has_value_type(...) -> std::false_type;\n\ntemplate <class\
    \ Tp>\n[[maybe_unused]] constexpr bool is_iterable_container_v = decltype(has_cbegin<Tp>(int{}))::value;\n\
    template <class Tp>\n[[maybe_unused]] constexpr bool is_container_v = decltype(has_value_type<Tp>(int{}))::value\
    \ || is_iterable_container_v<Tp>;\n\ntemplate <>\n[[maybe_unused]] constexpr bool\
    \ is_iterable_container_v<std::string_view> = false;\ntemplate <>\n[[maybe_unused]]\
    \ constexpr bool is_container_v<std::string_view> = false;\n#if INCLUDED(STRING)\n\
    template <>\n[[maybe_unused]] constexpr bool is_iterable_container_v<std::string>\
    \ = false;\ntemplate <>\n[[maybe_unused]] constexpr bool is_container_v<std::string>\
    \ = false;\n#endif\n\ntemplate <class Tp, class... Ts>\nstruct first_element {\n\
    \    using type = Tp;\n};\ntemplate <class... Ts>\nusing first_t = typename first_element<Ts...>::type;\n\
    \ntemplate <class Tp, std::enable_if_t<!decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> decltype(*std::cbegin(std::declval<Tp>()));\n\
    template <class Tp, std::enable_if_t<decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> typename Tp::value_type;\n\
    template <class Tp>\nauto check_elem(...) -> void;\n\ntemplate <class Tp>\nusing\
    \ elem_t = decltype(check_elem<Tp>(int{}));\n\ntemplate <class Tp>\n[[maybe_unused]]\
    \ constexpr bool is_multidim_container_v = is_container_v<Tp> && is_container_v<elem_t<Tp>>;\n\
    \ntemplate <class Tp>\nstd::enable_if_t<!is_container_v<Tp>> out(const Tp&);\n\
    void out(const char&);\nvoid out(const char*);\nvoid out(const std::string_view&);\n\
    \n#if INCLUDED(STRING)\nvoid out(const std::string&);\n#endif\n\n#ifdef __SIZEOF_INT128__\n\
    void out(const __int128&);\nvoid out(const unsigned __int128&);\n#endif\n\ntemplate\
    \ <class Tp1, class Tp2>\nvoid out(const std::pair<Tp1, Tp2>&);\n\n#if INCLUDED(TUPLE)\n\
    template <class... Ts>\nvoid out(const std::tuple<Ts...>&);\n#endif\n\n#if INCLUDED(STACK)\n\
    template <class... Ts>\nvoid out(std::stack<Ts...>);\n#endif\n\n#if INCLUDED(QUEUE)\n\
    template <class... Ts>\nvoid out(std::queue<Ts...>);\ntemplate <class... Ts>\n\
    void out(std::priority_queue<Ts...>);\n#endif\n\ntemplate <class C>\nstd::enable_if_t<is_iterable_container_v<C>>\
    \ out(const C&);\n\ntemplate <class Tp>\nstd::enable_if_t<!is_container_v<Tp>>\
    \ out(const Tp& arg) {\n    os << arg;\n    return;\n}\n\nvoid out(const char&\
    \ arg) {\n    os << '\\'' << arg << '\\'';\n}\n\nvoid out(const char* arg) {\n\
    \    os << '\\\"' << arg << '\\\"';\n}\n\nvoid out(const std::string_view& arg)\
    \ {\n    os << '\\\"' << arg << '\\\"';\n}\n\n#if INCLUDED(STRING)\nvoid out(const\
    \ std::string& arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n#endif\n\n#ifdef\
    \ __SIZEOF_INT128__\nvoid out(const __int128& arg) {\n    int sign = (arg < 0)\
    \ ? (-1) : 1;\n    if (sign == -1)\n        os << '-';\n    __int128 base = sign;\n\
    \    while (sign * arg >= sign * base * 10)\n        base *= 10;\n    while (base)\
    \ {\n        os << static_cast<char>('0' + (arg / base % 10));\n        base /=\
    \ 10;\n    }\n}\n\nvoid out(const unsigned __int128& arg) {\n    unsigned __int128\
    \ base = 1;\n    while (arg >= base * 10)\n        base *= 10;\n    while (base)\
    \ {\n        os << static_cast<char>('0' + (arg / base % 10));\n        base /=\
    \ 10;\n    }\n}\n#endif\n\ntemplate <class Tp1, class Tp2>\nvoid out(const std::pair<Tp1,\
    \ Tp2>& arg) {\n    os << '(';\n    out(arg.first);\n    os << \", \";\n    out(arg.second);\n\
    \    os << ')';\n}\n\n#if INCLUDED(TUPLE)\ntemplate <class T, std::size_t... Is>\n\
    void print_tuple(const T& arg, std::index_sequence<Is...>) {\n    static_cast<void>(((os\
    \ << (Is == 0 ? \"\" : \", \"), out(std::get<Is>(arg))), ...));\n}\n\ntemplate\
    \ <class... Ts>\nvoid out(const std::tuple<Ts...>& arg) {\n    os << '(';\n  \
    \  print_tuple(arg, std::make_index_sequence<sizeof...(Ts)>());\n    os << ')';\n\
    }\n#endif\n\n#if INCLUDED(STACK)\ntemplate <class... Ts>\nvoid out(std::stack<Ts...>\
    \ arg) {\n    if (arg.empty()) {\n        os << \"<empty stack>\";\n        return;\n\
    \    }\n    os << \"[ \";\n    while (!arg.empty()) {\n        out(arg.top());\n\
    \        os << ' ';\n        arg.pop();\n    }\n    os << ']';\n}\n#endif\n\n\
    #if INCLUDED(QUEUE)\ntemplate <class... Ts>\nvoid out(std::queue<Ts...> arg) {\n\
    \    if (arg.empty()) {\n        os << \"<empty queue>\";\n        return;\n \
    \   }\n    os << \"[ \";\n    while (!arg.empty()) {\n        out(arg.front());\n\
    \        os << ' ';\n        arg.pop();\n    }\n    os << ']';\n}\ntemplate <class...\
    \ Ts>\nvoid out(std::priority_queue<Ts...> arg) {\n    if (arg.empty()) {\n  \
    \      os << \"<empty priority_queue>\";\n        return;\n    }\n    os << \"\
    [ \";\n    while (!arg.empty()) {\n        out(arg.top());\n        os << ' ';\n\
    \        arg.pop();\n    }\n    os << ']';\n}\n#endif\n\ntemplate <class Container>\n\
    std::enable_if_t<is_iterable_container_v<Container>> out(const Container& arg)\
    \ {\n    if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {\n       \
    \ os << \"<empty container>\";\n        return;\n    }\n    os << \"[ \";\n  \
    \  std::for_each(std::cbegin(arg), std::cend(arg), [](const elem_t<Container>&\
    \ elem) {\n        out(elem);\n        os << ' ';\n    });\n    os << ']';\n \
    \   return;\n}\n\ntemplate <class Tp>\nstd::enable_if_t<!is_multidim_container_v<Tp>>\n\
    print(const std::string_view& name, const Tp& arg) {\n    os << name << \": \"\
    ;\n    out(arg);\n    if constexpr (is_container_v<Tp>)\n        os << '\\n';\n\
    \    return;\n}\n\ntemplate <class Tp>\nstd::enable_if_t<is_multidim_container_v<Tp>>\n\
    print(std::string_view name, const Tp& arg) {\n    os << name << \": \";\n   \
    \ if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {\n        os << \"\
    <empty multidimensional container>\\n\";\n        return;\n    }\n    std::for_each(std::cbegin(arg),\
    \ std::cend(arg),\n                  [&name, is_first_elem = true](const elem_t<Tp>&\
    \ elem) mutable {\n                      if (is_first_elem)\n                \
    \          is_first_elem = false;\n                      else\n              \
    \            for (std::size_t i = 0; i < name.length() + 2; i++)\n           \
    \                   os << ' ';\n                      out(elem);\n           \
    \           os << '\\n';\n                  });\n    return;\n}\n\ntemplate <class\
    \ Tp, class... Ts>\nvoid multi_print(std::string_view names, const Tp& arg, const\
    \ Ts&... args) {\n    if constexpr (sizeof...(Ts) == 0) {\n        names.remove_suffix(\n\
    \            std::distance(\n                names.crbegin(),\n              \
    \  std::find_if_not(names.crbegin(), names.crend(),\n                        \
    \         [](const char c) { return std::isspace(c); })));\n        print(names,\
    \ arg);\n        if constexpr (!is_container_v<Tp>)\n            os << '\\n';\n\
    \    } else {\n        std::size_t comma_pos = 0;\n\n        for (std::size_t\
    \ i = 0, paren_depth = 0, inside_quote = false; i < names.length(); i++) {\n \
    \           if (!inside_quote && paren_depth == 0 && i > 0 && names[i - 1] !=\
    \ '\\'' && names[i] == ',') {\n                comma_pos = i;\n              \
    \  break;\n            }\n            if (names[i] == '\\\"' || names[i] == '\\\
    '') {\n                if (i > 0 && names[i - 1] == '\\\\') continue;\n      \
    \          inside_quote ^= true;\n            }\n            if (!inside_quote\
    \ && names[i] == '(' && (i == 0 || names[i - 1] != '\\''))\n                paren_depth++;\n\
    \            if (!inside_quote && names[i] == ')' && (i == 0 || names[i - 1] !=\
    \ '\\''))\n                paren_depth--;\n        }\n\n        const std::size_t\
    \ first_varname_length = comma_pos - std::distance(\n                        \
    \                                         names.crend() - comma_pos,\n       \
    \                                                          std::find_if_not(\n\
    \                                                                     names.crend()\
    \ - comma_pos, names.crend(),\n                                              \
    \                       [](const char c) { return std::isspace(c); }));\n    \
    \    print(names.substr(0, first_varname_length), arg);\n\n        if constexpr\
    \ (!is_container_v<Tp>) {\n            if constexpr (is_container_v<first_t<Ts...>>)\n\
    \                os << '\\n';\n            else\n                os << \" | \"\
    ;\n        }\n\n        const std::size_t next_varname_begins_at = std::distance(\n\
    \            names.cbegin(),\n            std::find_if_not(\n                names.cbegin()\
    \ + comma_pos + 1, names.cend(),\n                [](const char c) { return std::isspace(c);\
    \ }));\n        names.remove_prefix(next_varname_begins_at);\n\n        multi_print(names,\
    \ args...);\n    }\n}\n}  // namespace debug_print\n\n#undef INCLUDED\n\n#endif\
    \  // DEBUG_PRINT_HPP\n"
  code: "#include <bits/stdc++.h>\n\n#ifndef DEBUG_PRINT_HPP\n#define DEBUG_PRINT_HPP\n\
    #define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)\n\n#define\
    \ INCLUDED(n) ((defined _GLIBCXX_##n) || (defined _LIBCPP_##n))\n\n#if __cplusplus\
    \ < 201703L\n#warning Please use C++17 (or later version).\n#endif\n#if !INCLUDED(ALGORITHM)\n\
    #warning Please include <algorithm> before including debug_print.hpp.\n#endif\n\
    #if !INCLUDED(CCTYPE)\n#warning Please include <cctype> before including debug_print.hpp.\n\
    #endif\n#if !INCLUDED(IOSTREAM)\n#warning Please include <iostream> before including\
    \ debug_print.hpp.\n#endif\n#if !INCLUDED(ITERATOR)\n#warning Please include <iterator>\
    \ before including debug_print.hpp.\n#endif\n#if !INCLUDED(STRING_VIEW)\n#warning\
    \ Please include <string_view> before including debug_print.hpp.\n#endif\n#if\
    \ !INCLUDED(TYPE_TRAITS)\n#warning Please include <type_traits> before including\
    \ debug_print.hpp.\n#endif\n\nnamespace debug_print {\nstd::ostream& os = std::cerr;\n\
    \ntemplate <class Tp>\nauto has_cbegin(int) -> decltype(std::cbegin(std::declval<Tp>()),\
    \ std::true_type{});\ntemplate <class Tp>\nauto has_cbegin(...) -> std::false_type;\n\
    template <class Tp>\nauto has_value_type(int) -> decltype(std::declval<typename\
    \ Tp::value_type>(), std::true_type{});\ntemplate <class Tp>\nauto has_value_type(...)\
    \ -> std::false_type;\n\ntemplate <class Tp>\n[[maybe_unused]] constexpr bool\
    \ is_iterable_container_v = decltype(has_cbegin<Tp>(int{}))::value;\ntemplate\
    \ <class Tp>\n[[maybe_unused]] constexpr bool is_container_v = decltype(has_value_type<Tp>(int{}))::value\
    \ || is_iterable_container_v<Tp>;\n\ntemplate <>\n[[maybe_unused]] constexpr bool\
    \ is_iterable_container_v<std::string_view> = false;\ntemplate <>\n[[maybe_unused]]\
    \ constexpr bool is_container_v<std::string_view> = false;\n#if INCLUDED(STRING)\n\
    template <>\n[[maybe_unused]] constexpr bool is_iterable_container_v<std::string>\
    \ = false;\ntemplate <>\n[[maybe_unused]] constexpr bool is_container_v<std::string>\
    \ = false;\n#endif\n\ntemplate <class Tp, class... Ts>\nstruct first_element {\n\
    \    using type = Tp;\n};\ntemplate <class... Ts>\nusing first_t = typename first_element<Ts...>::type;\n\
    \ntemplate <class Tp, std::enable_if_t<!decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> decltype(*std::cbegin(std::declval<Tp>()));\n\
    template <class Tp, std::enable_if_t<decltype(has_value_type<Tp>(int{}))::value,\
    \ std::nullptr_t> = nullptr>\nauto check_elem(int) -> typename Tp::value_type;\n\
    template <class Tp>\nauto check_elem(...) -> void;\n\ntemplate <class Tp>\nusing\
    \ elem_t = decltype(check_elem<Tp>(int{}));\n\ntemplate <class Tp>\n[[maybe_unused]]\
    \ constexpr bool is_multidim_container_v = is_container_v<Tp> && is_container_v<elem_t<Tp>>;\n\
    \ntemplate <class Tp>\nstd::enable_if_t<!is_container_v<Tp>> out(const Tp&);\n\
    void out(const char&);\nvoid out(const char*);\nvoid out(const std::string_view&);\n\
    \n#if INCLUDED(STRING)\nvoid out(const std::string&);\n#endif\n\n#ifdef __SIZEOF_INT128__\n\
    void out(const __int128&);\nvoid out(const unsigned __int128&);\n#endif\n\ntemplate\
    \ <class Tp1, class Tp2>\nvoid out(const std::pair<Tp1, Tp2>&);\n\n#if INCLUDED(TUPLE)\n\
    template <class... Ts>\nvoid out(const std::tuple<Ts...>&);\n#endif\n\n#if INCLUDED(STACK)\n\
    template <class... Ts>\nvoid out(std::stack<Ts...>);\n#endif\n\n#if INCLUDED(QUEUE)\n\
    template <class... Ts>\nvoid out(std::queue<Ts...>);\ntemplate <class... Ts>\n\
    void out(std::priority_queue<Ts...>);\n#endif\n\ntemplate <class C>\nstd::enable_if_t<is_iterable_container_v<C>>\
    \ out(const C&);\n\ntemplate <class Tp>\nstd::enable_if_t<!is_container_v<Tp>>\
    \ out(const Tp& arg) {\n    os << arg;\n    return;\n}\n\nvoid out(const char&\
    \ arg) {\n    os << '\\'' << arg << '\\'';\n}\n\nvoid out(const char* arg) {\n\
    \    os << '\\\"' << arg << '\\\"';\n}\n\nvoid out(const std::string_view& arg)\
    \ {\n    os << '\\\"' << arg << '\\\"';\n}\n\n#if INCLUDED(STRING)\nvoid out(const\
    \ std::string& arg) {\n    os << '\\\"' << arg << '\\\"';\n}\n#endif\n\n#ifdef\
    \ __SIZEOF_INT128__\nvoid out(const __int128& arg) {\n    int sign = (arg < 0)\
    \ ? (-1) : 1;\n    if (sign == -1)\n        os << '-';\n    __int128 base = sign;\n\
    \    while (sign * arg >= sign * base * 10)\n        base *= 10;\n    while (base)\
    \ {\n        os << static_cast<char>('0' + (arg / base % 10));\n        base /=\
    \ 10;\n    }\n}\n\nvoid out(const unsigned __int128& arg) {\n    unsigned __int128\
    \ base = 1;\n    while (arg >= base * 10)\n        base *= 10;\n    while (base)\
    \ {\n        os << static_cast<char>('0' + (arg / base % 10));\n        base /=\
    \ 10;\n    }\n}\n#endif\n\ntemplate <class Tp1, class Tp2>\nvoid out(const std::pair<Tp1,\
    \ Tp2>& arg) {\n    os << '(';\n    out(arg.first);\n    os << \", \";\n    out(arg.second);\n\
    \    os << ')';\n}\n\n#if INCLUDED(TUPLE)\ntemplate <class T, std::size_t... Is>\n\
    void print_tuple(const T& arg, std::index_sequence<Is...>) {\n    static_cast<void>(((os\
    \ << (Is == 0 ? \"\" : \", \"), out(std::get<Is>(arg))), ...));\n}\n\ntemplate\
    \ <class... Ts>\nvoid out(const std::tuple<Ts...>& arg) {\n    os << '(';\n  \
    \  print_tuple(arg, std::make_index_sequence<sizeof...(Ts)>());\n    os << ')';\n\
    }\n#endif\n\n#if INCLUDED(STACK)\ntemplate <class... Ts>\nvoid out(std::stack<Ts...>\
    \ arg) {\n    if (arg.empty()) {\n        os << \"<empty stack>\";\n        return;\n\
    \    }\n    os << \"[ \";\n    while (!arg.empty()) {\n        out(arg.top());\n\
    \        os << ' ';\n        arg.pop();\n    }\n    os << ']';\n}\n#endif\n\n\
    #if INCLUDED(QUEUE)\ntemplate <class... Ts>\nvoid out(std::queue<Ts...> arg) {\n\
    \    if (arg.empty()) {\n        os << \"<empty queue>\";\n        return;\n \
    \   }\n    os << \"[ \";\n    while (!arg.empty()) {\n        out(arg.front());\n\
    \        os << ' ';\n        arg.pop();\n    }\n    os << ']';\n}\ntemplate <class...\
    \ Ts>\nvoid out(std::priority_queue<Ts...> arg) {\n    if (arg.empty()) {\n  \
    \      os << \"<empty priority_queue>\";\n        return;\n    }\n    os << \"\
    [ \";\n    while (!arg.empty()) {\n        out(arg.top());\n        os << ' ';\n\
    \        arg.pop();\n    }\n    os << ']';\n}\n#endif\n\ntemplate <class Container>\n\
    std::enable_if_t<is_iterable_container_v<Container>> out(const Container& arg)\
    \ {\n    if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {\n       \
    \ os << \"<empty container>\";\n        return;\n    }\n    os << \"[ \";\n  \
    \  std::for_each(std::cbegin(arg), std::cend(arg), [](const elem_t<Container>&\
    \ elem) {\n        out(elem);\n        os << ' ';\n    });\n    os << ']';\n \
    \   return;\n}\n\ntemplate <class Tp>\nstd::enable_if_t<!is_multidim_container_v<Tp>>\n\
    print(const std::string_view& name, const Tp& arg) {\n    os << name << \": \"\
    ;\n    out(arg);\n    if constexpr (is_container_v<Tp>)\n        os << '\\n';\n\
    \    return;\n}\n\ntemplate <class Tp>\nstd::enable_if_t<is_multidim_container_v<Tp>>\n\
    print(std::string_view name, const Tp& arg) {\n    os << name << \": \";\n   \
    \ if (std::distance(std::cbegin(arg), std::cend(arg)) == 0) {\n        os << \"\
    <empty multidimensional container>\\n\";\n        return;\n    }\n    std::for_each(std::cbegin(arg),\
    \ std::cend(arg),\n                  [&name, is_first_elem = true](const elem_t<Tp>&\
    \ elem) mutable {\n                      if (is_first_elem)\n                \
    \          is_first_elem = false;\n                      else\n              \
    \            for (std::size_t i = 0; i < name.length() + 2; i++)\n           \
    \                   os << ' ';\n                      out(elem);\n           \
    \           os << '\\n';\n                  });\n    return;\n}\n\ntemplate <class\
    \ Tp, class... Ts>\nvoid multi_print(std::string_view names, const Tp& arg, const\
    \ Ts&... args) {\n    if constexpr (sizeof...(Ts) == 0) {\n        names.remove_suffix(\n\
    \            std::distance(\n                names.crbegin(),\n              \
    \  std::find_if_not(names.crbegin(), names.crend(),\n                        \
    \         [](const char c) { return std::isspace(c); })));\n        print(names,\
    \ arg);\n        if constexpr (!is_container_v<Tp>)\n            os << '\\n';\n\
    \    } else {\n        std::size_t comma_pos = 0;\n\n        for (std::size_t\
    \ i = 0, paren_depth = 0, inside_quote = false; i < names.length(); i++) {\n \
    \           if (!inside_quote && paren_depth == 0 && i > 0 && names[i - 1] !=\
    \ '\\'' && names[i] == ',') {\n                comma_pos = i;\n              \
    \  break;\n            }\n            if (names[i] == '\\\"' || names[i] == '\\\
    '') {\n                if (i > 0 && names[i - 1] == '\\\\') continue;\n      \
    \          inside_quote ^= true;\n            }\n            if (!inside_quote\
    \ && names[i] == '(' && (i == 0 || names[i - 1] != '\\''))\n                paren_depth++;\n\
    \            if (!inside_quote && names[i] == ')' && (i == 0 || names[i - 1] !=\
    \ '\\''))\n                paren_depth--;\n        }\n\n        const std::size_t\
    \ first_varname_length = comma_pos - std::distance(\n                        \
    \                                         names.crend() - comma_pos,\n       \
    \                                                          std::find_if_not(\n\
    \                                                                     names.crend()\
    \ - comma_pos, names.crend(),\n                                              \
    \                       [](const char c) { return std::isspace(c); }));\n    \
    \    print(names.substr(0, first_varname_length), arg);\n\n        if constexpr\
    \ (!is_container_v<Tp>) {\n            if constexpr (is_container_v<first_t<Ts...>>)\n\
    \                os << '\\n';\n            else\n                os << \" | \"\
    ;\n        }\n\n        const std::size_t next_varname_begins_at = std::distance(\n\
    \            names.cbegin(),\n            std::find_if_not(\n                names.cbegin()\
    \ + comma_pos + 1, names.cend(),\n                [](const char c) { return std::isspace(c);\
    \ }));\n        names.remove_prefix(next_varname_begins_at);\n\n        multi_print(names,\
    \ args...);\n    }\n}\n}  // namespace debug_print\n\n#undef INCLUDED\n\n#endif\
    \  // DEBUG_PRINT_HPP"
  dependsOn: []
  isVerificationFile: false
  path: debug.hpp
  requiredBy: []
  timestamp: '2024-02-25 20:07:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug.hpp
layout: document
redirect_from:
- /library/debug.hpp
- /library/debug.hpp.html
title: debug.hpp
---
