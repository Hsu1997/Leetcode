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
    int n = node.size();
    int i = 1;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < n && node[i] != -1){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
        }
        i++;
        if (i < n && node[i] != -1){
            temp->right = new TreeNode(node[i]);
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
    cout << root->val << " ";
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (!temp->left) cout << -1 << " ";
        else{
            cout << temp->left->val << " ";
            que.push(temp->left);
        }
        if (!temp->right) cout << -1 << " ";
        else{
            cout << temp->right->val << " ";
            que.push(temp->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    int now_depth = 0;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        now_depth++;
        // cout << root->val << " : " << now_depth << endl;
        if (now_depth == depth - 1){
            // cout << "find" << endl;
            TreeNode* temp1 = new TreeNode(val, root->left, nullptr);
            root->left = temp1;
            TreeNode* temp2 = new TreeNode(val, nullptr, root->right);
            root->right = temp2;
        }
        else if (now_depth < depth - 1){
            if (root->left) addOneRow(root->left, val, depth);
            if (root->right) addOneRow(root->right, val, depth);
        } 
        now_depth--;

        return root;
    }
};

int main(){
    // vector<int> node = {4,2,6,3,1,5};
    // int val = 1;
    // int depth = 2;
    // vector<int> node = {4,2,-1,3,1};
    // int val = 1;
    // int depth = 1;
    vector<int> node = {4,2,6,3,1,5};
    int val = 1;
    int depth = 3;

    TreeNode* root = create(node);
    print_tree(root);
    Solution S;
    root = S.addOneRow(root, val, depth);
    print_tree(root);
    return 0;
}