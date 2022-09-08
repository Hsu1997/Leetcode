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

    while(i < node.size()){
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
    vector<int> ans;
    
    void dfs(TreeNode* root){
        if (root == nullptr) return;

        if (root->left) dfs(root->left);
        ans.push_back(root->val);
        if (root->right) dfs(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main(){
    vector<int> node = {1,-1,2,3};
    TreeNode* root = create(node);
    Solution S;
    vector<int> ans = S.inorderTraversal(root);
    for (auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}