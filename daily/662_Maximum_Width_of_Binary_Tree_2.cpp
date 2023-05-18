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
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> que;
    que.push(root);
    TreeNode* temp;
    int i = 1;
    int n = nodes.size();
    while(i < n){
        temp = que.front();
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

void print_tree(TreeNode* root){
    if (!root) return;
    queue<TreeNode*> que;
    que.push(root);
    cout << root->val << " ";
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        if (temp->left){
            cout << temp->left->val << " ";
            que.push(temp->left);
        }
        else cout << "-1 ";
        if (temp->right){
            cout << temp->right->val << " ";
            que.push(temp->right);
        }
        else cout << "-1 ";
    }
}

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        queue<pair<int,TreeNode*>> que;
        que.push({0, root});
        while(!que.empty()){
            ans = max(ans, que.back().first - que.front().first + 1);
            int n = que.size();
            while(n--){
                int index = que.front().first;
                TreeNode* temp = que.front().second;
                que.pop();
                if (temp->left) que.push({index * 2LL + 1, temp->left});
                if (temp->right) que.push({index * 2LL + 2, temp->right});
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,3,2,5,3,-1,9};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.widthOfBinaryTree(root) << endl;
    return 0;
}