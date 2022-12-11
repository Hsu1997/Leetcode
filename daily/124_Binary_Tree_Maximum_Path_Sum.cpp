#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;

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
    unordered_map<TreeNode*,int> m;

    void dp(TreeNode* node){
        if (!node->left && !node->right) m[node] = node->val;
        else{
            if (node->left) dp(node->left);
            if (node->right) dp(node->right);
            m[node] = max({0, m[node->left], m[node->right]}) + node->val;
        }
    }

    int maxPathSum(TreeNode* root) {
        m[nullptr] = 0;
        dp(root);
        // for (auto i : m) cout << i.first << " : " << i.second << endl;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
            ans = max(ans, temp->val + max(0,m[temp->left]) + max(0,m[temp->right]));
        }
        return ans;
    }
};

int main(){
    // vector<int> nodes = {-10,9,20,-1,-1,15,7};
    // vector<int> nodes = {1,2,3};
    vector<int> nodes = {9,6,-3,-1,-1,-6,2,-1,-1,2,-1,-6,-6,-6};
    TreeNode* root = create(nodes);
    Solution S;
    cout << S.maxPathSum(root) << endl;
    return 0;
}