#include <iostream>
using namespace std;

#define MAX 100

// Function to print triplet representation
void printTriplet(int triplet[MAX][3]) {
    int n = triplet[0][2]; // number of non-zero elements
    cout << "Row Col Value\n";
    for (int i = 0; i <= n; i++) {
        cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }
}

// Function to convert normal matrix to triplet form
int convertToTriplet(int mat[10][10], int rows, int cols, int triplet[MAX][3]) {
    int k = 1; // index for triplet (start from 1 as 0th row is metadata)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = mat[i][j];
                k++;
            }
        }
    }
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = k - 1; // total non-zero elements
    return k; // return size of triplet
}

// (a) Transpose of Sparse Matrix
void transposeTriplet(int triplet[MAX][3], int trans[MAX][3]) {
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int n = triplet[0][2];

    trans[0][0] = cols;
    trans[0][1] = rows;
    trans[0][2] = n;

    int k = 1;
    for (int j = 0; j < cols; j++) {
        for (int i = 1; i <= n; i++) {
            if (triplet[i][1] == j) {
                trans[k][0] = triplet[i][1];
                trans[k][1] = triplet[i][0];
                trans[k][2] = triplet[i][2];
                k++;
            }
        }
    }
}

// (b) Addition of two sparse matrices
void addTriplet(int t1[MAX][3], int t2[MAX][3], int sum[MAX][3]) {
    if (t1[0][0] != t2[0][0] || t1[0][1] != t2[0][1]) {
        cout << "Addition not possible\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    int n1 = t1[0][2], n2 = t2[0][2];

    sum[0][0] = t1[0][0];
    sum[0][1] = t1[0][1];

    while (i <= n1 && j <= n2) {
        if (t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            sum[k][0] = t1[i][0];
            sum[k][1] = t1[i][1];
            sum[k][2] = t1[i][2];
            i++;
        } else if (t2[j][0] < t1[i][0] || (t2[j][0] == t1[i][0] && t2[j][1] < t1[i][1])) {
            sum[k][0] = t2[j][0];
            sum[k][1] = t2[j][1];
            sum[k][2] = t2[j][2];
            j++;
        } else { // same row and col
            sum[k][0] = t1[i][0];
            sum[k][1] = t1[i][1];
            sum[k][2] = t1[i][2] + t2[j][2];
            i++; j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i <= n1) {
        sum[k][0] = t1[i][0];
        sum[k][1] = t1[i][1];
        sum[k][2] = t1[i][2];
        i++; k++;
    }
    while (j <= n2) {
        sum[k][0] = t2[j][0];
        sum[k][1] = t2[j][1];
        sum[k][2] = t2[j][2];
        j++; k++;
    }

    sum[0][2] = k - 1;
}

// (c) Multiplication of two sparse matrices
void multiplyTriplet(int t1[MAX][3], int t2[MAX][3], int result[MAX][3]) {
    if (t1[0][1] != t2[0][0]) {
        cout << "Multiplication not possible\n";
        return;
    }

    int n1 = t1[0][2], n2 = t2[0][2];
    int k = 1;

    result[0][0] = t1[0][0];
    result[0][1] = t2[0][1];

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (t1[i][1] == t2[j][0]) {
                int row = t1[i][0];
                int col = t2[j][1];
                int val = t1[i][2] * t2[j][2];

                // Check if element already exists
                int found = 0;
                for (int x = 1; x < k; x++) {
                    if (result[x][0] == row && result[x][1] == col) {
                        result[x][2] += val;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    result[k][0] = row;
                    result[k][1] = col;
                    result[k][2] = val;
                    k++;
                }
            }
        }
    }
    result[0][2] = k - 1;
}

int main() {
    int mat1[10][10], mat2[10][10];
    int t1[MAX][3], t2[MAX][3], trans[MAX][3], sum[MAX][3], mult[MAX][3];
    int r, c;

    cout << "Enter rows and cols of matrix1: ";
    cin >> r >> c;
    cout << "Enter matrix1:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat1[i][j];

    cout << "Enter rows and cols of matrix2: ";
    int r2, c2;
    cin >> r2 >> c2;
    cout << "Enter matrix2:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> mat2[i][j];

    // Convert to triplet
    convertToTriplet(mat1, r, c, t1);
    convertToTriplet(mat2, r2, c2, t2);

    cout << "\nTriplet form of Matrix 1:\n";
    printTriplet(t1);

    cout << "\nTriplet form of Matrix 2:\n";
    printTriplet(t2);

    // (a) Transpose
    transposeTriplet(t1, trans);
    cout << "\nTranspose of Matrix 1:\n";
    printTriplet(trans);

    // (b) Addition
    addTriplet(t1, t2, sum);
    cout << "\nAddition result:\n";
    printTriplet(sum);

    // (c) Multiplication
    multiplyTriplet(t1, t2, mult);
    cout << "\nMultiplication result:\n";
    printTriplet(mult);

    return 0;
}
