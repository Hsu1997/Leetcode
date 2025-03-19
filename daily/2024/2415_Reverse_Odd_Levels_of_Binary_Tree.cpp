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

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> nodes = {};
        bfs(root, nodes);
        int n = nodes.size();
        int level = 0;
        deque<TreeNode*> que;
        que.push_back(root);
        int i = 0;
        while(i < n){
            int k = que.size();
            if (level % 2 == 0){
                while(k--){
                    TreeNode* curr = que.front();
                    que.pop_front();
                    curr->val = nodes[i++];
                    if (curr->left) que.push_back(curr->left);
                    if (curr->right) que.push_back(curr->right);
                }
            }
            else{
                while(k--){
                    TreeNode* curr = que.back();
                    que.pop_back();
                    curr->val = nodes[i++];
                    if (curr->right) que.push_front(curr->right);
                    if (curr->left) que.push_front(curr->left);
                }
            }
            level++;
        }
        return root;
    }
    void bfs(TreeNode* root, vector<int>& nodes){
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            nodes.push_back(curr->val);
            if (curr->left) que.push(curr->left);
            if (curr->right) que.push(curr->right);
        }
        return;
    }
};

TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    int n = nodes.size();
    while(i < n){
        TreeNode* temp = que.front();
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
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (!curr){
            cout << -1 << " ";
        }
        else{
            cout << curr->val << " ";
            que.push(curr->left);
            que.push(curr->right);
        }
    }
    return;
}

int main(){
    vector<int> nodes = {2,3,5,8,13,21,34};
    // vector<int> nodes = {7,13,11};
    // vector<int> nodes = {0,1,2,0,0,0,0,1,1,1,1,2,2,2,2};
    TreeNode* root = create_tree(nodes);
    Solution S;
    S.reverseOddLevels(root);
    print_tree(root);
    return 0;
}