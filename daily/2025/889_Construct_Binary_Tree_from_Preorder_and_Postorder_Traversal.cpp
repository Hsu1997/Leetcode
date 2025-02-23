#include <iostream>
#include <vector>
#include <unordered_map>
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
    // if (!root) return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (!curr) cout << -1 << " ";
        else{
            cout << curr->val << " ";
            que.push(curr->left);
            que.push(curr->right);
        }
    }
    cout << endl;
}

class Solution {
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n = preorder.size();
            unordered_map<int,int> post_val_to_pos;
            for (int i = 0; i < n; i++) post_val_to_pos[postorder[i]] = i;
            return create_tree(preorder, postorder, post_val_to_pos, 0, n-1, 0, n-1);
        }
        TreeNode* create_tree(vector<int>& preorder, vector<int>& postorder, unordered_map<int,int>& post_val_to_pos, int pre_start, int pre_end, int post_start, int post_end){
            if (pre_start > pre_end || post_start > post_end) return nullptr;
            TreeNode* root = new TreeNode(preorder[pre_start]);
            if (pre_start == pre_end) return root;
    
            int left_root_val = preorder[pre_start + 1];
            int left_root_pos = post_val_to_pos[left_root_val];
            int left_size = left_root_pos - post_start + 1;
            root->left = create_tree(preorder, postorder, post_val_to_pos, pre_start + 1, pre_start + left_size, post_start, left_root_pos);
            root->right = create_tree(preorder, postorder, post_val_to_pos, pre_start + left_size + 1, pre_end, left_root_pos + 1, post_end - 1);
            return root;
        }
    };

int main(){
    vector<int> preorder = {1,2,4,5,3,6,7};
    vector<int> postorder = {4,5,2,6,7,3,1};
    // vector<int> preorder = {1};
    // vector<int> postorder = {1};
    Solution S;
    TreeNode* root = S.constructFromPrePost(preorder, postorder);
    print_tree(root);
    return 0;
}