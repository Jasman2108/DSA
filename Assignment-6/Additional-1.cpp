#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

void pushBack(Node*& head, int d) {
    Node* n = new Node(d);
    if(!head) { head = n; n->next = head; return; }
    Node* tail = head;
    while(tail->next != head) tail = tail->next;
    tail->next = n;
    n->next = head;
}

void printCircular(Node* head) {
    if(!head) { cout << "Empty\n"; return; }
    Node* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while(cur != head);
    cout << "\n";
}

void splitList(Node* head, Node*& head1, Node*& head2) {
    head1 = nullptr;
    head2 = nullptr;
    if(!head) return;
    if(head->next == head) {
        head1 = head;
        head2 = nullptr;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next->next == head) fast = fast->next;
    head1 = head;
    head2 = slow->next;
    slow->next = head1;
    fast->next = head2;
}

int main() {
    int n, x;
    cin >> n;
    Node* head = nullptr;
    for(int i = 0; i < n; ++i) {
        cin >> x;
        pushBack(head, x);
    }
    Node* a = nullptr;
    Node* b = nullptr;
    splitList(head, a, b);
    printCircular(a);
    printCircular(b);
    return 0;
}
