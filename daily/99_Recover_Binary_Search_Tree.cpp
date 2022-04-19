#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    int position;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right){}
};

TreeNode* CreateTree(vector<int> nums){
    if (nums.size() == 0) return nullptr;
    // if (nums.size() == 1) return new TreeNode(nums[0]);
    TreeNode* root = new TreeNode(nums[0]);
    root->position = 0;
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        int temp_position = temp->position;
        if (temp_position*2+1 < nums.size() && nums[temp_position*2+1] != -1){
            temp->left = new TreeNode(nums[temp_position*2+1]);
            temp->left->position = temp_position*2+1;
            que.push(temp->left);
        }
        if (temp_position*2+2 < nums.size() && nums[temp_position*2+2] != -1){
            temp->right = new TreeNode(nums[temp_position*2+2]);
            temp->right->position = temp_position*2+2;
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
    TreeNode* previous = new TreeNode(numeric_limits<int>::min());
    TreeNode* abnormal1 = nullptr;
    TreeNode* abnormal2 = nullptr;

    void inorder(TreeNode* root){
        if (!root) return;

        inorder(root->left);
        if (abnormal1 != nullptr && root->val < previous->val){
            abnormal2 = root;
            return;
        }
        if (abnormal1 == nullptr && root->val < previous->val){
            abnormal1 = previous;
            abnormal2 = root;
        }
        previous = root;
        inorder(root->right);
        return;
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(abnormal1->val, abnormal2->val);
        return;
    }
};

int main(){
    // vector<int> nums = {3,1,4,-1,-1,2};
    vector<int> nums = {1,3,-1,-1,2};
    
    TreeNode* root = CreateTree(nums);
    PrintTree(root);
    Solution S;
    S.recoverTree(root);
    PrintTree(root);
    return 0;
}