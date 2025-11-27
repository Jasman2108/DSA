#include <iostream>
#include <vector>
using namespace std;

// Sift-down for a max-heap (used for ascending sort)
void maxHeapify(vector<int> &a, int n, int i) {
    while (true) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

// Build max-heap
void buildMaxHeap(vector<int> &a) {
    int n = (int)a.size();
    for (int i = n/2 - 1; i >= 0; --i) maxHeapify(a, n, i);
}

// Heapsort to get ascending order (in-place)
void heapSortIncreasing(vector<int> &a) {
    buildMaxHeap(a);
    int n = (int)a.size();
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);        // move current max to end
        maxHeapify(a, i, 0);    // restore max-heap on reduced array
    }
}

// Sift-down for a min-heap (used for descending sort)
void minHeapify(vector<int> &a, int n, int i) {
    while (true) {
        int smallest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < n && a[l] < a[smallest]) smallest = l;
        if (r < n && a[r] < a[smallest]) smallest = r;
        if (smallest == i) break;
        swap(a[i], a[smallest]);
        i = smallest;
    }
}

// Build min-heap
void buildMinHeap(vector<int> &a) {
    int n = (int)a.size();
    for (int i = n/2 - 1; i >= 0; --i) minHeapify(a, n, i);
}

// Heapsort to get descending order (in-place)
void heapSortDecreasing(vector<int> &a) {
    buildMinHeap(a);
    int n = (int)a.size();
    for (int i = n - 1; i > 0; --i) {
        swap(a[0], a[i]);        // move current min to end
        minHeapify(a, i, 0);    // restore min-heap on reduced array
    }
}

void printArray(const vector<int> &a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    if (!(cin >> n) || n <= 0) return 0;
    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << "\nOriginal array: ";
    printArray(a);

    vector<int> b = a; // copy for second sort

    heapSortIncreasing(a);
    cout << "Sorted (increasing): ";
    printArray(a);

    heapSortDecreasing(b);
    cout << "Sorted (decreasing): ";
    printArray(b);

    return 0;
}
