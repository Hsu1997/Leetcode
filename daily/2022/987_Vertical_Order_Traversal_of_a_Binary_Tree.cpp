#include <iostream>
#include <vector>
#include <queue>
#include <map>

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        map<int,vector<int>> m;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});
        // m[0].push_back(root->val);

        while(!que.empty()){
            int now_count = que.size();
            map<int,vector<int>> m_tmep;
            for (int k = 0; k < now_count; k++){
                TreeNode* temp = que.front().first;
                int position = que.front().second;
                que.pop();
                m_tmep[position].push_back(temp->val);

                if (temp->left) que.push({temp->left, position - 1});
                if (temp->right) que.push({temp->right, position + 1});
            }
            for (auto i : m_tmep){
                sort(i.second.begin(), i.second.end());
                m[i.first].insert(m[i.first].end(), i.second.begin(), i.second.end());
            }
        }

        for (auto i : m){
            vector<int> temp = i.second;
            ans.push_back(temp);
        }

        return ans;
    }
};

int main(){
    // vector<int> node = {3,9,20,-1,-1,15,7};
    // vector<int> node = {1,2,3,4,5,6,7};
    // vector<int> node = {1,2,3,4,6,5,7};
    vector<int> node = {3,1,4,0,2,2};
    TreeNode* root = create(node);
    Solution S;
    vector<vector<int>> ans = S.verticalTraversal(root);
    for (auto i : ans){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}