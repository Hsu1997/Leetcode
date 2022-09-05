#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ans;
        queue<Node*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<int> now_level;
            for (int i = 0; i < size; i++){
                Node* temp = que.front();
                que.pop();
                now_level.push_back(temp->val);
                for (auto i : temp->children) que.push(i);
            }
            ans.push_back(now_level);
        }
        return ans;
    }
};