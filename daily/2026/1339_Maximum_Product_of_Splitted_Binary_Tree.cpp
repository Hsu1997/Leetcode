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

TreeNode* createTree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int idx = 1;
    while(idx < n && !que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (nodes[idx] != 100001){
            curr->left = new TreeNode(nodes[idx]);
            que.push(curr->left);
        }
        idx++;
        if (idx < n && nodes[idx] != 100001){
            curr->right = new TreeNode(nodes[idx]);
            que.push(curr->right);
        }
        idx++;
    }
    return root;
}

class Solution {
public:
    void dfsSum(TreeNode* root, long long& sum){
        if (!root) return;
        sum += root->val;
        dfsSum(root->left, sum);
        dfsSum(root->right, sum);
        return;
    }
    int dfs(TreeNode* root, long long& ans, long long sum){
        if (!root) return 0;
        int curr = root->val;
        curr += dfs(root->left, ans, sum);
        curr += dfs(root->right, ans, sum);
        ans = max(ans, curr * (sum - curr));
        return curr;
    }
    int maxProduct(TreeNode* root) {
        int mod = 1e9 + 7;
        long long ans = 0;
        long long sum = 0;
        dfsSum(root, sum);
        dfs(root, ans, sum);
        return ans % mod;
    }
};

int main(){
    vector<int> nodes = {1,2,3,4,5,6};
    // vector<int> nodes = {1,100001,2,3,4,100001,100001,5,6};
    Solution S;
    TreeNode* root = createTree(nodes);
    cout << S.maxProduct(root) << endl;
    return 0;
}