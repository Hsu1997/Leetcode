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
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty() && i < nodes.size()){
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
    int ans = 0;

    void dfs(TreeNode* root, int depth){
        if (!root) return;
        ans = max(ans, depth);
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
        return;
    }

    int maxDepth(TreeNode* root) {
        dfs(root,1);
        return ans;
    }
};

int main(){
    vector<int> nodes = {3,9,20,-1,-1,15,7};
    // vector<int> nodes = {1,-1,2};
    // vector<int> nodes = {};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.maxDepth(root) << endl;
    return 0;
}