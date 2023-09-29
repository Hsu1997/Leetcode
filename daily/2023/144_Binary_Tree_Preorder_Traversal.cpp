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

TreeNode* create(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(i < nodes.size() && !que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < nodes.size() && nodes[i] != -1){
            temp->left = new TreeNode(nodes[i]);
            que.push(temp->left);    
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1){
            temp->right = new TreeNode(nodes[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    vector<int> preorder = {};
    
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return preorder;
        preorder.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return preorder;
    }
};

int main(){
    vector<int> nodes = {1,-1,2,3};
    // vector<int> nodes = {1};
    // vector<int> nodes = {};
    TreeNode* root = create(nodes);
    Solution S;
    vector<int> ans = S.preorderTraversal(root);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}