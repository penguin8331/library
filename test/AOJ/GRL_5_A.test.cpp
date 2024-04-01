#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A"
#include "../../graph/diameter-weighted.hpp"
#include "../../template/template.hpp"
int main() {
    int N;
    cin >> N;
    vector<vector<Edge>> G(N, vector<Edge>(0));
    for (int i = 0; i < N - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        Edge a, b;
        a.to = t;
        b.to = s;
        a.cost = w;
        b.cost = w;
        G[s].push_back(a);
        G[t].push_back(b);
    }
    cout << tree_diameter<ll>(G) << endl;
}