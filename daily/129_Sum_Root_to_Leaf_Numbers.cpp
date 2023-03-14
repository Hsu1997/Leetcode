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
    int n = nodes.size();
    if (n < 1) return nullptr;
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
    int ans = 0;

    void dfs(TreeNode* node, int acc){
        acc = acc * 10 + node->val;
        if (!node->left && !node->right){
            // cout << acc << endl;
            ans += acc;
        }
        else{
            if (node->left) dfs(node->left, acc);
            if (node->right) dfs(node->right, acc);
        }
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};

int main(){
    // vector<int> nodes = {1,2,3};
    vector<int> nodes = {4,9,0,5,1};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.sumNumbers(root) << endl;
    return 0;
}