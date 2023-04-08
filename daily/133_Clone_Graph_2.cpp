#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

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
    unordered_map<Node*, Node*> m;
    
    Node* cloneNode(Node* node){
        Node* c = new Node(node->val);
        m[node] = c;
        for (Node* i : node->neighbors){
            if (!m.count(i)) m[i] = cloneNode(i);
            c->neighbors.push_back(m[i]);
        }
        return c;
    }

    Node* cloneGraph(Node* node) {
        if (!node) return node;
        return cloneNode(node);
    }

    void print_graph(Node* node){
        vector<set<Node*>> edge(101);
        queue<Node*> que;
        que.push(node);
        while(!que.empty()){
            Node* temp = que.front();
            que.pop();
            for (Node* i : temp->neighbors){
                if (!edge[temp->val].count(i)) que.push(i);
                edge[temp->val].insert(i);
            }
        }
        for (auto i : edge){
            if (i.empty()) continue;
            cout << "[ ";
            for (auto j : i){
                cout << j->val << " ";
            }
            cout << "]";
        }
        cout << endl;
    }
};

int main(){
    Solution S;
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    a->neighbors = {b,d};
    b->neighbors = {a,c};
    c->neighbors = {b,d};
    d->neighbors = {a,c};
    S.print_graph(a);
    S.print_graph(S.cloneGraph(a));
    return 0;
}