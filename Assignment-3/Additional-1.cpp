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

    stack<int> s;

    cout << "Nearest smaller elements:\n";
    for (int i = 0; i < n; i++) {
        // remove elements greater or equal to arr[i]
        while (!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if (s.empty()) {
            cout << "-1 ";  // no smaller element
        } else {
            cout << s.top() << " ";
        }

        // push current element into stack
        s.push(arr[i]);
    }
    cout << endl;

    return 0;
}
