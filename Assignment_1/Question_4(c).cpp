#include <iostream>
using namespace std;

int main() {
    int A[10][10], T[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }

    // Transpose logic
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            T[j][i] = A[i][j];  
        }
    }

    // Print original
    cout << "Original Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Print transpose
    cout << "Transpose of Matrix:\n";
    for (int i = 0; i < cols; i++) {     
        for (int j = 0; j < rows; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
