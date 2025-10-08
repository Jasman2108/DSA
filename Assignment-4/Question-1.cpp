#include <iostream>
using namespace std;

#define SIZE 5   // Maximum size of the queue

class Queue {
private:
    int arr[SIZE];  // Array to store queue elements
    int front, rear;

public:
    // Constructor
    Queue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == SIZE - 1);
    }

    // Add element to queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;    // first element being inserted
        }
        rear++;
        arr[rear] = value;
        cout << value << " enqueued successfully.\n";
    }

    // Remove element from queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Cannot dequeue.\n";
            return;
        }

        cout << arr[front] << " dequeued successfully.\n";

        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front++;
        }
    }

    // Show the front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! No element to peek.\n";
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY! Nothing to display.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    do {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is EMPTY.\n";
            else
                cout << "Queue is NOT empty.\n";
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is FULL.\n";
            else
                cout << "Queue is NOT full.\n";
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
