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

TreeNode* create_tree(vector<int> node){
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        queue<TreeNode*> next_level;

        while(!que.empty()){
            int right_side = -1;
            while(!que.empty()){
                TreeNode* temp = que.front();
                que.pop();
                right_side = temp->val;
                if(temp->left) next_level.push(temp->left);
                if(temp->right) next_level.push(temp->right);
            }
            ans.push_back(right_side);
            swap(que, next_level);
        }
        return ans;
    }
};

int main(){
    vector<int> node = {1,2,3,-1,5,-1,4};
    TreeNode* root = create_tree(node);
    Solution S;
    vector<int> ans = S.rightSideView(root);
    for (auto i : ans) cout << i << " ";
    cout << endl;
    return 0;
}