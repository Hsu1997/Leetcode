#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* create_link_list(vector<int> nodes){
    ListNode* root = new ListNode();
    ListNode* temp = root;
    for (int i : nodes){
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    return root->next;
}

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp = head;
        while(temp){
            while(!s.empty() && temp->val > s.top()->val) s.pop();
            s.push(temp);
            temp = temp->next;
        }
        if (s.empty()) return nullptr;
        temp = s.top();
        s.pop();
        while(!s.empty()){
            s.top()->next = temp;
            temp = s.top();
            s.pop();
        }
        return temp;
    }
};

int main(){
    vector<int> nodes = {5,2,13,3,8};
    // vector<int> nodes = {1,1,1,1};
    ListNode* root = create_link_list(nodes);
    Solution S;
    root = S.removeNodes(root);
    while(root){
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    return 0;
}