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

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if (!root) return {};

        vector<double> ans;
        queue<TreeNode*> que;
        queue<TreeNode*> next;
        double temp;

        que.push(root);

        while(!que.empty()){
            temp = 0;
            int count = 0;
            while(!que.empty()){
                TreeNode* now = que.front();
                que.pop();
                count++;
                temp += now->val;
                if (now->left) next.push(now->left);
                if (now->right) next.push(now->right);
            }
            // cout << temp << endl;
            ans.push_back(temp/count);
            swap(que, next);
        }

        return ans;
    }
};

int main(){
    vector<int> node = {3,9,20,-1,-1,15,7};
    TreeNode* root = create(node);

    Solution S;
    vector<double> ans = S.averageOfLevels(root);

    for (auto i : ans) cout << i << " ";
    cout << endl;

    return 0;
}