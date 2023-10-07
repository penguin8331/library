#define PROBLEM "https://yukicoder.me/problems/no/1995"
#include "../../algorithm/interval_scheduling.hpp"
#include "../../template/template.hpp"

int main() {
    INT(N, M);
    vector<pii> A(M);
    scan(A);
    print((N - 1) * 2 - interval_scheduling(A));
}