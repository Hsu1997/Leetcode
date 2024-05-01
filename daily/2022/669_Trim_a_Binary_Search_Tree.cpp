#include <iostream>
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

TreeNode* CreateTree(vector<int> node){
    TreeNode* root = new TreeNode(node[0]);
    queue<TreeNode*> que;
    que.push(root); 
    for (int i = 1; i < node.size(); i+=2){
        TreeNode* temp = que.front();
        que.pop();
        temp->left = new TreeNode(node[i]);
        que.push(temp->left);
        if (i+1 < node.size()) temp->right = new TreeNode(node[i + 1]);
        que.push(temp->right);
    }
    return root;
}

void PrintAllTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        cout << temp->val << " ";
        if(temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* FindVaild(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val < low){
            while (root->val < low){
                root = root->right;
                if (root == nullptr) return nullptr;
            }
        }
        else if (root->val > high){
            while (root->val > high){
                root = root->left;
                if (root == nullptr) return nullptr;
            }
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // find root
        while (root->val < low || root->val > high){
            if (root->val < low) root = root->right;
            else if (root->val > high) root = root->left;
            if (root == nullptr) return nullptr;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            temp->left = FindVaild(temp->left, low, high);
            if (temp->left){
                que.push(temp->left);
            }
            temp->right = FindVaild(temp->right, low, high);
            if (temp->right){
                que.push(temp->right);
            }
        }
        return root;
    }
};

int main(){
    vector<int> node = {45,30,47,10,36,46,49,8,24,34,42};
    int low = 32;
    int high = 44;
    TreeNode* root = CreateTree(node);
    // PrintAllTree(root);
    Solution S;
    TreeNode* output = S.trimBST(root, low, high);
    PrintAllTree(output);
    return 0;
}