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

TreeNode* create_tree(vector<int> node){
    if (node.empty()) return nullptr;

    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(node[0]);
    que.push(root);
    int i = 1;

    while(i < node.size()){
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

TreeNode* find(TreeNode* root, int v){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp->val == v) return temp;
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    return nullptr;
}

void print_tree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        cout << temp->val << " ";
        if (temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    return;
}

class Solution {
public:
    TreeNode* LCA;

    int subproblem(TreeNode* root, TreeNode* p, TreeNode* q){
        // cout << "test" << endl;
        if (!root) return 0;
        int now = 0;
        if (root == p || root == q) now++;
        now += subproblem(root->left, p, q) + subproblem(root->right, p, q);
        if (now > 1) LCA = root;
        if (now) return 1;
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        subproblem(root, p, q);
        return LCA;
    }
};

int main(){
    // vector<int> node = {6,2,8,0,4,7,9,-1,-1,3,5};
    // TreeNode* root = create_tree(node);
    // TreeNode* p = find(root, 2);
    // TreeNode* q = find(root, 8);

    // vector<int> node = {6,2,8,0,4,7,9,-1,-1,3,5};
    // TreeNode* root = create_tree(node);
    // TreeNode* p = find(root, 2);
    // TreeNode* q = find(root, 4);

    vector<int> node = {2,1};
    TreeNode* root = create_tree(node);
    TreeNode* p = find(root, 2);
    TreeNode* q = find(root, 1);

    // print_tree(root);
    Solution S;
    cout << S.lowestCommonAncestor(root, p, q)->val << endl;
    return 0;
}