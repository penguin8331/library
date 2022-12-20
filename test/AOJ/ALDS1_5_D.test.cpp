#include "template/template.hpp"
#include "DataStructure/Inversion Number.hpp"

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << inversion_number(A) << endl;
}