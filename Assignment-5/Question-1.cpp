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

    // (a) Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning.\n";
    }

    // (b) Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Inserted " << value << " at the end.\n";
    }

    // (c) Insert before or after a node
    void insertBeforeAfter(int searchVal, int newVal, bool after) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* newNode = new Node(newVal);

        // Insert before head
        if (!after && head->data == searchVal) {
            newNode->next = head;
            head = newNode;
            cout << "Inserted " << newVal << " before " << searchVal << ".\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != searchVal) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node " << searchVal << " not found.\n";
            delete newNode;
            return;
        }

        if (after) { // insert after
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << newVal << " after " << searchVal << ".\n";
        } else { // insert before
            prev->next = newNode;
            newNode->next = temp;
            cout << "Inserted " << newVal << " before " << searchVal << ".\n";
        }
    }

    // (d) Delete at beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    // (e) Delete at end
    void deleteAtEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        cout << "Deleted " << temp->data << " from end.\n";
        prev->next = nullptr;
        delete temp;
    }

    // (f) Delete specific node
    void deleteSpecific(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            cout << "Deleted node with value " << value << ".\n";
            delete temp;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;
        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << value << " not found.\n";
            return;
        }

        prev->next = temp->next;
        cout << "Deleted node with value " << value << ".\n";
        delete temp;
    }

    // (g) Search for a node and display position
    void searchNode(int value) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Node with value " << value << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node with value " << value << " not found.\n";
    }

    // (h) Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main menu
int main() {
    LinkedList list;
    int choice, value, searchVal;
    bool after;

    do {
        cout << "\n---- MENU ----\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search Node\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter node value to insert before/after: ";
            cin >> searchVal;
            cout << "Insert 1.After or 0.Before? ";
            cin >> after;
            list.insertBeforeAfter(searchVal, value, after);
            break;

        case 4:
            list.deleteAtBeginning();
            break;

        case 5:
            list.deleteAtEnd();
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteSpecific(value);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            list.searchNode(value);
            break;

        case 8:
            list.display();
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
