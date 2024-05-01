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

TreeNode* CreateTree(vector<int> node){
    TreeNode* root = new TreeNode(node[0]);
    queue<TreeNode*> que;
    que.push(root); 
    for (int i = 1; i < node.size(); i+=2){
        TreeNode* temp = que.front();
        que.pop();
        temp->left = new TreeNode(node[i]);
        que.push(temp->left);
        if (i+1 < node.size()) temp->right = new TreeNode(node[i + 1]);
        que.push(temp->right);
    }
    return root;
}

void PrintAllTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        que.pop();
        cout << temp->val << " ";
        if(temp->left) que.push(temp->left);
        if (temp->right) que.push(temp->right);
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* now = root;
        while(now != nullptr && now->val != val){
            if (now->val > val) now = now->left;
            else now = now->right;
        }
        return now;
    }
};

int main(){
    vector<int> node = {4,2,7,1,3};
    TreeNode* root = CreateTree(node);
    // PrintAllTree(root);
    int val = 2;
    Solution S;
    TreeNode* output = S.searchBST(root, val);
    if (output) cout << output->val << endl;
    else cout << "nullptr" << endl;
    return 0;
}