#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    if(n <= 0) {
        cout << "Not Circular\n";
        return 0;
    }
    cout << "Enter " << n << " values: ";
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < n; i++) {
        cin >> val;
        Node* temp = new Node(val);
        if(!head) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }
    cout << "Make it circular? (1 for Yes / 0 for No): ";
    int ch;
    cin >> ch;
    if(ch == 1) tail->next = head;

    Node* slow = head;
    Node* fast = head;
    bool isCircular = false;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            isCircular = true;
            break;
        }
    }
    if(isCircular) cout << "Circular Linked List\n";
    else cout << "Not Circular\n";
    return 0;
}
