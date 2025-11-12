#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int d): data(d), prev(nullptr), next(nullptr) {}
};

Node* reverseInGroups(Node* head, int k) {
    if(!head || k <= 1) return head;
    Node* newHead = nullptr;
    Node* groupPrevTail = nullptr;
    Node* start = head;
    while(start) {
        Node* curr = start;
        int count = 0;
        while(curr && count < k) {
            curr = curr->next;
            count++;
        }
        Node* groupNext = curr;
        Node* prev = groupNext;
        curr = start;
        int i = 0;
        while(curr && i < count) {
            Node* nxt = curr->next;
            curr->next = prev;
            if(prev) prev->prev = curr;
            prev = curr;
            curr = nxt;
            i++;
        }
        Node* groupNewHead = prev;
        if(!newHead) newHead = groupNewHead;
        if(groupPrevTail) {
            groupPrevTail->next = groupNewHead;
            groupNewHead->prev = groupPrevTail;
        }
        groupPrevTail = start;
        start = groupNext;
    }
    return newHead;
}

int main() {
    int n;
    if(!(cin >> n)) return 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        Node* t = new Node(x);
        if(!head) head = tail = t;
        else {
            tail->next = t;
            t->prev = tail;
            tail = t;
        }
    }
    int k; cin >> k;
    head = reverseInGroups(head, k);
    Node* cur = head;
    while(cur) {
        cout << cur->data;
        if(cur->next) cout << " ";
        cur = cur->next;
    }
    cout << "\n";
    return 0;
}
