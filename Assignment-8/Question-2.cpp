#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

//  BST INSERT (iterative)
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    Node* parent = nullptr;
    Node* cur = root;
    while (cur) {
        parent = cur;
        if (key < cur->data) cur = cur->left;
        else if (key > cur->data) cur = cur->right;
        else return root; // duplicate, do nothing
    }

    if (key < parent->data) parent->left = new Node(key);
    else parent->right = new Node(key);

    return root;
}

//  (a) SEARCH - Recursive
Node* searchRecursive(Node* root, int key) {
    if (!root) return nullptr;
    if (root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) SEARCH - Iterative 
Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->data == key) return cur;
        if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

//  (b) MINIMUM 
Node* findMin(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}

// (c) MAXIMUM 
Node* findMax(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur;
}

// (d) INORDER SUCCESSOR of key 
Node* inorderSuccessor(Node* root, int key) {
    // find the node first
    Node* target = searchIterative(root, key);
    if (!target) return nullptr;

    // Case 1: right subtree exists
    if (target->right) return findMin(target->right);

    // Case 2: no right subtree -> search from root for the lowest ancestor
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->data) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->data) {
            cur = cur->right;
        } else break; // reached target
    }
    return succ;
}

// (e) INORDER PREDECESSOR of key 

Node* inorderPredecessor(Node* root, int key) {
    Node* target = searchIterative(root, key);
    if (!target) return nullptr;

    if (target->left) return findMax(target->left);

    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->data) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->data) {
            cur = cur->left;
        } else break;
    }
    return pred;
}

//  UTILITY: INORDER PRINT 
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

//  DEMO in main
int main() {
    /* Build a BST:
           50
         /    \
       30      70
      /  \    /  \
     20  40  60  80
    */
    Node* root = nullptr;
    int vals[] = {50, 30, 20, 40, 70, 60, 80};
    for (int v : vals) root = insertNode(root, v);

    cout << "BST (inorder): ";
    inorderPrint(root);
    cout << "\n\n";

    // (a) Search
    int keysToSearch[] = {40, 100};
    for (int k : keysToSearch) {
        Node* r1 = searchRecursive(root, k);
        cout << "Recursive search " << k << ": " << (r1 ? "Found" : "Not Found") << "\n";
        Node* r2 = searchIterative(root, k);
        cout << "Iterative search " << k << ": " << (r2 ? "Found" : "Not Found") << "\n";
    }
    cout << "\n";

    // (b) Maximum
    Node* mx = findMax(root);
    if (mx) cout << "Maximum in BST: " << mx->data << "\n";

    // (c) Minimum
    Node* mn = findMin(root);
    if (mn) cout << "Minimum in BST: " << mn->data << "\n";

    cout << "\n";

    // (d) Inorder successor
    int keysSucc[] = {50, 30, 80}; // 50 -> 60, 30 -> 40, 80 -> none
    for (int k : keysSucc) {
        Node* s = inorderSuccessor(root, k);
        cout << "Successor of " << k << ": " << (s ? to_string(s->data) : string("None")) << "\n";
    }
    cout << "\n";

    // (e) Inorder predecessor
    int keysPred[] = {50, 30, 20}; // 50 -> 40, 30 -> 20, 20 -> none
    for (int k : keysPred) {
        Node* p = inorderPredecessor(root, k);
        cout << "Predecessor of " << k << ": " << (p ? to_string(p->data) : string("None")) << "\n";
    }

    return 0;
}
