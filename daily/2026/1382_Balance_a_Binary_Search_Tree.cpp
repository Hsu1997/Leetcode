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

TreeNode* createTree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int idx = 1;
    while(idx < n && !que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (idx < n && nodes[idx] != -1){
            curr->left = new TreeNode(nodes[idx]);
            que.push(curr->left);
        }
        idx++;
        if (idx < n && nodes[idx] != -1){
            curr->right = new TreeNode(nodes[idx]);
            que.push(curr->right);
        }
        idx++;
    }
    return root;
}

void printTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (!curr) cout << "-1 ";
        else{
            cout << curr->val << " ";
            que.push(curr->left);
            que.push(curr->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& nodes){
        if (!root) return;
        dfs(root->left, nodes);
        nodes.push_back(root->val);
        dfs(root->right, nodes);
        return;
    }
    TreeNode* createBST(vector<int>& nodes, int l, int r){
        if (nodes.empty()) return nullptr;
        if (r < l || l >= nodes.size() || r < 0) return nullptr;
        int mid = l + (r - l + 1) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = createBST(nodes, l, mid - 1);
        root->right = createBST(nodes, mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return root;
        vector<int> nodes;
        dfs(root, nodes);
        int n = nodes.size();
        TreeNode* r = createBST(nodes, 0, n-1);
        return r;
    }
};

int main(){
    vector<int> nodes = {1,-1,2,-1,3,-1,4};
    // vector<int> nodes = {2,1,3};
    TreeNode* root = createTree(nodes);
    Solution S;
    printTree(S.balanceBST(root));
    return 0;
}