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
    while(!que.empty() && i < nodes.size()){
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

void print_tree(TreeNode* root){
    if (!root) return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp == nullptr) cout << -1 << " ";
        else{
            cout << temp->val << " ";
            que.push(temp->left);
            que.push(temp->right);
        }
    }
    cout << endl;
    return;
}

class Solution {
public:
    vector<TreeNode*> slove(int start, int end){
        vector<TreeNode*> ans;
        if (start > end){
            ans.push_back(nullptr);
            return ans;
        }

        for (int i = start; i <= end; i++){
            for (auto left_tree : slove(start, i-1)){
                for (auto right_tree : slove(i+1, end)){
                    TreeNode* root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return slove(1, n);
    }
};

int main(){
    int n = 3;
    Solution S;
    vector<TreeNode*> ans = S.generateTrees(n);
    for (auto i : ans) print_tree(i);
    return 0;
}