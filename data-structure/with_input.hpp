#pragma once
#include "../template/template.hpp"

template <class T, class = void>
struct with_input {};

template <class T>
struct with_input<T, std::enable_if_t<!std::is_class_v<T>>> {
   private:
    T val;

   public:
    with_input() {
        std::cin >> val;
    }
    explicit inline with_input(const T& val)
        : val(val) {}
    explicit inline with_input(T&& val)
        : val(static_cast<T&&>(val)) {}
    inline operator const T&() const {
        return val;
    }
    inline operator T&() {
        return val;
    }
};

using inti = with_input<int>;
using lli = with_input<ll>;
using stri = with_input<string>;
using chai = with_input<char>;
using doui = with_input<double>;
using ldi = with_input<ld>;