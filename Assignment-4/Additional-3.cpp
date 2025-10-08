#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int> q) {
    stack<int> s;
    int expected = 1;
    int n = q.size();

    // Process the queue
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // If the front matches expected, send to output queue (simulated)
        if (front == expected) {
            expected++;
        }
        else {
            // If stack top matches expected, pop all matching elements
            while (!s.empty() && s.top() == expected) {
                s.pop();
                expected++;
            }

            // If still doesn't match, push current element to stack
            if (front != expected) {
                s.push(front);
            } else {
                expected++;
            }
        }
    }

    // Pop remaining elements from stack
    while (!s.empty() && s.top() == expected) {
        s.pop();
        expected++;
    }

    // If all elements processed in correct order
    return (expected - 1 == n);
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if (checkSorted(q))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
