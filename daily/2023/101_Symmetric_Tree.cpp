#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* create_tree(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(i < n && !que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < n && nodes[i] != -1){
            temp->left = new TreeNode(nodes[i]);
            que.push(temp->left);
        }
        i++;
        if (i < n && nodes[i] != -1){
            temp->right = new TreeNode(nodes[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    bool compare(TreeNode* left_tree, TreeNode* right_tree){
        if (left_tree == nullptr && right_tree == nullptr) return true;
        if (!left_tree || !right_tree || left_tree->val != right_tree->val) return false;
        return compare(left_tree->left, right_tree->right) && compare(left_tree->right, right_tree->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right) return true;
        return compare(root->left, root->right);
    }
};

int main(){
    vector<int> nodes = {1,2,2,3,4,4,3};
    // vector<int> nodes = {1,2,2,-1,3,-1,3};
    // vector<int> nodes = {5,4,1,-1,1,-1,4,2,-1,2,-1};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.isSymmetric(root) << endl;
    return 0;
}
