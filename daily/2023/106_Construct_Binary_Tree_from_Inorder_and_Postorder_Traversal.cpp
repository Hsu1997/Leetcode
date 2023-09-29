#include <iostream>
#include <vector>

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

class Solution {
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inorder_head, int postorder_head, int length){
        if (length < 1) return nullptr;
        if (length == 1) return new TreeNode(inorder[inorder_head]);
        if (postorder_head + length - 1 >= postorder.size()) return nullptr;
        int r = postorder[postorder_head + length - 1];
        TreeNode* root = new TreeNode(r);
        int root_pos = -1;
        for (int i = inorder_head; i < inorder_head+length; i++){
            if (inorder[i] == r){
                root_pos = i;
                break;
            }
        }
        int left_size = root_pos - inorder_head;
        int right_size = length - left_size - 1;
        root->left = helper(inorder, postorder, inorder_head, postorder_head, left_size);
        root->right = helper(inorder, postorder, root_pos+1, postorder_head+left_size, right_size);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, 0, inorder.size());
    }
};

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    // vector<int> inorder = {-1};
    // vector<int> postorder = {-1};
    Solution S;
    TreeNode* ans = S.buildTree(inorder, postorder);

    return 0;
}