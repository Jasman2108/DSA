#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                cout << "Inversion: (" << arr[i] << "," << arr[j] << ")\n";
                count++;
            }
        }
    }

    cout << "Total number of inversions = " << count << endl;

    return 0;
}
