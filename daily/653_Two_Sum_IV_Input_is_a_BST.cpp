#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

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
    int n = node.size();
    int i = 1;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (i < n && node[i] != -1){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
        }
        i++;
        if (i < n && node[i] != -1){
            temp->right = new TreeNode(node[i]);
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
        if (!temp->left) cout << -1 << " ";
        else{
            cout << temp->left->val << " ";
            que.push(temp->left);
        }
        if (!temp->right) cout << -1 << " ";
        else{
            cout << temp->right->val << " ";
            que.push(temp->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    unordered_set<int> s;

    bool findTarget(TreeNode* root, int k) {
        if (s.find(root->val) != s.end()) return true;
        s.insert(k - root->val);
        if (root->left && findTarget(root->left, k)) return true;        
        if (root->right && findTarget(root->right, k)) return true;
        return false;
    }
};

int main(){
    vector<int> node = {5,3,6,2,4,-1,7};
    int k = 9;
    // int k = 28;
    TreeNode* root = create(node);
    Solution S;
    cout << S.findTarget(root, k) << endl;
    return 0;
}