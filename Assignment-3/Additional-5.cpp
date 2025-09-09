#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool canSortStack(vector<int> A) {
    stack<int> S;
    int expected = 1; // assuming array has elements 1..N; modify if needed

    int N = A.size();
    int index = 0; // index for array A

    while (index < N || !S.empty()) {
        if (!S.empty() && S.top() == expected) {
            S.pop();
            expected++;
        } else if (index < N) {
            S.push(A[index]);
            index++;
        } else {
            // top of stack is not what we expect and A is exhausted
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> A;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements of array:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    if (canSortStack(A))
        cout << "Yes, it is possible to sort B using the stack.\n";
    else
        cout << "No, it is not possible.\n";

    return 0;
}
