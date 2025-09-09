// Using linear Search
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = 8; 
    int i;

    cout << "Array elements: ";
    for (i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Linear search for missing number
    for (i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {  
            cout << "Missing number is: " << i + 1 << endl;
            return 0;
        }
    }

    cout << "Missing number is: " << n << endl;

    return 0;
}
//Using binary search
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; 
    int n = 8;
    int low = 0, high = n - 2; 
    int mid, missing = n;

    cout << "Array elements: ";
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            
            low = mid + 1;
        } else {
           
            missing = mid + 1;
            high = mid - 1;
        }
    }

    cout << "Missing number is: " << missing << endl;

    return 0;
}
