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
    int n = node.size();
    int i = 1;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < n && node[i] != -1){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
        }
        i++;
        if (i < n && node[i] != -1){
            temp->right = new TreeNode(node[i]);
            que.push(temp->right);
        }
        i++;
    }

    return root;
}

void print_tree(TreeNode* root){
    if (!root) return;

    queue<TreeNode*> que;
    que.push(root);
    cout << root->val << " ";
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (!temp->left) cout << -1 << " ";
        else{
            cout << temp->left->val << " ";
            que.push(temp->left);
        }
        if (!temp->right) cout << -1 << " ";
        else{
            cout << temp->right->val << " ";
            que.push(temp->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (root->val == targetSum && !root->left && !root->right) return true;
        if (hasPathSum(root->left, targetSum - root->val)) return true;
        if (hasPathSum(root->right, targetSum - root->val)) return true; 
        return false;
    }
};

int main(){
    vector<int> node = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,1};
    int targetSum = 22;
    // vector<int> node = {1,2,3};
    // int targetSum = 5;
    // vector<int> node = {};
    // int targetSum = 0;
    
    TreeNode* root = create(node);
    // print_tree(root);
    Solution S;
    cout << S.hasPathSum(root, targetSum) << endl;
    return 0;
}