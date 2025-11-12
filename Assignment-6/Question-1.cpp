#include <iostream>
#include <limits>
using namespace std;

struct NodeS {
    int data;
    NodeS* next;
    NodeS(int d): data(d), next(nullptr) {}
};

struct NodeD {
    int data;
    NodeD* prev;
    NodeD* next;
    NodeD(int d): data(d), prev(nullptr), next(nullptr) {}
};

class CircularList {
    NodeS* tail;
public:
    CircularList(): tail(nullptr) {}
    void display() {
        if(!tail) { cout << "Empty\n"; return; }
        NodeS* cur = tail->next;
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while(cur != tail->next);
        cout << "\n";
    }
    void insertFirst(int val) {
        NodeS* n = new NodeS(val);
        if(!tail) {
            tail = n;
            tail->next = tail;
        } else {
            n->next = tail->next;
            tail->next = n;
        }
    }
    void insertLast(int val) {
        insertFirst(val);
        tail = tail->next;
    }
    void insertAfter(int key, int val) {
        if(!tail) { cout << "List empty\n"; return; }
        NodeS* cur = tail->next;
        do {
            if(cur->data == key) {
                NodeS* n = new NodeS(val);
                n->next = cur->next;
                cur->next = n;
                if(cur == tail) tail = n;
                cout << "Inserted\n";
                return;
            }
            cur = cur->next;
        } while(cur != tail->next);
        cout << "Key not found\n";
    }
    void insertBefore(int key, int val) {
        if(!tail) { cout << "List empty\n"; return; }
        NodeS* head = tail->next;
        if(head->data == key) {
            insertFirst(val);
            return;
        }
        NodeS* prev = head;
        NodeS* cur = head->next;
        while(cur != head) {
            if(cur->data == key) {
                NodeS* n = new NodeS(val);
                prev->next = n;
                n->next = cur;
                cout << "Inserted\n";
                return;
            }
            prev = cur;
            cur = cur->next;
        }
        cout << "Key not found\n";
    }
    void deleteValue(int key) {
        if(!tail) { cout << "Empty\n"; return; }
        NodeS* head = tail->next;
        NodeS* cur = head;
        NodeS* prev = tail;
        do {
            if(cur->data == key) {
                if(cur == tail && cur == head) {
                    delete cur;
                    tail = nullptr;
                    cout << "Deleted\n";
                    return;
                }
                prev->next = cur->next;
                if(cur == tail) tail = prev;
                delete cur;
                cout << "Deleted\n";
                return;
            }
            prev = cur;
            cur = cur->next;
        } while(cur != head);
        cout << "Not found\n";
    }
    void searchValue(int key) {
        if(!tail) { cout << "Empty\n"; return; }
        NodeS* cur = tail->next;
        int pos = 1;
        bool found = false;
        do {
            if(cur->data == key) {
                cout << "Found at position " << pos << "\n";
                found = true;
            }
            cur = cur->next;
            pos++;
        } while(cur != tail->next);
        if(!found) cout << "Not found\n";
    }
};

