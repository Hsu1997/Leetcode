#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define null 0

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        int count = 0;
        int size;
        queue< pair<TreeNode*, long long> > q;
        q.push({root, 1});
        while(!q.empty()){
            size = q.size();
            count = max(count, (int)(q.back().second - q.front().second + 1));
            for (int i = 0; i < size; i++){
                pair<TreeNode*, int> current_pair = q.front();
                TreeNode* current = current_pair.first;
                q.pop();
                if (current->left != nullptr) q.push({current->left, (long long)current_pair.second*2});
                if (current->right != nullptr) q.push({current->right, (long long)current_pair.second*2 + 1});
            }
        }
        return count;
    }
};

TreeNode* CreateTree(vector<int> tree){
    TreeNode* root = new TreeNode(tree.at(0));
    if (tree.size() == 1) return root;
    vector<int>::iterator ptr = ++tree.begin();
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* current;
    while(!q.empty() && ptr != tree.end()){
        current = q.front();
        q.pop();
        if (*ptr != null) {
            current->left = new TreeNode(*ptr);
            q.push(current->left);
        }
        ptr++;
        if (ptr != tree.end()){
            current->right = new TreeNode(*ptr);
            q.push(current->right);
            ptr++;
        }
    }
    return root;
}

void PrintTree(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* current;
    while(!q.empty()){
        current = q.front();
        q.pop();
        cout << current->val << " ";
        if (current->left != nullptr) q.push(current->left);
        if (current->right != nullptr) q.push(current->right);
    }
}

int main(){
    vector<int> tree = {1,3,2,5,3,null,9};
    TreeNode* root = CreateTree(tree);
    // PrintTree(root);
    // cout << "\n" << root->right->left->val << endl;
    Solution S;
    cout << S.widthOfBinaryTree(root) << endl;
    return 0;
}