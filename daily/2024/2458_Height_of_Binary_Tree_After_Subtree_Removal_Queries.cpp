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

TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    int i = 1;
    int n = nodes.size();
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
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
    int dfs(TreeNode* root, int curr_level, unordered_map<int,pair<int,int>>& m){
        // cout << "dfs" << root->val << endl;
        int under_max = 0;
        if (root->left){
            under_max = max(under_max, dfs(root->left, curr_level+1, m));
        }
        if (root->right){
            under_max = max(under_max, dfs(root->right, curr_level+1, m));
        }
        pair<int,int> curr_pair = {curr_level, under_max};
        m[root->val] = curr_pair;
        // cout << root->val << " : {" << curr_level << "," << under_max << "}" << endl;
        return under_max + 1;
    }
    void find_ans(TreeNode* node, int limit, unordered_map<int,pair<int,int>>& m, vector<int>& ans){
        int left = 0;
        if (node->left) left = max(left, m[node->left->val].first + m[node->left->val].second);
        int right = 0;
        if (node->right) right = max(right, m[node->right->val].first + m[node->right->val].second);
        if (node->left) find_ans(node->left, max(limit, right), m, ans);
        if (node->left) ans[node->left->val] = max({ans[node->left->val], limit, right});
        if (node->right) find_ans(node->right, max(limit, left), m, ans);
        if (node->right) ans[node->right->val] = max({ans[node->right->val],limit, left});
        ans[node->val] = max(ans[node->val], m[node->val].first - 1);
        return;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // val : {level, under_max}
        unordered_map<int,pair<int,int>> m;
        dfs(root, 0, m);
        // for (auto i : m) cout << i.first << " : {" << i.second.first << "," << i.second.second << "}" << endl;
        int n = m.size();
        vector<int> ans(n+1);
        find_ans(root, 0, m, ans);
        // for (auto i : ans) cout << i << " ";
        int q_m = queries.size();
        vector<int> q(q_m);
        for (int i = 0; i < q_m; i++){
            q[i] = ans[queries[i]];
        }
        return q;
    }
};

int main(){
    vector<int> nodes = {1,3,4,2,-1,6,5,-1,-1,-1,-1,-1,7};
    vector<int> queries = {4};
    // vector<int> nodes = {5,8,9,2,1,3,7,4,6};
    // vector<int> queries = {3,2,4,8};
    // vector<int> nodes = {1,-1,5,3,-1,2,4};
    // vector<int> queries = {3,5,4,2,4};
    TreeNode* root = create_tree(nodes);
    Solution S;
    vector<int> ans = S.treeQueries(root, queries);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}