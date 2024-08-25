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

TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    int n = nodes.size();
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
    void traversal(TreeNode* root, vector<int>& postorder){
        if (!root) return;
        traversal(root->left, postorder);
        traversal(root->right, postorder);
        postorder.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        traversal(root, postorder);
        return postorder;
    }
};

int main(){
    vector<int> nodes = {1,-1,2,3};
    // vector<int> nodes = {};
    // vector<int> nodes = {1};
    TreeNode* root = create_tree(nodes);
    Solution S;
    vector<int> ans = S.postorderTraversal(root);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}