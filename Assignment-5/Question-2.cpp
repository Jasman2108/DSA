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

    // Function to insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Count occurrences of a key
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }

    // Delete all occurrences of a key
    void deleteAllOccurrences(int key) {
        // Delete from beginning if needed
        while (head != nullptr && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == key) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else {
                prev = current;
                current = current->next;
            }
        }
    }

    // Display linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    // Sample input: 1->2->1->2->1->3->1
    int arr[] = {1, 2, 1, 2, 1, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        list.insertAtEnd(arr[i]);
    }

    int key = 1;
    cout << "Original Linked List: ";
    list.display();

    int count = list.countOccurrences(key);
    cout << "Count of " << key << ": " << count << endl;

    list.deleteAllOccurrences(key);
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
