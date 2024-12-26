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
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while(i < n){
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
    if (!root) return;
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (!curr) cout << -1 << " ";
        else{
            cout << curr->val << " ";
            que.push(curr->left);
            que.push(curr->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            int curr_max = INT_MIN;
            while(n--){
                TreeNode* curr = que.front();
                que.pop();
                curr_max = max(curr_max, curr->val);
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            ans.push_back(curr_max);
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,3,2,5,3,-1,9};
    // vector<int> nodes = {1,2,3};
    TreeNode* root = create_tree(nodes);
    // print_tree(root);
    Solution S;
    vector<int> ans = S.largestValues(root);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}