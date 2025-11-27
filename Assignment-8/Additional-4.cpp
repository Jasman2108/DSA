#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Return the right view of the binary tree
vector<int> rightView(Node* root) {
    vector<int> result;
    if (!root) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        Node* node = nullptr;

        for (int i = 0; i < size; i++) {
            node = q.front();
            q.pop();

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(node->val); // last node of this level
    }

    return result;
}

int main() {
    // Example tree:
    //        1
    //      /   \
    //     2     3
    //      \     \
    //       5     4
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(4);

    vector<int> view = rightView(root);

    cout << "Right view: ";
    for (int x : view) cout << x << " ";
    cout << "\n";

    return 0;
}
