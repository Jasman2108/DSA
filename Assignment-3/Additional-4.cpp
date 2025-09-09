#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> temp(n);
    cout << "Enter temperatures:\n";
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    vector<int> answer(n, 0);  // initially all 0
    stack<int> s; // will store indices of days

    for (int i = 0; i < n; i++) {
        // while current temp is warmer than the day at top of stack
        while (!s.empty() && temp[i] > temp[s.top()]) {
            int prev = s.top();
            s.pop();
            answer[prev] = i - prev; // days waited
        }
        s.push(i); // push current day
    }

    cout << "Answer array (days to wait):\n";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