class DoublyList {
    NodeD* head;
public:
    DoublyList(): head(nullptr) {}
    void display() {
        if(!head) { cout << "Empty\n"; return; }
        NodeD* cur = head;
        while(cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
    void insertFirst(int val) {
        NodeD* n = new NodeD(val);
        if(!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }
    void insertLast(int val) {
        NodeD* n = new NodeD(val);
        if(!head) { head = n; return; }
        NodeD* cur = head;
        while(cur->next) cur = cur->next;
        cur->next = n;
        n->prev = cur;
    }
    void insertAfter(int key, int val) {
        if(!head) { cout << "Empty\n"; return; }
        NodeD* cur = head;
        while(cur) {
            if(cur->data == key) {
                NodeD* n = new NodeD(val);
                n->next = cur->next;
                n->prev = cur;
                if(cur->next) cur->next->prev = n;
                cur->next = n;
                cout << "Inserted\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Key not found\n";
    }
    void insertBefore(int key, int val) {
        if(!head) { cout << "Empty\n"; return; }
        NodeD* cur = head;
        while(cur) {
            if(cur->data == key) {
                NodeD* n = new NodeD(val);
                n->next = cur;
                n->prev = cur->prev;
                if(cur->prev) cur->prev->next = n;
                cur->prev = n;
                if(cur == head) head = n;
                cout << "Inserted\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Key not found\n";
    }
    void deleteValue(int key) {
        if(!head) { cout << "Empty\n"; return; }
        NodeD* cur = head;
        while(cur) {
            if(cur->data == key) {
                if(cur->prev) cur->prev->next = cur->next;
                else head = cur->next;
                if(cur->next) cur->next->prev = cur->prev;
                delete cur;
                cout << "Deleted\n";
                return;
            }
            cur = cur->next;
        }
        cout << "Not found\n";
    }
    void searchValue(int key) {
        if(!head) { cout << "Empty\n"; return; }
        NodeD* cur = head;
        int pos = 1;
        bool found = false;
        while(cur) {
            if(cur->data == key) {
                cout << "Found at position " << pos << "\n";
                found = true;
            }
            cur = cur->next;
            pos++;
        }
        if(!found) cout << "Not found\n";
    }
};

int chooseInt() {
    int x;
    while(!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter number: ";
    }
    return x;
}

int main() {
    CircularList cl;
    DoublyList dl;
    while(true) {
        cout << "\n1. Use Circular List\n2. Use Doubly List\n3. Exit\nChoose: ";
        int mainChoice = chooseInt();
        if(mainChoice == 3) break;
        if(mainChoice == 1) {
            while(true) {
                cout << "\n-- Circular List Menu --\n";
                cout << "1. Display\n2. Insert as First\n3. Insert as Last\n4. Insert After a Value\n5. Insert Before a Value\n6. Delete a Value\n7. Search a Value\n8. Back\nChoose: ";
                int c = chooseInt();
                if(c == 8) break;
                int val, key;
                switch(c) {
                    case 1: cl.display(); break;
                    case 2:
                        cout << "Enter value: "; val = chooseInt();
                        cl.insertFirst(val);
                        break;
                    case 3:
                        cout << "Enter value: "; val = chooseInt();
                        cl.insertLast(val);
                        break;
                    case 4:
                        cout << "Enter key to insert after: "; key = chooseInt();
                        cout << "Enter value: "; val = chooseInt();
                        cl.insertAfter(key, val);
                        break;
                    case 5:
                        cout << "Enter key to insert before: "; key = chooseInt();
                        cout << "Enter value: "; val = chooseInt();
                        cl.insertBefore(key, val);
                        break;
                    case 6:
                        cout << "Enter value to delete: "; key = chooseInt();
                        cl.deleteValue(key);
                        break;
                    case 7:
                        cout << "Enter value to search: "; key = chooseInt();
                        cl.searchValue(key);
                        break;
                    default: cout << "Invalid\n";
                }
            }
        } else if(mainChoice == 2) {
            while(true) {
                cout << "\n-- Doubly List Menu --\n";
                cout << "1. Display\n2. Insert as First\n3. Insert as Last\n4. Insert After a Value\n5. Insert Before a Value\n6. Delete a Value\n7. Search a Value\n8. Back\nChoose: ";
                int c = chooseInt();
                if(c == 8) break;
                int val, key;
                switch(c) {
                    case 1: dl.display(); break;
                    case 2:
                        cout << "Enter value: "; val = chooseInt();
                        dl.insertFirst(val);
                        break;
                    case 3:
                        cout << "Enter value: "; val = chooseInt();
                        dl.insertLast(val);
                        break;
                    case 4:
                        cout << "Enter key to insert after: "; key = chooseInt();
                        cout << "Enter value: "; val = chooseInt();
                        dl.insertAfter(key, val);
                        break;
                    case 5:
                        cout << "Enter key to insert before: "; key = chooseInt();
                        cout << "Enter value: "; val = chooseInt();
                        dl.insertBefore(key, val);
                        break;
                    case 6:
                        cout << "Enter value to delete: "; key = chooseInt();
                        dl.deleteValue(key);
                        break;
                    case 7:
                        cout << "Enter value to search: "; key = chooseInt();
                        dl.searchValue(key);
                        break;
                    default: cout << "Invalid\n";
                }
            }
        } else {
            cout << "Invalid\n";
        }
    }
    return 0;
}
