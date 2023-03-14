#pragma once
#include "../template/template.hpp"

#include <ext/rope>
using namespace __gnu_cxx;

template<class T>
ostream& operator<<(ostream& os, rope<T> A) {
    os << "[ ";
    for (const auto& i : A) {
        os << i << " ";
    }
    os << "]";
    return os;
}