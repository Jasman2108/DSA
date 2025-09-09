#include <iostream>
#include <stack>
#include <cctype> // for isdigit
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // If operand, push into stack
        if (isdigit(ch)) {
            s.push(ch - '0'); // convert char to int
        }
        // If operator, pop two operands and apply
        else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }

    return s.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single-digit numbers only): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
