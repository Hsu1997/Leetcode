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

TreeNode* create_tree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    int n = nodes.size();
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
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

class FindElements {
public:
    unordered_set<int> s;
    FindElements(TreeNode* root) {
        root->val = 0;
        recursion(root);
    }

    void recursion(TreeNode* root){
        if (!root) return;
        s.insert(root->val);
        if (root->left){
            root->left->val = root->val * 2 + 1;
            recursion(root->left);
        }
        if (root->right){
            root->right->val = root->val * 2 + 2;
            recursion(root->right);
        }
    }
    bool find(int target) {
        return s.find(target) != s.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main(){
    vector<int> nodes = {0,-1,0};
    vector<int> query = {1,2};
    // vector<int> nodes = {0,0,0,0,0};
    // vector<int> query = {1,3,5};
    // vector<int> nodes = {0,-1,0,0,-1,0};
    // vector<int> query = {2,3,4,5};
    TreeNode* root = create_tree(nodes);
    vector<int> ans;
    FindElements F(root);
    for (int q : query) ans.push_back(F.find(q));
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}