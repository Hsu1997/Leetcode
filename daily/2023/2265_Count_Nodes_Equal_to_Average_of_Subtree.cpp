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
    int count = 0;
    pair<int,int> dfs(TreeNode* root){
        if (!root) return {0,0};
        pair<int,int> l = dfs(root->left);
        pair<int,int> r = dfs(root->right);
        pair<int,int> ans = {l.first + r.first + root->val, l.second + r.second + 1};
        if (ans.first / ans.second == root->val) count++;
        return ans;
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};

int main(){
    // vector<int> nodes = {4,8,5,0,1,-1,6};
    vector<int> nodes = {1};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.averageOfSubtree(root) << endl;
    return 0;
}