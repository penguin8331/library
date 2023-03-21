#pragma once
#include "../template/template.hpp"

template <typename T>
inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template <typename T>
inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
    os << p.first << " " << p.second;
    return os;
}
template <typename T, typename U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (auto it = std::begin(v); it != std::end(v);) {
        os << *it << ((++it) != std::end(v) ? " " : "");
    }
    return os;
}
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &in : v) {
        is >> in;
    }
    return is;
}
inline void scan() {}
template <class Head, class... Tail>
inline void scan(Head &head, Tail &...tail) {
    std::cin >> head;
    scan(tail...);
}
template <class T>
inline void print(const T &t) { std::cout << t << '\n'; }
template <class Head, class... Tail>
inline void print(const Head &head, const Tail &...tail) {
    std::cout << head << ' ';
    print(tail...);
}
template <class... T>
inline void fin(const T &...a) {
    print(a...);
    exit(0);
}