#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include "../../data-structure/static-modular-arithmetic.hpp"
#include "../../math/algebra/matrix.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    Matrix<Fp<mod>> mat(N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mat[i][j];
        }
    }
    cout << det(mat) << endl;
}