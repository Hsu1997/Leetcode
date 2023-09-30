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


void print_tree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (!temp) cout << -1 << " ";
        else{
            que.push(temp->left);
            que.push(temp->right);
            cout << temp->val << " ";
        }
    }
    cout << endl;
}

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        vector<vector<TreeNode*>> dp(n + 1);
        dp[1].push_back(new TreeNode(0));
        for (int count = 3; count <= n; count += 2){
            for (int left = 1; left < count - 1; left += 2){
                int right = count - left - 1;
                for (auto i : dp[left]){
                    for (auto j : dp[right]){
                        TreeNode* temp = new TreeNode(0, i, j);
                        dp[count].push_back(temp);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main(){
    int n = 7;
    Solution S;
    vector<TreeNode*> ans = S.allPossibleFBT(n);
    for (auto i : ans) print_tree(i);
    return 0;
}