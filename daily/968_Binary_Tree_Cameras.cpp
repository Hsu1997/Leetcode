#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

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
    int n = node.size();
    TreeNode* root = new TreeNode(node[0]);

    queue<TreeNode*> que;
    que.push(root);

    for (int i = 1; i < n ; i++){
        TreeNode* temp = que.front();
        que.pop();
        if (node[i] != -1){
            temp->left = new TreeNode(node[i]);
            que.push(temp->left);
        }
        i++;
        if ((i < n) && node[i] != -1){
            temp->right = new TreeNode(node[i]);
            que.push(temp->right);
        }
    }

    return root;
}

void PrintTree(TreeNode* root){
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* temp = que.front();
        cout << temp->val << " ";
        que.pop();
        if (temp->left){
            que.push(temp->left);
        }
        if (temp->right){
            que.push(temp->right);
        }
        cout << endl;
    }
    return;
}

class Solution {
public:
    int ans;
    unordered_set<TreeNode*> covered;

    void dfs(TreeNode* node, TreeNode* parent){
        if (node){
            dfs(node->left, node);
            dfs(node->right, node);

            if (covered.find(node->left) == covered.end() || covered.find(node->right) == covered.end() || (parent == NULL && covered.find(node) == covered.end())){
                covered.insert(node);
                covered.insert(parent);
                covered.insert(node->left);
                covered.insert(node->right);
                ans++;
            }
        }
        return;
    }

    int minCameraCover(TreeNode* root) {
        ans = 0;
        covered.insert(NULL);
        dfs(root, NULL);
        return ans;
    }
};

int main(){
    vector<int> node = {0,0,-1,0,0};
    // vector<int> node = {0,0,-1,0,-1,0,-1,-1,0};

    TreeNode* root = CreateTree(node);
    Solution S;
    cout << S.minCameraCover(root) << endl;

    return 0;
}