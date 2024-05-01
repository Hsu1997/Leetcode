#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create(vector<int> node){
    if (node.empty()) return nullptr;
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

TreeNode* find(TreeNode* root, int n){
    if (!root) return root;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp->val == n){
            return temp;
        }
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    return nullptr;
}

void print(TreeNode* root){
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
    TreeNode* ans = nullptr;

    int sub(TreeNode* node, TreeNode* p, TreeNode* q){
        if (!node) return 0;

        int mid = (node == p || node == q)? 1 : 0;

        int left = sub(node->left, p, q);
        int right = sub(node->right, p, q);
        if (mid + left + right == 2) ans = node;
        return (mid + left + right > 0);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        sub(root, p, q);
        return ans;
    }
};

int main(){
    vector<int> node = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root = create(node);
    TreeNode* p = find(root, 5);
    TreeNode* q = find(root, 1);
    Solution S;
    TreeNode* target = S.lowestCommonAncestor(root, p, q);
    cout << target->val << endl;
    // print(root);
    return 0;
}