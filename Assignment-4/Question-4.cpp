#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string s) {
    queue<char> q;
    int freq[26] = {0};   // to count occurrences of each character (a-z)

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        // Increase frequency of this character
        freq[ch - 'a']++;

        // Push into queue
        q.push(ch);

        // Remove characters from front of queue which are repeating
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // Check the front
        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter characters (no spaces): ";
    cin >> input;

    cout << "First non-repeating sequence: ";
    firstNonRepeating(input);

    return 0;
}
