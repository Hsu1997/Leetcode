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
    int i = 1;

    while(!que.empty()){
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

void print_tree(TreeNode* root){
    if (!root) return;
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp != nullptr) cout << temp->val << " ";
        else cout << "null ";
        if (temp->left || temp->right){
            que.push(temp->left);
            que.push(temp->right);
        }
    }
    cout << endl;
    return;
}

class Solution {
public:
    vector<int> v;

    void subproblem(TreeNode* node){
        if (!node) return;
        subproblem(node->left);
        v.push_back(node->val);
        subproblem(node->right);
    }

    bool isValidBST(TreeNode* root) {
        subproblem(root);
        for (int i = 0; i < v.size()-1; i++){
            if (v[i] >= v[i+1]) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nodes = {2,1,3};
    // vector<int> nodes = {5,1,4,-1,-1,3,6};
    // vector<int> nodes = {5,4,6,-1,-1,3,7};
    TreeNode* root = create_tree(nodes);
    // print_tree(root);
    Solution S;
    cout << S.isValidBST(root) << endl;
    return 0;
}