#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string exp) {
    stack<char> s;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        // if opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // if closing bracket, check top of stack
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false; // nothing to match
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // mismatch
            }
        }
    }

    // stack should be empty if balanced
    return s.empty();
}

int main() {
    string exp;
    cout << "Enter an expression: ";
    cin >> exp;

    if (isBalanced(exp)) {
        cout << "Expression has Balanced Parentheses" << endl;
    } else {
        cout << "Expression does NOT have Balanced Parentheses" << endl;
    }

    return 0;
}
