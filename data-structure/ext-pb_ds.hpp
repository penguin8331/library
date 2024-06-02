#pragma once
#include "../template/template.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class Key, class Cmp_Fn = less<Key>>
using ordered_set = tree<Key, null_type, Cmp_Fn, rb_tree_tag,
                         tree_order_statistics_node_update>;