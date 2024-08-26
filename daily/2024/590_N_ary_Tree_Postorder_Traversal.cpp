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

Node* create_tree(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    int n = nodes.size();
    Node* root = new Node(nodes[0]);
    queue<Node*> que;
    que.push(root);
    int index = 2;
    while(index < n){
        Node* temp = que.front();
        que.pop();
        vector<Node*> _children;
        while(index < n && nodes[index] != -1){
            _children.push_back(new Node(nodes[index]));
            que.push(_children.back());
            index++;
        }
        temp->children = _children;
        index++;
    }
    return root;
}

class Solution {
public:
    vector<int> postorder_path;
    void traversal(Node* root){
        if (!root) return;
        for (Node* n : root->children) traversal(n);
        postorder_path.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        traversal(root);
        return postorder_path;
    }
};

int main(){
    vector<int> nodes = {1,-1,3,2,4,-1,5,6};
    // vector<int> nodes = {1,-1,2,3,4,5,-1,-1,6,7,-1,8,-1,9,10,-1,-1,11,-1,12,-1,13,-1,-1,14};
    Node* root = create_tree(nodes);
    Solution S;
    vector<int> ans = S.postorder(root);
    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}