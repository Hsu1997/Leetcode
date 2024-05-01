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

TreeNode* CreateTree(vector<int> nums){
    if (nums.size() == 1) return new TreeNode(nums[0]);

    int i = 1;
    TreeNode* root = new TreeNode(nums[0]);
    // cout << "0 : " << root->val << endl;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty() && i < nums.size()){
        TreeNode* temp = que.front();
        que.pop();
        if (nums[i] == -1){
            if (nums[i+1] == -1){
                // cout << i << " : pass 2" << endl;
                i = i+2;
                continue;
            }
            else{
                temp->right = new TreeNode(nums[i+1]);
                // cout << i << " : pass 1" << endl;
                que.push(temp->right);
                // cout << i+1 << " : " << temp->right->val << endl;
                i = i+2;
            }
        }
        else{
            temp->left = new TreeNode(nums[i]);
            // cout << i << " : " << temp->left->val << endl;
            i++;
            que.push(temp->left);
            if (i == nums.size() || nums[i] == -1) continue;
            temp->right = new TreeNode(nums[i]);
            // cout << i << " : " << temp->right->val << endl;
            i++;
            que.push(temp->right);
        }
    }
    return root;
}

void PrintTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        cout << temp->val << " ";
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    cout << endl;
}

class Solution {
public:
    int accumulate = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;

        convertBST(root->right);
        accumulate += root->val;
        root->val = accumulate;
        convertBST(root->left);
        return root;
    }
};

int main(){
    vector<int> nums = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};
    TreeNode* root = CreateTree(nums);
    // PrintTree(root);
    Solution S;
    S.convertBST(root);
    PrintTree(root);
    return 0;
}