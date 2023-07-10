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
    int i = 1;
    while(i < nodes.size()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < nodes.size() && nodes[i] != -1){
            temp->left = new TreeNode(nodes[i]);
            que.push(temp->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != -1){
            temp->right = new TreeNode(nodes[i]);
            que.push(temp->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    int minDepth(TreeNode* root) {
        int depth = 0;
        if (!root) return depth;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            depth++;
            int s = que.size();
            while(s--){
                TreeNode* temp = que.front();
                que.pop();
                if (!temp->left && !temp->right) return depth;
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nodes = {3,9,20,-1,-1,15,7};
    // vector<int> nodes = {2,-1,3,-1,4,-1,5,-1,6};
    // vector<int> nodes = {};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.minDepth(root)<< endl;
    return 0;
}