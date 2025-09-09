#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<int> s;
    int minElement;

public:
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minElement = x;
        } 
        else {
            if (x >= minElement) {
                s.push(x);
            } else {
                // store modified value
                s.push(2*x - minElement);
                minElement = x;
            }
        }
        cout << x << " pushed\n";
    }

    void pop() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        int t = s.top();
        s.pop();

        if (t >= minElement) {
            cout << "Popped: " << t << endl;
        } else {
            cout << "Popped: " << minElement << endl;
            minElement = 2*minElement - t; // restore previous min
        }
    }

    void getMin() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Minimum element = " << minElement << endl;
        }
    }

    void peek() {
        if (s.empty()) {
            cout << "Stack is empty!\n";
            return;
        }

        int t = s.top();
        if (t >= minElement) {
            cout << "Top element = " << t << endl;
        } else {
            cout << "Top element = " << minElement << endl;
        }
    }
};

int main() {
    SpecialStack st;
    st.push(5);
    st.push(3);
    st.getMin();   // 3
    st.push(7);
    st.push(2);
    st.getMin();   // 2
    st.pop();      // removes 2
    st.getMin();   // 3
    st.peek();     // top element

    return 0;
}
