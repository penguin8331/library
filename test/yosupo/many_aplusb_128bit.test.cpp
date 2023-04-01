#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
#include "../../data-structure/boost-multiprecision.hpp"
#include "../../template/template.hpp"

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        Bint a, b;
        cin >> a >> b;
        cout << a + b << endl;
    }
}