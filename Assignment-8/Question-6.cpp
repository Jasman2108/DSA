#include <bits/stdc++.h>
using namespace std;

// Generic priority queue implemented with a binary heap.
// Compare is the same type used by std::priority_queue:
//   - For a max-heap (largest element at top) use Compare = std::less<T> (default).
//   - For a min-heap (smallest element at top) use Compare = std::greater<T>.
template<typename T, typename Compare = std::less<T>>
class HeapPriorityQueue {
    vector<T> a;
    Compare comp;

    void siftUp(size_t idx) {
        while (idx > 0) {
            size_t parent = (idx - 1) / 2;
            // if parent has lower priority than child -> swap
            if (comp(a[parent], a[idx])) {
                swap(a[parent], a[idx]);
                idx = parent;
            } else break;
        }
    }

    void siftDown(size_t idx) {
        size_t n = a.size();
        while (true) {
            size_t left = 2*idx + 1;
            size_t right = 2*idx + 2;
            size_t best = idx;

            if (left < n && comp(a[best], a[left])) best = left;
            if (right < n && comp(a[best], a[right])) best = right;

            if (best == idx) break;
            swap(a[idx], a[best]);
            idx = best;
        }
    }

    void buildHeap() {
        if (a.empty()) return;
        for (int i = (int)a.size()/2 - 1; i >= 0; --i) siftDown(i);
    }

public:
    HeapPriorityQueue() = default;
    explicit HeapPriorityQueue(const vector<T>& vals) : a(vals) { buildHeap(); }

    void push(const T& value) {
        a.push_back(value);
        siftUp(a.size() - 1);
    }

    void pop() {
        if (a.empty()) return;
        a[0] = a.back();
        a.pop_back();
        if (!a.empty()) siftDown(0);
    }

    const T& top() const {
        if (a.empty()) throw runtime_error("top() called on empty priority queue");
        return a.front();
    }

    bool empty() const { return a.empty(); }
    size_t size() const { return a.size(); }

    // Optional: replace top with new value (pop + push optimized)
    void replaceTop(const T& value) {
        if (a.empty()) { push(value); return; }
        a[0] = value;
        siftDown(0);
    }
};

// Demo
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> values = { 15, 3, 17, 10, 84, 19, 6, 22, 9 };

    // Max-heap (default) -> top() gives largest element
    HeapPriorityQueue<int> maxPQ(values);
    cout << "Max-heap order (pop repeatedly): ";
    while (!maxPQ.empty()) {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }
    cout << "\n";

    // Min-heap -> top() gives smallest element
    HeapPriorityQueue<int, greater<int>> minPQ(values);
    cout << "Min-heap order (pop repeatedly): ";
    while (!minPQ.empty()) {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << "\n";

    // Example usage: insert and get top
    HeapPriorityQueue<int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(7);
    cout << "Current top (max): " << pq.top() << "\n"; // should be 7
    pq.pop();
    cout << "After pop, top: " << pq.top() << "\n";    // should be 5

    return 0;
}
