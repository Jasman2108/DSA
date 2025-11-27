#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

//  (a) INSERT (no duplicates) - recursive
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->data) {
        root->left = insertNode(root->left, key);
    } else if (key > root->data) {
        root->right = insertNode(root->right, key);
    } // if equal, do nothing (no duplicates)

    return root;
}

// Utility: find minimum node in a subtree
Node* findMinNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// (b) DELETE an element - recursive
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // found node to delete
        if (!root->left && !root->right) {
            // no child
            delete root;
            return nullptr;
        } else if (!root->left) {
            // only right child
            Node* tmp = root->right;
            delete root;
            return tmp;
        } else if (!root->right) {
            // only left child
            Node* tmp = root->left;
            delete root;
            return tmp;
        } else {
            // two children: replace with inorder successor (min in right subtree)
            Node* succ = findMinNode(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}

// (c) MAXIMUM DEPTH (height) 
int maxDepth(Node* root) {
    if (!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

//(d) MINIMUM DEPTH 
// Minimum number of nodes from root down to the nearest leaf.
// Careful: if one child is null, we must ignore that branch.
int minDepth(Node* root) {
    if (!root) return 0;

    // If left is NULL, recur for right
    if (!root->left) return 1 + minDepth(root->right);

    // If right is NULL, recur for left
    if (!root->right) return 1 + minDepth(root->left);

    // If both children exist, take the minimum
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Utility: inorder print 
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

//  Demo / simple menu 
int main() {
    Node* root = nullptr;

    // Sample insertions
    int vals[] = {50, 30, 20, 40, 70, 60, 80};
    for (int v : vals) root = insertNode(root, v);

    cout << "BST (inorder): ";
    inorderPrint(root);
    cout << "\n";

    cout << "Max depth (height): " << maxDepth(root) << "\n";
    cout << "Min depth: " << minDepth(root) << "\n\n";

    // Demonstrate delete cases
    cout << "Deleting 20 (leaf)\n";
    root = deleteNode(root, 20);
    cout << "Inorder now: "; inorderPrint(root); cout << "\n";

    cout << "Deleting 30 (node with one/two children)\n";
    root = deleteNode(root, 30);
    cout << "Inorder now: "; inorderPrint(root); cout << "\n";

    cout << "Deleting 50 (root with two children)\n";
    root = deleteNode(root, 50);
    cout << "Inorder now: "; inorderPrint(root); cout << "\n";

    cout << "\nFinal Max depth: " << maxDepth(root) << "\n";
    cout << "Final Min depth: " << minDepth(root) << "\n";

    return 0;
}
