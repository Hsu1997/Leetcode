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
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if (!temp->left && temp->right) return false;
            if (!temp->left) break;
            que.push(temp->left);
            if (!temp->right) break;
            que.push(temp->right);
        }
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if (temp->left || temp->right) return false;
        }
        return true;
    }
};

int main(){
    // vector<int> nodes = {1,2,3,4,5,6};
    vector<int> nodes = {1,2,3,4,5,-1,7};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.isCompleteTree(root) << endl;
    return 0;
}