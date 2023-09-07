#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* create_list(vector<int> nodes){
    if (nodes.empty()) return nullptr;
    ListNode* pseudo = new ListNode();
    ListNode* temp = pseudo;
    for (auto i : nodes){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return pseudo->next;
}

void print_list(ListNode* root){
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    return;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> sta;
        ListNode* pseudo = new ListNode(0, head);
        ListNode* current = pseudo;
        ListNode* h;
        ListNode* t;
        for (int i = 0; i <= right; i++){
            if (i == left-1) h = current;
            if (i == right) t = current->next;
            if (i >= left && i <= right) sta.push(current);
            current = current->next;
        }
        current = h;
        while(!sta.empty()){
            current->next = sta.top();
            sta.pop();
            current = current->next;
        }
        current->next = t;
        return pseudo->next;
    }
};

int main(){
    // vector<int> nodes = {1,2,3,4,5};
    // int left = 2;
    // int right = 4;
    vector<int> nodes = {5};
    int left = 1;
    int right = 1;
    ListNode* head = create_list(nodes);
    Solution S;
    print_list(S.reverseBetween(head, left, right));
    return 0;
}