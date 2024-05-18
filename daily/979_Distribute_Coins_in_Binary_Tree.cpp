#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
    while(i < nodes.size() && !que.empty()){
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

    int dfs(TreeNode* root){
        if (!root) return 0;
        int net_coin = root->val - 1;
        net_coin += dfs(root->left) + dfs(root->right);
        ans += abs(net_coin);
        return net_coin;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main(){
    vector<int> nodes = {3,0,0};
    // vector<int> nodes = {0,3,0};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.distributeCoins(root) << endl;
    return 0;
}