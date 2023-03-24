#pragma once
#include "../template/template.hpp"

struct Mo {
    vector<int> left, right, index;
    vector<bool> v;
    int window;
    int nl, nr, ptr;
    function<void(int)> insert, erase;

    Mo(int n, const function<void(int)> INSERT, const function<void(int)> ERASE)
        : window((int)sqrt(n)),
          nl(0),
          nr(0),
          ptr(0),
          v(n, false),
          insert(INSERT),
          erase(ERASE) {}

    /* push */
    void push(int l, int r) { left.push_back(l), right.push_back(r); }

    /* sort intervals */
    void build() {
        index.resize(left.size());
        iota(index.begin(), index.end(), 0);

        sort(begin(index), end(index), [&](int a, int b) {
            if (left[a] / window != left[b] / window) return left[a] < left[b];
            return right[a] < right[b];
        });
    }

    /* extend-shorten */
    void extend_shorten(int id) {
        v[id].flip();
        if (v[id])
            insert(id);
        else
            erase(id);
    }

    /* next id of interval */
    int next() {
        if (ptr == index.size()) return -1;
        int id = index[ptr];
        while (nl > left[id]) extend_shorten(--nl);
        while (nr < right[id]) extend_shorten(nr++);
        while (nl < left[id]) extend_shorten(nl++);
        while (nr > right[id]) extend_shorten(--nr);
        return index[ptr++];
    }
};
