#include <iostream>
#include <vector>
#include <unordered_map>
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

void print_tree(TreeNode* root){
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

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<TreeNode*,bool>> m;
        for (auto n : descriptions){
            int p = n[0];
            int c = n[1];
            if (m.find(p) == m.end()) m[p].first = new TreeNode(p);
            if (m.find(c) == m.end()) m[c].first = new TreeNode(c);
            if (n[2]) m[p].first->left = m[c].first;
            else m[p].first->right = m[c].first;
            m[c].second = 1;
        }
        for (auto i : m) if (i.second.second == 0) return i.second.first;
        return nullptr;
    }
};

int main(){
    vector<vector<int>> descriptions = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    // vector<vector<int>> descriptions = {{1,2,1},{2,3,0},{3,4,1}};
    Solution S;
    TreeNode* ans = S.createBinaryTree(descriptions);
    print_tree(ans);
    return 0;
}