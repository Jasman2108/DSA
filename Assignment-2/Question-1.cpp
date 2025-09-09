#include <iostream>
using namespace std;

int main() {
    int n, key;
    
    // Step 1: Input size of array
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    
    // Step 2: Input sorted array
    cout << "Enter " << n << " elements in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 3: Enter the element to search
    cout << "Enter the element to search: ";
    cin >> key;

    // Step 4: Binary Search using variables like students do
    int low = 0;
    int high = n - 1;
    int mid;
    int flag = 0; // to check if found

    while (low <= high) {
        mid = (low + high) / 2; // middle index

        if (arr[mid] == key) {
            cout << "Element found at index " << mid << endl;
            flag = 1;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1; // move right
        }
        else {
            high = mid - 1; // move left
        }
    }

    if (flag == 0) {
        cout << "Element not found!" << endl;
    }

    return 0;
}
