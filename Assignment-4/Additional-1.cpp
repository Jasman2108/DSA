#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;

    // Start with "1"
    q.push("1");

    for (int i = 1; i <= n; i++) {
        // Get front of queue
        string current = q.front();
        q.pop();

        // Print it
        cout << current;
        if (i != n) cout << ", ";

        // Generate next two numbers and push into queue
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinary(n);
    cout << endl;

    return 0;
}
