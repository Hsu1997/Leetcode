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

TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    int i = 1;
    int n = nodes.size();
    while(i < n && !que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (i < n && nodes[i] != -1){
            curr->left = new TreeNode(nodes[i]);
            que.push(curr->left);
        }
        i++;
        if (i < n && nodes[i] != -1){
            curr->right = new TreeNode(nodes[i]);
            que.push(curr->right);
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
        if (!curr) cout << "null ";
        else{
            que.push(curr->left);
            que.push(curr->right);
            cout << curr->val << " ";
        }
    }
    return;
}

class Solution {
public:
    vector<pair<int,int>> dfs(TreeNode* root){
        if (!root) return {};
        vector<pair<int,int>> relationship;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            if (curr->left){
                relationship.push_back({curr->val, curr->left->val});
                que.push(curr->left);
            }
            else{
                relationship.push_back({curr->val, -1});
            }
            if (curr->right){
                relationship.push_back({curr->val, curr->right->val});
                que.push(curr->right);
            }
            else{
                relationship.push_back({curr->val, -1});
            }
        }
        return relationship;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        vector<pair<int,int>> t1;
        vector<pair<int,int>> t2;
        t1 = dfs(root1);
        t2 = dfs(root2);
        // for (auto i : t1) cout << i.first << "," << i.second << " ";
        // cout << endl;
        // for (auto i : t2) cout << i.first << "," << i.second << " ";
        // cout << endl;
        if (t1.size() != t2.size()) return false;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        for (int i = 0; i < t1.size(); i++){
            if (t1[i] != t2[i]) return false;
        }
        return true;
    }
};

int main(){
    vector<int> nodes1 = {1,2,3,4,5,6,-1,-1,-1,7,8};
    vector<int> nodes2 = {1,3,2,-1,6,4,5,-1,-1,-1,-1,8,7};
    // vector<int> nodes1 = {};
    // vector<int> nodes2 = {};
    // vector<int> nodes1 = {};
    // vector<int> nodes2 = {1};
    TreeNode* root1 = create_tree(nodes1);
    TreeNode* root2 = create_tree(nodes2);
    Solution S;
    cout << S.flipEquiv(root1, root2) << endl;
    return 0;
}