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

TreeNode* create_tree(vector<int> tree){
    if (tree.size() == 0) return nullptr;

    TreeNode *root = new TreeNode(tree[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
   
    while(!que.empty() && i < tree.size()){
        TreeNode* temp = que.front();
        que.pop();
        // cout << tree[i] << " ";
        if (i < tree.size() && tree[i] != -1){
            temp->left = new TreeNode(tree[i]);
            que.push(temp->left);
        }
        i++;
        // cout << tree[i] << endl;
        if (i < tree.size() && tree[i] != -1){
            temp->right = new TreeNode(tree[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

void print_tree(TreeNode* root){
    if (root == NULL) return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        cout << temp->val << " ";
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
}

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int now_level = 1;
        int next_level = 0;
        int ans = 0;
        
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            now_level--;
            if(temp->left){
                que.push(temp->left);
                next_level++;
            }
            if(temp->right){
                que.push(temp->right);
                next_level++;
            }
            ans += temp->val;
            if (now_level == 0 && !que.empty()){
                swap(now_level, next_level);
                ans = 0;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> tree = {1,2,3,4,5,-1,6,7,-1,-1,-1,-1,8};
    TreeNode* root = create_tree(tree);
    // print_tree(root);
    Solution S;
    cout << S.deepestLeavesSum(root) << endl;
    return 0;
}