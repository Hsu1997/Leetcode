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
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int now = 1;
    while(now < nodes.size() && !que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (now < nodes.size() &&  nodes[now] != -1){
            temp->left = new TreeNode(nodes[now]);
            que.push(temp->left);
        }
        now++;
        if (now < nodes.size() &&  nodes[now] != -1){
            temp->right = new TreeNode(nodes[now]);
            que.push(temp->right);
        }
        now++;
    }
    return root;
}

class Solution {
public:

    bool evaluateTree(TreeNode* root) {
        if (!root->left || !root->right){
            return root->val;
        }
        else{
            if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
            else return evaluateTree(root->left) && evaluateTree(root->right);
        }
    }
};

int main(){
    // vector<int> nodes = {2,1,3,-1,-1,0,1};
    vector<int> nodes = {0};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.evaluateTree(root) << endl;
    return 0;
}