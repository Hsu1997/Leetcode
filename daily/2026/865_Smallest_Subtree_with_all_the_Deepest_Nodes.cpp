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
    void cntLevel(TreeNode* root, int curr, vector<int>& level){
        if (!root) return;
        level[root->val] = curr;
        cntLevel(root->left, curr + 1, level);
        cntLevel(root->right, curr + 1, level);
        return;
    }

    int dfs(TreeNode* root, int max_level, int cnt, vector<int>& level, TreeNode*& ans){
        if (!root) return 0;
        int left = dfs(root->left, max_level, cnt, level, ans);
        int right = dfs(root->right, max_level, cnt, level, ans);
        int total = ((level[root->val] == max_level)? 1 : 0) + left + right;
        if (ans != nullptr) return total;
        if (total == cnt) ans = root;
        return total;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<int> level(501, -1);
        cntLevel(root, 0, level);
        int max_level = -1;
        int cnt = 0;
        for (int l : level){
            if (l > max_level){
                max_level = l;
                cnt = 1;
            }
            else if (l == max_level) cnt++;
            else continue;
        }
        TreeNode* ans = nullptr;
        dfs(root, max_level, cnt, level, ans);
        return ans;
    }
};

int main(){
    vector<int> nodes = {3,5,1,6,2,0,8,100001,100001,7,4};
    // vector<int> nodes = {1};
    // vector<int> nodes = {0,1,3,100001,2};
    // vector<int> nodes = {3,5,1,6,2,0,8,100001,100001,7,4};
    Solution S;
    TreeNode* root = createTree(nodes);
    cout << S.subtreeWithAllDeepest(root)->val << endl;
    return 0;
}