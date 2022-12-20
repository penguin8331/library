#include "DataStructure/Binary Indexed Tree.hpp"
template <class T>
long long inversion_number(const vector<T> &a) {
    int n = (int)a.size();
    vector<T> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    long long res = 0;
    BIT<int> bit(n);
    for (int i = 0; i < n; ++i) {
        int order = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ++order;
        res += bit.sum(order + 1, n + 1);
        bit.add(order, 1);
    }
    return res;
}