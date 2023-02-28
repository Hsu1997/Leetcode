#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

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
    int n = nodes.size();
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty()){
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
    if (!root) cout << -1 << endl;
    else{
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if (!temp) cout << -1 << " ";
            else{
                cout << temp->val << " ";
                que.push(temp->left);
                que.push(temp->right);
            }
        }
    }
    return;
}

class Solution {
public:
    vector<int> tree;
    vector<TreeNode*> ans;
    unordered_map<string,int> cnt;

    string dfs(TreeNode* root){
        if (root == nullptr) return "";
        string temp = "(" + dfs(root->left) + ")" + to_string(root->val) + "(" + dfs(root->right) + ")";
        cnt[temp]++;
        if (cnt[temp] == 2) ans.push_back(root);
        return temp;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,2,3,4,-1,2,4,-1,-1,4};
    TreeNode* root = create_tree(nodes);
    // print_tree(root);
    Solution S;
    vector<TreeNode*> ans = S.findDuplicateSubtrees(root);
    for (auto i : ans) cout << i->val << endl;
    return 0;
}