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

TreeNode* create_tree(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    TreeNode* temp;
    int i = 1;
    int n = nodes.size();
    while(i < n){
        temp = que.front();
        que.pop();
        if (i < n && nodes[i] != -1){
            temp->left = new TreeNode(nodes[i]);
            que.push(temp->left);
        }
        i++;
        if (i < n && nodes[i] != -1){
            temp->right = new TreeNode(nodes[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

void print_tree(TreeNode* root){
    if (!root) return;
    queue<TreeNode*> que;
    que.push(root);
    cout << root->val << " ";
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp->left){
            cout << temp->left->val << " ";
            que.push(temp->left);
        }
        else cout << "-1 ";
        if (temp->right){
            cout << temp->right->val << " ";
            que.push(temp->right);
        }
        else cout << "-1 ";
    }
}

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* node, int l, int r){
        if (!node) ans = max({ans, l, r});
        else{
            dfs(node->left, 0, l+1);
            dfs(node->right, r+1, 0);
        }
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 1, 1);
        return ans - 1;
    }
};

int main(){
    // vector<int> nodes = {1,-1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1};
    // vector<int> nodes = {1,1,1,-1,1,-1,-1,1,1,-1,1};
    // vector<int> nodes = {1};
    vector<int> nodes = {2,8,6,1,1,7,9,8,9,3,1,4,8,-1,5,3,4,10,10,2,-1,5,-1,3,7,-1,3,-1,4,6,2,8,4,5,-1,-1,9,-1,6,-1,6,-1,-1,2,2,-1,3,2,-1,-1,8,1,9,8,8,5,10,-1,9,-1,8,-1,-1,-1,-1,5,7,2,10,-1,-1,-1,-1,-1,-1,3,-1,2,-1,-1,-1,8,7,-1,-1,3,1,-1,3,-1,-1,-1,7,1,-1,3,-1,-1,-1,-1,2,-1,2,-1,4,7,4,-1,-1,-1,9,-1,-1,-1,-1,8,8,-1,-1,-1,-1,7,2,1,4,-1,4,7,-1,5,9,-1,7,9,7,-1,10,9,6,-1,-1,7,2,3,-1,2,-1,9,5,9,-1,-1,5,-1,5,9,-1,-1,-1,-1,9,-1,-1,-1,-1,-1,7,-1,-1,-1,-1,-1,-1,-1,9,-1,4,1,-1,-1,-1,-1,4,4,-1,-1,4,-1,-1,-1,4};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.longestZigZag(root) << endl;
    return 0;
}