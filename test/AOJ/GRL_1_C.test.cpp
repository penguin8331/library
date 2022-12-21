#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include "template/template.hpp"
#include "graph/warshall-floyd.hpp"

int main() {
    int V, E;
    cin >> V >> E;
    ll maxi = INF / 12;
    vector<vector<ll>> dp(V, vector<ll>(V, maxi));
    for (int i = 0; i < V; i++) {
        dp[i][i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }
    warshallfloyd(dp, V);
    if (isnegative(dp, V)) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < V; i++) {
            if (dp[i][0] > maxi / 2) {
                cout << "INF";
            } else {
                cout << dp[i][0];
            }
            for (int j = 1; j < V; j++) {
                if (dp[i][j] > maxi / 2) {
                    cout << " INF";
                } else {
                    cout << " " << dp[i][j];
                }
            }
            cout << endl;
        }
    }
}