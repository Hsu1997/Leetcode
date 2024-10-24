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
TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int n = nodes.size();
    int i = 1;
    while(i < n){
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

void print_tree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (!curr) cout << -1 << " ";
        else{
            cout << curr->val << " ";
            que.push(curr->left);
            que.push(curr->right);
        }
    }
    return;
}

class Solution {
public:
    vector<int> level;
    vector<int> bfs(TreeNode* root){
        if (!root) return {};
        queue<TreeNode*> que;
        que.push(root);
        vector<int> level;
        while(!que.empty()){
            int k = que.size();
            int acc = 0;
            while(k--){
                TreeNode* curr = que.front();
                que.pop();
                acc += curr->val;
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            level.push_back(acc);
        }
        return level;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        level = bfs(root);
        root->val = 0;
        queue<TreeNode*> que;
        que.push(root);
        int l = 1;
        while(l < level.size()){
            int k = que.size();
            while(k--){
                TreeNode* curr = que.front();
                que.pop();
                int child = 0;
                if (curr->left) child += curr->left->val;
                if (curr->right) child += curr->right->val;
                if (curr->left){
                    curr->left->val = level[l] - child;
                    que.push(curr->left);
                }
                if (curr->right){
                    curr->right->val = level[l] - child;
                    que.push(curr->right);
                }
            }
            l++;
        }
        return root;
    }
};

int main(){
    // vector<int> nodes = {5,4,9,1,10,-1,7};
    vector<int> nodes = {3,1,2};
    TreeNode* root = create_tree(nodes);
    Solution S;
    root = S.replaceValueInTree(root);
    print_tree(root);
    return 0;
}