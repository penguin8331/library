#pragma once
#include "template/template.hpp"

struct LowLink {
    vector<int> aps;             // 関節点
    vector<pair<int, int>> brs;  // 橋

    vector<int> seen, ord, low;
    void dfs_lowlink(const vector<vector<int>> &G, int v, int p = -1) {
        static int time = 0;
        seen[v] = true;
        ord[v] = low[v] = time++;
        int num_of_child = 0;
        bool exist = false;  // for articulation point
        for (auto ch : G[v]) {
            if (seen[ch]) {
                if (ch != p) low[v] = min(low[v], ord[ch]);  // back edge
                continue;
            }
            dfs_lowlink(G, ch, v);
            low[v] = min(low[v], low[ch]);  // forward edge of DFS-tree
            if (ord[v] < low[ch]) brs.emplace_back(v, ch);
            if (ord[v] <= low[ch]) exist = true;
            ++num_of_child;
        }
        if ((p == -1 && num_of_child > 1) || (p != -1 && exist)) aps.emplace_back(v);
    }
    void solve(const vector<vector<int>> &G) {
        int N = (int)G.size();
        seen.assign(N, 0);
        ord.resize(N);
        low.resize(N);
        aps.clear();
        brs.clear();
        for (int v = 0; v < N; ++v)
            if (!seen[v]) dfs_lowlink(G, v);
    }
};