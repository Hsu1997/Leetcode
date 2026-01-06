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

TreeNode* createTree(vector<int>& nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    int idx = 1;
    while(idx < n && !que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (nodes[idx] != 100001){
            curr->left = new TreeNode(nodes[idx]);
            que.push(curr->left);
        }
        idx++;
        if (idx < n && nodes[idx] != 100001){
            curr->right = new TreeNode(nodes[idx]);
            que.push(curr->right);
        }
        idx++;
    }
    return root;
}

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 0;
        int max_val = INT_MIN;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while(!que.empty()){
            level++;
            int curr_sum = 0;
            int n = que.size();
            while(n--){
                TreeNode* curr = que.front();
                que.pop();
                curr_sum += curr->val;
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            if (curr_sum > max_val){
                ans = level;
                max_val = curr_sum;
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,7,0,7,-8,100001,100001};
    // vector<int> nodes = {989,100001,10250,98693,-89388,100001,100001,100001,-32127};
    Solution S;
    cout << S.maxLevelSum(createTree(nodes)) << endl;
    return 0;
}