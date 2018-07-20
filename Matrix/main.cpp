#include "matrix.h"

int main() {

    Matrix M1(3, 2), M2(3, 2);

    M2(0, 0) = 1;
    M2(0, 1) = 2;

    M2(1, 0) = 3;
    M2(1, 1) = 4;

    M2(2, 0) = 5;
    M2(2, 1) = 6;

    cin >> M1;
    cout << " M1 " << M1;
    cout << " M2 " << M2;

    cout << " M1 + M2 " << M1 + M2;
    cout << " M1 - M2 " << M1 - M2;
    cout << " M1 * M2 " << M1 * M2;

 //   cout << " M1 + 4  " << M1 + 4;
    cout << " 4 + M2 " << 4 + M2;

    cout << " -M1   " << -M1;
}
