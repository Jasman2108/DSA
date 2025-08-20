#include <iostream>
using namespace std;

int main() {
    int A[10][10], B[10][10], C[10][10];
    int m, n, p, q;

    cout << "Enter rows and columns of first matrix: ";
    cin >> m >> n;
    cout << "Enter rows and columns of second matrix: ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant matrix after multiplication:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
