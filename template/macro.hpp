#pragma once
#include "../template/template.hpp"

#define all(x) std::begin(x), std::end(x)
#define rall(x) std::rbegin(x), std::rend(x)
#define elif else if
#define updiv(N, X) (((N) + (X) - (1)) / (X))
#define sigma(a, b) ((a + b) * (b - a + 1) / 2)
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