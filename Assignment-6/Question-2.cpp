#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

int main() {
    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    if(n <= 0) return 0;
    cout << "Enter " << n << " values: ";
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i++) {
        cin >> val;
        Node* temp = new Node(val);
        if(!head) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    tail->next = head;
    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while(cur != head);
    cout << head->data << "\n";
    return 0;
}
