#include <iostream>
#include <climits>
#include <queue>
using namespace std;

// Function to get index of minimum element in first 'sortedIndex' elements
int minIndex(queue<int> &q, int sortedIndex) {
    int min_index = -1;
    int min_value = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        // find minimum in unsorted part
        if (curr <= min_value && i <= sortedIndex) {
            min_value = curr;
            min_index = i;
        }

        q.push(curr);
    }
    return min_index;
}

// Function to move minimum element at min_index to rear
void insertMinToRear(queue<int> &q, int min_index) {
    int min_value;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i == min_index) {
            min_value = curr; // skip pushing min element now
        } else {
            q.push(curr);
        }
    }

    q.push(min_value);
}

// Function to sort queue
void sortQueue(queue<int> &q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;

    // Sample Input
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
