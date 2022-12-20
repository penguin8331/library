#define PROBLEM "https://yukicoder.me/problems/1800"
#include "template/template.hpp"
#include "DataStructure/Static_ModularArithmetic.hpp"

int main() {
    using mint = Fp<MOD>;
    ll N, M;
    cin >> N >> M;
    mint ans = (modpow(mint(2), M) - 1) / 2;
    cout << ans << endl;
}
