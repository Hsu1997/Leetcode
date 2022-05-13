#include <iostream>
#include <vector>

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

Node createtree(vector<int> root){
    *root = new Node(root[0]);


}

class Solution {
public:
    Node* connect(Node* root) {
        
    }
};

int main(){
    vector<int> root = {1,2,3,4,5,-1,7};

}

