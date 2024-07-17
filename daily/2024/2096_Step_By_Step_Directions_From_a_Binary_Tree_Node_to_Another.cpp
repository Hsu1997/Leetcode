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

TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(!que.empty() && i < n){
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

class Solution {
public:
    TreeNode* min_root;
    int s;
    int d;
    string fd;

    TreeNode* lowestCommonAncestor(TreeNode* root) {
        if (root == nullptr || root->val == s || root->val == d) return root;
        TreeNode* left = lowestCommonAncestor(root->left);
        TreeNode* right = lowestCommonAncestor(root->right);
        if (left != nullptr && right != nullptr) return root;
        return left != nullptr ? left : right;
    }

    bool find_d(TreeNode* root){
        if (root->val == d) return true;
        if (root->left){
            fd += "L";
            if (find_d(root->left)) return true;
            fd.pop_back();
        }
        if (root->right){
            fd += "R";
            if (find_d(root->right)) return true;
            fd.pop_back();
        }
        return false;
    }

    int find_s(TreeNode* LCA){
        queue<TreeNode*> que;
        que.push(LCA);
        int ans = 0;
        while(!que.empty()){
            int k = que.size();
            while(k--){
                TreeNode* temp = que.front();
                if (temp->val == s) return ans;
                que.pop();
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            ans++;
        }
        return -1;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        s = startValue;
        d = destValue;
        TreeNode* LCA = lowestCommonAncestor(root);
        // cout << "LCA = " << LCA->val << endl;
        find_d(LCA);
        // cout << fd << endl;
        int up = find_s(LCA);
        // cout << up << endl;
        return string(up, 'U') + fd;
    }
};

int main(){
    vector<int> nodes = {5,1,2,3,-1,6,4};
    int startValue = 3;
    int destValue = 6;
    // vector<int> nodes = {2,1};
    // int startValue = 2;
    // int destValue = 1;
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.getDirections(root, startValue, destValue) << endl;
    return 0;
}