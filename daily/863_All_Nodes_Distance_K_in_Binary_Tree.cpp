#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* create_tree(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    TreeNode* root = new TreeNode(nodes[0]);
    int n = nodes.size();
    int i = 1;
    queue<TreeNode*> que;
    que.push(root);
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
    vector<int> distanceK(TreeNode* root, int target, int k) {
        vector<vector<int>> m(501);
        vector<bool> visited(501, false);
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            if (temp->left){
                m[temp->val].push_back(temp->left->val);
                m[temp->left->val].push_back(temp->val);
                que.push(temp->left);
            }
            if (temp->right){
                m[temp->val].push_back(temp->right->val);
                m[temp->right->val].push_back(temp->val);
                que.push(temp->right);
            }
        }
        queue<int> q;
        q.push(target);
        visited[target] = true;
        while(k--){
            int s = q.size();
            while(s--){
                int t = q.front();
                q.pop();
                for(auto i : m[t]){
                    if (!visited[i]){
                        q.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {3,5,1,6,2,0,8,-1,-1,7,4};
    int target = 5;
    int k = 2;
    // vector<int> nodes = {1};
    // int target = 1;
    // int k = 3;
    TreeNode* root = create_tree(nodes);
    Solution S;
    vector<int> ans = S.distanceK(root, target, k);
    for (auto i : ans) cout << i << " ";
    cout << endl;
}