#include <iostream>
#include <vector>
#include <unordered_set>
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

void printTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        cout << curr->val << " ";
        if (curr->left) que.push(curr->left);
        if (curr->right) que.push(curr->right);
    }
    cout << endl;
    return;
}

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> nodes;
        unordered_set<int> children;
        for (auto& t : descriptions){
            int p = t[0];
            int c = t[1];
            int l = t[2];
            nodes.insert(p);
            nodes.insert(c);
            children.insert(c);
            if (m.find(p) == m.end()){
                TreeNode* parent = new TreeNode(p);
                m[p] = parent;
            }
            if (m.find(c) == m.end()){
                TreeNode* child = new TreeNode(c);
                m[c] = child;
            }
            if (l == 1) m[p]->left = m[c];
            else m[p]->right = m[c];
        }
        for (int node : nodes) if (children.find(node) == children.end()) return m[node];
        return nullptr;
    }
};

int main(){
    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    // vector<vector<int>> descriptions = {{1,2,1},{2,3,0},{3,4,1}};
    Solution S;
    TreeNode* root = S.createBinaryTree(descriptions);
    printTree(root);
    return 0;
}