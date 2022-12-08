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
    int i = 1;
    while(!que.empty()){
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
        i++;
    }
    return root;
}

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if (temp->val <= high && temp->val >= low) ans += temp->val;
            if (temp->left && temp->val >= low) que.push(temp->left);
            if (temp->right && temp->val <= high) que.push(temp->right);
        }
        return ans;
    }
};

int main(){
    vector<int> node = {10,5,15,3,7,-1,18};
    int low = 7;
    int high = 15;
    // vector<int> node = {10,5,15,3,7,13,18,1,-1,6};
    // int low = 6;
    // int high = 10;
    TreeNode* root = create(node);
    Solution S;
    cout << S.rangeSumBST(root, low, high) << endl;
    return 0;
}