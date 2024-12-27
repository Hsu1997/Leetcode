#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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
    int i = 1;
    int n = nodes.size();
    queue<TreeNode*> que;
    que.push(root);
    while(i < n){
        TreeNode* curr = que.front();
        que.pop();
        if (i < n && nodes[i] != -1){
            curr->left = new TreeNode(nodes[i]);
            que.push(curr->left);
        }
        i++;
        if (i < n && nodes[i] != -1){
            curr->right = new TreeNode(nodes[i]);
            que.push(curr->right);
        }
        i++;
    }
    return root;
}
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while(!que.empty()){
            int curr_level_size = que.size();
            vector<int> temp;
            unordered_map<int,int> pos;
            while(curr_level_size--){
                TreeNode* curr = que.front();
                que.pop();
                pos[curr->val] = temp.size();
                temp.push_back(curr->val);
                if (curr->left) que.push(curr->left);
                if (curr->right) que.push(curr->right);
            }
            vector<int> sorted_temp = temp;
            sort(sorted_temp.begin(), sorted_temp.end());
            // for (auto i : pos) cout << i.first << ":" << i.second << endl;
            // for (auto i : temp) cout << i << " ";
            // cout << endl;
            // for (auto i : sorted_temp) cout << i << " ";
            // cout << endl;
            for (int i = 0; i < temp.size(); i++){
                if (temp[i] != sorted_temp[i]){
                    temp[pos[sorted_temp[i]]] = temp[i];
                    pos[temp[i]] = pos[sorted_temp[i]];
                    temp[i] = sorted_temp[i];
                    pos[sorted_temp[i]] = i;
                    ans++;
                }
            }
            // cout << "ans = " << ans << endl;
        }
        return ans;
    }
};

int main(){
    vector<int> nodes = {1,4,3,7,6,8,5,-1,-1,-1,-1,9,-1,10};
    // vector<int> nodes = {1,3,2,7,6,5,4};
    // vector<int> nodes = {1,2,3,4,5,6};
    TreeNode* root = create_tree(nodes);
    Solution S;
    cout << S.minimumOperations(root) << endl;
    return 0;
}