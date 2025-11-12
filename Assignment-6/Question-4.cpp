#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
    Node(char c): data(c), prev(nullptr), next(nullptr) {}
};

int main() {
    string s;
    getline(cin, s);
    Node* head = nullptr;
    Node* tail = nullptr;
    for(char c : s) {
        Node* n = new Node(c);
        if(!head) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    if(!head) {
        cout << "Palindrome\n";
        return 0;
    }
    Node* left = head;
    Node* right = tail;
    bool ok = true;
    while(left != right && left->prev != right) {
        if(left->data != right->data) { ok = false; break; }
        left = left->next;
        right = right->prev;
    }
    if(ok) cout << "Palindrome\n"; else cout << "Not Palindrome\n";
    return 0;
}
