#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int position;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* CreateTree(vector<int> nums){
    if (nums.size() == 1) return new TreeNode(nums[0]);

    TreeNode* root = new TreeNode(nums[0]);
    root->position = 0;
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        int temp_position = temp->position;
        int left_child = temp_position*2+1;
        int right_child = temp_position*2+2;
        que.pop();
        if (left_child < nums.size() && nums[left_child] != -1){
            temp->left = new TreeNode(nums[left_child]);
            temp->left->position = left_child;
            que.push(temp->left);
        }
        if (right_child < nums.size() && nums[right_child] != -1){
            temp->right = new TreeNode(nums[right_child]);
            temp->right->position = right_child;
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
    vector<int> tracking = {};
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return root;
        track(root);
        TreeNode* pseudo = new TreeNode();
        TreeNode* temp = pseudo;
        for (int i = 0; i < tracking.size(); i++){
            temp->right = new TreeNode(tracking[i]);
            temp = temp->right;
        }
        return pseudo->right;
    }

    TreeNode* track(TreeNode* root){
        if (!root) return root;
        increasingBST(root->left);
        tracking.push_back(root->val);
        increasingBST(root->right);
        return nullptr;
    }
};

int main(){
    vector<int> nums = {5,3,6,2,4,-1,8,1,-1,-1,-1,-1,-1,7,9};
    TreeNode* root = CreateTree(nums);
    PrintTree(root);
    Solution S;
    root = S.increasingBST(root);
    PrintTree(root);
    return 0;
}