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

TreeNode* create_tree(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    int i = 1;
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    while(i < n && !que.empty()){
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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int ans = INT_MIN;
        int round = 0;
        int max_level = 0;
        while(!que.empty()){
            round++;
            int n = que.size();
            int temp = 0;
            while(n--){
                TreeNode* node = que.front();
                que.pop();
                temp += node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            // cout << "round " << round << " : " << temp << endl;
            if (temp > ans) ans = temp, max_level = round;
        }
        return max_level;
    }
};

int main(){
    // vector<int> nodes = {1,7,0,7,-8,-1,-1};
    vector<int> nodes = {989,-1,10250,98693,-89388,-1,-1,-1,-32127};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.maxLevelSum(root) << endl;
    return 0;
}