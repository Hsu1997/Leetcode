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
    queue<TreeNode*> que;
    que.push(root);

    for (int i = 1; i < node.size(); i++){
        TreeNode* temp = que.front();
        que.pop();

        if (i < node.size() && node[i] != -1){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
        }
        i++;
        if (i < node.size() && node[i] != -1){
            temp->right = new TreeNode(node[i]);
            que.push(temp->right);
        }
    }

    return root;
}

class Solution {
public:
    int ans = 0;
    
    void dfs(TreeNode* root, int max_int){
        if (root->val >= max_int) ans++;
        
        max_int = max(max_int, root->val);
        if (root->left) dfs(root->left, max_int);
        if (root->right) dfs(root->right, max_int);
    }
    
    int goodNodes(TreeNode* root){
        dfs(root, INT_MIN);
        return ans;
    }
};

int main(){
    // vector<int> node = {3,1,4,3,-1,1,5};
    // vector<int> node = {3,3,-1,4,2};
    vector<int> node = {1};
    TreeNode* root = create(node);

    Solution S;
    cout << S.goodNodes(root) << endl;

    return 0;
}