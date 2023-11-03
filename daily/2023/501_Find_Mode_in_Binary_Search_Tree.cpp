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

TreeNode* create_tree(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(i < n && !que.empty()){
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
    int max_freq = 0;
    vector<int> ans;
    unordered_map<int,int> m;

    void dfs(TreeNode* node){
        if (!node) return;
        m[node->val]++;
        if (m[node->val] > max_freq) max_freq = m[node->val], ans.clear();
        if (m[node->val] == max_freq) ans.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
        return;
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main(){
    // vector<int> nodes = {1,-1,2,2};
    vector<int> nodes = {0};
    TreeNode* root = create_tree(nodes);
    Solution S;
    vector<int> ans = S.findMode(root);
    for (auto i : ans) cout << i <<  " ";
    cout << endl;
    return 0;
}