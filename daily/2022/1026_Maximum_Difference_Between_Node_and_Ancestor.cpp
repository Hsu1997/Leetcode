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
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
    while(i < nodes.size()){
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
    int ans = numeric_limits<int>::min();

    void dfs(TreeNode* node, int M, int m){
        if (abs(node->val - M) > ans) ans = abs(node->val - M);
        if (abs(node->val - m) > ans) ans = abs(node->val - m);
        if (node->val < m) m = node->val;
        if (node->val > M) M = node->val;
        if (node->left) dfs(node->left, M, m);
        if (node->right) dfs(node->right, M, m);
    }

    int maxAncestorDiff(TreeNode* root) {
        if (root->left) dfs(root->left, root->val, root->val);
        if (root->right) dfs(root->right, root->val, root->val);
        return ans;
    }
};

int main(){
    vector<int> nodes = {8,3,10,1,6,-1,14,-1,-1,4,7,13};
    // vector<int> nodes = {1,-1,2,-1,0,3};
    TreeNode* root = create(nodes);
    Solution S;
    cout << S.maxAncestorDiff(root) << endl;
    return 0;
}