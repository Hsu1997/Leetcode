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

TreeNode* create(vector<int> node){
    if (node.empty()) return nullptr;

    TreeNode* root = new TreeNode(node[0]);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;

    while(i < node.size()){
        TreeNode* temp = que.front();
        que.pop();

        if (i < node.size() && node[i] != -1){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
        }
        i++;
        if (i < node.size() && node[i] != -1){
            temp->right = new TreeNode(node[i]);
            que.push(temp->right);
        }
        i++;
    }

    return root;
}

void print(TreeNode* root){
    if (!root) return;

    queue<TreeNode*> que;
    que.push(root);

    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp == nullptr){
            cout << -1 << " ";
            continue;
        }
        else{
            cout << temp->val << " ";
            if (!temp->left && !temp->right) continue;
            else{
                que.push(temp->left);
                que.push(temp->right);
            }
        }
    }
    cout << endl;
}

class Solution {
public:
    int ans = 0;
    vector<int> count;

    void dfs(TreeNode* node){
        count[node->val]++;
        if (!node->left && !node->right){
            palindromic();
            // for (auto i : count) cout << i << " ";
            // cout << " : " << ans << endl;
        }
        else{
            if (node->left) dfs(node->left);
            if (node->right) dfs(node->right);
        }
        count[node->val]--;
    }

    void palindromic(){
        int odd = 0;
        for (auto i : count) if (i % 2 == 1) odd++;
        if (odd <= 1) ans++;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        count = vector<int>(10,0);
        dfs(root);
        return ans;
    }
};

int main(){
    // vector<int> node = {2,3,1,3,1,-1,1};
    // vector<int> node = {2,1,1,1,3,-1,-1,-1,-1,-1,1};
    vector<int> node = {9};
    TreeNode* root = create(node);
    // print(root);
    Solution S;
    cout << S.pseudoPalindromicPaths(root) << endl;
    return 0;
}