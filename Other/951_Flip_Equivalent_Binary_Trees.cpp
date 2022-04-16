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
        que.pop();
        if (temp->position * 2 + 1 < nums.size() && nums[temp->position * 2 + 1] != -1){
            temp->left = new TreeNode(nums[temp->position * 2 + 1]);
            temp->left->position = temp->position * 2 + 1;
            que.push(temp->left);
        }
        if (temp->position * 2 + 2 < nums.size() && nums[temp->position * 2 + 2] != -1){
            temp->right = new TreeNode(nums[temp->position * 2 + 2]);
            temp->right->position = temp->position * 2 + 2;
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2) return true;
        if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) return false;
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

int main(){
    vector<int> r1 = {1,2,3,4,5,6,-1,-1,-1,7,8};
    vector<int> r2 = {1,3,2,-1,6,4,5,-1,-1,-1,-1,-1,-1,8,7};
    TreeNode* root1 = CreateTree(r1);
    TreeNode* root2 = CreateTree(r2);
    PrintTree(root1);
    PrintTree(root2);
    Solution S;
    cout << S.flipEquiv(root1, root2) << endl;
    return 0;
}