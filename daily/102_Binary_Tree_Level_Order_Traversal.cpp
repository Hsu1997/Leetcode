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

TreeNode* createtree(vector<int> node){
    int n = node.size();
    if (n == 0) return NULL;
    TreeNode* root = new TreeNode(node[0]);
    if (n == 1) return root;
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;

    while(i < n && !que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < n && node[i] != -1) temp->left = new TreeNode(node[i]), que.push(temp->left);
        i++;
        if (i < n && node[i] != -1) temp->right = new TreeNode(node[i]), que.push(temp->right);
        i++;
    }
    return root;
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        queue<TreeNode*> next_level;
        while(!que.empty()){
            vector<int> now_level;
            while(!que.empty()){
                TreeNode* temp = que.front();
                que.pop();
                now_level.push_back(temp->val);
                if (temp->left) next_level.push(temp->left);
                if (temp->right) next_level.push(temp->right);
            }
            ans.push_back(now_level);
            swap(que, next_level);
        }
        return ans;
    }
};

int main(){
    vector<int> node = {3,9,20,-1,-1,15,7};
    TreeNode* root = createtree(node);
    Solution S;
    vector<vector<int>> ans = S.levelOrder(root);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}