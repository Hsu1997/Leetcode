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
    while(i < n){
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
    vector<int> ans = {};

    void dfs(TreeNode* node, int level){
        if (ans.size() <= level) ans.push_back(node->val);
        ans[level] = max(ans[level], node->val);
        if (node->left) dfs(node->left, level+1);
        if (node->right) dfs(node->right, level+1);
    }

    vector<int> largestValues(TreeNode* root) {
        if (root) dfs(root, 0);
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,3,2,5,3,-1,9};
    // vector<int> nodes = {1,2,3};
    TreeNode* root = create_tree(nodes);
    Solution S;
    vector<int> ans = S.largestValues(root);
    for (auto i : ans) cout << i <<  " ";
    cout << endl;
    return 0;
}