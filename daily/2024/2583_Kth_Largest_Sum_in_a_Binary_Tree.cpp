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
    queue<TreeNode*> que;
    que.push(root);
    int n = nodes.size();
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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int n = que.size();
            long long curr_sum = 0;
            while(n--){
                TreeNode* temp = que.front();
                que.pop();
                curr_sum += temp->val;
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
            pq.push(curr_sum);
        }
        if (pq.size() < k) return -1;
        for (int i = 0; i < k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
};

int main(){
    vector<int> nodes = {5,8,9,2,1,3,7,4,6};
    int k = 2;
    // vector<int> nodes = {1,2,-1,3};
    // int k = 1;
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.kthLargestLevelSum(root, k) << endl;
    return 0;
}