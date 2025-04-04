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
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty() && i < n){
        TreeNode* curr = que.front();
        que.pop();
        if (i < n && nodes[i] != -1){
            curr->left = new TreeNode(nodes[i]);
            que.push(curr->left);
        }
        i++;
        if (i < n && nodes[i] != -1){
            curr->right = new TreeNode(nodes[i]);
            que.push(curr->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root, 1).first;
    }
    pair<TreeNode*, int> dfs(TreeNode* root, int depth){
        if (!root) return {nullptr, 0};
        pair<TreeNode*, int> left = dfs(root->left, depth+1);
        pair<TreeNode*, int> right = dfs(root->right, depth+1);
        if (left.second > right.second) return left;
        else if (right.second > left.second) return right;
        else return {root, max(depth,left.second)};
        return {nullptr, -1};
    }
};

int main(){
    vector<int> nodes = {3,5,1,6,2,0,8,-1,-1,7,4};
    // vector<int> nodes = {1};
    // vector<int> nodes = {0,1,3,-1,2};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.lcaDeepestLeaves(root)->val << endl;
    return 0;
}