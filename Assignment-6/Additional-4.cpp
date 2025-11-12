#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node* random;
    Node(int d): data(d), prev(nullptr), next(nullptr), random(nullptr) {}
};

int main() {
    int n;
    if(!(cin >> n)) return 0;
    vector<int> vals(n);
    for(int i = 0; i < n; ++i) cin >> vals[i];
    vector<int> randIdx(n);
    for(int i = 0; i < n; ++i) cin >> randIdx[i];
    int k;
    cin >> k;

    vector<Node*> nodes(n);
    for(int i = 0; i < n; ++i) nodes[i] = new Node(vals[i]);
    for(int i = 0; i < n; ++i) {
        if(i > 0) { nodes[i]->prev = nodes[i-1]; nodes[i-1]->next = nodes[i]; }
    }
    for(int i = 0; i < n; ++i) {
        if(randIdx[i] == -1) nodes[i]->random = nullptr;
        else if(randIdx[i] >= 0 && randIdx[i] < n) nodes[i]->random = nodes[randIdx[i]];
        else nodes[i]->random = nullptr;
    }

    auto expectedIndex = [&](int i)->int {
        int ei = i + k;
        if(ei < 0 || ei >= n) return -1;
        return ei;
    };

    int wrongCount = 0;
    int wrongPos = -1;
    for(int i = 0; i < n; ++i) {
        int ei = expectedIndex(i);
        Node* expNode = (ei == -1) ? nullptr : nodes[ei];
        if(nodes[i]->random != expNode) {
            wrongCount++;
            wrongPos = i;
        }
    }

    if(wrongCount == 0) {
        cout << "All random pointers are correct\n";
    } else {
        cout << "Mismatches found: " << wrongCount << "\n";
        if(wrongPos != -1) {
            int ei = expectedIndex(wrongPos);
            nodes[wrongPos]->random = (ei == -1) ? nullptr : nodes[ei];
            cout << "Fixed node at index " << wrongPos << " to point to ";
            if(ei == -1) cout << "NULL\n"; else cout << "index " << ei << " (value " << nodes[ei]->data << ")\n";
        }
    }

    cout << "Final random mapping (index -> random_index or -1):\n";
    for(int i = 0; i < n; ++i) {
        int r = -1;
        for(int j = 0; j < n; ++j) if(nodes[i]->random == nodes[j]) { r = j; break; }
        cout << i << " -> " << r << "\n";
    }

    for(Node* p : nodes) delete p;
    return 0;
}
