#pragma once
#include "../template/template.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T>
ostream& operator<<(ostream& os, ordered_set<T> A) {
    os << "[ ";
    for (const T& i : A) {
        os << i << " ";
    }
    os << "]";
    return os;
}
template <class T, class U>
ostream& operator<<(ostream& os, gp_hash_table<T, U> m) {
    os << "[ ";
    for (const pair<T, U>& i : m) {
        os << "(" << i.first << "," << i.second << ")"
           << "";
    }
    os << "]";
    return os;
}