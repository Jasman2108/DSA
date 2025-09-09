#include <iostream>
#include <stack>
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

    int nge[n]; // to store answers
    stack<int> s; // will store indices

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // remove smaller elements
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = s.top();
        }

        // push current element
        s.push(arr[i]);
    }

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }

    return 0;
}
