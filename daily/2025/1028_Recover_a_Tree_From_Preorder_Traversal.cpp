#include <iostream>
#include <vector>
#include <string>
#include <stack>
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
    if (!root){
        cout << "-1" << endl;
        return;
    }
    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* curr = que.front();
        que.pop();
        if (!curr) cout << "-1" << " ";
        else{
            cout << curr->val << " ";
            que.push(curr->left);
            que.push(curr->right);
        }
    }
    cout << endl;
}

class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int,int>> nodes;
        int depth = 0;
        for (int i = 0; i < traversal.length(); i++){
            if (traversal[i] == '-') depth++;
            else{
                string num;
                while(i < traversal.length() && traversal[i] != '-'){
                    num += traversal[i];
                    i++;
                }
                nodes.push_back({stoi(num), depth});
                depth = 0;
                i--;
            }
        }
        // for (auto i : nodes) cout << i.first << " " << i.second << endl;
        if (nodes.empty()) return nullptr;
        TreeNode* root = new TreeNode(nodes[0].first);
        int n = nodes.size();
        stack<TreeNode*> sta;
        sta.push(root);
        for (int i = 1; i < n; i++){
            if (nodes[i].second == sta.size()){
                TreeNode* curr = sta.top();
                curr->left = new TreeNode(nodes[i].first);
                sta.push(curr->left);
            }
            else{
                int curr_depth = nodes[i].second;
                while(sta.size() > curr_depth) sta.pop();
                TreeNode* curr = sta.top();
                curr->right = new TreeNode(nodes[i].first);
                sta.push(curr->right);
            }
        }
        return root;
    }
};

int main(){
    string traversal = "1-2--3--4-5--6--7";
    // string traversal = "1-2--3---4-5--6---7";
    // string traversal = "1-401--349---90--88";
    Solution S;
    TreeNode* root = S.recoverFromPreorder(traversal);
    print_tree(root);
    return 0;
}