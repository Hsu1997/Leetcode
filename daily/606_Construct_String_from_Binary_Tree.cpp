#include <iostream>
#include <vector>
#include <queue>
#include <string>

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
    string preorder;

    void dfs(TreeNode* root){
        if (root == nullptr ) return;
        preorder += to_string(root->val);

        if (root->left == nullptr && root->right == nullptr) return;

        preorder += "(";
        dfs(root->left);
        preorder += ")";

        if (root->right){
            preorder += "(";
            dfs(root->right);
            preorder += ")";
        }
    }

    string tree2str(TreeNode* root) {
        dfs(root);
        return preorder;
    }
};

int main(){
    vector<int> node = {1,2,3,-1,4};
    TreeNode* root = create(node);
    Solution S;
    cout << S.tree2str(root) << endl;
    return 0;
}