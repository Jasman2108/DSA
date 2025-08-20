#include <iostream>
using namespace std;

int main() {
    int A[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Matrix is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    // Row sums
    cout << "Sum of each row:\n";
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += A[i][j];
        }
        cout << "Row " << i + 1 << " = " << sum << endl;
    }

    // Column sums
    cout << "Sum of each column:\n";
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += A[i][j];
        }
        cout << "Column " << j + 1 << " = " << sum << endl;
    }

    return 0;
}
