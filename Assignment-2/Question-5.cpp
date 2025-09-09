// Diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;

    int diag[n]; 
    cout << "Enter diagonal elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> diag[i];
    }

    cout << "Matrix form:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}
//Tri-diagonal Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;

    int tri[3 * n - 2]; // 3n-2 space
    cout << "Enter elements row-wise (only 3 diagonals):\n";
    for (int i = 0; i < 3 * n - 2; i++) {
        cin >> tri[i];
    }

    cout << "Matrix form:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) // main diagonal
                cout << tri[n - 1 + i] << " ";
            else if (i == j + 1) // lower diagonal
                cout << tri[i - 1] << " ";
            else if (j == i + 1) // upper diagonal
                cout << tri[2 * n - 1 + i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}


//Lower Triangular Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of lower triangular matrix: ";
    cin >> n;

    int lower[n * (n + 1) / 2];
    cout << "Enter elements row-wise (only lower part):\n";
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        cin >> lower[i];
    }

    cout << "Matrix form:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << lower[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}


//Upper Triangular Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of upper triangular matrix: ";
    cin >> n;

    int upper[n * (n + 1) / 2];
    cout << "Enter elements row-wise (only upper part):\n";
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        cin >> upper[i];
    }

    cout << "Matrix form:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << upper[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}


//Symmetric Matrix
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of symmetric matrix: ";
    cin >> n;

    int sym[n * (n + 1) / 2];
    cout << "Enter elements row-wise (only upper part):\n";
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        cin >> sym[i];
    }

    cout << "Matrix form:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j)
                cout << sym[k++] << " ";
            else
                cout << sym[j * (j + 1) / 2 + i] << " "; 
        }
        cout << endl;
    }
    return 0;
}
