#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// generate all BSTs with values in range [l, r]
vector<TreeNode*> gen(int l, int r) {
    vector<TreeNode*> res;
    if (l > r) {
        res.push_back(nullptr);
        return res;
    }
    for (int rootVal = l; rootVal <= r; ++rootVal) {
        vector<TreeNode*> leftTrees = gen(l, rootVal - 1);
        vector<TreeNode*> rightTrees = gen(rootVal + 1, r);
        for (TreeNode* L : leftTrees) {
            for (TreeNode* R : rightTrees) {
                TreeNode* root = new TreeNode(rootVal);
                root->left = L;
                root->right = R;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return {};
    return gen(1, n);
}

// serialize tree to string using preorder with null markers for easy printing
string serializePreorder(TreeNode* root) {
    if (!root) return "#";
    return to_string(root->val) + "," + serializePreorder(root->left) + "," + serializePreorder(root->right);
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n) || n < 0) return 0;

    vector<TreeNode*> trees = generateTrees(n);
    cout << "Total unique BSTs: " << trees.size() << "\n\n";

    for (size_t i = 0; i < trees.size(); ++i) {
        cout << "Tree " << i+1 << ": " << serializePreorder(trees[i]) << "\n";
    }

    // cleanup
    for (TreeNode* t : trees) deleteTree(t);

    return 0;
}
