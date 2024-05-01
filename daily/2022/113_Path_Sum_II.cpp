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
    int n = 1;
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (n < node.size() && node[n] != -1){
            temp->left = new TreeNode(node[n]);
            que.push(temp->left);
        }
        n++;
        if (n < node.size() && node[n] != -1){
            temp->right = new TreeNode(node[n]);
            que.push(temp->right);
        }
        n++;
    }

    return root;
}

class Solution {
public:
    vector<int> path;
    int sum = 0;
    int target;
    vector<vector<int>> ans;

    void dfs(TreeNode* node){
        path.push_back(node->val);
        sum += node->val;
        if (!node->left && !node->right){
            if (sum == target) ans.push_back(path);
        }
        else{
            if (node->left) dfs(node->left);
            if (node->right) dfs(node->right);
        }
        path.pop_back();
        sum -= node->val;
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return ans;
        target = targetSum;
        dfs(root);
        return ans;
    }
};

int main(){
    vector<int> node = {5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    int targetSum = 22;
    // vector<int> node = {1,2,3};
    // int targetSum = 5;
    // vector<int> node = {1,2};
    // int targetSum = 0;

    TreeNode* root = create(node);
    Solution S;
    vector<vector<int>> ans = S.pathSum(root, targetSum);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}