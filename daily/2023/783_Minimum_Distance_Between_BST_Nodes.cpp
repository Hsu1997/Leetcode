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
    vector<int> val;

    void dfs(TreeNode* root){
        if (!root) return;
        val.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        sort(val.begin(), val.end());
        int ans = INT_MAX;
        for (int i = 0; i < val.size()-1; i++){
            ans = min(ans, abs(val[i] - val[i+1]));
        }
        return ans;
    }
};

int main(){
    // vector<int> nodes = {4,2,6,1,3};
    vector<int> nodes = {1,0,48,-1,-1,12,49};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.minDiffInBST(root)<< endl;
    return 0;
}