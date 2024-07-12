#pragma once
#include "../template/template.hpp"

#define overload3(_1, _2, _3, name, ...) name
#define all1(v) std::begin(v), std::end(v)
#define all2(v, a) std::begin(v), std::begin(v) + a
#define all3(v, a, b) std::begin(v) + a, std::begin(v) + b
#define all(...) overload3(__VA_ARGS__, all3, all2, all1)(__VA_ARGS__)
#define rall1(v) std::rbegin(v), std::rend(v)
#define rall2(v, a) std::rbegin(v), std::rbegin(v) + a
#define rall3(v, a, b) std::rbegin(v) + a, std::rbegin(v) + b
#define rall(...) overload3(__VA_ARGS__, rall3, rall2, rall1)(__VA_ARGS__)
#define elif else if
#define updiv(N, X) (((N) + (X) - 1) / (X))
#define sigma(a, b) (((a) + (b)) * ((b) - (a) + 1) / 2)
#define INT(...)     \
    int __VA_ARGS__; \
    scan(__VA_ARGS__)
#define LL(...)     \
    ll __VA_ARGS__; \
    scan(__VA_ARGS__)
#define STR(...)        \
    string __VA_ARGS__; \
    scan(__VA_ARGS__)
#define CHR(...)      \
    char __VA_ARGS__; \
    scan(__VA_ARGS__)
#define DOU(...)        \
    double __VA_ARGS__; \
    scan(__VA_ARGS__)
#define LD(...)     \
    ld __VA_ARGS__; \
    scan(__VA_ARGS__)
#define pb push_back
#define eb emplace_back