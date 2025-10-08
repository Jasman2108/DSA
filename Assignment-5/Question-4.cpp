#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Display linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL\n";
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->next;   // store next node
            current->next = prev;   // reverse current node's pointer
            prev = current;         // move prev forward
            current = next;         // move current forward
        }

        head = prev; // new head
    }
};

int main() {
    LinkedList list;

    // Sample input: 1->2->3->4
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        list.insertAtEnd(arr[i]);

    cout << "Original Linked List: ";
    list.display();

    list.reverse();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}
