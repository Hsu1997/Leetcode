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
    int n = nodes.size();
    int i = 1;
    TreeNode* temp;
    while(!que.empty()){
        temp = que.front();
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

void print_tree(TreeNode* root){
    queue<TreeNode*> que;
    TreeNode* temp;
    que.push(root);
    while(!que.empty()){
        temp = que.front();
        que.pop();
        if (!temp) cout << -1 << " ";
        else{
            cout << temp->val << " ";
            que.push(temp->left);
            que.push(temp->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    int acc = 0;
    
    void add_acc(TreeNode* root){
        if (root->right) add_acc(root->right);
        root->val += acc;
        acc = root->val;
        if (root->left) add_acc(root->left);
    }

    TreeNode* bstToGst(TreeNode* root) {
        add_acc(root);
        return root;
    }
};

int main(){
    vector<int> nodes = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    // vector<int> nodes = {0,-1,1};
    TreeNode* root = create_tree(nodes);
    Solution S;
    TreeNode* ans = S.bstToGst(root);
    print_tree(ans);
    return 0;
}