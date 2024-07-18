#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
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
    TreeNode* root = new TreeNode(nodes[0]);
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
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
    void mapping(TreeNode* root, TreeNode* parent, unordered_map<int, pair<TreeNode*,TreeNode*>>& m){
        if (!root) return;
        m[root->val] = {root, parent};
        mapping(root->left, root, m);
        mapping(root->right, root, m);
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // val -> {node, parent}
        unordered_map<int, pair<TreeNode*,TreeNode*>> m;
        mapping(root, nullptr, m);
        // for (auto i : m){
        //     cout << i.first << " : , parent : " << ((i.second.second == nullptr)? 0 : i.second.second->val) << endl;
        // }
        unordered_set<TreeNode*> s;
        s.insert(root);
        for (int i : to_delete){
            TreeNode* node = m[i].first;
            TreeNode* parent = m[i].second;
            if (parent != nullptr && parent->left != nullptr && parent->left->val == i) parent->left = nullptr;
            if (parent != nullptr && parent->right != nullptr && parent->right->val == i) parent->right = nullptr;
            if (s.find(node) != s.end()) s.erase(node);
            if (node->left) s.insert(node->left);
            if (node->right) s.insert(node->right);
        }
        return vector<TreeNode*>(s.begin(), s.end());
    }
};

int main(){
    // vector<int> nodes = {1,2,3,4,5,6,7};
    // vector<int> to_delete = {3,5};
    vector<int> nodes = {1,2,4,-1,3};
    vector<int> to_delete = {3};
    TreeNode* root = create_tree(nodes);
    Solution S;
    vector<TreeNode*> ans = S.delNodes(root, to_delete);
    for (auto i : ans) cout << i->val << " ";
    cout << endl;
    return 0;
}