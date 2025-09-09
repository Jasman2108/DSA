#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    // push all characters into stack
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    // pop from stack to reverse
    string rev = "";
    while (!s.empty()) {
        rev += s.top();
        s.pop();
    }

    cout << "Reversed string: " << rev << endl;

    return 0;
}
