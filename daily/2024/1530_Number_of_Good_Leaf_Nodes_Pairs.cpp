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
    int ans = 0;
    void count_two_side(TreeNode* root, int distance){
        // cout << root->val << " : " << endl;
        if (root->left == nullptr && root->right == nullptr) return;
        vector<int> left(distance, 0);
        queue<TreeNode*> lq;
        if (root->left) lq.push(root->left);
        int depth = 1;
        while(!lq.empty() && depth < distance){
            int k = lq.size();
            while(k--){
                TreeNode* temp = lq.front();
                lq.pop();
                if (temp->left == nullptr && temp->right == nullptr){
                    // cout << temp->val << " is counted" << endl;
                    left[depth]++;
                }
                else{
                    if (temp->left) lq.push(temp->left);
                    if (temp->right) lq.push(temp->right);
                }
            }
            depth++;
        }
        // for (auto i : left) cout << i << " ";
        // cout << endl;

        vector<int> right(distance, 0);
        queue<TreeNode*> rq;
        if (root->right) rq.push(root->right);
        depth = 1;
        while(!rq.empty() && depth < distance){
            int k = rq.size();
            while(k--){
                TreeNode* temp = rq.front();
                rq.pop();
                if (temp->left == nullptr && temp->right == nullptr) right[depth]++;
                else{
                    if (temp->left) rq.push(temp->left);
                    if (temp->right) rq.push(temp->right);
                }
            }
            depth++;
        }
        // for (auto i : right) cout << i << " ";
        // cout << endl;

        int acc = 0;
        for (int i = 1; i < distance; i++) acc += left[i];
        int temp = 0;
        for (int i = 1; i < distance; i++){
            temp += acc * right[i];
            acc -= left[distance - i];
        }
        // cout << temp << endl;
        ans += temp;
        return;
    }
    
    int countPairs(TreeNode* root, int distance) {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            count_two_side(temp, distance);
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,2,3,-1,4};
    int distance = 3;
    // vector<int> nodes = {1,2,3,4,5,6,7};
    // int distance = 3;
    // vector<int> nodes = {7,1,4,6,-1,5,3,-1,-1,-1,-1,-1,2};
    // int distance = 3;
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.countPairs(root, distance) << endl;
    return 0;
}