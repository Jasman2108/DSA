#include <iostream>
#include <limits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

bool isBSTRange(Node* root, long long minA, long long maxA) {
    if (!root) return true;
    if (root->data <= minA || root->data >= maxA) return false;
    return isBSTRange(root->left, minA, root->data) &&
           isBSTRange(root->right, root->data, maxA);
}
bool isBSTRange(Node* root) {
    return isBSTRange(root,
        numeric_limits<long long>::min(),
        numeric_limits<long long>::max());
}

bool isBSTInorder(Node* root, long long &prev) {
    if (!root) return true;
    if (!isBSTInorder(root->left, prev)) return false;
    if (root->data <= prev) return false;
    prev = root->data;
    return isBSTInorder(root->right, prev);
}
bool isBSTInorder(Node* root) {
    long long prev = numeric_limits<long long>::min();
    return isBSTInorder(root, prev);
}

Node* sampleBST() {
    Node* r = new Node(50);
    r->left = new Node(30);
    r->right = new Node(70);
    r->left->left = new Node(20);
    r->left->right = new Node(40);
    r->right->left = new Node(60);
    r->right->right = new Node(80);
    return r;
}

Node* sampleNotBST() {
    Node* r = new Node(50);
    r->left = new Node(30);
    r->right = new Node(70);
    r->left->left = new Node(20);
    r->left->right = new Node(60);
    r->right->left = new Node(40);
    r->right->right = new Node(80);
    return r;
}

int main() {
    Node* bst = sampleBST();
    Node* notbst = sampleNotBST();

    cout << "Range check:\n";
    cout << (isBSTRange(bst) ? "BST" : "Not BST") << "\n";
    cout << (isBSTRange(notbst) ? "BST" : "Not BST") << "\n\n";

    cout << "Inorder check:\n";
    cout << (isBSTInorder(bst) ? "BST" : "Not BST") << "\n";
    cout << (isBSTInorder(notbst) ? "BST" : "Not BST") << "\n";

    return 0;
}
