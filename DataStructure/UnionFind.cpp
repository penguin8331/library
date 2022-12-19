//
// Union-Find tree
//

/*
    ・併合時の工夫: union by size
    par[x]: x が根のときは x を含むグループのサイズ (の -1 倍)、そうでないときは親ノード

    issame(x, y): x と y が同じグループにいるか, 計算量はならし O(α(n))
    unite(x, y): x と y を同じグループにする, 計算量はならし O(α(n))
    size(x): x を含むグループの所属メンバー数
*/

#include <bits/stdc++.h>
using namespace std;

#pragma region UnionFind
struct UnionFind {
    vector<int> par;

    UnionFind() {}
    UnionFind(int n) : par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y);  // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }

    vector<vector<int>> groups() {
        map<int, vector<int>> root_buf;
        for (int i = 0; i < par.size(); ++i) {
            int r = root(i);
            root_buf[r].push_back(i);
        }
        vector<vector<int>> res;
        for (const auto& i : root_buf) {
            res.push_back(i.second);
        }
        return res;
    }
};
#pragma endregion UnionFind
