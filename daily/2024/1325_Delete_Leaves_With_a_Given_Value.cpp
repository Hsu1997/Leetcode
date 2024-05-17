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
    int n = 1;
    queue<TreeNode*> que;
    que.push(root);
    while(n < nodes.size() && !que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (n < nodes.size() && nodes[n] != -1){
            temp->left = new TreeNode(nodes[n]);
            que.push(temp->left);
        }
        n++;
        if (n < nodes.size() && nodes[n] != -1){
            temp->right = new TreeNode(nodes[n]);
            que.push(temp->right);
        }
        n++;
    }
    return root;
}

void print_tree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp){
            cout << temp->val << " ";
            que.push(temp->left);
            que.push(temp->right);
        }
        else{
            cout << -1 << " ";
        }
    }
    cout << endl;
    return;
}

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root->left) root->left = removeLeafNodes(root->left, target);
        if (root->right) root->right = removeLeafNodes(root->right, target);
        if (!root->left && !root->right && root->val == target) return nullptr;
        return root;
    }
};

int main(){
    vector<int> nodes = {1,2,3,2,-1,2,4};
    int target = 2;
    // vector<int> nodes = {1,3,3,3,2};
    // int target = 3;
    // vector<int> nodes = {1,2,-1,2,-1,2};
    // int target = 2;
    TreeNode* root = create_tree(nodes);
    Solution S;
    S.removeLeafNodes(root, target);
    print_tree(root);
    return 0;
}