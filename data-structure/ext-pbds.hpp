#pragma once
#include "../template/template.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ostream& operator<<(ostream& os, rope<int> A) {
    os << "[ ";
    for (const auto& i : A) {
        os << i << " ";
    }
    os << "]";
    return os;
}