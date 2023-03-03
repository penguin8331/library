#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233"
#include "../../template/template.hpp"
#include "../../math/number/convert-base.hpp"

int main() {
    while (true) {
        int a;
        cin >> a;
        if (a == 0) return 0;
        auto res = convert_base(a, -10);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i];
        }
        cout << endl;
    }
}