#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d): data(d), prev(nullptr), next(nullptr) {}
};

struct CNode {
    int data;
    CNode* next;
    CNode(int d): data(d), next(nullptr) {}
};

void printD(DNode* head) {
    if(!head) { cout << "Empty\n"; return; }
    DNode* cur = head;
    while(cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void printC(CNode* head) {
    if(!head) { cout << "Empty\n"; return; }
    CNode* cur = head;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while(cur != head);
    cout << "\n";
}

void removeEvenD(DNode*& head) {
    DNode* cur = head;
    while(cur) {
        if(cur->data % 2 == 0) {
            DNode* del = cur;
            if(cur->prev) cur->prev->next = cur->next;
            else head = cur->next;
            if(cur->next) cur->next->prev = cur->prev;
            cur = cur->next;
            delete del;
        } else cur = cur->next;
    }
}

void removeEvenC(CNode*& head) {
    if(!head) return;
    CNode* cur = head;
    CNode* prev = nullptr;
    bool allEven = true;
    do {
        if(cur->data % 2 != 0) allEven = false;
        cur = cur->next;
    } while(cur != head);
    if(allEven) { head = nullptr; return; }
    while(head && head->data % 2 == 0) {
        CNode* temp = head;
        CNode* tail = head;
        while(tail->next != head) tail = tail->next;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    if(!head) return;
    prev = head;
    cur = head->next;
    while(cur != head) {
        if(cur->data % 2 == 0) {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
}

int main() {
    int n, x;
    cout << "Enter number of nodes: ";
    cin >> n;
    DNode* dh = nullptr;
    DNode* dt = nullptr;
    cout << "Enter " << n << " values for Doubly Linked List: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        DNode* t = new DNode(x);
        if(!dh) dh = dt = t;
        else {
            dt->next = t;
            t->prev = dt;
            dt = t;
        }
    }
    CNode* ch = nullptr;
    CNode* ct = nullptr;
    cout << "Enter " << n << " values for Circular Linked List: ";
    for(int i = 0; i < n; i++) {
        cin >> x;
        CNode* t = new CNode(x);
        if(!ch) ch = ct = t;
        else {
            ct->next = t;
            ct = t;
        }
    }
    if(ct) ct->next = ch;
    removeEvenD(dh);
    removeEvenC(ch);
    cout << "Doubly Linked List after removing even nodes:\n";
    printD(dh);
    cout << "Circular Linked List after removing even nodes:\n";
    printC(ch);
    return 0;
}
