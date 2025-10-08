#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to get length of linked list
int getLength(Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find intersection
Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    // Move pointer of longer list ahead by difference
    Node* ptrA = headA;
    Node* ptrB = headB;

    if (lenA > lenB) {
        int diff = lenA - lenB;
        while (diff--) ptrA = ptrA->next;
    } else {
        int diff = lenB - lenA;
        while (diff--) ptrB = ptrB->next;
    }

    // Move both pointers together to find intersection
    while (ptrA && ptrB) {
        if (ptrA == ptrB) return ptrA; // intersection found
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }

    return nullptr; // no intersection
}

int main() {
    // Creating sample linked lists
    // List A: 4->1->8->5
    // List B: 5->6->1->8->5
    Node* intersect = new Node(8);
    intersect->next = new Node(5);

    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = intersect; // merge at 8

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = intersect; // merge at 8

    Node* result = getIntersectionNode(headA, headB);

    if (result)
        cout << "Intersected at " << result->data << endl;
    else
        cout << "No intersection.\n";

    return 0;
}
