#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* up;
    Node* down;
    Node(int v): data(v), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

int main() {
    int r, c;
    if(!(cin >> r >> c)) return 0;
    vector<vector<Node*>> g(r, vector<Node*>(c, nullptr));
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            int x; cin >> x;
            g[i][j] = new Node(x);
        }
    }
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            if(j+1 < c) g[i][j]->next = g[i][j+1];
            if(j-1 >= 0) g[i][j]->prev = g[i][j-1];
            if(i-1 >= 0) g[i][j]->up = g[i-1][j];
            if(i+1 < r) g[i][j]->down = g[i+1][j];
        }
    }

    cout << "Row-wise (using next):\n";
    for(int i = 0; i < r; ++i) {
        Node* cur = g[i][0];
        while(cur) {
            cout << cur->data;
            if(cur->next) cout << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    cout << "Column-wise (using down):\n";
    for(int j = 0; j < c; ++j) {
        Node* cur = g[0][j];
        while(cur) {
            cout << cur->data;
            if(cur->down) cout << " ";
            cur = cur->down;
        }
        cout << "\n";
    }

    for(int i = 0; i < r; ++i)
        for(int j = 0; j < c; ++j)
            delete g[i][j];

    return 0;
}
