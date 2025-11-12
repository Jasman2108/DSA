#include <iostream>
using namespace std;

struct NodeD {
    int data;
    NodeD* prev;
    NodeD* next;
    NodeD(int d): data(d), prev(nullptr), next(nullptr) {}
};

struct NodeC {
    int data;
    NodeC* next;
    NodeC(int d): data(d), next(nullptr) {}
};

int main() {
    int n, val;
    cout << "Enter number of nodes for Doubly Linked List: ";
    cin >> n;
    NodeD* headD = nullptr;
    NodeD* tailD = nullptr;
    cout << "Enter " << n << " values: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        NodeD* temp = new NodeD(val);
        if(!headD) headD = tailD = temp;
        else {
            tailD->next = temp;
            temp->prev = tailD;
            tailD = temp;
        }
    }
    int sizeD = 0;
    NodeD* curD = headD;
    while(curD) {
        sizeD++;
        curD = curD->next;
    }
    cout << "Size of Doubly Linked List: " << sizeD << "\n";

    cout << "Enter number of nodes for Circular Linked List: ";
    cin >> n;
    NodeC* headC = nullptr;
    NodeC* tailC = nullptr;
    cout << "Enter " << n << " values: ";
    for(int i = 0; i < n; i++) {
        cin >> val;
        NodeC* temp = new NodeC(val);
        if(!headC) headC = tailC = temp;
        else {
            tailC->next = temp;
            tailC = temp;
        }
    }
    if(tailC) tailC->next = headC;
    if(!headC) {
        cout << "Size of Circular Linked List: 0\n";
        return 0;
    }
    int sizeC = 0;
    NodeC* curC = headC;
    do {
        sizeC++;
        curC = curC->next;
    } while(curC != headC);
    cout << "Size of Circular Linked List: " << sizeC << "\n";
    return 0;
}
