#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* position[101] = {0}; 
    Node* cloneGraph(Node* node) {
        if (node == NULL) return node;
        Check(node);
        return position[1];
    };

    Node* Check(Node* node){
        if (position[node->val] == 0){
            // create the new node
            vector<Node*> temp_neighbor;
            temp_neighbor.reserve(node->neighbors.size());
            Node* temp = new Node (node->val, temp_neighbor);

            position[node->val] = temp;
            // temp->val = node->val;
            for (auto neighbor : node->neighbors){
                temp->neighbors.push_back(Check(neighbor));
            }
            return temp;
        }
        else{
            return position[node->val];
        }
    };
};

void PrintGraph(Node* node){
    for (auto neighbor : node->neighbors){
        cout << neighbor->val;
    }
}

int main(){
    vector<Node*> emp;
    emp.reserve(2); 
    Node *a = new Node(1, emp);
    Node *b = new Node(2, emp);
    Node *c = new Node(3, emp);
    Node *d = new Node(4, emp);
    a->neighbors.push_back(b);
    a->neighbors.push_back(d);
    b->neighbors.push_back(a);
    b->neighbors.push_back(c);
    c->neighbors.push_back(b);
    c->neighbors.push_back(d);
    d->neighbors.push_back(a);
    d->neighbors.push_back(c);

    Solution S;
    PrintGraph(S.cloneGraph(a));


    return 0;
}