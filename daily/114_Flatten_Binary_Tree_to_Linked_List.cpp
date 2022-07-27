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

TreeNode* create(vector<int> node){
    if (node.empty()) return nullptr;
    TreeNode* root = new TreeNode(node[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty()){
        TreeNode* temp = que.front();
        // cout << temp->val << endl;
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

void print(TreeNode* root){
    if (!root) return;
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
    return;
}

class Solution {
public:
    TreeNode* now;

    void sub(TreeNode* node){
        now->right = node;
        now->left = nullptr;
        now = now->right;
        TreeNode* temp = now->right;
        if (now->left) sub(now->left);
        if (temp) sub(temp);
    }

    void flatten(TreeNode* root) {
        if (!root) return;
        now = new TreeNode();
        sub(root);
        return;
    }
};

int main(){
    vector<int> node = {1,2,5,3,4,-1,6};
    TreeNode* root = create(node);
    Solution S;
    S.flatten(root);
    print(root);
    return 0;
}