#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Recursive solution
int sumOfLeftLeavesRec(Node* root) {
    if (!root) return 0;
    int sum = 0;
    if (root->left) {
        if (!root->left->left && !root->left->right) // left child is a leaf
            sum += root->left->val;
        else
            sum += sumOfLeftLeavesRec(root->left);
    }
    sum += sumOfLeftLeavesRec(root->right);
    return sum;
}

// Iterative solution (stack)
int sumOfLeftLeavesIter(Node* root) {
    if (!root) return 0;
    int sum = 0;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
        Node* cur = st.top(); st.pop();
        if (cur->left) {
            if (!cur->left->left && !cur->left->right) sum += cur->left->val;
            else st.push(cur->left);
        }
        if (cur->right) st.push(cur->right);
    }
    return sum;
}

// small demo
int main() {
    // Build this tree:
    //      3
    //     / \
    //    9  20
    //      /  \
    //     15   7
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Recursive sum of left leaves: " << sumOfLeftLeavesRec(root) << "\n"; // expects 24 (9 + 15)
    cout << "Iterative sum of left leaves: " << sumOfLeftLeavesIter(root) << "\n";

    return 0;
}
