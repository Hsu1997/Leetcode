/*
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
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        
        queue<Node*> que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            Node* pre = NULL;
            Node* temp = NULL;
            
            while(size > 0){
                temp = que.front();
                que.pop();
                size--;
                
                if (temp->left != NULL) que.push(temp->left);
                if (temp->right != NULL) que.push(temp->right);
                
                if (pre == NULL){
                    pre = temp;
                }
                else{
                    pre->next = temp;
                    pre = temp;
                }
            }            
        }
        return root;
    }
};