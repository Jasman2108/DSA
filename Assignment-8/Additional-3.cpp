#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Return maximum depth of the binary tree
int maxDepth(Node* root) {
    if (!root) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

// Simple demo
int main() {
    // Example tree:
    //      1
    //     / \
    //    2   3
    //   /
    //  4
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "Maximum depth of tree: " << maxDepth(root) << "\n";

    return 0;
}
