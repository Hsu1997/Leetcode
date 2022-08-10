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

void print_tree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (!temp) cout << "null ";
        else{
            cout << temp->val << " ";
            if (temp->left || temp->right){
                que.push(temp->left);
                que.push(temp->right);
            }
        }
    }
    cout << endl;
    return;
}

class Solution {
public:
    TreeNode* subtree(vector<int>& nums, int start, int end){
        if (start > end) return nullptr;

        int mid = start + (end - start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = subtree(nums, start, mid-1);
        root->right = subtree(nums, mid+1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = subtree(nums, 0, mid-1);
        root->right = subtree(nums, mid+1, nums.size()-1);
        return root;
    }
};

int main(){
    // vector<int> nums = {-10,-3,0,5,9};
    vector<int> nums = {0,1,2,3,4,5};
    Solution S;
    TreeNode* root = S.sortedArrayToBST(nums);
    print_tree(root);
    return 0;
}