#include <iostream>
using namespace std;

#define SIZE 5   // Maximum size of the circular queue

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    // Constructor
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Add element to queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is FULL! Cannot enqueue.\n";
            return;
        }

        if (isEmpty()) {
            // first element
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

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
            // only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
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
            cq.enqueue(value);
            break;

        case 2:
            cq.dequeue();
            break;

        case 3:
            cq.peek();
            break;

        case 4:
            cq.display();
            break;

        case 5:
            if (cq.isEmpty())
                cout << "Queue is EMPTY.\n";
            else
                cout << "Queue is NOT empty.\n";
            break;

        case 6:
            if (cq.isFull())
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
