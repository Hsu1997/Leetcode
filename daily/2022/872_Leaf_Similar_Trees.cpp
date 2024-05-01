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

TreeNode* create(vector<int> node){
    if (node.empty()) return nullptr;
    TreeNode* root = new TreeNode(node[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < node.size() && node[i] != -1){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
        }
        i++;
        if (i < node.size() && node[i] != -1){
            temp->right = new TreeNode(node[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    vector<int> leaf1;
    vector<int> leaf2;

    void dfs(TreeNode* root, vector<int>& leaf){
        if (!root->left && !root->right){
            // cout << root->val << " ";
            leaf.push_back(root->val);
        }
        else{
            if (root->left) dfs(root->left, leaf);
            if (root->right) dfs(root->right, leaf);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, leaf1);
        // cout << endl;
        dfs(root2, leaf2);
        // cout << endl;
        
        return leaf1 == leaf2;
    }
};

int main(){
    vector<int> node1 = {3,5,1,6,2,9,8,-1,-1,7,4};
    vector<int> node2 = {3,5,1,6,7,4,2,-1,-1,-1,-1,-1,-1,9,8};
    TreeNode* root1 = create(node1);
    TreeNode* root2 = create(node2);
    Solution S;
    cout << S.leafSimilar(root1, root2) << endl;
    return 0;
}