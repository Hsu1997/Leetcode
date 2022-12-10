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

TreeNode* create(vector<int> nodes){
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
    long ans = 0;
    long mod = 1e9+7;
    long sum = 0;

    void traverse(TreeNode* root){
        sum += root->val;
        if (root->left) traverse(root->left);
        if (root->right) traverse(root->right);
    }

    long acc(TreeNode* node){
        if (!node) return 0;
        long left = acc(node->left);
        long right = acc(node->right);
        long temp = (left + right + node->val);
        // cout << temp << endl;
        if (temp * (sum - temp) > ans) ans = temp * (sum - temp);
        return temp;
    }

    int maxProduct(TreeNode* root) {
        traverse(root);
        // cout << sum << endl;
        acc(root);
        return ans % mod;
    }
};

int main(){
    // vector<int> nodes = {1,2,3,4,5,6};
    vector<int> nodes = {1,-1,2,3,4,-1,-1,5,6};
    TreeNode* root = create(nodes);
    Solution S;
    cout << S.maxProduct(root) << endl;
    return 0;
}