#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* create_list(vector<vector<int>> nodes){
    int n = nodes.size();
    unordered_map<int,Node*> m;
    Node* pseudo = new Node(0);
    Node* temp = pseudo;
    for (int i = 0; i < n; i++){
        int val = nodes[i][0];
        int random = nodes[i][1];
        temp->next = new Node(val);
        temp = temp->next;
        m[i] = temp;
    }
    temp = pseudo->next;
    for (int i = 0; i < n; i++){
        if (nodes[i][1] != -1) temp->random = m[nodes[i][1]];
        temp = temp->next;
    }
    return pseudo->next;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* pseudo = new Node(0);
        unordered_map<Node*,int> original;
        Node* temp = head;
        int i = 0;
        while(temp){
            original[temp] = i;
            temp = temp->next;
            i++;
        }
        temp = pseudo;
        unordered_map<int,Node*> ans;
        int index = 0;
        while(index < i){
            temp->next = new Node(0);
            temp = temp->next;
            ans[index] = temp;
            index++;
        }
        temp = pseudo->next;
        while(temp){
            temp->val = head->val;
            if (head->random) temp->random = ans[original[head->random]];
            temp = temp->next;
            head = head->next;
        }
        return pseudo->next;
    }
};

int main(){
    vector<vector<int>> nodes = {{7,0},{13,0},{11,4},{10,2},{1,0}};
    Node* head = create_list(nodes);
    Solution S;
    Node* ans = S.copyRandomList(head);
    return 0;
}