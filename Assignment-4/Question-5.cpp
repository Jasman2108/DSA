// Implement Stack Using Two Queues
#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
private:
    queue<int> q1, q2;

public:
    // Push element onto stack
    void push(int x) {
        // Step 1: push new element in q2
        q2.push(x);

        // Step 2: move all elements of q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: swap q1 and q2
        swap(q1, q2);
        cout << x << " pushed to stack\n";
    }

    // Pop element from stack
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q1.front() << " popped from stack\n";
        q1.pop();
    }

    // Top element
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.pop();

    cout << "Top element after pops: " << s.top() << endl;

    return 0;
}

//Implement Stack Using One Queue
#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
private:
    queue<int> q;

public:
    // Push element
    void push(int x) {
        int size = q.size();
        q.push(x);

        // Move all previous elements behind the new one
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << x << " pushed to stack\n";
    }

    // Pop element
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << q.front() << " popped from stack\n";
        q.pop();
    }

    // Top element
    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    // Check if stack is empty
    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    StackUsingOneQueue s;

    s.push(5);
    s.push(15);
    s.push(25);

    cout << "Top element: " << s.top() << endl;

    s.pop();
    s.pop();

    cout << "Top element after pops: " << s.top() << endl;

    return 0;
}

