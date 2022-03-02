#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<Node*> q;
        q.push(root);
        Node* current;
        int size = 0;
        int level_end = 1;
        while(!q.empty()){
            current = q.front();
            q.pop();
            // cout << current->val << endl;
            size++;
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
            if (size == level_end){
                level_end = level_end * 2 + 1;
                current->next = NULL;
            }
            else{
                current->next = q.front();
            }
        }
        return root;
    }
};

void CreateNode(Node* parents, int limit){
    if (parents->val >= limit) return;
    parents->left = new Node(parents->val*2);
    // cout << "create node " << parents->val*2 << ", limit = " << limit << endl;
    parents->right = new Node(parents->val*2+1);
    // cout << "create node " << parents->val*2+1 << ", limit = " << limit << endl;
    CreateNode(parents->left, limit);
    CreateNode(parents->right, limit);
}

int main(){
    int size = 7;
    int hight = log2(size+1);
    Node* root = new Node(1);
    CreateNode(root, pow(2,(hight-1)));

    Solution S;
    S.connect(root);
    Node* current_level = root;
    Node* current = root;
    while(current_level != NULL){
        while(current != NULL){
            cout << current->val << " ";
            current = current->next;
        }
        current_level = current_level->left;
        current = current_level;
    }
    return 0;
}