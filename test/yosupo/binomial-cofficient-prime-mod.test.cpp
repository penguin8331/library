#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include "../../data-structure/dynamic_modular-arithmetic.hpp"
#include "../../math/combinatorics/binomial-coefficient.hpp"
#include "../../template/template.hpp"

int main() {
    INT(T, m);
    MODS.push_back(m);
    using mint = Fp<0>;
    BiCoef<mint> bc;
    bc.init(20000000);
    while (T--) {
        INT(n, k);
        if (n < k) {
            print(0);
            continue;
        }
        print(bc.com(n, k));
    }
}