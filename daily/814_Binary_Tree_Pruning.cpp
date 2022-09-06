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
    if (root == nullptr){
        cout << "empty tree" << endl;
        return;
    }

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
        else cout << -1 << " ";
        if (temp->right){
            cout << temp->right->val << " ";
            que.push(temp->right);
        }
        else cout << -1 << " ";
    }
    return;
}

class Solution {
public:
    TreeNode* r;

    bool dfs(TreeNode* root){
        if (!root) return false;
        // cout << "Node " << root->val << " : " << endl;

        bool left = false;
        bool right = false;
        bool subtree = false;

        left = dfs(root->left);
        right = dfs(root->right);
        // cout << "left = " << left << ", right = " << right << endl;
        subtree = left || right || (root->val == 1);

        if (!left) root->left = nullptr;
        if (!right) root->right = nullptr;

        if (root == r && subtree == false){
            // cout << "Root" << endl;   
            r = nullptr;
        }

        return subtree;
    }

    TreeNode* pruneTree(TreeNode* root) {
        r = root;
        dfs(root);
        // print(r);
        return r;
    }
};

int main(){
    vector<int> node = {0,-1,0,0,0};
    TreeNode* root = create(node);
    Solution S;
    S.pruneTree(root);
    print(root);
    return 0;
}