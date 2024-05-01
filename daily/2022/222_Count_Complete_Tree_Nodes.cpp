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

TreeNode* create_complete_tree(vector<int> node){
    if (node.empty()) return nullptr;

    TreeNode* root = new TreeNode(node[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(i < node.size()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < node.size()){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
            i++;
        }
        if (i < node.size()){
            temp->right = new TreeNode(node[i]);
            que.push(temp->right);
            i++;
        }
    }
    return root;
}

void print_tree(TreeNode* root){
    if (!root) return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        int n = que.size();
        for (int i = 0; i < n; i++){
            TreeNode* temp = que.front();
            que.pop();
            cout << temp->val << " ";
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> que;
        que.push(root);
        int ans = 1;
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if (temp->left){
                que.push(temp->left);
                ans++;
            }
            if (temp->right){
                que.push(temp->right);
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> node = {1,2,3,4,5,6};
    // vector<int> node = {1};
    // vector<int> node = {};
    TreeNode* root = create_complete_tree(node);
    // print_tree(root);
    Solution S;
    cout << S.countNodes(root) << endl; 
    return 0;
}