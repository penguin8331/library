#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0233"
#include "../../math/number/convert-base.hpp"
#include "../../template/template.hpp"

int main() {
    while (true) {
        int a;
        cin >> a;
        if (a == 0) return 0;
        auto res = convert_base(a, -10);
        for (int i = 0; i < (int)res.size(); i++) {
            cout << res[i];
        }
        cout << endl;
    }
}