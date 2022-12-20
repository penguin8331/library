#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0009"
#include "template/template.hpp"
#include "data-structure/eratostenes.hpp"

int main() {
    Eratos era(1e6);
    int a;
    while (cin >> a) {
        cout << distance(era.primes.begin(), upper_bound(all(era.primes), a)) << endl;
    }
}
