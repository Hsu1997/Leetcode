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
    int n = nodes.size();
    int i = 1;
    TreeNode* temp;
    while(!que.empty()){
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
    queue<TreeNode*> que;
    TreeNode* temp;
    que.push(root);
    while(!que.empty()){
        temp = que.front();
        que.pop();
        if (!temp) cout << -1 << " ";
        else{
            cout << temp->val << " ";
            que.push(temp->left);
            que.push(temp->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    vector<int> nodes;
    void inorder(TreeNode* root){
        if (root->left) inorder(root->left);
        nodes.push_back(root->val);
        if (root->right) inorder(root->right);
    }

    TreeNode* create_tree(int start, int end){
        if (start > end) return nullptr;
        if (start == end) return new TreeNode(nodes[start]);
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = create_tree(start, mid-1);
        root->right = create_tree(mid+1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return create_tree(0, nodes.size()-1);
    }
};

int main(){
    vector<int> nodes = {1,-1,2,-1,3,-1,4,-1,-1};
    // vector<int> nodes = {2,1,3};
    TreeNode* root = create_tree(nodes);
    Solution S;
    TreeNode* ans = S.balanceBST(root);
    print_tree(ans);
    return 0;
}